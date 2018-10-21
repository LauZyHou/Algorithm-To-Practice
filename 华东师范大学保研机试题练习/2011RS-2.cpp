#include<bits/stdc++.h>
using namespace std;

int w,h;
char mapi[1000][80];//地图
bool vst[1000][80];//访问
int fx[][2]={{0,1},{0,-1},{1,0},{1,-1},{-1,0},{-1,1},{1,1},{-1,-1}};//8方向

void DFS(int a,int b){
    if(mapi[a][b]!='*')
        return;
    vst[a][b]=true;
    //8个方向DFS
    for(int i=0;i<8;i++){
        int ny=a+fx[i][0];
        int nx=b+fx[i][1];
        if(0<=nx && nx<w && 0<=ny && ny<h){
            if(mapi[ny][nx]=='*' && vst[ny][nx]==false)
                DFS(ny,nx);
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    while(scanf("%d%d",&w,&h)!=EOF){
        getchar();//"\n"
        for(int i=0;i<h;i++){
            gets(mapi[i]);
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                vst[i][j]=false;
        }
        int ans=0;//block count

        //求最多的连通分量
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(mapi[i][j]=='*' && vst[i][j]==false){
                    DFS(i,j);
                    ans++;
                }
            }
        }

        printf("%d\n",ans);

    }
    return 0;
}
