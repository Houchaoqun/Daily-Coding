// ����Ļ�������.cpp : Defines the entry point for the console application.
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
	rcdtype r[maxsize+1];  //r[0]����  ����������
	int length;
}sqlist;

//********����Ļ���������***********
class paixu
{
public:
	void input(sqlist&l);
	void output(sqlist&l);
	
//************ϣ������****************
	void shellinsert(sqlist&L,int dk)
	{
	for(i=dk+1;i<=n;++i)
		if(L.r[i].key<L.r[i-dk].key)
		{
			L.r[0]=L.r[i];					// �ݴ���R[0]
			for(j=i-dk;j>0&&(L.r[0].key<L.r[j].key);j-=dk)
				L.r[j+dk]=L.r[j];			// ��¼���ƣ����Ҳ���λ��
			L.r[j+dk]=L.r[0];               // ����
		}									// if
	}										// ShellInsert
	void ShellSort (sqlist &L, int dlta[], int t)
	{										// ����Ϊdlta[]��ϣ������
	for (k=0; k<t; ++k)
		shellinsert(L, dlta[k]);			//һ������Ϊdlta[k]�Ĳ�������
	}										// ShellSort
//***********************************


//***********ð������****************
	void BubbleSort(sqlist&L) 
	{										//��˳���L��ð������
		//for(i=1;i<=L.length;i++)
		//	cin>>L.r[i].key;
		for(i=2;i<=L.length;i++)
		{									//����n��1��ɨ��
			// cout<<"length"<<L.length<<endl;
			bool is_finished=true;							//move�ǽ������ı�־     
			for(j=L.length;j>=i;j--) 
				if(L.r[j].key<L.r[j-1].key) 
				{							//�������򽻻� 
					temp=L.r[j].key;
					L.r[j].key=L.r[j-1].key;
					L.r[j-1].key=temp;
					is_finished = false;
				}
				//cout<<L.r[i].key<<" ";
			if(is_finished)return;				//���û���ƶ������������
		}
	}
//************************************

//*************��������--�����㷨�ĸĽ�******
	int Partition( sqlist  &L, int low, int high ) 
	{															//����������L.R[low..high]����һ�η��������ػ�׼λ���±�
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
//**********��low��high����Ŀ��������㷨*************
	void  QSort(sqlist&L,int low,int high)  
	{													//����������L.R[low..high]���п�������
	  if(low<high) 
	  {
			pivotloc=Partition(L,low,high);				//���з��������ػ�׼�±�                              
			QSort(L,low,pivotloc-1) ;					// ����������п�������                            
			QSort(L,pivotloc+1,high) ;					// ���Ұ������п�������                            
	  }
} 
//**********������˳�����п��������㷨**************
	void quicksort(sqlist&l)
	{
		QSort(l,1,l.length);
	}

//****************�����������*************************


private:
	int n,i,j,k;
	int temp;
	int pivotkey;
	int pivotloc;
	//sqlist *temp;
};
 
void paixu::input(sqlist&l)
{
	cout<<"�������ݸ���length��";
	cin>>l.length;
	cout<<"���������length������"<<endl;
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
	cout<<"��ð��������˳��Ϊ��"<<endl;
	p.output(l);
	
	//****************************************
	p.quicksort(l);
	cout<<"����������Ľ�����˳��Ϊ��"<<endl;
	p.output(l);
	
	//****************************************
	int a[3]={1,3,5};
	p.ShellSort(l,a,l.length);
	cout<<"��ϣ��������˳��Ϊ��"<<endl;
	p.output(l);

	system("pause");
	return 0;
}
