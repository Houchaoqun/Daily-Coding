#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char *padString(const char*s, int n){
	int size = 2*n+3;
	char *p = new char[size];
	p[0] = '$';
	for(int i=1; i<size-1; i++){
		if(i%2 == 0){
			p[i] = s[i/2-1];
		}else{
			p[i] = '#';
		}
	}
	
	p[size-1] = '\0';
	return p;
}

int Longest(const char*s, int n){
	int mx = 0;
	int id = 1;
	int max = 0;
	char *p = NULL;
	p = padString(s, n);
	int psize = strlen(p);
	int pp[psize];
	memset(pp, 0, psize);
	
	for(int i=1; p[i]!='\0'; i++){
		pp[i] = mx > i?std::min(pp[2*id-i], mx-i):1;
		while(p[i+pp[i]] == p[i-pp[i]]){
			pp[i]++;
		}
		if(i+pp[i] > mx){
			mx = 1+pp[i];
			id = i;
		}
	}
	
	for(int i=0; i<psize;i++){
		if(pp[i] > max){
			max = pp[i];
		}
	}
	
	free(p);
	return (max-1);
}



int main(){
	
	char s[64];
	cin >> s;
	char *ps = padString(s, strlen(s));
	free(ps);
	
	int length = Longest(s, strlen(s));
	cout<< length <<endl;
	
	return 0;
	
}
