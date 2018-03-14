#ifndef _DFS_H_  
#define _DFS_H_  
	/* 1. ͼ - �ڽӾ����ʾ�� */
	/* ---------------------------------------------------------------- */
	/* �����Ƶ����ݽṹ
	#define VRType int
	#define InfoType int
	#define VertexType char
	#define max_n 20
	typedef enum{DG, DN, AG, AN} GraphKind;

	// ���������������
	typedef struct { 
		VRType    adj;			//VRTypeΪ�������͡�ͼ--0,1;��--Ȩֵ
		InfoType  *Info; 		//�뻡��ص���Ϣ��ָ��,��ʡ��
	}ArcCell, AdjMatrix[max_n][max_n];

	// ͼ������
	typedef struct{		
		VertexType vexs[max_n];		// ��������
		AdjMatrix  arcs;		// �ڽӾ���
		int        vexnum, arcnum;	// ������������
		GraphKind  kind;		// ͼ����
	}MGraph; 	
	 */
	/* ---------------------------------------------------------------- */

	/* �򻯵����ݽṹ */
	#define max_vexNum 26	// �����и���
	#define MAX_PATH_LENGTH 9999999
	typedef struct{
		int vex_num, arc_num;			// ������ ����
		char vexs[max_vexNum];			// ��������
		double arcs[max_vexNum][max_vexNum];	// �ڽӾ���
	}Graph;

	void CreateGraph(Graph &G);
	void DFS_Traverse(Graph G);
	void DFS(Graph G, char city_start);	// ������ȱ��� - stack
	void BFS(Graph G);				// ������ȱ���	- queue

	bool is_visited[max_vexNum];			// �洢��ǰ�����Ƿ��ѱ�����
	char path_DFS[MAX_PATH_LENGTH][max_vexNum];	// �洢����·��
	double lenth_DFS[MAX_PATH_LENGTH];		// �洢����·����Ӧ�ĳ���

	long int path_num = 0, path_index = 0;
	long double bestLength = MAX_PATH_LENGTH + 0.0;	// ���·����ʼ��Ϊ�����

	// ���ܺ���
	void CreateGraph(Graph &G);
	int _findCityIndex(Graph G, char city_start);
	void DFS(Graph G, char city_start);

#endif  //_BP_H_ 
