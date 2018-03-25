// ����Ļ�������.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream> 
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
	
	void BubbleSort2(sqlist&L) 
	{									
		
		for(i=L.length; i>1; i--)
		{
			bool is_finished=true;    
			for(j=1; j<i; j++) 
				if(L.r[j].key>L.r[j+1].key) 
				{
					temp=L.r[j].key;
					L.r[j].key=L.r[j+1].key;
					L.r[j+1].key=temp;
					is_finished = false;
				}
			if(is_finished) return;
		}
	}
//************************************

//*************��������--�����㷨�ĸĽ�******
	int Partition(sqlist  &L, int low, int high) 
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
	void  QuickSort(sqlist&l)
	{
		QSort(l,1,l.length);
	}

//****************�����������*************************


//************ϣ������****************
	void ShellInsert(sqlist&L, int dk)
	{
		for(i=dk+1; i<=L.length; ++i)
			if(L.r[i].key < L.r[i-dk].key)
			{
				L.r[0]=L.r[i];					// �ݴ���R[0]
				for(j=i-dk; j>0 && (L.r[0].key<L.r[j].key); j-=dk)
					L.r[j+dk]=L.r[j];			// ��¼���ƣ����Ҳ���λ��
				L.r[j+dk]=L.r[0];               // ����
			}
//			output(L);
	}
	
	void ShellSort (sqlist &L, int dlta[], int t)
	{										// ����Ϊdlta[]��ϣ������
		for (k=0; k<t; ++k)
		{
			cout<<"===== dlta = "<<dlta[k]<<" ====="<<endl;
			ShellInsert(L, dlta[k]);	    //һ������Ϊdlta[k]�Ĳ�������
			output(L);
		}
			
	}										// ShellSort
//***********************************

private:
	int n,i,j,k;
	int temp;
	int pivotkey;
	int pivotloc;
	//sqlist *temp;
};
 
void paixu::input(sqlist&l)
{
	ifstream in_data;
	in_data.open("./data2.txt");
//	cout<<"�������ݸ���length��";
	in_data>>l.length;
//	cout<<"���������length������"<<endl;
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
	sqlist l1, l2, l3;
	
	p.input(l1);
	p.BubbleSort2(l1);
	cout<<"��ð��������˳��Ϊ��"<<endl;
	p.output(l1);
	
	p.input(l2);
	p.QuickSort(l2);
	cout<<"����������Ľ�����˳��Ϊ��"<<endl;
	p.output(l2);
	
	p.input(l3);
	int a[3] = {5,3,1};
	cout<<"��ϣ��������˳��Ϊ��"<<endl;
	p.ShellSort(l3, a, 3);
	p.output(l3);

	system("pause");
	return 0;
}
