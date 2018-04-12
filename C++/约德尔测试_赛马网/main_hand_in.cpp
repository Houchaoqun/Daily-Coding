#include <iostream>
#include <vector>
#include <stdio.h>
#include <iomanip> 
#include <fstream>
using namespace std;

#define MAX_NUM 1010
vector<char> source;
vector<char> target;
int len = 0;

void get_data(){
	
	char temp;
	
	while(1){
		
		temp = getchar();
		if(temp == '\n'){
			break;
		}
		
		source.push_back(temp);
		len++;
		
	}
	
	for(int i=0; i<len; i++){
		temp = getchar();
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

// 判断ch是数字，条件是 (ch>='0' && ch<='9')
// 判断ch是字符，条件是 (ch>='A' && ch<='Z'  ||  ch>='a' && ch<='z')

void transfer_01(){
	
	bool is_digit, is_letter;
	for(int i=0; i<len; i++){
		is_digit = (source[i]>='0' && source[i]<='9');
		is_letter = (source[i]>='A' && source[i]<='Z') || (source[i]>='a' && source[i]<='z');
		
		if(is_digit || is_letter){
			source[i] = '1';
		}else{
			source[i] = '0';
		}
	}
}

int compare(){
	
	float ratio = 0.0;
	int same_num = 0;
	
	for(int i=0; i<len; i++){
		if(source[i] == target[i]){
			same_num++;
		}
	}
	
	ratio = float(same_num*100)/len;
	cout<<setiosflags(ios::fixed);
	cout.precision(2);
	cout<<ratio<<"%"<<endl;
	
	// printf("%.2f", ratio);
	
	return 0;
}


int main(){
	
	get_data();
	transfer_01();
	// display();
	compare();
	return 0;
}
