#include <iostream>
#include <fstream>
using namespace std;

#define MOD 1000000007
#define MAX_NUM 102
struct jnb{
	int money;
	bool is_used;
};
int a[MAX_NUM];
jnb b[MAX_NUM];
int combine[2*MAX_NUM][2*MAX_NUM];  // 使用 第 1,2,...i 种面值的硬币时，需要找金额为 j 的钱
int n1, n2, m;


void input(){
	
//	cin>>n1>>n2>>m;
//	
//	for(int i=0; i<n1; i++){
//		cin>>a[i];
//	}
//	
//	for(int i=0; i<n2; i++){
//		cin>>b[i];
//	}

	ifstream in_data;
	in_data.open("./data.txt");
	in_data>>n1;
	in_data>>n2;
	in_data>>m;
	for(int i=0; i<n1; i++){
		in_data>>a[i];
	}
	
	for(int i=0; i<n2; i++){
		in_data>>b[i].money;
		b[i].is_used = false;
	}
	
}

void display(){
	
	cout<<n1<<" "<<n2<<" "<<m<<endl;
	for(int i=0; i<n1; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	for(int i=0; i<n2; i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	
	
}

int find_money(){
	
	for(int i=0; i<=n1+n2; i++){
		combine[i][0] = 1;
	}
	
	for(int j=0; j<=m; j++){
		combine[0][i] = 0;
	}
	
	for(int i=1; i<=n1+n2; i++){
		
		for(int j=1; j<=m; j++){
			if(j < a[i-1]){
				combine[i][j] = combine[i-1][j];
				continue;
			}
			
			combine[i][j] = combine[i-1][j] + combine[i][j-a[i-1]];
		}
		
	}
	
}

int excute(){
	int result=0;
	
	
	
	return result;
}

int main(){
	input();
	display();
	
	int result = excute();
	result %= MOD;
	cout<<result<<endl;
} 
