#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 100

typedef struct{
	int data[MAX_SIZE];
	int length;
}Sqlist;

typedef struct LNode{
	// 单链表 
	int data;
	struct LNode *next;
}LNode;

typedef struct DLNode{
	// 双链表 
	int data;
	struct DLNode *prior;
	struct DLNode *next;
}DLNode;

typedef struct BTNode{
	// 二叉树：链式存储结构 
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

typedef struct TBTNode{
	// 线索二叉树
	// ltag=0, lchild --> 指针，指向左孩子 
	// ltag=1, lchild --> 索引，指向结点的直接前驱 
	char data;
	int ltag, rtag; // 线索标记 
	struct TBTNode *lchild;
	struct TBTNode *rchild;
}TBTNode;

// 邻接矩阵 
typedef struct{
	int no;
	char info;
}VertexType;

typedef struct{
	int edges[MAX_SIZE][MAX_SIZE];
	int n, e; // 顶点数和边数
	VertexType vex[MAX_SIZE]; 
}MGraph;

// 邻接链表
 

int main(){
	
	return 0;
} 





