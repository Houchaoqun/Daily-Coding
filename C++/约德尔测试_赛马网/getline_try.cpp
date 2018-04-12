#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s1, s2;
	vector <char> c1;
	getline(cin, s1);
	getline(cin, s2);
	
	for(int i=0; i<s1.length() ;i++){
		cout<<s1[i]<<endl;
		// c1.push_back(s1[i]);
	}
	
	for(int i=0; i<s2.length() ;i++){
		cout<<s2[i]<<endl;
	}
	

	return 0;
}
