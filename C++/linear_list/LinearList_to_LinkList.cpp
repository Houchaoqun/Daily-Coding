// 将顺序表转化为链表.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define list_init_size 20
#define listincrement 5
typedef struct					//顺序表结构体
{
	int *elem;
	int length;
	int listsize;
}sqlist;
typedef struct lnode			//链表结构体
{
	int data;
	lnode *next;
}lnode,*linklist;
class operation
{
public:
	//顺序表的初始化
	void initsqlist(sqlist&l)
	{
		l.elem=new int [list_init_size];
		if(!l.elem)return;
		l.length=0;
		l.listsize=list_init_size;
	}
	//链表的初始化
	void initlinklist(linklist&l)
	{
		if(!l)return;
		l=new lnode;
		l->next=NULL;
	}
	//顺序表的建立
	void creatlist_sq(sqlist&l,int a[])
	{
		initsqlist(l);
		cout<<"length=";
		cin>>l.length;
		cout<<"请输入长度为"<<l.length<<"的顺序链表："<<endl;
		for(i=0;i<l.length;i++)
		{
			cin>>a[i];
		}
		l.elem=&a[0];
	}
	//顺序表转化为链表
	void exchange(linklist&L,sqlist&l)   //将顺序表转化为带有头结点的链表。
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
		cout<<"表长为length="<<linklist_length(L)<<endl;
	}
	void display(linklist&L,int length)  //输出链表
	{
		cout<<"顺序表转化后的链表为："<<endl;
		for(i=0;i<length;i++)
		{
			cout<<L->next->data<<" ";
			L=L->next;
		}
		cout<<endl;
	}
	//求表长
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
