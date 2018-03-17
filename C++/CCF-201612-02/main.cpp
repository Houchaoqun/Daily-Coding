#include <iostream>
#include <fstream>

using namespace std;

int T;  // 小明的税后所得
 
void input(){
//	ifstream in_data;
//	in_data.open("./data.txt");
//	in_data >> n;
//	for(int i=0; i<n; i++){
//		in_data >> a[i];
//	}

	cin >> T;
} 

int calculate(){
	
	int S, A;
	int guess_T;
	int money_hand_in;
	S = T;
	
	while(true){
		money_hand_in = 0;
		
		while(true){
			
			if(S%100 == 0){
				break;
			}
			S += 5;
		}
		
		if(S > 3500){
			A = S - 3500;
			if(A > 1500){
				money_hand_in += 1500*0.03;
				if(A > 4500){
					money_hand_in += (4500-1500)*0.1;
					if(A > 9000){
						money_hand_in += (9000-4500)*0.2;
						if(A > 35000){
							money_hand_in += (35000-9000)*0.25;
							if(A > 55000){
								money_hand_in += (55000-35000)*0.3;
								if(A > 80000){
									money_hand_in += (80000-55000)*0.35;
									money_hand_in += (A-80000)*0.45;
								}else{
									money_hand_in += (A-55000)*0.35;
								}
							}else{
								money_hand_in += (A-35000)*0.3;
							}
						}else{
							money_hand_in += (A-9000)*0.25;
						}
					}else{
						money_hand_in += (A-4500)*0.2;
					}
				}else{
					money_hand_in += (A-1500)*0.1;
				}
			}else{
				money_hand_in += (A - 1500)*0.03;
			}
		}else{
			money_hand_in = 0;
		}
		
		
		guess_T = S - money_hand_in;
		if(guess_T == T){
			break;
		}
//		cout<<S<<" "<<money_hand_in<<endl;
		S += 5;
		

	}

	return S;
	
}


int main(){
	
	input();
	cout<<calculate()<<endl;
	return 0;
}
