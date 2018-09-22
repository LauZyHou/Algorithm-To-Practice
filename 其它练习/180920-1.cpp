#include<iostream>
#include<string>
using namespace std;

//string练习 

int main(){
	string s1;
	string s2=s1;
	string s3="OK 123\nABC ";
	string s4(s3);
	string s5(10,'a');//只能是char 
	string s6("啊啊");
	string* s7=new string(3,'b');
	cout<<s1<<"\n"<<s2<<"\n"<<s3<<"\n"<<s4<<"\n"<<s5<<"\n"<<s6<<"\n"<<*s7<<endl;
	
	string s8(20,'-');
	cout<<s8<<endl;
	
	//拼接 
	string s9=s6+*s7;
	cout<<s9<<endl;
	
	//读入,以空白符(包括换行)分隔 
//	cin>>s1>>s2;
//	cout<<s1<<"\t"<<s2<<endl;
	
	//读入,就是读入一行
//	getline(cin,s1);
//	cout<<s1<<endl;
//	getline(cin,s1);
//	cout<<s1<<endl;
	 
	//string对象和字符面值及字符串面值混在一条语句中使用时
	//必须确保+的两侧的运算对象至少有一个是string
	//+是左结合的!!!!!!!!!!! 
	s1=s6+"恩恩"+"诶诶";
	cout<<s1<<endl;//啊啊恩恩诶诶 
	
	//当数组用
	int len=s1.size();
	cout<<"长度是"<<len<<endl;
	for(int i=0;i<len;i++)
		cout<<s1[i];
	cout<<"\n";
	
	//迭代器访问 
	for(string::iterator it=s1.begin();it!=s1.end();it++){
		cout<<*it;
		*it='6';
	}
	cout<<"\n";
	
	//使用const_iterator使得访问元素时是能读不能写
	//这跟常量指针意思差不多
	for(string::const_iterator it=s1.begin();it!=s1.end();it++){
		cout<<*it;//输出很多6,一个中文可以占两个ASCII码字符 
		//不能用*it=这样写其值 
	}
	cout<<"\n";	
	
	//查找子串
	size_t found1=s1.find("56");//std::size_t类型,find()函数 
	size_t found2=s3.find(" 1");
	if(found1!=string::npos)//string::npos表示找不到 
		cout<<found1<<endl;
	if(found2!=string::npos)
		cout<<found2<<endl;//输出第一次找到的起始下标 
	
	return 0;
}
