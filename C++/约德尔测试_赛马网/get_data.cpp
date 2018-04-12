#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define MAX_NUM 1010
vector<char> source;
vector<char> target;
int len = 0;

void get_data(){
	
	ifstream in_data;
	in_data.open("./data.txt");
	char temp;
	
	while(1){
		
		temp = in_data.get();
		if(temp == '\n'){
			break;
		}
		
		source.push_back(temp);
		len++;
		
	}
	
	for(int i=0; i<len; i++){
		temp = in_data.get();
		target.push_back(temp);
	}
	
}

void display(){
	
	cout<<"len = "<<len<<endl;
	
	for(int i=0; i<len; i++){
		cout<<source[i];
	}
	cout<<endl;
	
	for(int i=0; i<len; i++){
		cout<<target[i];
	}
	cout<<endl;
}


int main(){
	
	get_data();
	display();
	return 0;
}
