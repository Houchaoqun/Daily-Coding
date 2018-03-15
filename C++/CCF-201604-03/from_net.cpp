#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

#define MAX_NUM 11

int N;
string current, relative[MAX_NUM];
string path[MAX_NUM];
vector<string> stk, newStk;

void input(){
	ifstream in_data;
	in_data.open("./data.txt");
	in_data >> N;
	in_data >> current;
	
	for(int i=0; i<N; i++){
		in_data >> relative[i];
	}
}

void printStack(const vector<string> &stk) {
    for(int i=0; i<stk.size(); i++) {
        cout << "/" << stk[i];
    }
    if(stk.empty()) cout << "/";
    cout << "\n";
}

void formalize(vector<string> &stk, string path) {
    stringstream ss(path);
    string dir;
    bool first = true;
    while(getline(ss, dir, '/')) {
//    	cout<<dir<<"|||"<<&stk<<endl;
        if(dir.empty()) {
            if (first) stk = vector<string>();
        }
        else if(dir == "..") {
            if(!stk.empty()){
            	stk.pop_back();
			}
        }
        else if(dir == ".") {}
        else {
            stk.push_back(dir);
        }
        first = false;
    }
}

int main() {
//    int N;
//    cin >> N;
//    string current, relative;
//    cin >> current;
	input();
    vector<string> stk, newStk;
    formalize(stk, current);
//    cin.ignore();
    for(int i=0; i<N; i++){
    	newStk = stk;
        formalize(newStk, relative[i]);
        printStack(newStk);
	}
}




