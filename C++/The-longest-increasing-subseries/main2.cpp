#include<iostream>  
#include<algorithm>  
#include<cstdio>  
using namespace std;  
  
int d[105];  
int a[105];  
  
# ����һ������ΪN�����飬�ҳ�һ����ĵ������������У���һ������������˳�����ң���
# 
int main()  
{  
    int i,j,n,m;  
    freopen("./test.txt","r",stdin);
    cin>>m;  
    while(m--)  
    {  
        cin>>n;  
        for(i=0; i<n; i++)  
        {  
            cin>>a[i];  
        }  
        d[0]=1;  
        int ans=0;  
        for(i=1;i<n;i++)  
        {  
            int Max=0;  
            for(j=i-1;j>=0;j--)  
            {  
                if(a[i]>a[j])  
                {  
                    if(Max<d[j]) Max=d[j];  
                }  
            }  
            d[i]=Max+1;  
            ans=max(ans,d[i]);  
        }  
        cout<<ans<<endl;  
    }  
    fclose(stdin);  
    return 0;  
}  
