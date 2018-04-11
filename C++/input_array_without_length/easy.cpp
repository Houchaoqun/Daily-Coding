// 9
// 8 3 6 9 9 9 0 0 1
//  

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAX_NUM 1000
int num;
int a[MAX_NUM];


void display(){
	cout<<"===== result info ====="<<endl;
	cout<<num<<endl;
	for(int i=0; i<num; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void input_cin(){
	
	cin >> num;
	for(int i=0; i<num; i++)
    {
        cin>>a[i];
    }
    
}

void input_ifstream(){
	ifstream in_data;
	in_data.open("./easy.txt");
	in_data >> num;
	for(int i=0; i<num; i++)
    {
        in_data >> a[i];
    }
}

int main(){
	
//	input_cin();
	input_ifstream();
	display();
	return 0;
}
