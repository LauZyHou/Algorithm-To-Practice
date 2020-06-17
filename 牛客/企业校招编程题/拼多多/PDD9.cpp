#include<bits/stdc++.h>
using namespace std;

int n, m;
int cd[100];
bool cd_used[100];

class Bear{
public:
  int id;
  int atk;
  int hry;
};

Bear bear[10];

bool cmpAtk(const Bear& a, const Bear& b) {
    return a.atk > b.atk;
}

bool cmpId(const Bear& a, const Bear& b) {
    return a.id < b.id;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> cd[i];
        cd_used[i] = false;
    }
    for(int i=0;i<n;i++) {
        cin >> bear[i].atk >> bear[i].hry;
        bear[i].id = i;
    }
    sort(bear, bear+n, cmpAtk);
    sort(cd, cd+m, greater<int>());
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(cd_used[j] || cd[j]>bear[i].hry)
                continue;
            bear[i].hry -= cd[j];
            cd_used[j] = true;
        }
    }
    sort(bear, bear+n, cmpId);
    for(int i=0;i<n;i++) {
        cout << bear[i].hry << endl;
    }
    return 0;
}