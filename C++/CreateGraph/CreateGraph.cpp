#include <iostream>
#include <fstream>
#include <iomanip>	// 本文用于输出对齐
using namespace std;

#define max_vexNum 26    // 最大城市个数  
#define MAX_PATH_LENGTH 9999999  

typedef struct{  
    int vex_num, arc_num;                  // 顶点数 边数  
    char vexs[max_vexNum];                 // 顶点向量  
    double arcs[max_vexNum][max_vexNum];   // 邻接矩阵  
}Graph;  


void CreateGraph(Graph &G){  
    ifstream read_in;  
    read_in.open("./city10.txt");  
    if (!read_in.is_open())  
    {  
        cout<<"文件读取失败."<<endl;  
        return;  
    }  
      
    read_in >> G.vex_num;  
    // read_in >> G.arc_num;  
    G.arc_num = 0;  
    for (int i = 0;i < G.vex_num; i++)  
    {  
        read_in >> G.vexs[i];  
    }  
    G.vexs[G.vex_num] = '\0';    // char的结束符.  
  
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

int main(){
	Graph G;
	CreateGraph(G);
}


