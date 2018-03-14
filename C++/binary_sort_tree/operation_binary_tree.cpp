// Ҷ�ӽ�����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct bitree
{
	char data;
	struct bitree *lchild,*rchild;
}bitree;
class tree
{
public:
//�������������������������
void creat_tree(bitree*&bt)
{
	char ch;
	ch=getchar();
	if(ch==' ')bt=NULL;
	else
	{
		bt=new bitree;
		bt->data=ch;
		creat_tree(bt->lchild);
		creat_tree(bt->rchild);
	}
}
//����Ҷ�ӽ������//�������
int countleaf(bitree*bt,int&count)
{
	if(bt)
	{
		if((!bt->lchild)&&(!bt->rchild))
			count++;
		else
		{
			countleaf(bt->lchild,count);
			countleaf(bt->rchild,count);
		}
	}
	return count;
}
//����������ȡ��������
int depth(bitree*bt)
{
	if(!bt)depthval=0;
	else
	{
		depthleft=depth(bt->lchild);
		depthright=depth(bt->rchild);
		depthval=1+(depthleft>depthright?depthleft:depthright);
	}
	return depthval;                                 //return���������ã�
}
//����һ���������Ľ�㡣
/*bitree *gettreenode(char item,bitree *lptr,bitree *rptr)
{
	t=new bitree;
	t->data=item;
	t->lchild=lptr;
	t->rchild=rptr;
	return t;
}
//��ֵ���������������
bitree *copytree(bitree *t)
{
	if(!t)return NULL;
	if(t->lchild)
		newlptr=copytree(t->lchild);
	else newlptr=NULL;
	if(t->rchild)
		newrptr=copytree(t->rchild);
	else newrptr=NULL;
	newT=gettreenode(t->data,newlptr,newrptr);
	return newT;
}*/
private:
	int depthleft,depthright,depthval;
	bitree *newlptr,*newrptr;
	bitree *newT;
};
int main(int argc, char* argv[])
{
	int count=0;						//���ò����Ĵ��ݵ�ʱ��ע�⸳��ֵ����������
	bitree *bt;
	tree t;
	t.creat_tree(bt);
	cout<<"������Ҷ�ӽ����Ϊ"<<t.countleaf(bt,count)<<endl;
	cout<<"���������Ϊ"<<t.depth(bt)<<endl;
	//cout<<"��õ��µĽ��Ϊ��"<<t.gettreenode(ch,bt->lchild,bt->rchild)<<endl;
	//cout<<"���Ƶ�����Ϊ��"<<t.copytree(bt)<<endl;
	return 0;
}
