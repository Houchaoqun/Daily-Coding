#include <iostream>
#include <fstream>

using namespace std;

#define MAX_NUM 101
int N;
int need_time;

struct x_CLOCK{
	int hour;
	int min;
};

x_CLOCK x_clock[MAX_NUM];
x_CLOCK class_time;
x_CLOCK result_clock;

void input(){
//	ifstream in_data;
//	in_data.open("./data.txt");
//	in_data >> N;
//	for(int i=0; i<N; i++){
//		in_data >> clock[i].hour;
//		in_data >> clock[i].min;
//	}
//	
//	in_data >> need_time;
//	in_data >> class_time.hour;
//	in_data >> class_time.min;

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> x_clock[i].hour;
		cin >> x_clock[i].min;
	}
	
	cin >> need_time;
	cin >> class_time.hour;
	cin >> class_time.min;
}

void display(){
	cout<<N<<endl;
	for(int i=0; i<N; i++){
		cout<<x_clock[i].hour<<" ";
		cout<<x_clock[i].min<<endl;
	}
	cout<<need_time<<endl;
	cout<<class_time.hour<<" "<<class_time.min<<endl;
}

int excute(){
	
	// time operation
	x_CLOCK latest_time;
	latest_time.hour = class_time.hour;
	latest_time.min = class_time.min;
	
	// - need_time
	if(latest_time.min < need_time){
		latest_time.hour -= 1;
		latest_time.min += 60;
		latest_time.min -= need_time;
	}else{
		latest_time.min -= need_time;
	}
//	cout<<latest_time.hour<<" "<<latest_time.min<<endl;
	
	// judge
	int target_clock_index;
	result_clock.hour = 0;
	result_clock.min = 0;
	for(int i=0; i<N; i++){
		
		if(x_clock[i].min < latest_time.min){
			x_clock[i].hour -= 1;
			x_clock[i].min += 60;
		}
		
		// satisified
		if((x_clock[i].hour<latest_time.hour) || (x_clock[i].hour==latest_time.hour && x_clock[i].min<=latest_time.min)){
			// get min
			// cout<<clock[i].hour<<" "<<clock[i].min<<endl;
			bool case1 = (result_clock.hour < x_clock[i].hour);
			bool case2 = (result_clock.hour == x_clock[i].hour && result_clock.min < x_clock[i].min);
			if(case1 || case2){
				// update
				result_clock.hour = x_clock[i].hour;
				result_clock.min = x_clock[i].min;
				
				if(result_clock.min>=60){
					result_clock.min -= 60;
					result_clock.hour += 1;
				}
			}
		}
		
	}
	
	cout<<result_clock.hour<<" "<<result_clock.min<<endl;
}

int main(){
	
	input();
	// display();
	excute();
	
	return 0;
}
