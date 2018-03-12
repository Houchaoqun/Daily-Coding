#include <iostream>
#include <fstream>
using namespace std;

//CCF-CSP
//试题编号：	201709-2
//试题名称：	公共钥匙盒
//时间限制：	1.0s
//内存限制：	256.0MB

//问题描述
//　　有一个学校的老师共用N个教室，按照规定，所有的钥匙都必须放在公共钥匙盒里，老师不能带钥匙回家。每次老师上课前，都从公共钥匙盒里找到自己上课的教室的钥匙去开门，上完课后，再将钥匙放回到钥匙盒中。
//　　钥匙盒一共有N个挂钩，从左到右排成一排，用来挂N个教室的钥匙。一串钥匙没有固定的悬挂位置，但钥匙上有标识，所以老师们不会弄混钥匙。
//　　每次取钥匙的时候，老师们都会找到自己所需要的钥匙将其取走，而不会移动其他钥匙。每次还钥匙的时候，还钥匙的老师会找到最左边的空的挂钩，将钥匙挂在这个挂钩上。如果有多位老师还钥匙，则他们按钥匙编号从小到大的顺序还。如果同一时刻既有老师还钥匙又有老师取钥匙，则老师们会先将钥匙全还回去再取出。
//　　今天开始的时候钥匙是按编号从小到大的顺序放在钥匙盒里的。有K位老师要上课，给出每位老师所需要的钥匙、开始上课的时间和上课的时长，假设下课时间就是还钥匙时间，请问最终钥匙盒里面钥匙的顺序是怎样的？
//输入格式
//　　输入的第一行包含两个整数N, K。
//　　接下来K行，每行三个整数w, s, c，分别表示一位老师要使用的钥匙编号、开始上课的时间和上课的时长。可能有多位老师使用同一把钥匙，但是老师使用钥匙的时间不会重叠。
//　　保证输入数据满足输入格式，你不用检查数据合法性。
//输出格式
//　　输出一行，包含N个整数，相邻整数间用一个空格分隔，依次表示每个挂钩上挂的钥匙编号。

// 作者：houchaoqun 
// 时间：20180312 
// 思路：
// 1. 老规矩，使用文件读写的方式测试数据，编写函数： void input(); 以及相关输出的函数； 
// 2. 阅读题目并理解：
//    1) 公共钥匙盒初始化顺序为：1,2 ... N; 经过K个老师上课用钥匙的情况，求出最后公共钥匙盒的顺序； 
//    2) 每个老师有3个关键字段：使用的钥匙编号；开始上课的时间；上课的时长； 
//    3) 针对每个老师：有两个操作钥匙的时刻，分别是“取钥匙”和 “还钥匙”，构成2K个时刻；分别用两个函数实现对应功能：void fun_back_key(int key_id, int time); void fun_get_key(int key_id, int time); 
//    4)  fun_back_key(): 还钥匙时，钥匙盒最左边的空挂钩优化放置；
//    5) 设计 point_time结构体表示每个操作钥匙的时刻，包括钥匙编号、对钥匙的操作、哪个时刻等字段；
//    6)  point_time important_time[2*MAX_K]; 表示2K个操作，先对每个操作的时刻以从小到大的顺序进行排序。
//    7)  使用冒泡排序，三种情况下需要交换前后两个变量的位置：case1, case2, case3（下文有说明） 
// 3. 处理特殊情况
//    1) 如果同一时刻既有老师还钥匙又有老师取钥匙，则老师们会先将钥匙全还回去再取出：还钥匙优先。 
//    2) 果同一时刻有多个老师同时还钥匙：则他们按钥匙编号从小到大的顺序还。
//  
// 程序流程如下： 
// 1.获取用户输入的相关变量，定义相关的结构体； 
// 2.计算获得2K个操作钥匙的时刻；point_time important_time[2*MAX_K];
// 3.根据时刻，按从小到大对 important_time[2*MAX_K] 使用冒泡排序，注意特殊情况的处理：相同时刻 2个优先原则； 
// 4.初始化公共钥匙盒的顺序：int box_state[MAX_N];
// 5.分别对2K个时刻进行钥匙的模拟操作：注意考虑特殊情况，如果 important_time[] 中有相同的时刻，则需根据优先原则进行处理； 
//
//




#define MAX_N 1001
#define MAX_K 1001
#define MAX_w 1001
#define MAX_s 10001
#define MAX_c 101

struct point_time{
	int teacher_index;
	bool is_back; // true --> back key; false --> get key;
	int time;
};

struct teacher{
	int id;
	int start_class;
	int time_class;
};

teacher teacher_info[MAX_K];
point_time important_time[2*MAX_K];
int box_state[MAX_N];
int N,K;

void input(){
	fstream in_read;
	in_read.open("data.txt");
	in_read >> N;
	in_read >> K;
	
	for(int i = 0; i<K; i++){
		in_read >> teacher_info[i].id;
		in_read >> teacher_info[i].start_class;
		in_read >> teacher_info[i].time_class;
	}

//	cin >> N;
//	cin >> K;
//	for(int i = 0; i<K; i++){
//		cin >> teacher_info[i].id;
//		cin >> teacher_info[i].start_class;
//		cin >> teacher_info[i].time_class;
//	}

}

void print_info(){
	cout<<N<<" "<<K<<endl;
	for(int i=0; i< K; i++){
		 cout<<teacher_info[i].id<<" "<<teacher_info[i].start_class<<" "<<teacher_info[i].time_class<<" "<<endl;
	}
}

void print_point(){
	for(int i=0; i<2*K; i++){
		cout<<"teacher_index = "<<important_time[i].teacher_index<<"; time = "<<important_time[i].time<<"; is_back = "<<important_time[i].is_back<<endl;
	}
}

void print_box_state(){
	for(int i = 0; i < N; i++){
		cout<<box_state[i]<<" ";
	}
	cout<<endl;
}

// back key
void fun_back_key(int key_id, int time){
	for(int t=0; t<N; t++){
		if(box_state[t] == 0){
			box_state[t] = key_id;
			break;
		}
	}
	cout<<"back key: "<<"time="<<time<<"; ";
	print_box_state();
}

// get key
void fun_get_key(int key_id, int time){
	for(int t=0; t<N; t++){
		if(box_state[t] == key_id){
			box_state[t] = 0;
			break;
		}
	}
	cout<<"get  key: "<<"time="<<time<<"; ";
	print_box_state();
}

void excute(){
	cout<<"excuting..."<<endl;
	// point time
	for(int i=0; i<K; i++){
		// get key
		important_time[2*i].teacher_index = teacher_info[i].id;
		important_time[2*i].time = teacher_info[i].start_class;
		important_time[2*i].is_back = false;
		// cout<<"teacher_index = "<<important_time[i].teacher_index<<"; time = "<<important_time[i].time<<"; is_back = "<<important_time[i].is_back<<endl;
		
		// back key
		important_time[2*i+1].teacher_index = teacher_info[i].id;
		important_time[2*i+1].time = teacher_info[i].start_class + teacher_info[i].time_class;
		important_time[2*i+1].is_back = true;
		// cout<<"teacher_index = "<<important_time[i+1].teacher_index<<"; time = "<<important_time[i+1].time<<"; is_back = "<<important_time[i+1].is_back<<endl;
	}
	
	cout<<"before sorted..."<<endl;
	print_point();
	
	// sort
	point_time temp;
	bool case1, case2, case3;
	for(int i=0; i<2*K-1; i++){
		for(int j=0; j<2*K-1-i; j++){
			// 不同时刻的情况，前者的时刻大于后者的时刻 
			case1 = (important_time[j].time > important_time[j+1].time);
			// 同一个时刻，前后两个老师的操作分别是还和取，还为优先的原则。 
			case2 = (important_time[j].time == important_time[j+1].time && important_time[j].is_back == false && important_time[j+1].is_back == true);
			// 同一个可是，前后两个老师都是还钥匙，且前者欲还的钥匙编号小于后者的钥匙编号：钥匙编号小的优先还。 
			case3 = (important_time[j].time == important_time[j+1].time && important_time[j].is_back == true && important_time[j+1].is_back == true && important_time[j].teacher_index > important_time[j+1].teacher_index);  // 如果有多位老师还钥匙，则他们按钥匙编号从小到大的顺序还
			if(case1 | case2 | case3){
				temp = important_time[j];
				important_time[j] = important_time[j+1];
				important_time[j+1] = temp;
			}
		}
	}
	
	cout<<"after sorted..."<<endl;
	print_point();
	
	// handle box key: asume 0 as null
	// init
	for(int i=0; i<N; i++){
		box_state[i] = i+1; 
	}
	
	// work
	point_time same_time[2*MAX_K];
	for(int i=0; i<2*K; i++){
		// 相同时刻，特殊处理 
		// the same time
		int num_index_same_time = 0;
		while(important_time[i].time == important_time[i+1].time){
			same_time[num_index_same_time] = important_time[i];
			num_index_same_time++;
			i++;
		}
		
		if(num_index_same_time>0){
			// deal with the same time
			for(int index=0; index<num_index_same_time; index++){
				
				// display
				// printf("[same time] time=%d, id=%d, is_back=%d \n",(same_time[index].time, same_time[index].teacher_index, same_time[index].is_back));
				// cout<<"time="<<same_time[index].time<<" ";
				// cout<<"id="<<same_time[index].teacher_index<<" ";
				// cout<<"is_back="<<same_time[index].is_back<<endl;
				
				// work
				if(same_time[index].is_back){
					fun_back_key(same_time[index].teacher_index, same_time[index].time);
				}else{
					fun_get_key(same_time[index].teacher_index, same_time[index].time);
				}
			}
		}
		
		// without the same time
		// 正常流程，不存在相同的时刻； 
		if(important_time[i].is_back){
			// back
			fun_back_key(important_time[i].teacher_index, important_time[i].time);
		}else{
			// get
			fun_get_key(important_time[i].teacher_index, important_time[i].time);
		}
	}
	
	print_box_state();
}

int main(){
	
	input();
	print_info();
	excute();
	
	return 0;
}
