#include<iostream>
#include<cstdio>
#include<cstring>
//#include<fstream>
using namespace std;

//统计文件中单词数目 

char buffer[256];

int main(){
	FILE *fp;//C语言文件读写 
	fp=fopen("./2.txt","r");
	if(!fp){
		cout<<"没打开"<<endl;
	}
	int a[3];
	memset(a,0,sizeof(int)*3);
	while(fscanf(fp,"%s",buffer)>0){//没读到文件尾 
		if(0==strcmp(buffer,"ok1"))
			a[0]++;
		else if(0==strcmp(buffer,"ok2"))
			a[1]++;
		else if(0==strcmp(buffer,"ok3"))
			a[2]++;
	}
	cout<<"ok1:"<<a[0]<<"\tok2:"<<a[1]<<"\tok3:"<<a[2]<<endl;
	fclose(fp);//关文件 
	return 0;
}
