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
	rcdtype r[maxsize+1];  //r[0]置闲  用作岗哨项
	int length;
}sqlist;

class paixu
{
	
public:
	void input(sqlist&l);
	void output(sqlist&l);
	
	int Partition( sqlist &L, int low, int high ) 
	{														//对排序区间L.R[low..high]进行一次分区，返回基准位置下标
		pivotkey=L.r[low].key;
		i=low;
		j=high;
		L.r[0]=L.r[low];
		while(i<j)
		{
			while(j>i&&L.r[j].key>=pivotkey)j--;		//i指向基准,j向左扫描 
			L.r[i]=L.r[j];
			//temp=L.r[j].key;							// 比基准小的记录移到低端                           
			//L.r[j].key=L.r[i].key;
			//L.r[i].key=temp;
			while(i<j&&L.r[i].key<=pivotkey)i++;		//j指向基准i向右扫描                              
			L.r[j]=L.r[i];
			//temp=L.r[i].key;								// 比基准大的记录移到高端                        
			//L.r[i].key=L.r[j].key;
			//L.r[j].key=temp;
		}
		L.r[i]=L.r[0];									//基准到位
		return i;										//返回基准的位置下标
	}
	
	void  QSort(sqlist&L,int low,int high)  
	{												//对排序区间L.R[low..high]进行快速排序
	  if(low<high) 
	  {
			pivotloc=Partition(L,low,high);				//进行分区，返回基准下标                              
			QSort(L,low,pivotloc-1) ;					// 对左半区进行快速排序                            
			QSort(L,pivotloc+1,high) ;					// 对右半区进行快速排序                            
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
	cout<<"原数组的顺序为："<<endl;
	p.output(l);
	
	//****************************************
	p.quicksort(l);
	cout<<"经快速排序改进版后的顺序为："<<endl;
	p.output(l);

	system("pause");
	return 0;
}



