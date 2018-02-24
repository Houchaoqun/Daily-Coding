#include<iostream>  
#include<algorithm>  
#include<cstdio>  
using namespace std;  
const int INF=1e9;  
int d[105];  
int a[105];  
int g[105];  

# 给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但是顺序不能乱）。
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
        	g[i]=INF; //初始化g[i]  
		}
			
        for(i=0;i<n;i++)  
        {  
            int k=lower_bound(g+1,g+1+n,a[i])-g;  
            d[i]=k;  
            g[k]=a[i];        //更新g[k],使g数组保持最小递增序列(第1~n个元素均为当前可取最小值),不会丢失最优解  
            ans=max(d[i],ans);  
        }  
        cout<<ans<<endl;  
    }  
    fclose(stdin);  
    return 0;  
}  
