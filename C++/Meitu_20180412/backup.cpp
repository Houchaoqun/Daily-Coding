#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NUM 100
int a[MAX_NUM];
int n;

int excute(){
	n = 10;
	for(int i=0; i<n; i++){
		a[i] = n-i;
	}
	
	cout<<"before sorted..."<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	cout<<"after sorted..."<<endl;
	sort(a, a + n);
	
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
} 

int main(){

	excute();
	return 0;
}
