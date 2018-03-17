#include <iostream>
#include <fstream>

using namespace std;

#define MAX_NUM 1000
int n;
int a[MAX_NUM];

void input(){
	ifstream in_data;
	in_data.open("./data.txt");
	in_data >> n;
	for(int i=0; i<n; i++){
		in_data >> a[i];
	}
}

void diaplay(){
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void BubbleSort(){
	int temp;
	
	for(int i=0; i<n; i++)
    {
    	bool is_finished = true;   // speed up
        for (int j=0; j<n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                
                is_finished = false;
            }
        }
        
        if(is_finished){
        	break;
		}
    }
}

int main(){
	
	input();
	
	cout<<"before sort..."<<endl;
	diaplay();
	
	BubbleSort();
	
	cout<<"after sorted..."<<endl;
	diaplay();
	
	return 0;
}


