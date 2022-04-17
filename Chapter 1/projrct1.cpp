#include <iostream>
#include <stdio.h>
#define MAXSIZE 100					//˳�����ܴﵽ����󳤶�
#define OK 1
#define ERROR 0

using namespace std;

typedef int ElemType;
typedef int Status;

//-------˳���Ĵ洢�ṹ---------
typedef struct
{
	ElemType* elem;   //�洢�ռ�Ļ���ַ
	int length;				//��ǰ����
}SqList;						//˳���Ľṹ����ΪSqList

//-------˳���ĳ�ʼ��---------
Status InitList(SqList& L)					//����һ���յ�˳���L
{
	L.elem = new ElemType[MAXSIZE];					//Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L.elem)
	{
		exit(OVERFLOW);						//�洢����ʧ���˳�
	}
	L.length = 0;									//�ձ���Ϊ0
	return OK;
}

//-------˳���Ĳ���---------
Status ListInsert(SqList& L, int  i, ElemType e)			//��˳���L�е�i��λ�ò����µ�Ԫ��e��iֵ�ĺϷ���Χ��1<=i<=L.length+1
{
	if ((i < 1) || (i > L.length + 1))									//iֵ���Ϸ�
	{
		cout << "����ʧ�ܣ�" << endl;
		return ERROR;
	}
	if (L.length > MAXSIZE)												//��ǰ�洢�ռ�����
	{
		cout << "����ʧ�ܣ�" << endl;
		return ERROR;
	}
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
	cout << "����ɹ���" << endl;
	return OK;
}

//-------˳���Ĳ���---------
int LocateElem(SqList L, ElemType e)										//��˳���L�в���ֵΪe������Ԫ�أ����������
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			return i + 1;															//���ҳɹ����������i+1
		}																					
	}
	return 0;																			//����ʧ�ܣ�����0
}

//-------˳����ȡֵ---------
Status GetElem(SqList L, int i, ElemType& e)							
{
	if (i<1 || i>L.length)														//�ж�iֵ�Ƿ����������������ERROR
	{
		cout << "��λ�ò�����" << endl;
		return ERROR;
	}
	e = L.elem[i - 1];																//elem[i-1]��Ԫ�洢��i������Ԫ��
	cout << "ȡ����ֵΪ��" <<e<< endl;
	return OK;
}

//-------˳����ɾ��---------
Status ListDelete(SqList& L, int i)											//��˳���L��ɾ����i��Ԫ�أ�iֵ�ĺϷ���Χ��1<=i<=L.length
{
	if ((i < 1) || (i > L.length))													//iֵ���Ϸ�
	{
		cout << "�޿�ɾ����Ԫ�أ�" << endl;
		return ERROR;
	}
	for (int j = i; j <= L.length - 1; j++)
	{
		L.elem[j - 1] = L.elem[j];												//��ɾ��Ԫ��֮���Ԫ��ǰ��
	}
	--L.length;																			//����1
	cout << "ɾ���ɹ���" << endl;
	return OK;
}

//-------˳���ı���---------
Status TraverseList(SqList L)
{
	for (int i = 0; i < L.length; i++)										//����ÿ������Ԫ��
	{
		cout << L.elem[i]  ;
	}
	cout << endl;																	//��ӡ����
	return OK;
}

//-------˳���ı��ж�---------
Status ListLength(SqList L)
{
	int s = 0;
	if ((L.length < 0) || (L.length > MAXSIZE))
	{
		cout << "���Ա�ĳ���Ϊ0��" << endl;
		return ERROR;
	}
	else
	{
		s=L.length;
		cout <<"���Ա�ĳ���Ϊ��" << s << endl;
		return OK;
	}
}

//-------˳����Ԫ��ǰ��---------
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
		cout << "��Ԫ�ز�����ǰ����" << endl;
		return ERROR;
	}
	else
	{
		pre_e = L.elem[i - 1];											//����ǰ��
		cout << "��Ԫ�ص�ǰ��Ϊ��" << pre_e << endl;
		return OK;
	}
}

//-------˳����Ƿ�Ϊ��---------
bool ListEmpty(SqList L)
{
	return (L.length == 0);											//1��ʾ���Ա�Ϊ�գ�0��ʾ���Ա�ǿ�
}

//-------˳��������---------
void DestroyList(SqList& L)
{
	free(L.elem);
	cout << "���ٳɹ���" << endl;
}

int main()
{
	SqList L;
		cout << "---------------�˵�ѡ��---------------" << endl;
		cout << "----------1�����Ա�ĳ�ʼ��----------" << endl;
		cout << "----------2�����Ա�Ĳ���----------" << endl;
		cout << "----------3�����Ա���Ƿ�Ϊ��----------" << endl;
		cout << "----------4�����Ա�ı�----------" << endl;
		cout << "----------5�����Ա��ǰ��----------" << endl;
		cout << "----------6�����Ա��ɾ��----------" << endl;
		cout << "----------7�����Ա�ı���----------" << endl;
		cout << "----------8�����Ա��ȡֵ----------" << endl;
		cout << "----------9�����Ա�Ĳ���----------" << endl;
		cout << "----------10�����Ա������----------" << endl;
		cout << "----------0���˳�----------" << endl;
		int flag = 1;
     while(flag==1)
	 { 
		int k;																//�˵�ѡ��
		cout << "��ѡ��Ĳ���ѡ�" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			InitList(L);
			cout << "���Ա��ʼ���ɹ���" << endl;
			continue;
		case 2:
			int pos1;
			cout << "������Ҫ�����λ�ã�" << endl;
			cin >> pos1;
			ElemType val1;
			cout << "������Ҫ�����ֵ��" << endl;
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
			cout << "Ҫ����Ԫ��Ϊ��" << endl;
			cin >> cur;
			PriorElem(L, cur, pre);
			continue;
		case 6:
			int pos2;
			cout << "������Ҫɾ����Ԫ�ص�λ�ã�" << endl;
			cin >> pos2;
			ListDelete(L, pos2);
			continue;
		case 7:
			cout << "˳����Ԫ��Ϊ��" << endl;
			TraverseList(L);
			continue;
		case 8:
			int pos3;
			cout << "��������Ҫ��ȡ��Ԫ�ص�λ�ã�" << endl;
			cin >> pos3;
			int val2;
			GetElem(L, pos3, val2);
			continue;
		case 9:
			int val3,val4;
			cout << "����������Ԫ�أ�" << endl;
			cin >> val3;
			val4 = LocateElem(L, val3);
			cout <<"��Ԫ�����ڵ�λ��Ϊ��" << val4 << endl;
		case 10:
			DestroyList(L);
			continue;
		case 0:
			flag = 0;
			break;
		default:
			cout << "��������ȷ��ѡ�" << endl;
			continue;
		}
	}
	return 0;
}
