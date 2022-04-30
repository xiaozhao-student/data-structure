#include<iostream>
#define OK 1
#define ERROR 0
#define MAXSIZE 100									//��������ܴﵽ�����̶�

using namespace std;

typedef int Status;
typedef int ElemType;

//----------������Ĵ洢�ṹ----------
typedef struct LNode
{
	ElemType data;									//����������
	struct LNode* next;								//����ָ����
}LNode, * LinkList;									//LinkListΪָ��ṹ��LNode��ָ������


//----------������ĳ�ʼ��----------
Status InitList(LinkList& L)						//����һ���յĵ�����L
{
	L = new LNode;									//�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL;									//ͷ����ָ�����ÿ�
	return OK;
}

//----------�������ȡֵ----------
Status GetElem(LinkList L, int i, ElemType& e)		//�ڴ�ͷ���ĵ�����L�и������i��ȡԪ�ص�ֵ����e����L�е�i������Ԫ�ص�ֵ
{
	LNode* p;										//pΪָ��������ĳ������ָ��
	int j;											//jΪ������
	p = L->next;									//��ʼ����pָ����Ԫ���
	j = 1;											//������j��ֵ��Ϊ1
	while (p && j < i)								//˳�������ɨ�裬ֱ��pΪ�ջ�pָ���i��Ԫ��
	{
		p = p->next;								//pָ����һ�����
		++j;										//������j��Ӧ��1
	}
	if (!p || j > i)								//iֵ���Ϸ�i>n��i<=0
	{
		return ERROR;
	}
	e = p->data;									//ȡ��i������������
	return OK;
}

//----------������İ�ֵ����----------
LNode* LocateElem(LinkList L, ElemType e)			//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
{
	LNode* p;										//pΪָ��������ĳ������ָ��
	p = L->next;									//��ʼ����pָ����Ԫ���
	while (p && p->data != e)						//˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e
	{
		p = p->next;								//pָ����һ�����
	}
	return p;										//���ҳɹ�����ֵΪe�Ľ���ַp������ʧ��pΪNULL
}

//----------������Ĳ���----------
Status ListInsert(LinkList& L, int i, ElemType e)	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
{
	LNode* p;
	p = L;
	int j = 0;
	while (p && (j < i - 1))
	{
		p = p->next;
		++j;										//���ҵ�i-1����㣬pָ��ý��
	}
	if (i<0 || j>i - 1)								//i>n+1����i<1
	{
		return ERROR;
	}
	LNode* s = new LNode;							//�����½��*s
	s->data = e;									//�����*s����������Ϊe
	s->next = p->next;								//�����*s��ָ����ָ����ai
	p->next = s;									//�����*p��ָ����ָ����*s
	return OK;
}

//----------�������ɾ��----------
Status ListDelete(LinkList& L, int i)				//�ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ��
{
	LNode* p;
	p = L;
	int j = 0;
	while ((p->next) && (j < i - 1))						//���ҵ�i-1����㣬pָ��ý��
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))					//��i>n��i<1ʱ��ɾ��λ�ò�����
	{
		return ERROR;
	}
	LNode* q = p->next;								//��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next = q->next;								//�ı�ɾ�����ǰ������ָ����
	delete q;										//�ͷ�ɾ�����Ŀռ�
	return OK;
}

//----------ǰ�巨����������----------
void CreateList_H(LinkList& L, int n)				//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
{
	L = new LNode;
	L->next = NULL;									//�Ƚ���һ����ͷ���Ŀ�����
	for (int i = 0; i < n; ++i)
	{
		LNode* p = new LNode;						//�����½��*p
		cout << "Ҫ����ĵ�" << (i + 1) << "������ֵΪ��" << endl;
		cin >> p->data;								//����Ԫ��ֵ�����½��*p��������
		p->next = L->next;
		L->next = p;								//���½��*p���뵽ͷ���֮��
		cout << "����ɹ���" << endl;
	}
}

//----------��巨����������----------
void CreateList_R(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;									//�Ƚ���һ����ͷ���Ŀ�����
	LNode* r = L;									//βָ��rָ��ͷָ��
	for (int i = 0; i < n; ++i)
	{
		LNode* p = new LNode;						//�����½��*p
		cout << "Ҫ����ĵ�" << (i + 1) << "������ֵΪ��" << endl;
		cin >> p->data;								//����Ԫ��ֵ�����½��*p��������
		p->next = NULL;
		r->next = p;								//���½��*p����β���*r֮��
		r = p;										//rָ���µ�β���*p
		cout << "����ɹ���" << endl;
	}
}

//----------������ı���----------
Status TraverseList(LinkList& L)
{
	LNode* p;
	p = L->next;									//����Ԫ�ڵ㿪ʼ����

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}

//----------������ĳ���----------
int ListLength(LinkList& L)							//�����������ͬʱĬ�Ϲ�����Ԫ�ڵ�
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

//----------����������----------
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

//----------�����������----------
Status DestroyList(LinkList& L)						//��ͷ��ʼ����
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
	cout << "---------------�˵�ѡ��------------" << endl;
	cout << "----------1��������ĳ���---------" << endl;
	cout << "----------2���������ȡֵ-----------" << endl;
	cout << "----------3��������İ�ֵ����-------" << endl;
	cout << "----------4��������Ĳ���-----------" << endl;
	cout << "----------5���������ɾ��-----------" << endl;
	cout << "----------6��ǰ�巨����������--------" << endl;
	cout << "----------7����巨����������--------" << endl;
	cout << "----------8��������ı���-----------" << endl;
	cout << "----------9������������-----------" << endl;
	cout << "----------10�������������----------" << endl;
	cout << "----------0���˳�-----------" << endl;

	int flag = 1;									//������־
	LinkList L;
	InitList(L);
	while (flag == 1)
	{
		int k;											//�˵�ѡ��
		cout << "��������Ҫѡ���ѡ�" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			int length;
			length = ListLength(L);
			cout << "������ĳ���Ϊ��" << length << endl;
			continue;
		case 2:
			int pos1;
			ElemType val1;
			cout << "��������λ�ã�" << endl;
			cin >> pos1;
			GetElem(L, pos1, val1);
			cout << "��ȡ�Ľ���ֵΪ��" << val1 << endl;
			continue;
		case 3:
			int val2;
			cout << "������Ҫ���ҵĽ���ֵ��" << endl;
			cin >> val2;
			LNode* val3;
			val3 = LocateElem(L, val2);
			cout << "Ҫ���ҵĽ��ĵ�ַΪ��" << val3 << endl;
			continue;
		case 4:
			int pos2;
			cout << "������Ҫ�����λ�ã�" << endl;
			cin >> pos2;
			ElemType val4;
			cout << "������Ҫ�����ֵ��" << endl;
			cin >> val4;
			ListInsert(L, pos2, val4);
			cout << "����ɹ���" << endl;
			continue;
		case 5:
			int pos3, val5;
			cout << "������Ҫɾ���Ľ���λ�ã�" << endl;
			cin >> pos3;
			val5 = ListDelete(L, pos3);
			if (val5 == 0)
			{
				cout << "ɾ��ʧ�ܣ�" << endl;
			}
			else
			{
				cout << "ɾ���ɹ���" << endl;
			}
			continue;
		case 6:
			int count1;
			cout << "Ҫ����Ľ��Ԫ�صĸ���Ϊ��" << endl;
			cin >> count1;
			CreateList_H(L, count1);
			continue;
		case 7:
			int count2;
			cout << "Ҫ����Ľ��Ԫ�صĸ���Ϊ��" << endl;
			cin >> count2;
			CreateList_R(L, count2);
			continue;
		case 8:
			cout << "�õ�����Ϊ��";
			TraverseList(L);
			continue;
		case 9:
			ClearList(L);
			cout << "����ɹ���" << endl;
			continue;
		case 10:
			DestroyList(L);
			cout << "���ٳɹ���" << endl;
			continue;
		case 0:
			flag = 0;
		default:
			cout << "��������ȷ��ѡ�" << endl;
			continue;
		}
	}

}