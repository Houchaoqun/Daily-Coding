#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 为了指定文件系统中的某个文件，需要用路径来定位
// 路径由若干部分构成，每个部分是一个目录或者文件的名字，相邻两个部分之间用 / 符号分隔
// 根目录: 树的根节点，用一个单独的 / 符号表示
// 当前目录: 表示用户目前正在工作的目录
// 绝对路径：以 / 符号开头，表示从根目录开始构建的路径
// 相对路径：不以 / 符号开头，表示从当前目录开始构建的路径
// . 表示本目录  /d1/./f1 指定的就是 /d1/f1
// 多个连续的 / 出现，其效果等同于一个 /

#define MAX_NUM 11

int p;
string path_current;
string path[MAX_NUM];

void input(){
	ifstream in_data;
	in_data.open("./data.txt");
	in_data >> p;
	in_data >> path_current;
	
	for(int i=0; i<p; i++){
		in_data >> path[i];
	}
}

void display(){
	cout<<p<<endl;
	cout<<path_current<<endl;
	for(int i=0; i<p; i++){
		cout << path[i]<<endl;
	}
	
}

// 路径正规化
// 一个路径经过正规化操作后，其指定的文件不变，
// 变成一个不包含 . 和 .. 的绝对路径，且不包含连续多个 / 符号 
// 如果一个路径以 / 结尾，那么它代表的一定是一个目录，正规化操作要去掉结尾的 /
// 若这个路径代表根目录，则正规化操作的结果是 /
// 若路径为空字符串，则正规化操作的结果是当前目录

string normalize_one(string str){
	// 对输入的字符进行预处理，主要如下：
	// 含有多个/
	// 末尾以/结尾的，去掉 
	// 含有 ./ 直接去掉 
	// 如果为空，则直接返回当前目录： path_current
	
//	cout<<str.length()<<endl;
	string temp;
	for(int i=0; i<str.length()-1; i++){
		
		if(str[i]=='/'&&str[i+1]=='/'){
//			cout<<str[i]<<" "<<str[i+1]<<endl;
		}else{
			str[i]
			temp.append();
		}
	}
	str = temp;
	
	return str;
}

void normalize_two(){
	// 将每个路径根据斜杠/划分为数组表示多个“指令”
	// 以斜杠/开头的表示绝对路径，根节点 
}

int excute(){
	
	string xx = "/d1///d2/d3/f1";
	xx = normalize_one(xx);
	cout<<xx<<endl;
	return 0;
}

int main(){
	
//	input();
//	display();
	excute();
	return 0;
}


