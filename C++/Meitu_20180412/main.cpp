#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NUM 1010
int a[MAX_NUM][MAX_NUM];
int result[MAX_NUM][MAX_NUM];
int N = 0;

void input(){
	
    int temp;
    
    do{
        cin >> temp;
		a[0][N] = temp;
        N++;
    }while(cin.get() != '\n');
    
    
    for(int i=1; i<N; i++){
    	for(int j=0; j<N; j++){
    		cin>>a[i][j];
		}
	}
	
}

void display(){  
      
      
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
    cout<<endl;   
}  

int excute(){
	
	// ԭ����ĵ�һ�е�����ת90�Ⱥ�����һ�� 
	
	// ���ѿռ� 
//	int temp; 
//	for(int i=0; i<N; i++){
//    	for(int j=0; j<N; j++){
//    		result[j][N-1-i] = a[i][j];
//		}
//	}
//	display();
	
	// ��ʡ�ռ䣬ֱ�����
	for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		cout<<a[N-1-j][i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
} 

int main(){
	
	input();
	excute();
	
	return 0;
}
