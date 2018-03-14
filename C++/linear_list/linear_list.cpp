// ��ϰ  ���Ա�.cpp : Defines the entry point for the console application.
//
//************���������������Ա�Ķ���*********************
/*
*************���Ա�˳��洢�ṹ��ȱ�㣺
		  �����ɾ������ʱ����Ҫ�����ƶ�Ԫ�ء�
ADT List{
 ���ݶ���D={ai|ai��ElemSet,i=1,2,...,n,n��0}
 ���ݹ�ϵ��R1={<ai-1,ai>|ai-1,ai��D,i=2,...,n}
 ����������
 ******************ͨ�������л����������ϵ��ã���ʵ�ֶ����Ա�ĸ��Ӳ���***************************
 InitList(&L)
  �������������һ���յ����Ա�L
 DestroyList(&L)
  ��ʼ���������Ա�L�Ѵ��ڡ�
  �����������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
 ClearList((&L)
  ��ʼ���������Ա�L�Ѵ��ڡ�
  �����������L����Ϊ�ձ�
 ListEmpty(L)
  ��ʼ���������Ա�L�Ѵ��ڡ�  
  �����������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
 ListLength(L)
  ��ʼ���������Ա�L�Ѵ��ڡ�
  �������������L������Ԫ�ظ���
 GetElem(L,i,&e)
  ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L)��
  �����������e����L�е�i������Ԫ�ص�ֵ
 LocateElem(L,e,compare())
  ��ʼ���������Ա��Ѵ��ڣ�compare()������Ԫ���ж�������
  �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
 PriorElem(L,cur_e,&pre_e)
  ��ʼ���������Ա�L�Ѵ��ڡ�  
  �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
 NextElem(L,cur_e,&next_e)
  ��ʼ���������Ա��Ѵ��ڡ�
  �������:��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
 ListInsert(&L,i,e)
  ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1��
  �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e,L�ĳ��ȼ�1��
 ListDelete(&L,i,&e)
  ��ʼ���������Ա�L�Ѵ����ҷǿգ�1��i��ListLength(L)��
  ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ,L�ĳ��ȼ�1��
 ListTraverse(L,visit())
  ��ʼ���������Ա�L�Ѵ���
  ������������ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�
}ADT List;


*/


#include "stdafx.h"
#include <iostream>
using namespace std;
typedef int elemtype;
#define list_init_size 20
#define listincrement 5
typedef struct
{
	elemtype *elem;        //����ַָ��
	int length;            //���Ա���         ��a1��a2.....an,"length"����n�Ĵ�С��
	int listsize;          //���Ա�Ĵ洢����   �������Ա�ʱ������Ŀռ��С������length�Ĳ�𣿣���
}sqlist;
class operation
{
public:
	void creat_list(sqlist&l,int a[])
	{
		cout<<"�������Ա��ȣ�"<<endl;
		cin>>l.length;
		cout<<"���볤��Ϊ"<<l.length<<"�����Ա��Ԫ��"<<endl;
		for(i=0;i<l.length;i++)
			cin>>a[i];
		l.elem=&a[0];
	}
	void output_list(sqlist&l,int a[])
	{
		//cout<<"������������Ա�Ϊ��"<<endl;
		for(i=0;i<l.length;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
//***********��ʼ����˳���*******************�������������һ���յ����Ա�L
	int initlist_sq(sqlist&l)
	{
		l.elem=new elemtype[list_init_size];
		if(!l.elem) return 0;                      //l.elemΪnull��return overflow ��洢����ʧ��
		l.length=0;
		l.listsize=list_init_size;
		return 1;
	}
//********************************************
//***********����Ԫ�ز�������λ������*********�������������L�е�һ����e�����ϵ��Ԫ��-----ʱ�临�Ӷ�O��n��
	int locateelem(sqlist&l,elemtype e)
	{
		q=l.elem;                                  //��elem���׵�ַ��ֵ��q��
		i=1;
		while(i<=l.length&&*q++!=e)
			i++;
		return i<=l.length?i:e;                    //return�ķ���ֵ����i<=l.length������ʱ�򣬱�ʾwhile�Ľ�������Ϊ�ҵ�*q=e,�����ҵ��˶�λԪ�ء�
	}
//********************************************
//***************����Ԫ����*******************�����������e����L�е�i������Ԫ�ص�ֵ��
	int getelem(sqlist&l,int i,elemtype e)
	{
		q=l.elem;
		if(i<=0||i>l.length)return 0;          //i����ȡС��1�ʹ���l.length���ȵ�����
		e=*(q+i-1);                            //e=l.elem[i-1];
		return e;
	}
//********************************************
//************�������Ա�**********************�����������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
	int destorylist(sqlist&l)
	{
		if(l.length==0)return 0;              //��LΪ�ձ��������
		delete[]l.elem;                       //�ͷ�˳���L��ռ�Ŀռ�
		l.listsize=l.length=0;
		return 0;
	}
//********************************************
//***************�������(ǰ��)***************�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e,L�ĳ��ȼ�1��
	int listinsert_by_me(sqlist&l,int i,elemtype e)
	{
		if(i<1||i>l.length+1)return 0;               //����λ��i����1=<i<=n+1
		if(l.length>=l.listsize)                    //����չ����
		{l.elem=new elemtype[l.listsize+listincrement];}
		q=l.elem;
		for(j=l.length+1;j>=i;j--)
		{
			*(q+j)=*(q+j-1);
		}
		*(q+i-1)=e;
		l.length++;
		return 0;
	}
//************PPT�ϵĳ���(�������)*************
	int listinsert(sqlist&l,int i,elemtype e)
	{
		int *newbase;
		int *p;
		if(i<1||i>l.length+1)return 0;
		if(l.length>=l.listsize)
		{
			int newsize;
			newsize=l.listsize+listincrement;
			newbase=(elemtype*)realloc(l.elem,newsize*sizeof(elemtype));
			if(!newbase) return 0;
			l.elem=newbase;
			l.listsize+=listincrement;
		}
		q=l.elem+i-1;
		for(p=l.elem+l.length-1;p>=q;p--)
			*(p+1)=*p;
		*q=e;   //q=&e;
		l.length++;
		cout<<"���������������Ա�Ϊ��"<<endl;
		return 1;
	}
//*********************************************
//*********************************�����������

//**************ɾ������***********************���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ,L�ĳ��ȼ�1��
//******ɾ�������󣬱��뱣֤ɾ�����߼������ڵ�Ԫ��������Ҳ����..
//************ɾ�������㷨*********************
//1.������λ�� i �Ƿ�Ϸ���1��i��n��n��ɾ��λ�ã�n=l.length
//2.��ai+1��an�������һλ //������an��ai+1;
//3.�޸ı���L.length--
	int deletelist(sqlist&l,int i,elemtype e)
	{
		if(i<1||i>l.length)return 0;
		q=l.elem;
		e=*(q+i-1);
		for(j=i;j<=l.length;j++)
			*(q+j-1)=*(q+j);
		l.length--;
		cout<<"��ɾ������������Ա�Ϊ:"<<endl;
		cout<<"��ɾ����elemΪ"<<e<<endl;
		return 0;
	}
//********˳��������Ӧ�þ���*******************
//********����˳���*****************************
//********�㷨*****************
//��ʼʱ�ڱ�ͷ�ͱ�β����һ��ָ��i��j��
//����i��j��ָ��Ԫ�أ�
//i++; j--;
//�ظ�ִ�У�ֱ��i��j������
	void invertlist_by_me(sqlist&l,int a[])
	{
		//*******ʧ��Ʒ*************
		/*int *temp;
		i=1;
		j=l.length;
		//l.elem=&a[0];
		q=&a[0];
		//p=l.elem+j-1;
		p=&a[l.length-1];
		while(i<j)
		{
			temp=q;
			q=p;
			p=temp;
			q=&a[i];
			i++;
			j--;
			p=&a[j-1];
		}
		for(i=0;i<l.length;i++)
			cout<<a[i]<<" ";
		cout<<endl;*/
		//***********�ɹ�Ʒ��myself��*************
		int temp;
		i=0,j=l.length-1;
		while(i<j)
		{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			i++;
			j--;
		}
		cout<<"���ú��˳���Ϊ��"<<endl;
		for(i=0;i<l.length;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
//*************PPT****************
	void invert(elemtype *e,int s,int t)
	{
		while(s<t)
		{
			temp=e[s];
			e[s]=e[t];
			e[t]=temp;
			s++;
			t--;
		}
	}
	void invertsqlist(sqlist&l)
	{
		invert(l.elem,0,l.length-1);
	}
//********************************
//***********ʵ��ǰm��Ԫ�����n��Ԫ�ػ���**********m+n=l.length��
	int exchange(sqlist&l,int m,int n)
	{
		invert(l.elem,0,m-1);
		invert(l.elem,m,l.length-1);
		invert(l.elem,0,m+n-1);
		return 0;
	}
//*********************************************�ɹ���
//****************��˳���ʵ��purge****************
	void purge(sqlist&A,sqlist&B)
	{
		initlist_sq(A);
		initlist_sq(B);
		creat_list(B,a);
		int e;
		A.elem[0]=B.elem[0];                     //��B�е���Ԫ�ظ�ֵ��A�е���Ԫ��
		A.length=1;                              //��A�����Ա���Ϊ1
		for(i=1;j<B.length;i++)                  //i=1����B�еĵڶ���Ԫ�ؿ�ʼ�ֱ���A�����е�Ԫ�رȽϣ���������ͬ�������A.elem[A.length++]
		{
			j=0;
			e=B.elem[i];
			while(j<A.length&&A.elem[j]!=e)      //B.elem[i]����A���Ҳ�����j<A�����Ա��ȣ���j++
				j++;
			if(j==A.length)						 //j==A.length����������ǰ��e����������A��
				A.elem[A.length++]=e;
		}
		delete[]B.elem;
		B.length=B.listsize=0;
	}
	
private:
	int i,j,temp;
	int *q,*p;
	int a[100];
};
int main(int argc, char* argv[])
{
	operation list;
	sqlist l;  //A
	sqlist L;  //B
	int a[100];
	list.purge(l,L);
	//list.initlist_sq(l);
	//list.creat_list(l,a);
	//list.exchange(l,3,l.length-3);
	//list.invertlist_by_me(l,a);
	//**************************
	//list.listinsert_by_me(l,3,0);
	list.output_list(l,a);
	//**************************
	//int e=0;
	//list.deletelist(l,2,e);
	//list.output_list(l,a);
	return 0;
}
