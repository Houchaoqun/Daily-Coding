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
	string s2(s1);		//s2��s1�ĸ���
    string s3=s2;		//s3��s2�ĸ���
    string s4(10,'c');	//��s4��ʼ��   10��c 
    string s5="hiya";	//������ʼ��
    string s6=string(10,'c');//������ʼ��������һ����ʼ���õĶ��󣬿�����s6
	
    //string s(cp,n)
    char cs[]="12345";
    string s7(cs,3);	  //�����ַ���cs��ǰ3���ַ���s����

    //string s(s2,pos2)
    string s8="asac";
    string s9(s8,2);	  //��s8�ĵڶ����ַ���ʼ���������ܳ���s8��size

    //string s(s2,pos2,len2)
    string s10="qweqweqweq";
    string s11(s10,3,4);  //s11��s10���±�3��ʼ4���ַ��Ŀ���
	
//	display(s11);
}

void _operation(){
	// substr
//	string s="abcdefg";
    //s.substr(pos1,n)�����ַ���λ��Ϊpos1�����n���ַ���ɵĴ�
//    string s2=s.substr(0,5);//abcde
    //s.substr(pos)//�õ�һ��pos����β�Ĵ�
//    string s3=s.substr(4);//efg
//    display(s2);
//    display(s3);
    
    // insert
//    string str="abcdefghi";
//    str.insert(6, "xx");   // s��posλ�ò���str, abcdefxxghi
//    str.insert(6, "xyz123", 3, 4);  // λ��a�������n���ַ�, abcdef123ghi
//    str.insert(0, "that is cool", 8);  // ��posλ�ò���ӿ�ʼ�������n���ַ� that is abcdefghi
    
//    display(str);
    
    // erase ɾ��
//	string str ("This is an example sentence.");
//	str.erase(10, 8);  // ֱ��ָ��ɾ�����ַ���λ�õ�ʮ�������8���ַ�
//  str.erase(str.begin() + 9);  //ɾ��������ָ����ַ�
//    str.erase (str.begin()+5, str.end()-9);
//    display(str);
    
    // append
//    string str;
//    string str2="Writing ";
//    str.append(str2);
//    str.append(str2,1,3);  // ��6���ַ���ʼ��3���ַ� rit
    
    // replace
    // ֧��ʹ���޷�������Ѱ��λ�ã�Ҳ֧���õ�����Ѱ��λ��
//    string str="this is a test string.";
//    string str2="n example";
//    str.replace(9,5,str2); // ��9���ַ��Լ������4���ַ���str2����
//
//    display(str);
    
    // assign: stringʹ��assign�������Ķ�����и�ֵ
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
	// ��strcmp����һ������������ַ�����ȣ���ô����0�����ö�����ڲ�������1��С�ڷ���-1
	string s1="123",s2="123";
    cout<<s1.compare(s2)<<endl;  // 0
    
}

int main(){
	
	init();
	_operation();
	
	return 0;
}





