#include <iostream>  
#include <algorithm>  
#include <numeric>  //��ֵ�㷨
#include <vector>
#include <math.h>
using namespace std;  

int main()  
{  
    int ia[]={10,0,1,2,3,4,5,6};  
    int *i= find(ia,ia+7,9);//�����������в���Ԫ�� 9   
    int *j= find(ia,ia+7,3);//�����������в���Ԫ�� 3  
    int *end=ia+7;//�������λ��
    if(i == end)
       cout<<"û���ҵ�Ԫ�� 9"<<endl;  
    else   
       cout<<"�ҵ�Ԫ��9"<<endl;  
         
    vector<int> iv(ia, ia+5);
	cout<<accumulate(iv.begin(),iv.end(),0)<<endl; //�ۼ�  ��ֵΪ0  
	cout<<inner_product(iv.begin(),iv.end(),iv.begin(),10)<<endl;//���������ڻ�  ��ֵΪ10  
	cout<<pow(10,3)<<endl; // ƽ��
	
	sort(ia, ia+8);
	for(int i=0;i<8;i++)
 		cout<<ia[i]<<endl;
 		
 	string str("cvicses");
    string s(str.rbegin(),str.rend());
    cout << s <<endl;	
 	
    return 0;
}

