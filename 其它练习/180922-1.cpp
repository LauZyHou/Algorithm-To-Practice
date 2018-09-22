#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

//stack和queue练习 
//cin.get(char)读进char里,cin.getline(char*,长度,结束符)

int main(){
	//stack
	stack<int> s;
	s.push(3);//push
	s.push(5);
	cout<<s.top()<<"\n";//取top 
	s.pop();//pop
	cout<<s.top()<<"\n";
	cout<<s.size()<<"\n";//size
	cout<<s.empty()<<"\n";//empty判空 
	
	string str(10,'-');
	cout<<str<<endl;
	
	//queue
	queue<int> q;
	q.push(3);//push
	q.push(5);
	cout<<q.front()<<"\n";//front队头 
	cout<<q.back()<<"\n";//back队尾
	cout<<boolalpha<<q.empty()<<"\n";//empty
	q.pop();//pop出队 
	cout<<q.size()<<"\n";//size
	
	//用cin反复读字符练习 
	char next;
	do{
		cin.get(next);
		cout<<"-"<<next<<"-";//最后还是有个"-\n-" 
	}while(next!='\n');
	
	cout<<str<<endl;
	
	//cin.getline(字符指针(char*),字符个数N(int),结束符(char));
	//直到读满N-1个，或者遇到指定的结束符为止。若不指定结束符，则默认结束符为'\n'
	char *c=new char[20];
	cin.getline(c,10,'p');
	printf("%s",c);
	
	return 0;
}
