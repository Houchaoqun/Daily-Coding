#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void file_wr(){
	// read file
	cout<<"***** read file *****"<<endl;
	ifstream file_r;
	file_r.open("data.txt");
	int num;
	file_r >> num;
	for(int i = 0; i < num; i++){
		int temp;
		file_r >>temp;
		cout << temp << endl;
	}
	
	// write file
	cout<<"***** write file *****"<<endl;
	ofstream file_w;
	file_w.open("data_write.txt");
	string content = "hello, I want to write file.";
	char content2[100];
	cin.getline(content2, 100);
	file_w << content << endl;
	file_w << content2 << endl;
	
	// display what you write
	cout<<"display content of file"<<endl;
	ifstream read_file;
	read_file.open("data_write.txt");
	string bookname;
	while (getline(read_file, bookname))
    {
    	// getline(cin, str) --> 
        cout << bookname << endl;

    }
}

int main(){
	
	file_wr();
	return 0;
}

