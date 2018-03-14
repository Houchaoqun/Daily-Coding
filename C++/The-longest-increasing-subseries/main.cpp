#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
//ת����LCS���⣬ʱ�临�Ӷ�O(n*n)
int d[105][105];
int a[105];
int b[105];
int c[105][105];

void LCS_path(int i,int j)   //��ӡ·��
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

// ����һ������ΪN�����飬�ҳ�һ����ĵ������������У���һ������������˳�����ң���
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

