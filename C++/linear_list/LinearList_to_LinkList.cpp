// ��˳���ת��Ϊ����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define list_init_size 20
#define listincrement 5
typedef struct					//˳���ṹ��
{
	int *elem;
	int length;
	int listsize;
}sqlist;
typedef struct lnode			//����ṹ��
{
	int data;
	lnode *next;
}lnode,*linklist;
class operation
{
public:
	//˳���ĳ�ʼ��
	void initsqlist(sqlist&l)
	{
		l.elem=new int [list_init_size];
		if(!l.elem)return;
		l.length=0;
		l.listsize=list_init_size;
	}
	//����ĳ�ʼ��
	void initlinklist(linklist&l)
	{
		if(!l)return;
		l=new lnode;
		l->next=NULL;
	}
	//˳���Ľ���
	void creatlist_sq(sqlist&l,int a[])
	{
		initsqlist(l);
		cout<<"length=";
		cin>>l.length;
		cout<<"�����볤��Ϊ"<<l.length<<"��˳������"<<endl;
		for(i=0;i<l.length;i++)
		{
			cin>>a[i];
		}
		l.elem=&a[0];
	}
	//˳���ת��Ϊ����
	void exchange(linklist&L,sqlist&l)   //��˳���ת��Ϊ����ͷ��������
	{
		initlinklist(L);
		initsqlist(l);
		creatlist_sq(l,a);
		lnode *p,*q;
		q=L;
		for(i=0;i<l.length;i++)
		{
			p=new lnode;
			p->data=l.elem[i];
			p->next=q->next;
			q->next=p;
			q=p;
		}
		display(L,l.length);
		cout<<"��Ϊlength="<<linklist_length(L)<<endl;
	}
	void display(linklist&L,int length)  //�������
	{
		cout<<"˳���ת���������Ϊ��"<<endl;
		for(i=0;i<length;i++)
		{
			cout<<L->next->data<<" ";
			L=L->next;
		}
		cout<<endl;
	}
	//���
	int linklist_length(linklist L)
	{
		if(!L)return 0;
		int n=0;
		while(L->next)
		{
			L=L->next;
			n++;
		}
		return n;
	}
private:
	int i,j;
	int a[100];
	int length;
};

int main(int argc, char* argv[])
{
	operation list;
	linklist L;
	sqlist l;
	list.exchange(L,l);
	return 0;
}
