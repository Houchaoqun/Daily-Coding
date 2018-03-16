#include <iostream>  
#include <algorithm>  
#include <numeric>  //数值算法
#include <vector>
#include <math.h>
using namespace std;  

int main()  
{  
    int ia[]={10,0,1,2,3,4,5,6};  
    int *i= find(ia,ia+7,9);//在整个数组中查找元素 9   
    int *j= find(ia,ia+7,3);//在整个数组中查找元素 3  
    int *end=ia+7;//数组最后位置
    if(i == end)
       cout<<"没有找到元素 9"<<endl;  
    else   
       cout<<"找到元素9"<<endl;  
         
    vector<int> iv(ia, ia+5);
	cout<<accumulate(iv.begin(),iv.end(),0)<<endl; //累加  初值为0  
	cout<<inner_product(iv.begin(),iv.end(),iv.begin(),10)<<endl;//两个数组内积  初值为10  
	cout<<pow(10,3)<<endl; // 平方
	
	sort(ia, ia+8);
	for(int i=0;i<8;i++)
 		cout<<ia[i]<<endl;
 		
 	string str("cvicses");
    string s(str.rbegin(),str.rend());
    cout << s <<endl;	
 	
    return 0;
}

