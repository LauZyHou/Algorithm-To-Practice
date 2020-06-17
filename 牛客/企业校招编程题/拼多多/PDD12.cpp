#include<bits/stdc++.h>
using namespace std;

int arr[10010];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i<n/2;i++) {
        int b = arr[i] + arr[n-1-i];
        if(b>maxi)
            maxi = b;
        if(b<mini)
            mini = b;
    }
    cout << maxi-mini << endl;
    return 0;
}