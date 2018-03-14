#include <iostream>
#include <fstream>
#include <iomanip>	// ���������������
using namespace std;

#define max_vexNum 26    // �����и���  
#define MAX_PATH_LENGTH 9999999  

typedef struct{  
    int vex_num, arc_num;                  // ������ ����  
    char vexs[max_vexNum];                 // ��������  
    double arcs[max_vexNum][max_vexNum];   // �ڽӾ���  
}Graph;  


void CreateGraph(Graph &G){  
    ifstream read_in;  
    read_in.open("./city10.txt");  
    if (!read_in.is_open())  
    {  
        cout<<"�ļ���ȡʧ��."<<endl;  
        return;  
    }  
      
    read_in >> G.vex_num;  
    // read_in >> G.arc_num;  
    G.arc_num = 0;  
    for (int i = 0;i < G.vex_num; i++)  
    {  
        read_in >> G.vexs[i];  
    }  
    G.vexs[G.vex_num] = '\0';    // char�Ľ�����.  
  
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

int main(){
	Graph G;
	CreateGraph(G);
}


