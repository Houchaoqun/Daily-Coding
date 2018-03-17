#include <iostream>
#include <fstream>

using namespace std;
 
#define MAX_N 1001
int a[MAX_N];
int n;
int result;
int num_result = 0;
 
void input(){
//	ifstream in_data;
//	in_data.open("./data.txt");
//	in_data >> n;
//	for(int i=0; i<n; i++){
//		in_data >> a[i];
//	}

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
} 

void display(){
	for(int i=0; i<n; i++){
		cout << a[i]<<" ";
	}
	cout<<endl;
}

int find_zws(){
	
	int num_big, num_small;
	result = -1;
	for(int i=0; i<n; i++){
		num_big = 0;
		num_small = 0;
		for(int j=0; j<n; j++){
			if(a[i]>a[j]){
				num_big++;
			}else if(a[i]<a[j]){
				num_small++;
			}
		}
		
		if(num_big == num_small){
			result = a[i];
			break;
		}
	}
	
	return result;
	
}

int main(){
	
	input();
//	display();
	cout<<find_zws()<<endl;
	
	return 0;
}
