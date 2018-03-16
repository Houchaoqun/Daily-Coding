// ջ_����_vector_map_algorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//
// reference http://blog.csdn.net/google19890102/article/details/51701144


#include "vector_map_stack.h"

void Container_test::show_algorithm()
{
	
}

void Container_test::show_map()
{
/*
	��׼��map������һ���Լ�-ֵ(key-value)�洢����������
	1. map����Ķ���ͳ�ʼ��
	2. map����Ļ�����������Ҫ�������Ԫ�أ�������
*/
	// insert:
	map<int, int> mp;
	for (int i = 0; i < 10; i++){
		mp[i] = i;
	}
	for (int i = 10; i < 20; i++){
		mp.insert(make_pair(i, i));
	}
	map<int, int>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++){
		printf("%d-->%d\n", it->first, it->second);
	}
	cout<<"================================================="<<endl;
	map<int, int> mp2;
	for (int i = 0; i < 20; i++){
		mp2.insert(make_pair(i, i));
	}

	if (mp2.count(0)){
		printf("yes!\n");
	}else{
		printf("no!\n");
	}

	map<int, int>::iterator it_find;
	it_find = mp2.find(0);
	if (it_find != mp2.end()){
		it_find->second = 20;
	}else{
		printf("no!\n");
	}

	map<int, int>::iterator it2;
	for (it2 = mp2.begin(); it2 != mp2.end(); it2++){
		printf("%d->%d\n", it2->first, it2->second);
	}
}

void Container_test::show_queue()
{
/*
	queue �Ļ��������У�
	1. ��ӣ�������q.push(x); ��x �ӵ����е�ĩ�ˡ�
	2. ���ӣ�������q.pop(); �������еĵ�һ��Ԫ�أ�ע�⣬�����᷵�ر�����Ԫ�ص�ֵ��
	3. ���ʶ���Ԫ�أ�������q.front()�������类ѹ����е�Ԫ�ء�
	4. ���ʶ�βԪ�أ�������q.back()�������ѹ����е�Ԫ�ء�
	5. �ж϶��пգ�������q.empty()�������п�ʱ������true��
	6. ���ʶ����е�Ԫ�ظ�����������q.size()
*/

	int e,n,m;
	queue<int> q1;

	for(int i=0;i<10;i++){
		q1.push(i);
	}

	if(!q1.empty()){
		cout<<"It's not empty.\n";
	}

	n=q1.size();
	cout<<n<<endl;

	m=q1.back();
	cout<<m<<endl;

	for(int j=0;j<n;j++)
	{
		e=q1.front();
		cout<<e<<" ";
		q1.pop();
	}
	cout<<endl;
	if(q1.empty()){
		cout<<"It's empty.\n";
	}

}

void Container_test::show_stack()
{
/*
	stack(��ջ����һ�������ĸı࣬��ʵ����һ���Ƚ���������ݽṹ
	1. ��ջ����s.push(x);
	2. ��ջ:�� s.pop().ע�⣺��ջ����ֻ��ɾ��ջ����Ԫ�أ��������ظ�Ԫ�ء�
	3. ����ջ������s.top();
	4. �ж�ջ�գ���s.empty().��ջ��ʱ����true.
	5. ����ջ�е�Ԫ�ظ�������s.size����;
*/
	stack<double>s;
	for(int i=0;i<10;i++)  
		s.push(i);  
	while(!s.empty())  
	{  
		printf("%lf\n",s.top());  
		s.pop();  
	}  
	cout<<"ջ�ڵ�Ԫ�صĸ���Ϊ��"<<s.size()<<endl; 

}


void Container_test::show_vector()
{
	vector<int>v;	// Initial vector - null
	v.push_back(1);
	cout<<"vector's size = "<<v.size()<<endl;
	cout<<"vector's value of 0 position = "<<v[0]<<endl;
	v.pop_back();
	cout<<v.size()<<endl;
	//cout<<v[0]<<endl;

	// examples
	vector<int>example;
	for (int i = 0; i < 10; i++){
		example.push_back(i);
		cout<<example[i]<<" ";
	}
	cout<<endl;
	
	// insert delete traverse
	// insert: push_back() and insert()
	cout<<"before insert() = "<<example[0]<<endl;
	example.insert(example.begin(), -1);
	cout<<"after insert() = "<<example[0]<<endl;

	// delete: erase() and clear() and pop_back()
	int i = 0;
	vector<int>::iterator it;
	for (it = example.begin(); it != example.end(); it++){
		i++ ;
		if (i == 2){
			example.erase(it);
			break;
		}
	}

	// Traverse
	vector<int> example2;
	for (int i = 0; i < 10; i++){
		example2.push_back(i);
	}
	// according to index    
	for (vector<int>::size_type ix = 0; ix != example2.size(); ix ++){
		printf("%d\t", example2[ix]);
	}
	printf("\n");

	// according to iterator
	vector<int>::iterator it2;
	for (it2 = example2.begin(); it2 != example2.end(); it2 ++){
		printf("%d\t", *it2);
	}
	printf("\n");

}

int main()
{
	Container_test tContainer_test;
	// tContainer_test.show_vector();
	// tContainer_test.show_map();
	// tContainer_test.show_stack();
	tContainer_test.show_queue();


	// system("pause");
	getchar();
	return 0;
}

