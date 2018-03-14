#include <iostream>
#include <fstream>
using namespace std;

#define MAXLENGTH 1000
int _array[MAXLENGTH] = {0};
int _len;
int k = 5;

void get_data(){
	fstream in_data;
	in_data.open("data.txt");
	in_data >> _len;
	for(int i = 0; i < _len; i++){
		in_data >> _array[i];
	}
}

void print_data(){
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
		while(_array[j] > _array[pivotkey_index]){
			j--;
		}
		
		temp_value = _array[pivotkey_index];
		_array[pivotkey_index] = _array[j];
		_array[j] = temp_value;
		pivotkey_index = j;
		
		// move i
		while(_array[i] < _array[pivotkey_index]){
			i++;
		}
		temp_value = _array[pivotkey_index];
		_array[pivotkey_index] = _array[i];
		_array[i] = temp_value;
		pivotkey_index = i;
		
	}
	
	return pivotkey_index;
}

int Q_sort(int start, int end){
	if(start < end){
		int pivotkey_index = partition(start, end);
		cout<<"pivotkey_index = "<<pivotkey_index<<endl;
		Q_sort(0, pivotkey_index-1);
		Q_sort(pivotkey_index+1, end);
	}
	return 0;
}

int quicksort(int start, int end){
	int result = Q_sort(start, end);
	return result;
}

// quick sort end.

int main(){
	get_data();
	cout<<"before sort..."<<endl;
	print_data();
	
	int result;
	result = quicksort(0, _len-1);
	cout<<"after sort..."<<endl;
	print_data();
	
	cout<<"result = "<<result<<endl;
	return 0;
}





