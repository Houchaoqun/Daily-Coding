#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAX_NUM 1000
int num;
int a[MAX_NUM];

void display(){
	cout<<endl;
	cout<<num<<endl;
	for(int i=0; i<num; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void input_cin(){
	
	num = 0;
	for(int i=0;;i++)
    {
        cin>>a[num];
        num++;
        if(getchar()=='\n') //遇回车结束
            break;  
    }
    
    display();
}

void input_cin2(){
	
	num = 0;
	do{
		cin >> a[num];
		num++;
	}while(cin.get() != '\n');
    
    display();
}

void input_cin_get(){
	
	// cin.get(字符数组名，接收长度，结束符)
	// 结束符意味着遇到该符号结束字符串读取,默认为ENTER，读取的字符个数最多为（长度-1），因为最后一个为”n”。
	// 要注意的是，cin.get()操作遇到结束符停止读取，但并不会将结束符从缓冲区丢弃。
	
	num = 0;
	while(true)
    {
        if(cin.get() == '\n') //遇回车结束
        	break;
    	else{
    		// cin.get(ch1);
			// ch1 = cin.get();
    		a[num] = cin.get();
    		num++;
		}
             
    }
    
    display();
}

void input_getc(){
//	char c;
//	c = getc(stdin);
//	cout<<c<<endl;
	
	num = 0;
	while(getc(stdin) != '\n'){
		a[num] = getc(stdin) - '0';
		num++;
	}
	display();
}


void input_ifstream(){
	
	ifstream in_data;
	in_data.open("./data.txt");
	streampos pos = in_data.tellg();
	num = pos;
	in_data.seekg(0, ios::end);      //设置文件指针到文件流的尾部
	cout << "File size: " << num << endl;
	in_data.seekg(pos);
	

	for(int i=0; i<num; i++){
		in_data >> a[i];
	}
	
	in_data.close(); 

	display();
	
}

void input_ifstream2(){
	
	ifstream in_data;
	in_data.open("./data.txt");
	
	num = 0;
	for(int i=0;;i++)
    {
        in_data >> a[num];
        num++;
        if(getchar()=='\n') //遇回车结束
            break;  
    }

	display();
	
}

void input_fgetc(){
	
	// int fgetc(FILE *stream)
	FILE *fp;
	fp = fopen("./data.txt","r");
	int c;
	if(fp == NULL) 
	{
		perror("error...");
		return;
	}
	
	num = 0;
	do
	{
		// 该函数以无符号 char 强制转换为 int 的形式返回读取的字符
		// 一个字符一个字符地读出来 
		// C 库函数 int fgetc(FILE *stream) 从指定的流 stream 获取下一个字符（一个无符号字符），
		// 并把位置标识符往前移动。
		c = fgetc(fp);
		
		if( feof(fp) )
		{
			break ;
		}
		
		a[num] = c;
		num++;
		printf("%c", c);
	}while(1);
	
    fclose(fp);
    
    display();
}

int main(){
	
	input_cin2();
	return 0;
}
