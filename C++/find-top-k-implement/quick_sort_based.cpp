#include <iostream>
#include <fstream>
using namespace std;

#define MAXLENGTH 1000
int _array[MAXLENGTH] = {0};
int _len;
int K;
int result = 0;

void get_data(){
	fstream in_data;
	in_data.open("data.txt");
	in_data >> _len;
	in_data >> K;
	for(int i = 0; i < _len; i++){
		in_data >> _array[i];
	}
}

void print_data(){
	cout<<"_len = "<<_len<<"; K = "<<K<<endl;
	for(int i = 0; i<_len; i++){
		cout<<_array[i]<<" ";
	}
	cout<<endl;
}

// quick sort
int partition(int start, int end){
	
	if(start > end){
		return 0;
	}
	
	int temp_value;
	int pivotkey_index = start;
	int i = start;
	int j = end;
	
	while(i < j){
		
		// move j
		while(i<j&&_array[j] > _array[pivotkey_index]){
			j--;
		}
		
		temp_value = _array[pivotkey_index];
		_array[pivotkey_index] = _array[j];
		_array[j] = temp_value;
		pivotkey_index = j;
		
		// move i
		while(i<j&&_array[i] < _array[pivotkey_index]){
			i++;
		}
		temp_value = _array[pivotkey_index];
		_array[pivotkey_index] = _array[i];
		_array[i] = temp_value;
		pivotkey_index = i;
		
	}
	
	return pivotkey_index;
}

// find-top-k 
void Q_sort(int start, int end){
	// cout<<"call Q_sort function..."<<endl;
	if(start < end){
		int pivotkey_index = partition(start, end);
		// cout<<"pivotkey_index = "<<pivotkey_index<<endl; 
		if(pivotkey_index+1 == K){
			result = _array[pivotkey_index];
		}else if(pivotkey_index+1 > K){
			Q_sort(0, pivotkey_index-1);
		}else{
			Q_sort(pivotkey_index+1, end);
		}
	}
}


// quick sort end.

int main(){
	get_data();
	print_data();
	
	Q_sort(0, _len-1);
	
	cout<<"the "<<K<<"th number = "<<result<<endl;
	return 0;
}





