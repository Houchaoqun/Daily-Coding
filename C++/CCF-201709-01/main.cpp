#include <iostream>
#include <fstream>
using namespace std; 

void input_data();
int excute(); 

int N;

void input_data(){
	cin>>N;
}

int excute(){
	// 3 --> 1
	// 5 --> 2
	// limit function: 50*num_5 + 30*num_3 <= N; N <= 300; --> 5*num_5 + 3*num_3 <= 30
	// target function = (5*num_5 + 2*num_5) + (3*num_3 + 1*num_3)
	int num_5;  // 5*num_5 + 3*num_3 <= 30  -->  num_5 <= 6, when num_3=0
	int num_3;  // 5*num_5 + 3*num_3 <= 30 --> num_3 <= 10, when num_5=0
	int max_buy = 0;
	int temp_buy_num, money_used, buy_one;
	int limit_5 = 6;
	int limit_3 = 10;
	
	for(num_5 = 0; num_5 <= limit_5; num_5++){
		for(num_3 = 0; num_3 <= limit_3; num_3++){
			money_used = 50*num_5 + 30*num_3;
			buy_one = 0;
			if(money_used <= N){
				// buy one
				if((N - money_used) >= 10){
					buy_one = (N - money_used)/10;
				}
				temp_buy_num = (7*num_5 + 4*num_3) + buy_one;
				if(max_buy < temp_buy_num){
					max_buy = temp_buy_num;
					// cout<<"num_5 = "<<num_5<<"; num_3 = "<<num_3<<"; money_used = "<<money_used<<"; buy_one = "<<buy_one<<"; max_buy = "<<max_buy<<endl;
				}
			}
		}
	}
	
	return max_buy;
}

int main(){
	
	input_data();
	cout<<excute()<<endl;
	
	return 0;
}
