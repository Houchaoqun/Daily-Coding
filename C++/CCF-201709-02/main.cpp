#include <iostream>
#include <fstream>
using namespace std;

#define MAX_N 1001
#define MAX_K 1001
#define MAX_w 1001
#define MAX_s 10001
#define MAX_c 101

struct key{
	int index;
	bool is_used;
};

struct point_time{
	int teacher_index;
	bool is_back; // true --> back key; false --> get key;
	int time;
};

struct teacher{
	int id;
	int start_class;
	int time_class;
};

int teacher[MAX_K];
point_time important_time[2*MAX_K];
int wsc[MAX_K][3];
int box_state[MAX_N];
int N,K;

void input(){
	fstream in_read;
	in_read.open("data.txt");
	in_read >> N;
	in_read >> K;
	
//	for(int i = 0; i<K; i++){
//		in_read >> teacher[i].id;
//		in_read >> teacher[i].start_class;
//		in_read >> teacher[i].time_class;
//	}

	for(int i = 0; i<K; i++){
		in_read >> wsc[i][0];
		in_read >> wsc[i][1];
		in_read >> wsc[i][2];
	}
}

void print_info(){
	cout<<N<<" "<<K<<endl;
	for(int i=0; i< K; i++){
		// cout<<teacher[i].id<<" "<<teacher[i].start_class<<" "<<teacher[i].time_class<<" "<<endl;
		cout<<wsc[i][0]<<" "<<wsc[i][1]<<" "<<wsc[i][2]<<" "<<endl;
	}
}

void print_point(){
	for(int i=0; i<2*K; i++){
		cout<<"teacher_index = "<<important_time[i].teacher_index<<"; time = "<<important_time[i].time<<"; is_back = "<<important_time[i].is_back<<endl;
	}
}

void print_box_state(){
	for(int i = 0; i < N; i++){
		cout<<box_state[i]<<"";
	}
	cout<<endl;
}

void excute(){
	
	// point time
	for(int i=0; i<K; i++){
		// back key
		important_time[2*i].teacher_index = wsc[i][0];
		important_time[2*i].time = wsc[i][1];
		important_time[2*i].is_back = false;
		// cout<<"teacher_index = "<<important_time[i].teacher_index<<"; time = "<<important_time[i].time<<"; is_back = "<<important_time[i].is_back<<endl;
		
		// get key
		important_time[2*i+1].teacher_index = wsc[i][0];
		important_time[2*i+1].time = wsc[i][1] + wsc[i][2];
		important_time[2*i+1].is_back = true;
		// cout<<"teacher_index = "<<important_time[i+1].teacher_index<<"; time = "<<important_time[i+1].time<<"; is_back = "<<important_time[i+1].is_back<<endl;
	}
	
	cout<<"before sorted..."<<endl;
	print_point();
	
	// sort
	point_time temp;
	for(int i=0; i<2*K-1; i++){
		for(int j=0; j<2*K-1-i; j++){
			if(important_time[j].time > important_time[j+1].time){
				temp = important_time[j];
				important_time[j] = important_time[j+1];
				important_time[j+1] = temp;
			}
		}
	}
	
	cout<<"after sorted..."<<endl;
	print_point();
	
	// handle box key: 0 --> null
	// init
	for(int i=0; i<N; i++){
		box_state[i] = i+1; 
	}
	
	// work
	point_time same_time[2*MAX_K];
	for(int i=0; i<2*K; i++){
//		cout<<"i="<<i<<endl;
		// the same time
		int index_same_time = 0;
		while(important_time[i].time == important_time[i+1].time){
			same_time[index_same_time] = important_time[i];
			index_same_time++;
			i++;
		}
		
		if(index_same_time>0){
			cout<<"xx"<<endl;
		}
		
		// without the same time
		if(important_time[i].is_back){
			cout<<"back key"<<endl;
			for(int t=0; t<N; t++){
				if(box_state[t] == 0){
					box_state[t] = important_time[i].teacher_index;
					break;
				}
			}
		}else{
			// get
			cout<<"get key"<<endl;
			for(int t=0; t<N; t++){
				if(box_state[t] == important_time[i].teacher_index){
					box_state[t] = 0;
					break;
				}
			}
		}
		cout<<"time = "<<important_time[i].time<<"; ";
		print_box_state();
		
		
	} 
	
}

int main(){
	
	input();
	print_info();
	excute();
	
	return 0;
}
