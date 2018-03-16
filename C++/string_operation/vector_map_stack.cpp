// 栈_队列_vector_map_algorithm.cpp : 定义控制台应用程序的入口点。
//
// reference http://blog.csdn.net/google19890102/article/details/51701144


#include "vector_map_stack.h"

void Container_test::show_algorithm()
{
	
}

void Container_test::show_map()
{
/*
	标准库map类型是一种以键-值(key-value)存储的数据类型
	1. map对象的定义和初始化
	2. map对象的基本操作，主要包括添加元素，遍历等
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
	queue 的基本操作有：
	1. 入队，如例：q.push(x); 将x 接到队列的末端。
	2. 出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。
	3. 访问队首元素，如例：q.front()，即最早被压入队列的元素。
	4. 访问队尾元素，如例：q.back()，即最后被压入队列的元素。
	5. 判断队列空，如例：q.empty()，当队列空时，返回true。
	6. 访问队列中的元素个数，如例：q.size()
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
	stack(堆栈）是一个容器的改编，它实现了一个先进后出的数据结构
	1. 入栈：如s.push(x);
	2. 出栈:如 s.pop().注意：出栈操作只是删除栈顶的元素，并不返回该元素。
	3. 访问栈顶：如s.top();
	4. 判断栈空：如s.empty().当栈空时返回true.
	5. 访问栈中的元素个数，如s.size（）;
*/
	stack<double>s;
	for(int i=0;i<10;i++)  
		s.push(i);  
	while(!s.empty())  
	{  
		printf("%lf\n",s.top());  
		s.pop();  
	}  
	cout<<"栈内的元素的个数为："<<s.size()<<endl; 

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

