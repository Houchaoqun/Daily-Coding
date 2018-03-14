#include <iostream>
#include <stdlib.h> 
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>	// ���������������

#include "tsp_dfs.h"

using namespace std;

ofstream DFS_fout("./city_10_out_2.txt");

int main(){
	cout<<"����ʼ..."<<endl;
	time_t T_begin = clock();

	Graph G;
	CreateGraph(G);

	for (int i = 0; i < G.vex_num; i++)
	{
		is_visited[i] = false;
	}

	char city_start = 'A';
	DFS(G, city_start);


	for (int i = 0; i < path_num; i++)
	{
		for (int j = 0; j <= G.vex_num; j++)
		{
			// cout<<path_DFS[i][j]<<" ";
			// DFS_fout<<path_DFS[i][j]<<" ";
		}
		// cout<<"��Ӧ��·��lenth_DFS[] = "<<lenth_DFS[i]<<endl;
		// DFS_fout<<"��Ӧ��·��lenth_DFS[] = "<<lenth_DFS[i]<<endl;
	}

	// DFS_fout<<"���·��bestLength = "<<bestLength<<endl;
	cout<<"���·��bestLength = "<<bestLength<<endl;

	time_t T_end = clock();
	double RunningTime = double(T_end - T_begin)/CLOCKS_PER_SEC;
	// DFS_fout<<"��������ʱ�� RunningTime = "<<RunningTime<<endl;
	cout<<"��������ʱ�� RunningTime = "<<RunningTime<<endl;
	system("pause");
	return 0;
}

void CreateGraph(Graph &G){
	ifstream read_in;
	read_in.open("./city10.txt");
	if (!read_in.is_open())
	{
		cout<<"�ļ���ȡʧ��."<<endl;
		return;
	}
	
	read_in >> G.vex_num;

	G.arc_num = 0;
	for (int i = 0;i < G.vex_num; i++)
	{
		read_in >> G.vexs[i];
	}
	G.vexs[G.vex_num] = '\0';	// char�Ľ�����.

	for (int i = 0; i < G.vex_num;i++)
	{
		for (int j = 0; j < G.vex_num; j++)
		{
			read_in >> G.arcs[i][j];

			// calculate the arc_num
			if (G.arcs[i][j] > 0)
			{
				G.arc_num++;
			}
		}
	}

	// display
	cout<<"����ͼ������ϣ������Ϣ���£�"<<endl;
	cout<<"���������� G.vex_num = "<<G.vex_num<<endl;
	cout<<"�������� G.arc_num = "<<G.arc_num<<endl;
	cout<<"������������ vexs[max_vexNum] = ";
	for (int i = 0; i < G.vex_num; i++)
	{
		cout<<G.vexs[i]<<" ";
	}
	cout<<endl<<"���ڽӾ��� arcs[max_vexNum][max_vexNum] ���£�"<<endl;
	for (int i = 0; i < G.vex_num;i++)
	{
		for (int j = 0; j < G.vex_num; j++)
		{
			cout << std::right<<setw(10) << G.arcs[i][j]<<" ";
		}
		cout<<endl;
	}
}

int _findCityIndex(Graph G, char city_start){
	for (int i = 0; i < G.vex_num;i++)
	{
		if (G.vexs[i] == city_start)
		{
			return i;
		}
	}
	cout<<"��error����ǰ����δ�ҵ���"<<endl;
	return -1;
}

void DFS(Graph G, char city_start){
	int v_index = _findCityIndex(G, city_start);	// ��ʼ����,ÿ�ε��ã��ݹ飩������.

	if (path_index == G.vex_num - 1 && G.arcs[v_index][int('A') - 65] > 0)
	{
		path_DFS[path_num][path_index] = city_start;
		path_DFS[path_num][path_index + 1] = 'A';   // AΪ��ʼ����
		lenth_DFS[path_num] = 0;	// �洢���·��

		// �������·��
		for (int i = 0; i < G.vex_num; i++)
		{
			lenth_DFS[path_num] += G.arcs[(int)path_DFS[path_num][i] - 65][(int)path_DFS[path_num][i+1] - 65];
		}

		if (bestLength > lenth_DFS[path_num])
		{
			// �������·��
			bestLength = lenth_DFS[path_num];
		}

		DFS_fout << "�ڡ�" << (path_num + 1) << "����·����" << endl;
		path_num++;	// ��һ��·��
		// ��ʼ����һ��·������һ����ͬ
		for (int i = 0; i < G.vex_num;i++)
		{
			path_DFS[path_num][i] = path_DFS[path_num-1][i];
		}
		return;
	}
	else
	{
		for (int i = 0; i < G.vex_num; i++)
		{
			if (G.arcs[v_index][i] > 0 && !is_visited[i])
			{
				path_DFS[path_num][path_index] = city_start;
				path_index++;
				is_visited[v_index] = true;
				DFS(G, (char)(i + 65));
				path_index--;
				is_visited[v_index] = false;
			}
		}
	}

}
