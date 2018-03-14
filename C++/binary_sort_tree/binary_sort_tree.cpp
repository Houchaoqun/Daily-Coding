// 侯超群 二叉排序树.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

typedef struct node
{
	int element;
	node *lchild,*rchild;
}node, *nodeptr;

class BST
{
public:
	void insertnode(nodeptr *head,int data);//如果*head为空，申请结点令其左右孩子都为空，即叶子结点。else，按照二叉树的特点插入。
	nodeptr creatTree();//构造二叉排序树，返回值为head，以输入0作为结束标志。
	void printTree(nodeptr head);//中序遍历输出
};

void BST::insertnode(nodeptr *head,int data)
{
	if(!(*head))
	{
		(*head)=new node;
		(*head)->element=data;
		(*head)->lchild=NULL;
		(*head)->rchild=NULL;
	}
	else
		if(data<(*head)->element)
			insertnode(&(*head)->lchild,data);
		else
			insertnode(&(*head)->rchild,data);
}

nodeptr BST::creatTree()
{
	cout<<"请依次输入构造的排序二叉树的键值(注：以输入“0且enter”作为结束)："<<endl;
	nodeptr head=NULL;
	int data;
	cin>>data;
	while(data!=0)
	{
		insertnode(&head,data);
		cin>>data;
	}
	return head;
}

void BST::printTree(nodeptr head)
{
	if(head!=NULL)
	{
		printTree(head->lchild);
		cout<<head->element<<" ";
		printTree(head->rchild);
	}
	return;
}

int main()
{
	BST tree;
	nodeptr head;
	head=tree.creatTree();
	cout<<"排序二叉树经中序遍历后的顺序为："<<endl;
	tree.printTree(head);
	cout<<endl;
	return 0;
}
