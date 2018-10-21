#include<bits/stdc++.h>
using namespace std;

int num[65535],sizeNum;//统计字符数目
int t,mx,i,cnum,j,lineNum;//j==sizeNum
char str[65535];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&mx);
        getchar();
        gets(str);
        while(str[i]!='\0'){
            cnum++;
            if(str[i]=='.' || str[i]=='?' || str[i]=='!'){
                num[j++]=cnum;
                cnum=0;
                if(str[i+1]==' ')
                    i++;
            }
            i++;
        }
        if(cnum!=0){
            num[j++]=cnum;
        }
/*
        for(int k=0;k<j;k++)
            cout<<num[k]<<"\t";
        cout<<endl;
*/
        int pr=0;
        for(i=0;i<j;i++){
            pr+=num[i];
            if(pr>mx){
                if(pr==num[i]){
                    cout<<"Impossible"<<endl;
                    goto NXT;
                }
                else{
                    lineNum++;
                    pr=num[i];
                }
            }
        }
        if(pr>0)
            lineNum++;
        cout<<lineNum<<endl;
        NXT:
        i=j=cnum=lineNum=0;
    }

    return 0;
}
