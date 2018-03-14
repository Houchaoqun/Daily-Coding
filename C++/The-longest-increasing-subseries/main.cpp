#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
//转化成LCS问题，时间复杂度O(n*n)
int d[105][105];
int a[105];
int b[105];
int c[105][105];

void LCS_path(int i,int j)   //打印路径
{
    if(i==0||j==0) return;
    if(c[i][j]==1)
    {
        LCS_path(i-1,j-1);
        cout<<a[i]<<" ";  //a[i]==b[j]

    }
    else if(c[i][j]==2)
    {
        LCS_path(i-1,j);
    }
    else
    {
        LCS_path(i,j-1);
    }
}

// 给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但是顺序不能乱）。
// 
int main()
{
    int i,j,n,m;
    freopen("./test.txt","r",stdin);
    cin>>m;
    while(m--)
    {
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(a[i]==b[j])
                {
                    d[i][j]=1+d[i-1][j-1];
                    c[i][j]=1;
                }
                else if(d[i-1][j]>d[i][j-1])
                {
                    d[i][j]=d[i-1][j];
                    c[i][j]=2;
                }
                else
                {
                    d[i][j]=d[i][j-1];
                    c[i][j]=3;
                }
            }
        }
        LCS_path(n,n);
        cout<<endl;
        cout<<d[n][n]<<endl;
    }
    fclose(stdin);
    return 0;
}

