// 排序的基本操作.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
#define maxsize 1000
typedef int keytype;

typedef struct 
{
	keytype key;
	//infotype otherinfo;
}rcdtype;

typedef struct
{
	rcdtype r[maxsize+1];  //r[0]置闲  用作岗哨项
	int length;
}sqlist;

//********排序的基本操作类***********
class paixu
{
public:
	void input(sqlist&l);
	void output(sqlist&l);
	
//************希尔排序****************
	void shellinsert(sqlist&L,int dk)
	{
	for(i=dk+1;i<=n;++i)
		if(L.r[i].key<L.r[i-dk].key)
		{
			L.r[0]=L.r[i];					// 暂存在R[0]
			for(j=i-dk;j>0&&(L.r[0].key<L.r[j].key);j-=dk)
				L.r[j+dk]=L.r[j];			// 记录后移，查找插入位置
			L.r[j+dk]=L.r[0];               // 插入
		}									// if
	}										// ShellInsert
	void ShellSort (sqlist &L, int dlta[], int t)
	{										// 增量为dlta[]的希尔排序
	for (k=0; k<t; ++k)
		shellinsert(L, dlta[k]);			//一趟增量为dlta[k]的插入排序
	}										// ShellSort
//***********************************


//***********冒泡排序****************
	void BubbleSort(sqlist&L) 
	{										//对顺序表L作冒泡排序
		//for(i=1;i<=L.length;i++)
		//	cin>>L.r[i].key;
		for(i=2;i<=L.length;i++)
		{									//进行n－1趟扫描
			// cout<<"length"<<L.length<<endl;
			bool is_finished=true;							//move是交换与否的标志     
			for(j=L.length;j>=i;j--) 
				if(L.r[j].key<L.r[j-1].key) 
				{							//如逆序则交换 
					temp=L.r[j].key;
					L.r[j].key=L.r[j-1].key;
					L.r[j-1].key=temp;
					is_finished = false;
				}
				//cout<<L.r[i].key<<" ";
			if(is_finished)return;				//如果没有移动发生，则结束
		}
	}
//************************************

//*************快速排序--分区算法的改进******
	int Partition( sqlist  &L, int low, int high ) 
	{															//对排序区间L.R[low..high]进行一次分区，返回基准位置下标
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
//**********对low，high区间的快速排序算法*************
	void  QSort(sqlist&L,int low,int high)  
	{													//对排序区间L.R[low..high]进行快速排序
	  if(low<high) 
	  {
			pivotloc=Partition(L,low,high);				//进行分区，返回基准下标                              
			QSort(L,low,pivotloc-1) ;					// 对左半区进行快速排序                            
			QSort(L,pivotloc+1,high) ;					// 对右半区进行快速排序                            
	  }
} 
//**********对整个顺序表进行快速排序算法**************
	void quicksort(sqlist&l)
	{
		QSort(l,1,l.length);
	}

//****************快速排序结束*************************


private:
	int n,i,j,k;
	int temp;
	int pivotkey;
	int pivotloc;
	//sqlist *temp;
};
 
void paixu::input(sqlist&l)
{
	cout<<"输入数据个数length：";
	cin>>l.length;
	cout<<"输入无序的length个数："<<endl;
	for(i=1;i<=l.length;i++)
		cin>>l.r[i].key;
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
	//****************************************
	p.BubbleSort(l);
	cout<<"经冒泡排序后的顺序为："<<endl;
	p.output(l);
	
	//****************************************
	p.quicksort(l);
	cout<<"经快速排序改进版后的顺序为："<<endl;
	p.output(l);
	
	//****************************************
	int a[3]={1,3,5};
	p.ShellSort(l,a,l.length);
	cout<<"经希尔排序后的顺序为："<<endl;
	p.output(l);

	system("pause");
	return 0;
}
