// 复习  线性表.cpp : Defines the entry point for the console application.
//
//************抽象数据类型线性表的定义*********************
/*
*************线性表顺序存储结构的缺点：
		  插入或删除操作时，需要大量移动元素。
ADT List{
 数据对象：D={ai|ai∈ElemSet,i=1,2,...,n,n≥0}
 数据关系：R1={<ai-1,ai>|ai-1,ai∈D,i=2,...,n}
 基本操作：
 ******************通过对下列基本运算的组合调用，可实现对线性表的复杂操作***************************
 InitList(&L)
  操作结果：构造一个空的线性表L
 DestroyList(&L)
  初始条件：线性表L已存在。
  操作结果：若L为空表，则返回TRUE,否则返回FALSE。
 ClearList((&L)
  初始条件：线性表L已存在。
  操作结果：将L重置为空表。
 ListEmpty(L)
  初始条件：线性表L已存在。  
  操作结果：若L为空表，则返回TRUE,否则返回FALSE。
 ListLength(L)
  初始条件：线性表L已存在。
  操作结果：返回L中数据元素个数
 GetElem(L,i,&e)
  初始条件：线性表L已存在，1≤i≤ListLength(L)。
  操作结果：用e返回L中第i个数据元素的值
 LocateElem(L,e,compare())
  初始条件：线性表已存在，compare()是数据元素判定函数。
  操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。
 PriorElem(L,cur_e,&pre_e)
  初始条件：线性表L已存在。  
  操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
 NextElem(L,cur_e,&next_e)
  初始条件：线性表已存在。
  操作结果:若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。
 ListInsert(&L,i,e)
  初始条件：线性表L已存在，1≤i≤ListLength(L)+1。
  操作结果：在L中第i个位置之前插入新的数据元素e,L的长度加1。
 ListDelete(&L,i,&e)
  初始条件：线性表L已存在且非空，1≤i≤ListLength(L)。
  操作结果：删除L的第i个数据元素，并用e返回其值,L的长度减1。
 ListTraverse(L,visit())
  初始条件：线性表L已存在
  操作结果：依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败。
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
	elemtype *elem;        //基地址指针
	int length;            //线性表长度         有a1，a2.....an,"length"代表n的大小。
	int listsize;          //线性表的存储容量   构造线性表时所申请的空间大小！！与length的差别？？？
}sqlist;
class operation
{
public:
	void creat_list(sqlist&l,int a[])
	{
		cout<<"输入线性表长度："<<endl;
		cin>>l.length;
		cout<<"输入长度为"<<l.length<<"的线性表的元素"<<endl;
		for(i=0;i<l.length;i++)
			cin>>a[i];
		l.elem=&a[0];
	}
	void output_list(sqlist&l,int a[])
	{
		//cout<<"经操作后的线性表为："<<endl;
		for(i=0;i<l.length;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
//***********初始化空顺序表*******************操作结果：构造一个空的线性表L
	int initlist_sq(sqlist&l)
	{
		l.elem=new elemtype[list_init_size];
		if(!l.elem) return 0;                      //l.elem为null，return overflow 则存储分配失败
		l.length=0;
		l.listsize=list_init_size;
		return 1;
	}
//********************************************
//***********查找元素操作（定位函数）*********操作结果：返回L中第一个与e满足关系的元素-----时间复杂度O（n）
	int locateelem(sqlist&l,elemtype e)
	{
		q=l.elem;                                  //把elem的首地址赋值给q。
		i=1;
		while(i<=l.length&&*q++!=e)
			i++;
		return i<=l.length?i:e;                    //return的返回值，当i<=l.length成立的时候，表示while的结束是因为找到*q=e,即，找到了定位元素。
	}
//********************************************
//***************读表元操作*******************操作结果：用e返回L中第i个数据元素的值。
	int getelem(sqlist&l,int i,elemtype e)
	{
		q=l.elem;
		if(i<=0||i>l.length)return 0;          //i不能取小于1和大于l.length长度的数。
		e=*(q+i-1);                            //e=l.elem[i-1];
		return e;
	}
//********************************************
//************销毁线性表**********************操作结果：若L为空表，则返回TRUE,否则返回FALSE。
	int destorylist(sqlist&l)
	{
		if(l.length==0)return 0;              //若L为空表，则结束。
		delete[]l.elem;                       //释放顺序表L所占的空间
		l.listsize=l.length=0;
		return 0;
	}
//********************************************
//***************插入操作(前插)***************操作结果：在L中第i个位置之前插入新的数据元素e,L的长度加1。
	int listinsert_by_me(sqlist&l,int i,elemtype e)
	{
		if(i<1||i>l.length+1)return 0;               //插入位置i有误，1=<i<=n+1
		if(l.length>=l.listsize)                    //需扩展数组
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
//************PPT上的程序(插入操作)*************
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
		cout<<"经插入操作后的线性表为："<<endl;
		return 1;
	}
//*********************************************
//*********************************插入操作结束

//**************删除操作***********************操作结果：删除L的第i个数据元素，并用e返回其值,L的长度减1。
//******删除操作后，必须保证删除后逻辑上相邻的元素物理上也相邻..
//************删除操作算法*********************
//1.检查插入位置 i 是否合法，1≤i≤n，n个删除位置；n=l.length
//2.将ai+1至an逐个左移一位 //而不是an至ai+1;
//3.修改表长：L.length--
	int deletelist(sqlist&l,int i,elemtype e)
	{
		if(i<1||i>l.length)return 0;
		q=l.elem;
		e=*(q+i-1);
		for(j=i;j<=l.length;j++)
			*(q+j-1)=*(q+j);
		l.length--;
		cout<<"经删除操作后的线性表为:"<<endl;
		cout<<"被删除的elem为"<<e<<endl;
		return 0;
	}
//********顺序表的其他应用举例*******************
//********逆置顺序表*****************************
//********算法*****************
//初始时在表头和表尾各设一个指针i和j；
//互换i、j所指的元素；
//i++; j--;
//重复执行，直至i和j相遇。
	void invertlist_by_me(sqlist&l,int a[])
	{
		//*******失败品*************
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
		//***********成功品（myself）*************
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
		cout<<"逆置后的顺序表为："<<endl;
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
//***********实现前m个元素与后n个元素互换**********m+n=l.length。
	int exchange(sqlist&l,int m,int n)
	{
		invert(l.elem,0,m-1);
		invert(l.elem,m,l.length-1);
		invert(l.elem,0,m+n-1);
		return 0;
	}
//*********************************************成功！
//****************用顺序表实现purge****************
	void purge(sqlist&A,sqlist&B)
	{
		initlist_sq(A);
		initlist_sq(B);
		creat_list(B,a);
		int e;
		A.elem[0]=B.elem[0];                     //将B中的首元素赋值给A中的首元素
		A.length=1;                              //令A的线性表长度为1
		for(i=1;j<B.length;i++)                  //i=1，从B中的第二个元素开始分别于A中已有的元素比较，若都不相同，则插入A.elem[A.length++]
		{
			j=0;
			e=B.elem[i];
			while(j<A.length&&A.elem[j]!=e)      //B.elem[i]都在A中找不到且j<A的线性表长度，则j++
				j++;
			if(j==A.length)						 //j==A.length成立，代表当前的e都不出现在A中
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
