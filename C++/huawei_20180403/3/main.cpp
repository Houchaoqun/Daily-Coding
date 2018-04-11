#include <iostream>
#include <fstream>

using namespace std;

#define MAX_NUM 50
int num_flow;
int num_ganmes;
struct GAMES{
	int NO;
	int need_flow;
	int gold_award;
};
GAMES games[MAX_NUM];

void input(){
	ifstream in_data;
	in_data.open("./data.txt");
	
	in_data >> num_flow;
	num_ganmes = 0;
	int temp[MAX_NUM];
	for(int i=0; i<MAX_NUM; i++){
		in_data >> temp[num_ganmes];
		cout<<i<<" "<<temp[num_ganmes]<<endl;
		if(!temp[num_ganmes]){
			break;
		}else{
			num_ganmes++;
		}
	}
	num_ganmes -= 1;
	for(int i=0; i<num_ganmes-1; i++){
		games[i].NO = i+1;
		games[i].need_flow = temp[i];
		games[i].gold_award = temp[i+1];
	}
	num_ganmes = num_ganmes/2;
	
}

void display(){
	cout<<num_ganmes<<endl;
	for(int i=0; i<num_ganmes; i++){
		cout<<games[i].need_flow<<" ";
	}
	cout<<endl;
	
	for(int i=0; i<num_ganmes; i++){
		cout<<games[i].gold_award<<" ";
	}
	cout<<endl;
}

int excute(){
	
}

int main(){
	input();
	// display();
	
	return 0;
}
