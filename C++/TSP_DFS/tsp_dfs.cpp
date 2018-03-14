#include <iostream>
#include <stdlib.h> 
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>	// 本文用于输出对齐

#include "tsp_dfs.h"

using namespace std;

ofstream DFS_fout("./city_10_out_2.txt");

int main(){
	cout<<"程序开始..."<<endl;
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
		// cout<<"对应的路程lenth_DFS[] = "<<lenth_DFS[i]<<endl;
		// DFS_fout<<"对应的路程lenth_DFS[] = "<<lenth_DFS[i]<<endl;
	}

	// DFS_fout<<"最短路程bestLength = "<<bestLength<<endl;
	cout<<"最短路程bestLength = "<<bestLength<<endl;

	time_t T_end = clock();
	double RunningTime = double(T_end - T_begin)/CLOCKS_PER_SEC;
	// DFS_fout<<"程序运行时间 RunningTime = "<<RunningTime<<endl;
	cout<<"程序运行时间 RunningTime = "<<RunningTime<<endl;
	system("pause");
	return 0;
}

void CreateGraph(Graph &G){
	ifstream read_in;
	read_in.open("./city10.txt");
	if (!read_in.is_open())
	{
		cout<<"文件读取失败."<<endl;
		return;
	}
	
	read_in >> G.vex_num;

	G.arc_num = 0;
	for (int i = 0;i < G.vex_num; i++)
	{
		read_in >> G.vexs[i];
	}
	G.vexs[G.vex_num] = '\0';	// char的结束符.

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
	cout<<"无向图创建完毕，相关信息如下："<<endl;
	cout<<"【顶点数】 G.vex_num = "<<G.vex_num<<endl;
	cout<<"【边数】 G.arc_num = "<<G.arc_num<<endl;
	cout<<"【顶点向量】 vexs[max_vexNum] = ";
	for (int i = 0; i < G.vex_num; i++)
	{
		cout<<G.vexs[i]<<" ";
	}
	cout<<endl<<"【邻接矩阵】 arcs[max_vexNum][max_vexNum] 如下："<<endl;
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
	cout<<"【error】当前城市未找到！"<<endl;
	return -1;
}

void DFS(Graph G, char city_start){
	int v_index = _findCityIndex(G, city_start);	// 起始城市,每次调用（递归）都更新.

	if (path_index == G.vex_num - 1 && G.arcs[v_index][int('A') - 65] > 0)
	{
		path_DFS[path_num][path_index] = city_start;
		path_DFS[path_num][path_index + 1] = 'A';   // A为起始城市
		lenth_DFS[path_num] = 0;	// 存储最短路径

		// 计算最短路径
		for (int i = 0; i < G.vex_num; i++)
		{
			lenth_DFS[path_num] += G.arcs[(int)path_DFS[path_num][i] - 65][(int)path_DFS[path_num][i+1] - 65];
		}

		if (bestLength > lenth_DFS[path_num])
		{
			// 更新最短路径
			bestLength = lenth_DFS[path_num];
		}

		DFS_fout << "第【" << (path_num + 1) << "】条路径！" << endl;
		path_num++;	// 下一条路径
		// 初始化下一次路径与上一次相同
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
