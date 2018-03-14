// 复习  线性表  链式表示.cpp : Defines the entry point for the console application.



//线性表顺序存储结构的优点：
//1.逻辑关系上相邻的两个元素在物理位置上也相邻；
//2.可以随机存取顺序表中的任一元素，元素的存储位置可由公式线性求得。


#include "stdafx.h"
#include <iostream>

using namespace std;
typedef int elemtype;

typedef struct Lnode
{
	elemtype	data ;
	struct Lnode	*next ;
} Lnode, *Linklist;             //LNode——结构体类型名，描述链表中的结点类型
								//LinkList——结构体指针类型名，用来说明单链表类型的变量
class operation
{
public:
//************display*********************** 输出操作！！！！
	void display(Linklist&l,int length)
	{
		Lnode *p;
		p=l->next;
		j=0; 
		while(p&&j<length)                  // ！！！！attention
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
//******************************************
//************初始化空链表****************** 
	int initlist(Linklist&l)				//1.申请空间
	{										//2.若l为空表则结束
		l=new Lnode;						 //3.将l的next指向NULL，即构造一个空链表
		if(!l)return 0;
		l->next=NULL;
		return 1;
	}
//******************************************
//************创建一个非空链表**************
//***************头插法*********************
	void input(Linklist&l)           //n为链表的长度
	{
		int n;
		cout<<"请输入链表长度n=";
		cin>>n;
		l=new Lnode;
		l->next=NULL;
		Lnode *p;	
		cout<<"请依次输入链表的数据："<<endl;
		for(i=0;i<n;i++)
		{
			p=new Lnode;
			cin>>p->data;
			p->next=l->next;              //舍去此语句，则结果只输出最后一个数，且调试失败。 将p与L链表联合起来。
			l->next=p;					  //插入链表
		}
		cout<<"用户所设置的链表为："<<endl;
		for(i=0;i<n;i++)                  //输出元素与输入元素相反
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
//*************尾插法***********************
	void creatlist(Linklist&l)
	{
		Lnode *p;
		Lnode *s;
		l=new Lnode;
		l->next=NULL;
		p=l;
		int n;
		cout<<"请输入链表的长度n=";
		cin>>n;
		cout<<"请输入长度为"<<n<<"的链表元素："<<endl;
		for(i=0;i<n;i++)
		{
			s=new Lnode;
			cin>>s->data;
			p->next=s->next;  //？？s->next=p->next!!           //上下两种都行。 s->next=null;
			//s->next=NULL;
			p->next=s;
			p=s;
			//delete s;         //！！！！！这个不能有，有的话就出现内存错误！！
		}
		//delete p;                        //错误原因在delete s和p，两者均不能在此处delete！！！！！！
		cout<<"用户所设置的链表为："<<endl;
		for(i=0;i<n;i++)                  //输出元素与输入元素相同
		{
			cout<<l->next->data<<" ";        //注意输出链表的时候，s和p已经是不存在的了，应用l去输出链表。
			l=l->next;
		}
		cout<<endl;
		delete s,p;
	}
//*************读表元操作******************* 还未成功！！！！！
	int getelem(Linklist l,int i,elemtype&e) //L是带头结点的单链表，读L的第i个元素，用e返回其值
	{	
		Lnode *p;
		//p=new Lnode;
		p=l->next;
		for(j=1;j<i;j++)
			p=p->next;
		e=p->data;
		cout<<"L的第i个元素为"<<e<<endl;
		return 1;

		/*j=1;
		while(p&&j<i)
		{
			p=p->next;
			j++;
		}
		if(!p||j>i)return 0;
		e=p->data;
		return 1;*/
	}
//***********求表长*****************
	int listlength(Linklist l)     // L是带头结点的单链表
	{
		int n=0;
		while(l->next)
		{
			n++;
			l=l->next;
		}
		return n;
	}
//***********************************
//***********插入操作****************
	int listinsert(Linklist&l,int i,elemtype e)   // L是带头结点的单链表,在ai之前插入新结点e
	{
		Lnode *p;
		p=new Lnode;
		p=l->next;
		for(j=1;j<i-1;j++)
		{
			p=p->next;
		}
		Lnode *s;
		s=new Lnode;
		s->data=e;
		s->next=p->next;
		p->next=s;
		int length;
		length=listlength(l)+1;
		cout<<"插入后的链表为："<<endl;
		display(l,length);
		delete p;
		return 0;
	}
//PPT程序:插入法
	int listinsert_ppt(Linklist&l,int i,elemtype e)
	{
		Lnode *p,*s;
		p=l; j=0;										//p指向头结点，j是计数器
		while(p && j<i-1){ p=p->next; j++; }			//找指向ai-1的p
		if (!p || j>i-1) return 0;						//i非法,i大于表长或i<1
		s=(Lnode*)malloc(sizeof(Lnode));
		s->data=e;   
		s->next=p->next;  p->next=s;					//修改指针
		int length;
		length=listlength(l);
		cout<<"插入后的链表为："<<endl;
		p=l->next;
		for(j=0;j<length+1;j++)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		return 1;

	}
//************************************************
//****************删除操作***********************// L是带头结点的单链表,删除ai，用参数e带回被删结点的值
	int listdelete(Linklist l,int i,elemtype&e)
	{
		Lnode *q,*p;
		p=l->next;
		for(j=1;j<i-1;j++)
			p=p->next;
		q=p->next;
		p->next=q->next;
		e=q->data;
		free(q);
		cout<<"被删除的元素为"<<e<<endl;
		length=listlength(l)-1;
		for(j=0;j<length;j++)
		{
			cout<<l->next->data<<" ";
			l=l->next;
		}
		cout<<endl;
		return 0;
	}
//PPT程序，删除操作
	int ListDelete(Linklist L,int i,elemtype &e)
	{														// L是带头结点的单链表,删除ai，用参数e带回被删结点的值
		Lnode *p,*q;
		p=L; j=0;												//p指向头结点，j是计数器
		while(p && j<i-1){p=p->next; j++;}					//p指向ai-1
		if (!p || j>i-1) return 0;							// i非法
		q=p->next;
		e=q->data;
		p->next=q->next;
		free(q);								//修改指针
		length=listlength(L)-1;
		cout<<"所删除元素为"<<e<<endl;
		cout<<"经删除操作后的链表为"<<endl;
		display(L,length);
		return 1;
	}    
//******************************************************
//*****************逆置单链表***************************
//********注意：逆置单链表的循环过程中，尽量用while()！
//法一：头插法逆置
	void reverselinklist(Linklist &l)               //为何输不出来？？？？
	{
		Lnode *p,*q;
		p=l->next;
		l->next=NULL;
		length=listlength(l);
		for(i=0;i<length;i++)
		{
			q=p->next;
			p->next=l->next;
			l->next=p;
			p=q;
		}
		cout<<"逆置后的单链表为："<<endl;
		display(l,length);
	}
//PPT，法一：头插法逆置
	void ReverseLinkList1(Linklist&L)
	{											// L是带头结点的单链表。用头插法逆置L
		Lnode *p,*q;
		p=L->next;								//p指向a1
		L->next=NULL;							//剥离头结点
		while (p)
		{
			q=p->next ;							//用辅助指针q“拽住”p的后继
			p->next=L->next ;					//将当前待插入链表中的首结点*p插入L中，成为L的首结点
			L->next=p ;
            p=q ;								//p,q后移
		}
		cout<<"逆置后的单链表为："<<endl;
		length=listlength(L);
		display(L,length);
	}
//********法二：将所有节点的next指针逆转*************
	void reverselinklist_next(Linklist&l)
	{
		Lnode *p,*q,*r;
		p=l->next;
		q=p->next;
		p->next=NULL;
		while(q)
		{
			r=q->next;
			q->next=p;
			p=q;
			q=r;
		}
		l->next=p;
		length=listlength(l);
		cout<<"将所有节点的next指针逆转后所得的逆置为："<<endl;
		display(l,length);
	}
//****************************************************
private:
	int i,j;
	int length;
};



int main(int argc, char* argv[])
{	
	operation list;
	Linklist l;
	list.initlist(l);
	//list.input(l);                 //头插
	list.creatlist(l);           //尾插
	int e;
	list.getelem(l,3,e);         //取元素操作
	//cout<<"链表长度为listlength="<<list.listlength(l)<<endl;
	//list.listinsert(l,2,0);      //插入法
	//list.listinsert_ppt(l,2,0);  //插入法_PPT
	//list.listdelete(l,2,e);      //删除元素
	//list.ListDelete(l,2,e);      //删除元素_PPT
	//list.reverselinklist(l);     //by myself 头插法逆置
	//list.ReverseLinkList1(l);    //by PPT    头插法逆置
	//list.reverselinklist_next(l);  //by myself 指针逆转法逆置
	return 0;
}
