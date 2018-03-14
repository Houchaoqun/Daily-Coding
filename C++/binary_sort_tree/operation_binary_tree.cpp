// 叶子结点个数.cpp : Defines the entry point for the console application.
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
//创建树，利用先序遍历创建。
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
//计算叶子结点数。//先序遍历
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
//计算树的深度。后序遍历
int depth(bitree*bt)
{
	if(!bt)depthval=0;
	else
	{
		depthleft=depth(bt->lchild);
		depthright=depth(bt->rchild);
		depthval=1+(depthleft>depthright?depthleft:depthright);
	}
	return depthval;                                 //return参数的作用！
}
//生成一个二叉树的结点。
/*bitree *gettreenode(char item,bitree *lptr,bitree *rptr)
{
	t=new bitree;
	t->data=item;
	t->lchild=lptr;
	t->rchild=rptr;
	return t;
}
//赋值二叉树。后序遍历
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
	int count=0;						//利用参数的传递的时候，注意赋初值，这样赋。
	bitree *bt;
	tree t;
	t.creat_tree(bt);
	cout<<"该树的叶子结点数为"<<t.countleaf(bt,count)<<endl;
	cout<<"该树的深度为"<<t.depth(bt)<<endl;
	//cout<<"获得的新的结点为："<<t.gettreenode(ch,bt->lchild,bt->rchild)<<endl;
	//cout<<"复制的新树为："<<t.copytree(bt)<<endl;
	return 0;
}
