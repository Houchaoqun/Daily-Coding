#ifndef _DFS_H_  
#define _DFS_H_  
	/* 1. 图 - 邻接矩阵表示法 */
	/* ---------------------------------------------------------------- */
	/* 较完善的数据结构
	#define VRType int
	#define InfoType int
	#define VertexType char
	#define max_n 20
	typedef enum{DG, DN, AG, AN} GraphKind;

	// 弧结点与矩阵的类型
	typedef struct { 
		VRType    adj;			//VRType为弧的类型。图--0,1;网--权值
		InfoType  *Info; 		//与弧相关的信息的指针,可省略
	}ArcCell, AdjMatrix[max_n][max_n];

	// 图的类型
	typedef struct{		
		VertexType vexs[max_n];		// 顶点向量
		AdjMatrix  arcs;		// 邻接矩阵
		int        vexnum, arcnum;	// 顶点数，边数
		GraphKind  kind;		// 图类型
	}MGraph; 	
	 */
	/* ---------------------------------------------------------------- */

	/* 简化的数据结构 */
	#define max_vexNum 26	// 最大城市个数
	#define MAX_PATH_LENGTH 9999999
	typedef struct{
		int vex_num, arc_num;			// 顶点数 边数
		char vexs[max_vexNum];			// 顶点向量
		double arcs[max_vexNum][max_vexNum];	// 邻接矩阵
	}Graph;

	void CreateGraph(Graph &G);
	void DFS_Traverse(Graph G);
	void DFS(Graph G, char city_start);	// 深度优先遍历 - stack
	void BFS(Graph G);				// 广度优先遍历	- queue

	bool is_visited[max_vexNum];			// 存储当前城市是否已被访问
	char path_DFS[MAX_PATH_LENGTH][max_vexNum];	// 存储所有路径
	double lenth_DFS[MAX_PATH_LENGTH];		// 存储所有路径对应的长度

	long int path_num = 0, path_index = 0;
	long double bestLength = MAX_PATH_LENGTH + 0.0;	// 最短路径初始化为无穷大

	// 功能函数
	void CreateGraph(Graph &G);
	int _findCityIndex(Graph G, char city_start);
	void DFS(Graph G, char city_start);

#endif  //_BP_H_ 
