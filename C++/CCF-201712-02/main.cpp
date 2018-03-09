#include <iostream>
#include <fstream>
using namespace std;

#define MAX_LEN 1001
struct child{
	int id;
	bool visied;
};

child _arr[MAX_LEN];
int n;
int k;

void input();
void print_data();
bool be_out(int id);
int find_vitory();

void input(){
	cin >> n;
	cin >> k;
	
	// init
	for(int i = 1; i <= n; i++){
		_arr[i].id = i;
		_arr[i].visied = false;
	}

}

//void print_data(){
//	for(int i = 1; i <= n; i++){
//		cout<<_arr[i].id<<" ";
//	}
//	cout<<endl;
//}

bool be_out(int id){
	
	if(id%k==0){
		return true;
	}else if(id%10 ==k){
		return true;
	}
	
	return false;
}

int find_vitory(){
	int account_now = 0;
	int index = 1;
	int child_left = n;
	while(child_left!=1){
//		cout<<"=================="<<endl;
//		
//		cout<<"child_left = "<<child_left<<endl;
//		cout<<"index = "<<index<<endl;
		
		if(!_arr[index].visied){
			
			account_now++;
//			cout<<"account_now = "<<account_now<<endl;
			// 
			if(be_out(account_now)){
				_arr[index].visied = true;
				// cout<<_arr[index].id<<" - out"<<endl;
				child_left--;
			}
		}
		
		
		
		index++;
		if(index>n){
			index -= n;
		}
		
	}
	
	int result;
	for(int i = 1; i <= n; i++){
		if(!_arr[i].visied){
			result = i;
			break;
		}
	}
	
	return result;
}

int main(){
	input();
	// print_data();
	cout<<find_vitory()<<endl;
	
	return 0;
}
