#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 100

typedef struct{
	int data[MAX_SIZE];
	int length;
}Sqlist;

typedef struct LNode{
	// ������ 
	int data;
	struct LNode *next;
}LNode;

typedef struct DLNode{
	// ˫���� 
	int data;
	struct DLNode *prior;
	struct DLNode *next;
}DLNode;

typedef struct BTNode{
	// ����������ʽ�洢�ṹ 
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

typedef struct TBTNode{
	// ����������
	// ltag=0, lchild --> ָ�룬ָ������ 
	// ltag=1, lchild --> ������ָ�����ֱ��ǰ�� 
	char data;
	int ltag, rtag; // ������� 
	struct TBTNode *lchild;
	struct TBTNode *rchild;
}TBTNode;

// �ڽӾ��� 
typedef struct{
	int no;
	char info;
}VertexType;

typedef struct{
	int edges[MAX_SIZE][MAX_SIZE];
	int n, e; // �������ͱ���
	VertexType vex[MAX_SIZE]; 
}MGraph;

// �ڽ�����
 

int main(){
	
	return 0;
} 





