#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void display(string ss){
	cout<<ss<<endl;
}

void init(){
	string s;
	string s1("hello world.");
	string s2(s1);		//s2是s1的副本
    string s3=s2;		//s3是s2的副本
    string s4(10,'c');	//把s4初始化   10个c 
    string s5="hiya";	//拷贝初始化
    string s6=string(10,'c');//拷贝初始化，生成一个初始化好的对象，拷贝给s6
	
    //string s(cp,n)
    char cs[]="12345";
    string s7(cs,3);	  //复制字符串cs的前3个字符到s当中

    //string s(s2,pos2)
    string s8="asac";
    string s9(s8,2);	  //从s8的第二个字符开始拷贝，不能超过s8的size

    //string s(s2,pos2,len2)
    string s10="qweqweqweq";
    string s11(s10,3,4);  //s11是s10从下标3开始4个字符的拷贝
	
//	display(s11);
}

void _operation(){
	// substr
//	string s="abcdefg";
    //s.substr(pos1,n)返回字符串位置为pos1后面的n个字符组成的串
//    string s2=s.substr(0,5);//abcde
    //s.substr(pos)//得到一个pos到结尾的串
//    string s3=s.substr(4);//efg
//    display(s2);
//    display(s3);
    
    // insert
//    string str="abcdefghi";
//    str.insert(6, "xx");   // s的pos位置插入str, abcdefxxghi
//    str.insert(6, "xyz123", 3, 4);  // 位置a到后面的n个字符, abcdef123ghi
//    str.insert(0, "that is cool", 8);  // 在pos位置插入从开始到后面的n个字符 that is abcdefghi
    
//    display(str);
    
    // erase 删除
//	string str ("This is an example sentence.");
//	str.erase(10, 8);  // 直接指定删除的字符串位置第十个后面的8个字符
//  str.erase(str.begin() + 9);  //删除迭代器指向的字符
//    str.erase (str.begin()+5, str.end()-9);
//    display(str);
    
    // append
//    string str;
//    string str2="Writing ";
//    str.append(str2);
//    str.append(str2,1,3);  // 第6个字符开始的3个字符 rit
    
    // replace
    // 支持使用无符号整数寻找位置，也支持用迭代器寻找位置
//    string str="this is a test string.";
//    string str2="n example";
//    str.replace(9,5,str2); // 第9个字符以及后面的4个字符被str2代替
//
//    display(str);
    
    // assign: string使用assign可以灵活的对其进行赋值
//    string str;
//    str.assign("pangrams are cool", 5);
//    display(str);
    
    // find
    string str("There are two needles in this haystack with needles.");
    string str2 ("needle");
    size_t found = str.find(str2);
    if (found!=std::string::npos){
    	cout << "first 'needle' found at: " << found << '\n';
	}
	
	// compare
	// 和strcmp函数一样，如果两个字符串相等，那么返回0，调用对象大于参数返回1，小于返回-1
	string s1="123",s2="123";
    cout<<s1.compare(s2)<<endl;  // 0
    
}

int main(){
	
	init();
	_operation();
	
	return 0;
}





