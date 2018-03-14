// ����������.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
class node
{
public:
	char data;
	node *lchild;
	node *rchild;

};

int creat_tree(node *&t)
{
	char ch;
	ch=getchar();
	if(ch==' ')t=NULL;
	else
	{
		t=new node;
		t->data=ch;
		creat_tree(t->lchild);
		creat_tree(t->rchild);
	}
	return 0;
}

//�ݹ����
void xianxu(node *t)
{
	if(t==NULL)return;
	else
	{
		cout<<t->data;
	xianxu(t->lchild);
	xianxu(t->rchild);
	}
}

void zx(node *t)
{
	if(t==NULL)return;
	else
	{
		zx(t->lchild);
		cout<<t->data;
		zx(t->rchild);
	}
}

void hx(node *t)
{
	if(t==NULL)return;
	else
	{
		hx(t->lchild);
		hx(t->rchild);
		cout<<t->data;
	}
}

//�ǵݹ����
class feidigui
{
public:
	void xx(node *t)
	{
		i=0;
		p=t;
		while((p!=NULL)||(i>0))
		{
			while(p!=NULL)
			{
				cout<<p->data;
				s[++i]=p;
				p=p->lchild;
			}
			p=s[i--];
			p=p->rchild;
		}
	}
	void zx(node *t)
	{
		i=0;
		p=t;
		do{
			while(p!=NULL)
			{
				i=i+1;
				s[i]=p;
				p=p->lchild;
			}
			if(i>0)
			{
				p=s[i];
				i=i-1;
				cout<<p->data;
				p=p->rchild;
			}
		}while((p!=NULL)||(i!=0));
	}
	
	void hx(node *t)
	{
		int a[100],b;
		i=0;
		p=t;
		do{
			while(p!=NULL)
			{
				s[i]=p;
				a[i++]=0;
				p=p->lchild;
			}
			if(i>0)
			{
				b=a[--i];
				p=s[i];
				if(b==0)
				{
					s[i]=p;
					a[i++]=1;
					p=p->rchild;
				}
				else
				{
					cout<<p->data;
					p=NULL;
				}
			}
		}while(p!=NULL||i>0);
	}
private:
	node *p;
	node *s[100];
	int i;
};

int main()
{
	node *n;
	creat_tree(n);
	cout<<"����ݹ����Ϊ��  ";
	xianxu(n);
	cout<<endl<<"����ݹ����Ϊ��  ";
	zx(n);
	cout<<endl<<"����ݹ����Ϊ��  ";
	hx(n);
	cout<<endl<<"�ǵݹ��������Ϊ��";
	feidigui fd;
	fd.xx(n);
	cout<<endl<<"�ǵݹ��������Ϊ��";
	fd.zx(n);
	cout<<endl<<"�ǵݹ�������Ϊ��";
	fd.hx(n);
	cout<<endl;
	return 0;
}
