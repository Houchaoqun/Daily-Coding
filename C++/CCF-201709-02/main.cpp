#include <iostream>
#include <fstream>
using namespace std;

//CCF-CSP
//�����ţ�	201709-2
//�������ƣ�	����Կ�׺�
//ʱ�����ƣ�	1.0s
//�ڴ����ƣ�	256.0MB

//��������
//������һ��ѧУ����ʦ����N�����ң����չ涨�����е�Կ�׶�������ڹ���Կ�׺����ʦ���ܴ�Կ�׻ؼҡ�ÿ����ʦ�Ͽ�ǰ�����ӹ���Կ�׺����ҵ��Լ��ϿεĽ��ҵ�Կ��ȥ���ţ�����κ��ٽ�Կ�׷Żص�Կ�׺��С�
//����Կ�׺�һ����N���ҹ����������ų�һ�ţ�������N�����ҵ�Կ�ס�һ��Կ��û�й̶�������λ�ã���Կ�����б�ʶ��������ʦ�ǲ���Ū��Կ�ס�
//����ÿ��ȡԿ�׵�ʱ����ʦ�Ƕ����ҵ��Լ�����Ҫ��Կ�׽���ȡ�ߣ��������ƶ�����Կ�ס�ÿ�λ�Կ�׵�ʱ�򣬻�Կ�׵���ʦ���ҵ�����ߵĿյĹҹ�����Կ�׹�������ҹ��ϡ�����ж�λ��ʦ��Կ�ף������ǰ�Կ�ױ�Ŵ�С�����˳�򻹡����ͬһʱ�̼�����ʦ��Կ��������ʦȡԿ�ף�����ʦ�ǻ��Ƚ�Կ��ȫ����ȥ��ȡ����
//�������쿪ʼ��ʱ��Կ���ǰ���Ŵ�С�����˳�����Կ�׺���ġ���Kλ��ʦҪ�ϿΣ�����ÿλ��ʦ����Ҫ��Կ�ס���ʼ�Ͽε�ʱ����Ͽε�ʱ���������¿�ʱ����ǻ�Կ��ʱ�䣬��������Կ�׺�����Կ�׵�˳���������ģ�
//�����ʽ
//��������ĵ�һ�а�����������N, K��
//����������K�У�ÿ����������w, s, c���ֱ��ʾһλ��ʦҪʹ�õ�Կ�ױ�š���ʼ�Ͽε�ʱ����Ͽε�ʱ���������ж�λ��ʦʹ��ͬһ��Կ�ף�������ʦʹ��Կ�׵�ʱ�䲻���ص���
//������֤�����������������ʽ���㲻�ü�����ݺϷ��ԡ�
//�����ʽ
//�������һ�У�����N��������������������һ���ո�ָ������α�ʾÿ���ҹ��Ϲҵ�Կ�ױ�š�

// ���ߣ�houchaoqun 
// ʱ�䣺20180312 
// ˼·��
// 1. �Ϲ�أ�ʹ���ļ���д�ķ�ʽ�������ݣ���д������ void input(); �Լ��������ĺ����� 
// 2. �Ķ���Ŀ����⣺
//    1) ����Կ�׺г�ʼ��˳��Ϊ��1,2 ... N; ����K����ʦ�Ͽ���Կ�׵�����������󹫹�Կ�׺е�˳�� 
//    2) ÿ����ʦ��3���ؼ��ֶΣ�ʹ�õ�Կ�ױ�ţ���ʼ�Ͽε�ʱ�䣻�Ͽε�ʱ���� 
//    3) ���ÿ����ʦ������������Կ�׵�ʱ�̣��ֱ��ǡ�ȡԿ�ס��� ����Կ�ס�������2K��ʱ�̣��ֱ�����������ʵ�ֶ�Ӧ���ܣ�void fun_back_key(int key_id, int time); void fun_get_key(int key_id, int time); 
//    4)  fun_back_key(): ��Կ��ʱ��Կ�׺�����ߵĿչҹ��Ż����ã�
//    5) ��� point_time�ṹ���ʾÿ������Կ�׵�ʱ�̣�����Կ�ױ�š���Կ�׵Ĳ������ĸ�ʱ�̵��ֶΣ�
//    6)  point_time important_time[2*MAX_K]; ��ʾ2K���������ȶ�ÿ��������ʱ���Դ�С�����˳���������
//    7)  ʹ��ð�����������������Ҫ����ǰ������������λ�ã�case1, case2, case3��������˵���� 
// 3. �����������
//    1) ���ͬһʱ�̼�����ʦ��Կ��������ʦȡԿ�ף�����ʦ�ǻ��Ƚ�Կ��ȫ����ȥ��ȡ������Կ�����ȡ� 
//    2) ��ͬһʱ���ж����ʦͬʱ��Կ�ף������ǰ�Կ�ױ�Ŵ�С�����˳�򻹡�
//  
// �����������£� 
// 1.��ȡ�û��������ر�����������صĽṹ�壻 
// 2.������2K������Կ�׵�ʱ�̣�point_time important_time[2*MAX_K];
// 3.����ʱ�̣�����С����� important_time[2*MAX_K] ʹ��ð������ע����������Ĵ�����ͬʱ�� 2������ԭ�� 
// 4.��ʼ������Կ�׺е�˳��int box_state[MAX_N];
// 5.�ֱ��2K��ʱ�̽���Կ�׵�ģ�������ע�⿼�������������� important_time[] ������ͬ��ʱ�̣������������ԭ����д��� 
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
			// ��ͬʱ�̵������ǰ�ߵ�ʱ�̴��ں��ߵ�ʱ�� 
			case1 = (important_time[j].time > important_time[j+1].time);
			// ͬһ��ʱ�̣�ǰ��������ʦ�Ĳ����ֱ��ǻ���ȡ����Ϊ���ȵ�ԭ�� 
			case2 = (important_time[j].time == important_time[j+1].time && important_time[j].is_back == false && important_time[j+1].is_back == true);
			// ͬһ�����ǣ�ǰ��������ʦ���ǻ�Կ�ף���ǰ��������Կ�ױ��С�ں��ߵ�Կ�ױ�ţ�Կ�ױ��С�����Ȼ��� 
			case3 = (important_time[j].time == important_time[j+1].time && important_time[j].is_back == true && important_time[j+1].is_back == true && important_time[j].teacher_index > important_time[j+1].teacher_index);  // ����ж�λ��ʦ��Կ�ף������ǰ�Կ�ױ�Ŵ�С�����˳��
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
		// ��ͬʱ�̣����⴦�� 
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
		// �������̣���������ͬ��ʱ�̣� 
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
