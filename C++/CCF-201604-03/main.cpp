#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Ϊ��ָ���ļ�ϵͳ�е�ĳ���ļ�����Ҫ��·������λ
// ·�������ɲ��ֹ��ɣ�ÿ��������һ��Ŀ¼�����ļ������֣�������������֮���� / ���ŷָ�
// ��Ŀ¼: ���ĸ��ڵ㣬��һ�������� / ���ű�ʾ
// ��ǰĿ¼: ��ʾ�û�Ŀǰ���ڹ�����Ŀ¼
// ����·������ / ���ſ�ͷ����ʾ�Ӹ�Ŀ¼��ʼ������·��
// ���·�������� / ���ſ�ͷ����ʾ�ӵ�ǰĿ¼��ʼ������·��
// . ��ʾ��Ŀ¼  /d1/./f1 ָ���ľ��� /d1/f1
// ��������� / ���֣���Ч����ͬ��һ�� /

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

// ·�����滯
// һ��·���������滯��������ָ�����ļ����䣬
// ���һ�������� . �� .. �ľ���·�����Ҳ������������ / ���� 
// ���һ��·���� / ��β����ô�������һ����һ��Ŀ¼�����滯����Ҫȥ����β�� /
// �����·�������Ŀ¼�������滯�����Ľ���� /
// ��·��Ϊ���ַ����������滯�����Ľ���ǵ�ǰĿ¼

string normalize_one(string str){
	// ��������ַ�����Ԥ������Ҫ���£�
	// ���ж��/
	// ĩβ��/��β�ģ�ȥ�� 
	// ���� ./ ֱ��ȥ�� 
	// ���Ϊ�գ���ֱ�ӷ��ص�ǰĿ¼�� path_current
	
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
	// ��ÿ��·������б��/����Ϊ�����ʾ�����ָ�
	// ��б��/��ͷ�ı�ʾ����·�������ڵ� 
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


