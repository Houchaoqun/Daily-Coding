#include <iostream>
#include <fstream>
using namespace std;

#define MAX_LEN 1000
int _array[MAX_LEN] = {0};
int n;

void input(){
//	fstream in_data;
//	in_data.open("data.txt");
//	in_data >> n;
//	for(int i = 0; i<n;i++){
//		in_data >> _array[i];
//	}

	cin >> n;
	for(int i = 0; i<n; i++){
		cin>>_array[i];
	}
}
//
//void print_data(){
//	for(int i = 0; i < n; i++){
//		cout<<_array[i]<<" ";
//	}
//	cout<<endl;
//}

int _calculate(int a, int b){
	int cal = a - b;
	if(cal>0){
		return cal;
	}else{
		return -cal;
	}
}

int find_min(){
	int result = 10001;
	int cal;
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			cal = _calculate(_array[i], _array[j]);
			if(result>cal){
				result = cal;
			}
		}
	}
	
	return result;
}



int main(){
	input();
	// print_data();
	cout<<find_min()<<endl;
	return 0;
}




