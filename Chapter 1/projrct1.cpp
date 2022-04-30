#include<iostream>
#define OK 1
#define ERROR 0
#define MAXSIZE 100									//单链表可能达到的最大程度

using namespace std;

typedef int Status;
typedef int ElemType;

//----------单链表的存储结构----------
typedef struct LNode
{
	ElemType data;									//结点的数据域
	struct LNode* next;								//结点的指针域
}LNode, * LinkList;									//LinkList为指向结构体LNode的指针类型


//----------单链表的初始化----------
Status InitList(LinkList& L)						//构造一个空的单链表L
{
	L = new LNode;									//生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL;									//头结点的指针域置空
	return OK;
}

//----------单链表的取值----------
Status GetElem(LinkList L, int i, ElemType& e)		//在带头结点的单链表L中根据序号i获取元素的值，用e返回L中第i个数据元素的值
{
	LNode* p;										//p为指向单链表中某个结点的指针
	int j;											//j为计数器
	p = L->next;									//初始化，p指向首元结点
	j = 1;											//计数器j初值赋为1
	while (p && j < i)								//顺链域向后扫描，直到p为空或p指向第i个元素
	{
		p = p->next;								//p指向下一个结点
		++j;										//计数器j相应加1
	}
	if (!p || j > i)								//i值不合法i>n或i<=0
	{
		return ERROR;
	}
	e = p->data;									//取第i个结点的数据域
	return OK;
}

//----------单链表的按值查找----------
LNode* LocateElem(LinkList L, ElemType e)			//在带头结点的单链表L中查找值为e的元素
{
	LNode* p;										//p为指向单链表中某个结点的指针
	p = L->next;									//初始化，p指向首元结点
	while (p && p->data != e)						//顺链域向后扫描，直到p为空或p所指结点的数据域等于e
	{
		p = p->next;								//p指向下一个结点
	}
	return p;										//查找成功返回值为e的结点地址p，查找失败p为NULL
}

//----------单链表的插入----------
Status ListInsert(LinkList& L, int i, ElemType e)	//在带头结点的单链表L中第i个位置插入值为e的新结点
{
	LNode* p;
	p = L;
	int j = 0;
	while (p && (j < i - 1))
	{
		p = p->next;
		++j;										//查找第i-1个结点，p指向该结点
	}
	if (i<0 || j>i - 1)								//i>n+1或者i<1
	{
		return ERROR;
	}
	LNode* s = new LNode;							//生成新结点*s
	s->data = e;									//将结点*s的数据域置为e
	s->next = p->next;								//将结点*s的指针域指向结点ai
	p->next = s;									//将结点*p的指针域指向结点*s
	return OK;
}

//----------单链表的删除----------
Status ListDelete(LinkList& L, int i)				//在带头结点的单链表L中，删除第i个元素
{
	LNode* p;
	p = L;
	int j = 0;
	while ((p->next) && (j < i - 1))						//查找第i-1个结点，p指向该结点
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))					//当i>n或i<1时，删除位置不合理
	{
		return ERROR;
	}
	LNode* q = p->next;								//临时保存被删结点的地址以备释放
	p->next = q->next;								//改变删除结点前驱结点的指针域
	delete q;										//释放删除结点的空间
	return OK;
}

//----------前插法创建单链表----------
void CreateList_H(LinkList& L, int n)				//逆位序输入n个元素的值，建立带表头结点的单链表L
{
	L = new LNode;
	L->next = NULL;									//先建立一个带头结点的空链表
	for (int i = 0; i < n; ++i)
	{
		LNode* p = new LNode;						//生成新结点*p
		cout << "要插入的第" << (i + 1) << "个结点的值为：" << endl;
		cin >> p->data;								//输入元素值赋给新结点*p的数据域
		p->next = L->next;
		L->next = p;								//将新结点*p插入到头结点之后
		cout << "插入成功！" << endl;
	}
}

//----------后插法创建单链表----------
void CreateList_R(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;									//先建立一个带头结点的空链表
	LNode* r = L;									//尾指针r指向头指针
	for (int i = 0; i < n; ++i)
	{
		LNode* p = new LNode;						//生成新结点*p
		cout << "要插入的第" << (i + 1) << "个结点的值为：" << endl;
		cin >> p->data;								//输入元素值赋给新结点*p的数据域
		p->next = NULL;
		r->next = p;								//将新结点*p插入尾结点*r之后
		r = p;										//r指向新的尾结点*p
		cout << "插入成功！" << endl;
	}
}

//----------单链表的遍历----------
Status TraverseList(LinkList& L)
{
	LNode* p;
	p = L->next;									//从首元节点开始遍历

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}

//----------单链表的长度----------
int ListLength(LinkList& L)							//构建单链表的同时默认构建首元节点
{
	LNode* p;
	p = L->next;
	int j = 1;
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

//----------单链表的清空----------
Status ClearList(LinkList& L)
{
	LNode* p;
	while (L->next != NULL)
	{
		p = L->next->next;
		free(L->next);
		L->next = p;
	}
	L->next = NULL;
	return OK;
}

//----------单链表的销毁----------
Status DestroyList(LinkList& L)						//从头开始销毁
{
	LNode* p;
	while (L)
	{
		p = L->next;
		free(L);
		L = p;
	}
	return OK;
}

int main()
{
	cout << "---------------菜单选项------------" << endl;
	cout << "----------1、单链表的长度---------" << endl;
	cout << "----------2、单链表的取值-----------" << endl;
	cout << "----------3、单链表的按值查找-------" << endl;
	cout << "----------4、单链表的插入-----------" << endl;
	cout << "----------5、单链表的删除-----------" << endl;
	cout << "----------6、前插法构建单链表--------" << endl;
	cout << "----------7、后插法构建单链表--------" << endl;
	cout << "----------8、单链表的遍历-----------" << endl;
	cout << "----------9、单链表的清空-----------" << endl;
	cout << "----------10、单链表的销毁----------" << endl;
	cout << "----------0、退出-----------" << endl;

	int flag = 1;									//设立标志
	LinkList L;
	InitList(L);
	while (flag == 1)
	{
		int k;											//菜单选项
		cout << "请输入您要选择的选项：" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			int length;
			length = ListLength(L);
			cout << "该链表的长度为：" << length << endl;
			continue;
		case 2:
			int pos1;
			ElemType val1;
			cout << "请输入结点位置：" << endl;
			cin >> pos1;
			GetElem(L, pos1, val1);
			cout << "获取的结点的值为：" << val1 << endl;
			continue;
		case 3:
			int val2;
			cout << "请输入要查找的结点的值：" << endl;
			cin >> val2;
			LNode* val3;
			val3 = LocateElem(L, val2);
			cout << "要查找的结点的地址为：" << val3 << endl;
			continue;
		case 4:
			int pos2;
			cout << "请输入要插入的位置：" << endl;
			cin >> pos2;
			ElemType val4;
			cout << "请输入要插入的值：" << endl;
			cin >> val4;
			ListInsert(L, pos2, val4);
			cout << "插入成功！" << endl;
			continue;
		case 5:
			int pos3, val5;
			cout << "请输入要删除的结点的位置：" << endl;
			cin >> pos3;
			val5 = ListDelete(L, pos3);
			if (val5 == 0)
			{
				cout << "删除失败！" << endl;
			}
			else
			{
				cout << "删除成功！" << endl;
			}
			continue;
		case 6:
			int count1;
			cout << "要插入的结点元素的个数为：" << endl;
			cin >> count1;
			CreateList_H(L, count1);
			continue;
		case 7:
			int count2;
			cout << "要插入的结点元素的个数为：" << endl;
			cin >> count2;
			CreateList_R(L, count2);
			continue;
		case 8:
			cout << "该单链表为：";
			TraverseList(L);
			continue;
		case 9:
			ClearList(L);
			cout << "清除成功！" << endl;
			continue;
		case 10:
			DestroyList(L);
			cout << "销毁成功！" << endl;
			continue;
		case 0:
			flag = 0;
		default:
			cout << "请输入正确的选项！" << endl;
			continue;
		}
	}

}