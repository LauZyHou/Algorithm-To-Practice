#include<iostream>
#include<list>
using namespace std;

//ËØÊý¶Ô,×÷·Ï

list<int> su;
int n,t,cnt;

bool isSu(int n) {
    if(n == 1)
        return false;
    if(n < 4)
        return true;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}


int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d",&t);
        if(t<3){
            printf("0\n");
            continue;
        }
        for(int i = 2; i <= t; i++) {
            if(isSu(i))
                su.push_back(i);
        }
        if(su.empty()){
            printf("0\n");
            continue;
        }
        list<int>::const_iterator itA=su.cbegin();
        list<int>::const_iterator itB=su.cend();
        while(itA!=itB){
            if(*itA+*itB==t+1){
                cnt++;
                itA++;
                if(itA==itB)
                    break;
                itB--;
                cout<<"P";
            }else if(*itA+*itB<t+1){
                itA++;
                cout<<"L";
            }else{
                itB--;
                cout<<"K";
            }
        }
        cnt=cnt<<2;
        if(((*itA)<<2)==t+1)
            cnt++;
        printf("%d--\n",cnt);
        cnt=0;
        su.clear();
    }
    return 0;
}
