#include <iostream>
#include <fstream>

using namespace std;

#define MAX 1000
static int n=0;
static int totalWeight=0;

typedef struct
{
	int ID;
	float weight;
	float valued;
}Array;

Array object[MAX];

void display()
{
	for (int i=0;i<n;i++)
	{
		cout<<object[i].ID<<"  "<<object[i].valued<<"  "<<object[i].weight<<"  valued/weight="<<object[i].valued/object[i].weight<<endl;
	}
}

void getArray()
{
	cin>>totalWeight;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		object[i].ID=i;
		cin>>object[i].valued;
	}

	for (int i=0;i<n;i++)
	{
		cin>>object[i].weight;
	}
//	display();
}

void sort()
{
	// getArray();
	Array temp;
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if ((object[i].valued/object[i].weight)<(object[j].valued/object[j].weight))
			{
				temp=object[i];
				object[i]=object[j];
				object[j]=temp;
			}
		}
	}
	display();
}

int excute(){
	// 
	
	
	return 0;
}

int main(){
	getArray();
	sort();
	return 0;
}
