#include <iostream>
#include <fstream>
using namespace std;

#define maxsize 1000
typedef int keytype;

typedef struct 
{
	keytype key;
}rcdtype;

typedef struct
{
	rcdtype r[maxsize+1];  //r[0]����  ����������
	int length;
}sqlist;

class paixu
{
	
public:
	void input(sqlist&l);
	void output(sqlist&l);
	
	int Partition( sqlist &L, int low, int high ) 
	{														//����������L.R[low..high]����һ�η��������ػ�׼λ���±�
		pivotkey=L.r[low].key;
		i=low;
		j=high;
		L.r[0]=L.r[low];
		while(i<j)
		{
			while(j>i&&L.r[j].key>=pivotkey)j--;		//iָ���׼,j����ɨ�� 
			L.r[i]=L.r[j];
			//temp=L.r[j].key;							// �Ȼ�׼С�ļ�¼�Ƶ��Ͷ�                           
			//L.r[j].key=L.r[i].key;
			//L.r[i].key=temp;
			while(i<j&&L.r[i].key<=pivotkey)i++;		//jָ���׼i����ɨ��                              
			L.r[j]=L.r[i];
			//temp=L.r[i].key;								// �Ȼ�׼��ļ�¼�Ƶ��߶�                        
			//L.r[i].key=L.r[j].key;
			//L.r[j].key=temp;
		}
		L.r[i]=L.r[0];									//��׼��λ
		return i;										//���ػ�׼��λ���±�
	}
	
	void  QSort(sqlist&L,int low,int high)  
	{												//����������L.R[low..high]���п�������
	  if(low<high) 
	  {
			pivotloc=Partition(L,low,high);				//���з��������ػ�׼�±�                              
			QSort(L,low,pivotloc-1) ;					// ����������п�������                            
			QSort(L,pivotloc+1,high) ;					// ���Ұ������п�������                            
	  }
	} 
	
	void quicksort(sqlist&l)
	{
		QSort(l,1,l.length);
	}
	
private:
	int n,i,j,k;
	int move,temp;
	int pivotkey;
	int pivotloc;
	
};

void paixu::input(sqlist&l)
{
	ifstream in_data;
	in_data.open("./data.txt");
	in_data>>l.length;
	for(i=1;i<=l.length;i++)
		in_data>>l.r[i].key;
}

void paixu::output(sqlist&l)
{
	for(i=1;i<=l.length;i++)
		cout<<l.r[i].key<<" ";
	cout<<endl;
}

int main(int argc, char* argv[])
{
	paixu p;
	sqlist l;
	p.input(l);
	cout<<"ԭ�����˳��Ϊ��"<<endl;
	p.output(l);
	
	//****************************************
	p.quicksort(l);
	cout<<"����������Ľ�����˳��Ϊ��"<<endl;
	p.output(l);

	system("pause");
	return 0;
}



