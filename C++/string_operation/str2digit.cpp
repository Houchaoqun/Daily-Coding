#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	
	string str = "128.00";
	double digit;
	
	stringstream str2digit;
	str2digit << str;
	str2digit >> digit;
	
	double add_num = 22.50;
	
	cout<< (digit + add_num) <<endl;

    return 0;
}
