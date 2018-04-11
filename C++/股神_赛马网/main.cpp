#include <iostream>

using namespace std;

int main(){
	
	int n;
	int temp_added, days_added;
	
	while(cin >> n){
		
		int money = 1;
		bool is_added = true;
		days_added = 1;
		int i=2;
		
		while(i <= n){
			temp_added = days_added;
			
			if(is_added){
				
				while(i <= n){
					
					if(temp_added>0){
						money += 1;
//						cout<<"i="<<i<<";  money="<<money<<" [add]"<<endl;
						i += 1;
						temp_added -= 1;
					}else{
						break;
					}
				}
				is_added = false;
				
			}else{
				money -= 1;
				days_added += 1;
				is_added = true;
//				cout<<"i="<<i<<";  money="<<money<<" [minues]"<<endl;
				
				i += 1;
			}
		}
		
		cout<<money<<endl;
//		cout<<"==="<<endl;
	}
	
	return 0;
	
} 
