// ��ϰ  ���Ա�  ��ʽ��ʾ.cpp : Defines the entry point for the console application.



//���Ա�˳��洢�ṹ���ŵ㣺
//1.�߼���ϵ�����ڵ�����Ԫ��������λ����Ҳ���ڣ�
//2.���������ȡ˳����е���һԪ�أ�Ԫ�صĴ洢λ�ÿ��ɹ�ʽ������á�


#include "stdafx.h"
#include <iostream>

using namespace std;
typedef int elemtype;

typedef struct Lnode
{
	elemtype	data ;
	struct Lnode	*next ;
} Lnode, *Linklist;             //LNode�����ṹ�������������������еĽ������
								//LinkList�����ṹ��ָ��������������˵�����������͵ı���
class operation
{
public:
//************display*********************** ���������������
	void display(Linklist&l,int length)
	{
		Lnode *p;
		p=l->next;
		j=0; 
		while(p&&j<length)                  // ��������attention
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
//******************************************
//************��ʼ��������****************** 
	int initlist(Linklist&l)				//1.����ռ�
	{										//2.��lΪ�ձ������
		l=new Lnode;						 //3.��l��nextָ��NULL��������һ��������
		if(!l)return 0;
		l->next=NULL;
		return 1;
	}
//******************************************
//************����һ���ǿ�����**************
//***************ͷ�巨*********************
	void input(Linklist&l)           //nΪ����ĳ���
	{
		int n;
		cout<<"������������n=";
		cin>>n;
		l=new Lnode;
		l->next=NULL;
		Lnode *p;	
		cout<<"������������������ݣ�"<<endl;
		for(i=0;i<n;i++)
		{
			p=new Lnode;
			cin>>p->data;
			p->next=l->next;              //��ȥ����䣬����ֻ������һ�������ҵ���ʧ�ܡ� ��p��L��������������
			l->next=p;					  //��������
		}
		cout<<"�û������õ�����Ϊ��"<<endl;
		for(i=0;i<n;i++)                  //���Ԫ��������Ԫ���෴
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
//*************β�巨***********************
	void creatlist(Linklist&l)
	{
		Lnode *p;
		Lnode *s;
		l=new Lnode;
		l->next=NULL;
		p=l;
		int n;
		cout<<"����������ĳ���n=";
		cin>>n;
		cout<<"�����볤��Ϊ"<<n<<"������Ԫ�أ�"<<endl;
		for(i=0;i<n;i++)
		{
			s=new Lnode;
			cin>>s->data;
			p->next=s->next;  //����s->next=p->next!!           //�������ֶ��С� s->next=null;
			//s->next=NULL;
			p->next=s;
			p=s;
			//delete s;         //������������������У��еĻ��ͳ����ڴ���󣡣�
		}
		//delete p;                        //����ԭ����delete s��p�����߾������ڴ˴�delete������������
		cout<<"�û������õ�����Ϊ��"<<endl;
		for(i=0;i<n;i++)                  //���Ԫ��������Ԫ����ͬ
		{
			cout<<l->next->data<<" ";        //ע����������ʱ��s��p�Ѿ��ǲ����ڵ��ˣ�Ӧ��lȥ�������
			l=l->next;
		}
		cout<<endl;
		delete s,p;
	}
//*************����Ԫ����******************* ��δ�ɹ�����������
	int getelem(Linklist l,int i,elemtype&e) //L�Ǵ�ͷ���ĵ�������L�ĵ�i��Ԫ�أ���e������ֵ
	{	
		Lnode *p;
		//p=new Lnode;
		p=l->next;
		for(j=1;j<i;j++)
			p=p->next;
		e=p->data;
		cout<<"L�ĵ�i��Ԫ��Ϊ"<<e<<endl;
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
//***********���*****************
	int listlength(Linklist l)     // L�Ǵ�ͷ���ĵ�����
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
//***********�������****************
	int listinsert(Linklist&l,int i,elemtype e)   // L�Ǵ�ͷ���ĵ�����,��ai֮ǰ�����½��e
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
		cout<<"����������Ϊ��"<<endl;
		display(l,length);
		delete p;
		return 0;
	}
//PPT����:���뷨
	int listinsert_ppt(Linklist&l,int i,elemtype e)
	{
		Lnode *p,*s;
		p=l; j=0;										//pָ��ͷ��㣬j�Ǽ�����
		while(p && j<i-1){ p=p->next; j++; }			//��ָ��ai-1��p
		if (!p || j>i-1) return 0;						//i�Ƿ�,i���ڱ���i<1
		s=(Lnode*)malloc(sizeof(Lnode));
		s->data=e;   
		s->next=p->next;  p->next=s;					//�޸�ָ��
		int length;
		length=listlength(l);
		cout<<"����������Ϊ��"<<endl;
		p=l->next;
		for(j=0;j<length+1;j++)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		return 1;

	}
//************************************************
//****************ɾ������***********************// L�Ǵ�ͷ���ĵ�����,ɾ��ai���ò���e���ر�ɾ����ֵ
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
		cout<<"��ɾ����Ԫ��Ϊ"<<e<<endl;
		length=listlength(l)-1;
		for(j=0;j<length;j++)
		{
			cout<<l->next->data<<" ";
			l=l->next;
		}
		cout<<endl;
		return 0;
	}
//PPT����ɾ������
	int ListDelete(Linklist L,int i,elemtype &e)
	{														// L�Ǵ�ͷ���ĵ�����,ɾ��ai���ò���e���ر�ɾ����ֵ
		Lnode *p,*q;
		p=L; j=0;												//pָ��ͷ��㣬j�Ǽ�����
		while(p && j<i-1){p=p->next; j++;}					//pָ��ai-1
		if (!p || j>i-1) return 0;							// i�Ƿ�
		q=p->next;
		e=q->data;
		p->next=q->next;
		free(q);								//�޸�ָ��
		length=listlength(L)-1;
		cout<<"��ɾ��Ԫ��Ϊ"<<e<<endl;
		cout<<"��ɾ�������������Ϊ"<<endl;
		display(L,length);
		return 1;
	}    
//******************************************************
//*****************���õ�����***************************
//********ע�⣺���õ������ѭ�������У�������while()��
//��һ��ͷ�巨����
	void reverselinklist(Linklist &l)               //Ϊ���䲻������������
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
		cout<<"���ú�ĵ�����Ϊ��"<<endl;
		display(l,length);
	}
//PPT����һ��ͷ�巨����
	void ReverseLinkList1(Linklist&L)
	{											// L�Ǵ�ͷ���ĵ�������ͷ�巨����L
		Lnode *p,*q;
		p=L->next;								//pָ��a1
		L->next=NULL;							//����ͷ���
		while (p)
		{
			q=p->next ;							//�ø���ָ��q��קס��p�ĺ��
			p->next=L->next ;					//����ǰ�����������е��׽��*p����L�У���ΪL���׽��
			L->next=p ;
            p=q ;								//p,q����
		}
		cout<<"���ú�ĵ�����Ϊ��"<<endl;
		length=listlength(L);
		display(L,length);
	}
//********�����������нڵ��nextָ����ת*************
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
		cout<<"�����нڵ��nextָ����ת�����õ�����Ϊ��"<<endl;
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
	//list.input(l);                 //ͷ��
	list.creatlist(l);           //β��
	int e;
	list.getelem(l,3,e);         //ȡԪ�ز���
	//cout<<"������Ϊlistlength="<<list.listlength(l)<<endl;
	//list.listinsert(l,2,0);      //���뷨
	//list.listinsert_ppt(l,2,0);  //���뷨_PPT
	//list.listdelete(l,2,e);      //ɾ��Ԫ��
	//list.ListDelete(l,2,e);      //ɾ��Ԫ��_PPT
	//list.reverselinklist(l);     //by myself ͷ�巨����
	//list.ReverseLinkList1(l);    //by PPT    ͷ�巨����
	//list.reverselinklist_next(l);  //by myself ָ����ת������
	return 0;
}
