#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define MOD 1000000007
#define MAX_NUM 102
#define MAX_MONEY 100000

struct STATE_TABLE{
	// int coin_id;
	vector <int> state;
	int money_needed;
	// int length;
};

// STATE_TABLE state_table[2*MAX_NUM][MAX_MONEY];
vector <STATE_TABLE> state_table[2*MAX_NUM];


struct jnb{
	int money;
	bool is_used;
};

int a[MAX_NUM];
int b[MAX_NUM];
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
		in_data>>b[i];
		// in_data>>b[i].money;
		// b[i].is_used = false;
	}
	
	// init
	int len;
	STATE_TABLE temp;
	for(int i=0; i<n1; i++){
		len=1;
		while(len*a[i] <= m){
			temp.money_needed = m - len*a[i];
			for(int index=0; index<len; index++){
				temp.state.push_back(a[i]);
			}
			state_table[i].push_back(temp);
			
			// clear the vector of temp...
			temp.state.clear();
			len += 1;
		}
	}
	
	for(int i=0; i<n2; i++){
		if(b[i] <= m){
			cout<<"xx"<<endl;
			temp.money_needed = m - b[i];
			temp.state.push_back(b[i]);
			state_table[i+n1].push_back(temp);
			
			temp.state.clear();
		}
	}

	
}

void display(){
	
	cout<<n1<<" "<<n2<<" "<<m<<endl;
	for(int i=0; i<n1; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	for(int i=0; i<n2; i++){
		// cout<<b[i].money<<" ";
		cout<<b[i]<<" ";
	}
	cout<<endl;
	
	cout<<"=== State of transfer ==="<<endl;
	for(int i=0; i<n1+n2; i++){
		for(int j=0; j<state_table[i].size(); j++){
			cout<<state_table[i][j].money_needed<<" - {";
			for(int index=0; index < state_table[i][j].state.size(); index++){
				cout<<state_table[i][j].state[index]<<" ";
			}
			cout<<"}"<<"  ";
		}
		cout<<endl;
	}
	
}


int excute(){
	
	int result=0;
	for(int i=0; i<n1+n2-1; i++){
		for(int j=0; j<state_table[i].size(); j++){
			for(int t=i+1; t<n1+n2; t++){
				// fuck....
			}
		}
	}
	
	
	
	return result;
}

int main(){
	input();
	display();
	
	int result = excute();
	result %= MOD;
	cout<<result<<endl;
} 
