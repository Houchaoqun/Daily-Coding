#include<iostream>  
#include<algorithm>  
#include<cstdio>  
using namespace std;  
const int INF=1e9;  
int d[105];  
int a[105];  
int g[105];  

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
        
        int ans=0;  
        for(i=1;i<=n;i++){
        	g[i]=INF; //��ʼ��g[i]  
		}
			
        for(i=0;i<n;i++)  
        {  
            int k=lower_bound(g+1,g+1+n,a[i])-g;  
            d[i]=k;  
            g[k]=a[i];        //����g[k],ʹg���鱣����С��������(��1~n��Ԫ�ؾ�Ϊ��ǰ��ȡ��Сֵ),���ᶪʧ���Ž�  
            ans=max(d[i],ans);  
        }  
        cout<<ans<<endl;  
    }  
    fclose(stdin);  
    return 0;  
}  
