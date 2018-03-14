// �Ⱥ ����������.cpp : Defines the entry point for the console application.
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
	void insertnode(nodeptr *head,int data);//���*headΪ�գ��������������Һ��Ӷ�Ϊ�գ���Ҷ�ӽ�㡣else�����ն��������ص���롣
	nodeptr creatTree();//�������������������ֵΪhead��������0��Ϊ������־��
	void printTree(nodeptr head);//����������
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
	cout<<"���������빹�������������ļ�ֵ(ע�������롰0��enter����Ϊ����)��"<<endl;
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
	cout<<"���������������������˳��Ϊ��"<<endl;
	tree.printTree(head);
	cout<<endl;
	return 0;
}
