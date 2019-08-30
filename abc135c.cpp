#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    rep(i,n+1){
        int tmp;
        cin >> tmp;
        a.emplace_back(tmp);
    }
    vector<int> b;
    rep(i,n){
        int tmp;
        cin >> tmp;
        b.emplace_back(tmp);
    }
    /*
    配列xを用意し、x[n+1]=a[n+1]
    x[n] = max(x[n+1]+a[n]-b[n],0)
    count += min(a[n]+x[n+1], b[n])
    x[n-1] = max(x[n]+a[n-1]-b[n-1],0)
    ...
    x[1] = max(x[2]+x[1]-b[1], 0)
    count += min(a[1])+x[2], b[1])
    まで繰り返す。
    */
    int x[n+10];
    rep(i,n+1){
        x[i] = 0;
    }
    x[n] = a[n];
    int count = 0;
    for(int i=n-1; i>=0; i--){
        x[i] = max(x[i+1]+a[i]-b[i],0);
        count += min(a[i]+x[i+1], b[i]);
    }
    cout << count << endl;
}

int main(){
  solve();
  return 0;
}