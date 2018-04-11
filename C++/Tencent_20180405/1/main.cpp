#include <iostream>
#include <fstream>
using namespace std;
 
#define MAX_NUM 1000
int num;
int a[MAX_NUM];

void input_cin(){
	
	cin >> num;
	for(int i=0; i<num; i++)
    {
        cin>>a[i];
    }
    
}

void input_ifstream(){
	ifstream in_data;
	in_data.open("./data.txt");
	in_data >> num;
	for(int i=0; i<num; i++)
    {
        in_data >> a[i];
    }
}

void display(){
	cout<<"===== result info ====="<<endl;
	cout<<num<<endl;
	for(int i=0; i<num; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	
//	input_cin();
	input_ifstream();
	display();
	return 0;
}
