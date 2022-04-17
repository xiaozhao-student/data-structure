#include <iostream>
#include <stdio.h>
#define MAXSIZE 100					//顺序表可能达到的最大长度
#define OK 1
#define ERROR 0

using namespace std;

typedef int ElemType;
typedef int Status;

//-------顺序表的存储结构---------
typedef struct
{
	ElemType* elem;   //存储空间的基地址
	int length;				//当前长度
}SqList;						//顺序表的结构类型为SqList

//-------顺序表的初始化---------
Status InitList(SqList& L)					//构造一个空的顺序表L
{
	L.elem = new ElemType[MAXSIZE];					//为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem)
	{
		exit(OVERFLOW);						//存储分配失败退出
	}
	L.length = 0;									//空表长度为0
	return OK;
}

//-------顺序表的插入---------
Status ListInsert(SqList& L, int  i, ElemType e)			//在顺序表L中第i个位置插入新的元素e，i值的合法范围是1<=i<=L.length+1
{
	if ((i < 1) || (i > L.length + 1))									//i值不合法
	{
		cout << "插入失败！" << endl;
		return ERROR;
	}
	if (L.length > MAXSIZE)												//当前存储空间已满
	{
		cout << "插入失败！" << endl;
		return ERROR;
	}
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
	cout << "插入成功！" << endl;
	return OK;
}

//-------顺序表的查找---------
int LocateElem(SqList L, ElemType e)										//在顺序表L中查找值为e的数据元素，返回其序号
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			return i + 1;															//查找成功，返回序号i+1
		}																					
	}
	return 0;																			//查找失败，返回0
}

//-------顺序表的取值---------
Status GetElem(SqList L, int i, ElemType& e)							
{
	if (i<1 || i>L.length)														//判断i值是否合理，若不合理，返回ERROR
	{
		cout << "该位置不合理！" << endl;
		return ERROR;
	}
	e = L.elem[i - 1];																//elem[i-1]单元存储第i个数据元素
	cout << "取出的值为：" <<e<< endl;
	return OK;
}

//-------顺序表的删除---------
Status ListDelete(SqList& L, int i)											//在顺序表L中删除第i个元素，i值的合法范围是1<=i<=L.length
{
	if ((i < 1) || (i > L.length))													//i值不合法
	{
		cout << "无可删除的元素！" << endl;
		return ERROR;
	}
	for (int j = i; j <= L.length - 1; j++)
	{
		L.elem[j - 1] = L.elem[j];												//被删除元素之后的元素前移
	}
	--L.length;																			//表长减1
	cout << "删除成功！" << endl;
	return OK;
}

//-------顺序表的遍历---------
Status TraverseList(SqList L)
{
	for (int i = 0; i < L.length; i++)										//遍历每个数据元素
	{
		cout << L.elem[i]  ;
	}
	cout << endl;																	//打印美观
	return OK;
}

//-------顺序表的表长判断---------
Status ListLength(SqList L)
{
	int s = 0;
	if ((L.length < 0) || (L.length > MAXSIZE))
	{
		cout << "线性表的长度为0！" << endl;
		return ERROR;
	}
	else
	{
		s=L.length;
		cout <<"线性表的长度为：" << s << endl;
		return OK;
	}
}

//-------顺序表的元素前驱---------
Status PriorElem(SqList L, int cur_e, int& pre_e)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.elem[i]==cur_e)
		{
			break;
		}
	}
	if (i == 0)
	{
		cout << "该元素不存在前驱！" << endl;
		return ERROR;
	}
	else
	{
		pre_e = L.elem[i - 1];											//返回前驱
		cout << "该元素的前驱为：" << pre_e << endl;
		return OK;
	}
}

//-------顺序表是否为空---------
bool ListEmpty(SqList L)
{
	return (L.length == 0);											//1表示线性表为空，0表示线性表非空
}

//-------顺序表的销毁---------
void DestroyList(SqList& L)
{
	free(L.elem);
	cout << "销毁成功！" << endl;
}

int main()
{
	SqList L;
		cout << "---------------菜单选项---------------" << endl;
		cout << "----------1、线性表的初始化----------" << endl;
		cout << "----------2、线性表的插入----------" << endl;
		cout << "----------3、线性表的是否为空----------" << endl;
		cout << "----------4、线性表的表长----------" << endl;
		cout << "----------5、线性表的前驱----------" << endl;
		cout << "----------6、线性表的删除----------" << endl;
		cout << "----------7、线性表的遍历----------" << endl;
		cout << "----------8、线性表的取值----------" << endl;
		cout << "----------9、线性表的查找----------" << endl;
		cout << "----------10、线性表的销毁----------" << endl;
		cout << "----------0、退出----------" << endl;
		int flag = 1;
     while(flag==1)
	 { 
		int k;																//菜单选项
		cout << "您选择的操作选项：" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			InitList(L);
			cout << "线性表初始化成功！" << endl;
			continue;
		case 2:
			int pos1;
			cout << "请输入要插入的位置：" << endl;
			cin >> pos1;
			ElemType val1;
			cout << "请输入要插入的值：" << endl;
			cin >> val1;
			ListInsert(L, pos1, val1);
			continue;
		case 3:
			cout << ListEmpty(L) << endl;								
			continue;
		case 4:
			ListLength(L);
			continue;
		case 5:
			int pre;
			int cur;
			cout << "要检查的元素为：" << endl;
			cin >> cur;
			PriorElem(L, cur, pre);
			continue;
		case 6:
			int pos2;
			cout << "请输入要删除的元素的位置：" << endl;
			cin >> pos2;
			ListDelete(L, pos2);
			continue;
		case 7:
			cout << "顺序表的元素为：" << endl;
			TraverseList(L);
			continue;
		case 8:
			int pos3;
			cout << "请输入您要索取的元素的位置：" << endl;
			cin >> pos3;
			int val2;
			GetElem(L, pos3, val2);
			continue;
		case 9:
			int val3,val4;
			cout << "请输入待查的元素：" << endl;
			cin >> val3;
			val4 = LocateElem(L, val3);
			cout <<"该元素所在的位置为：" << val4 << endl;
		case 10:
			DestroyList(L);
			continue;
		case 0:
			flag = 0;
			break;
		default:
			cout << "请输入正确的选项！" << endl;
			continue;
		}
	}
	return 0;
}
