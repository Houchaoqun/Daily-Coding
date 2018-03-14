// 两序列的最长公共子序列.cpp : 定义控制台应用程序的入口点。
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

	cout<<"读取的内容如下："<<endl;
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

	//利用递推公式获得矩阵的过程
	for (int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if (i==0||j==0)    //----》递推公式第一步
			{
				c[i][j]=0;
			}
			if (i>0&&j>0&&x[i-1]==y[j-1])   //-----》递推公式第二步
			{
				c[i][j]=c[i-1][j-1]+1;
			}
			if (i>0&&j>0&&x[i-1]!=y[j-1])	//-----》递推公式第三步
			{
				c[i][j]=max(c[i][j-1],c[i-1][j]);
			}
		}
	}

	cout<<"利用递推公式得到的矩阵如下："<<endl;
	for (int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}

	//获得最大公共子序列的过程和长度
	int k=c[n][m];
	int length=c[n][m];
	char *s=new char[m];
	while(k>0)
	{

		// n<----->i----->x[]
		// m<----->j----->y[]
		if (c[n][m]==c[n-1][m])//该位置的数等于上一行同一列的数的情况
		{
			n--;    //往上一行移动
		}
		else if (c[n][m]==c[n][m-1])
		{
			m--;    //往左一列移动
		}
		else   //当且仅当该位置的左和上方向的数字都与该位置不一样的情况：就是有递推公式第二步得到的----》i,j>0 and xi==yj
		{
			s[--k]=x[n-1];    //  n《----》i
			n--;	//沿该位置的对角线移动
			m--;
		}
		

	}

	cout<<"最长公共子序列为：";
	for (int i=0;i<length;i++)
	{
		cout<<s[i];
	}
	cout<<"  对应的长度为："<<length<<endl;

	system("pause");
	return 0;
}

