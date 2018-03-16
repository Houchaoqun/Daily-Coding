#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	
	string str1 = "/d2/d4/f1";
	string str2 = "/d1/../../d2";
	string str3 = "hello world hcq!";
	string dir;
	string dir_list[50];
	int i=0;
	
	stringstream ss(str3);
	while(getline(ss, dir, ' ')){
		dir_list[i] = dir;
		cout<<dir_list[i]<<endl;
		i++;
	}
	
	return 0;
} 
