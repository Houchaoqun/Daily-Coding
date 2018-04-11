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
        if(getchar()=='\n') //���س�����
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
	
	// cin.get(�ַ������������ճ��ȣ�������)
	// ��������ζ�������÷��Ž����ַ�����ȡ,Ĭ��ΪENTER����ȡ���ַ��������Ϊ������-1������Ϊ���һ��Ϊ��n����
	// Ҫע����ǣ�cin.get()��������������ֹͣ��ȡ���������Ὣ�������ӻ�����������
	
	num = 0;
	while(true)
    {
        if(cin.get() == '\n') //���س�����
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
	in_data.seekg(0, ios::end);      //�����ļ�ָ�뵽�ļ�����β��
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
        if(getchar()=='\n') //���س�����
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
		// �ú������޷��� char ǿ��ת��Ϊ int ����ʽ���ض�ȡ���ַ�
		// һ���ַ�һ���ַ��ض����� 
		// C �⺯�� int fgetc(FILE *stream) ��ָ������ stream ��ȡ��һ���ַ���һ���޷����ַ�����
		// ����λ�ñ�ʶ����ǰ�ƶ���
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
