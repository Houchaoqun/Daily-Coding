#include<iostream> 
using namespace std;

int main() 
{ 
	int year;
	bool case1, case2;
	while(cin>>year) 
	{
		case1 = (year%4==0 && year%100!=0);
		case2 = (year%400==0);
		if(case1 || case2) 
			cout<<year<<" is leap year."<<endl; 
		else 
			cout<<year<<" is not leap year."<<endl;
		cout<<"========"<<endl;
	}
	
	return 0; 
}
