// �����е������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <fstream>
using namespace std;

#define  MAXNUM 20
void getSource(int &n,char x[],int &m,char y[])
{
	ifstream readChar;
	readChar.open("./source2.txt");
	
	readChar>>n;
	for (int i=0;i<n;i++)
	{
		readChar>>x[i];
	}

	readChar>>m;
	for (int i=0;i<m;i++)
	{
		readChar>>y[i];
	}

	cout<<"��ȡ���������£�"<<endl;
	for (int i=0;i<n;i++)
	{
		cout<<x[i];
	}
	cout<<endl;
	for (int i=0;i<m;i++)
	{
		cout<<y[i];
	}
	cout<<endl;
}

int max(int c1,int c2)
{
	if (c1>c2)
	{
		return c1;
	}
	else
		return c2;
}

int main()
{
	int n=0,m=0;
	char *x=new char[n];
	char *y=new char[m];
	getSource(n,x,m,y);

	int c[MAXNUM][MAXNUM];

	//���õ��ƹ�ʽ��þ���Ĺ���
	for (int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if (i==0||j==0)    //----�����ƹ�ʽ��һ��
			{
				c[i][j]=0;
			}
			if (i>0&&j>0&&x[i-1]==y[j-1])   //-----�����ƹ�ʽ�ڶ���
			{
				c[i][j]=c[i-1][j-1]+1;
			}
			if (i>0&&j>0&&x[i-1]!=y[j-1])	//-----�����ƹ�ʽ������
			{
				c[i][j]=max(c[i][j-1],c[i-1][j]);
			}
		}
	}

	cout<<"���õ��ƹ�ʽ�õ��ľ������£�"<<endl;
	for (int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}

	//�����󹫹������еĹ��̺ͳ���
	int k=c[n][m];
	int length=c[n][m];
	char *s=new char[m];
	while(k>0)
	{

		// n<----->i----->x[]
		// m<----->j----->y[]
		if (c[n][m]==c[n-1][m])//��λ�õ���������һ��ͬһ�е��������
		{
			n--;    //����һ���ƶ�
		}
		else if (c[n][m]==c[n][m-1])
		{
			m--;    //����һ���ƶ�
		}
		else   //���ҽ�����λ�õ�����Ϸ�������ֶ����λ�ò�һ��������������е��ƹ�ʽ�ڶ����õ���----��i,j>0 and xi==yj
		{
			s[--k]=x[n-1];    //  n��----��i
			n--;	//�ظ�λ�õĶԽ����ƶ�
			m--;
		}
		

	}

	cout<<"�����������Ϊ��";
	for (int i=0;i<length;i++)
	{
		cout<<s[i];
	}
	cout<<"  ��Ӧ�ĳ���Ϊ��"<<length<<endl;

	system("pause");
	return 0;
}

