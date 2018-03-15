#include <iostream>
#include <fstream>
using namespace std;

#define LENGTH 16
#define WEIGHT 10
#define LEN_BOX 4

int matrix[LENGTH][WEIGHT];
int box[LEN_BOX][LEN_BOX];
int offset;

struct position{
	int x;
	int y;
};

void input(){
	// 输入保证前4行中的数字都是0
	// 输入保证板块的图案中正好包含4个方块，且4个方块是连在一起的
	
	ifstream in_data;
	in_data.open("./data.txt");
	
	for(int i=0;i<LENGTH-1;i++){
		for(int j=0;j<WEIGHT;j++){
			in_data >> matrix[i][j];
		}
	}
	
	for(int j=0;j<WEIGHT;j++){
		matrix[LENGTH-1][j]=1;
	}	
	
	
	for(int i=0;i<LEN_BOX;i++){
		for(int j=0;j<LEN_BOX;j++){
			in_data >> box[i][j];
		}
	}
	
	in_data >> offset;
	
	
	// input in hand
//	for(int i=0;i<LENGTH-1;i++){
//		for(int j=0;j<WEIGHT;j++){
//			cin >> matrix[i][j];
//		}
//	}
//	
//	for(int j=0;j<WEIGHT;j++){
//		matrix[LENGTH-1][j]==1;
//	}	
//	
//	
//	for(int i=0;i<LEN_BOX;i++){
//		for(int j=0;j<LEN_BOX;j++){
//			cin >> box[i][j];
//		}
//	}
//	
//	cin >> offset;

} 

void display(){
	
	for(int i=0;i<LENGTH;i++){
		for(int j=0;j<WEIGHT;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<LEN_BOX;i++){
		for(int j=0;j<LEN_BOX;j++){
			cout<< box[i][j] << " ";
		}
		cout<<endl;
	}
	
	cout<<offset<<endl;
	
}

void dis_matrix(){
	// cout<<"****************"<<endl;
	for(int i=0;i<LENGTH-1;i++){
		for(int j=0;j<WEIGHT-1;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<matrix[i][WEIGHT-1]<<endl;
	}
}


void excute(){

	// 当板块中某一个方块的下边缘与方格图上的方块上边缘重合或者达到下边界时，板块不再移动
	// 如果此时方格图的某一行全放满了方块，则该行被消除并得分
	
	// 定位四个方块的位置
	position pos[4];
	int index = 0;
	for(int s=0;s<LEN_BOX;s++){
		for(int t=0;t<LEN_BOX;t++){
			if(box[s][t] == 1){
				pos[index].x = s;
				pos[index].y = t;
				index++;
//				cout<<(s)<<" "<<(t)<<endl;
			}
		}
	}
	
	bool is_fineshed = false;
	int down_num;
	for(int i=0; i<LENGTH-1; i++){
		
		if(is_fineshed){
			break;
		}
		
		// 每次往下预判一行
		for(int k=0; k<index;k++){
			if(matrix[i+1+pos[k].x][offset-1+pos[k].y] == 1){
				is_fineshed = true;
				
				// update matrix
				for(int k=0; k<index; k++){
//					cout<<(i+pos[k].x)<<" "<<(offset-1+pos[k].y)<<endl;
					matrix[i+pos[k].x][offset-1+pos[k].y] = 1;
				}
				break;
			}
		}
		

	}
	
	dis_matrix();
}

int main(){
	input();
//	 display();
	excute();
}



