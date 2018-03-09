#include <iostream>
#include <fstream>
using namespace std;

#define MAX_LEN 1000
int _array[MAX_LEN] = {0};
int n;

void input(){
	fstream in_data;
	in_data.open("data.txt");
	in_data >> n;
	for(int i = 0; i<n;i++){
		in_data >> _array[i];
	}
}

void print_data(){
	for(int i = 0; i < n; i++){
		cout<<_array[i]<<" ";
	}
	cout<<endl;
}



int main(){
	input();
	print_data();
	
	return 0;
}




