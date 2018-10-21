#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

struct stu{
    char name[7];
    long long cj;
}stdnt[50010];

//两个学生比较大小(a<b返回true)
bool Cmp(stu a,stu b){
    if(a.cj!=b.cj)//先按成绩比较,小的在前面
        return a.cj<b.cj;
    return a.name<b.name;//再按字典序在前面的
}

//二分查找
//查询大于某个分数s的第一个学生
int BFind(int low,int high,long long s){
    int mid=(low+high)/2;
    while(low<high){
        if(stdnt[mid].cj<=s){
            low=mid+1;
            mid=(low+high)/2;
        }else if(stdnt[mid].cj>s){
            //大于时,这个也不能丢掉
            high=mid;
            mid=(low+high)/2;
        }
    }
    return low;
}

int T,N,Q;
long long q[50010];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%s%ld",stdnt[i].name,&stdnt[i].cj);//char*不用再加&
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
            scanf("%ld",q+i);
        sort(stdnt,stdnt+N,Cmp);//排序
        for(int i=0;i<Q;i++){
            if(q[i]>=stdnt[N-1].cj)//比最大的还大
                printf("Impossible\n");
            else
                printf("%s\n",stdnt[BFind(0,N-1,q[i])].name);
        }
    }
    return 0;
}
