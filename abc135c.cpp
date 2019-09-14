#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int n;
    cin >> n;
    vector<long long> a;
    rep(i,n+1){
        int tmp;
        cin >> tmp;
        a.emplace_back(tmp);
    }
    vector<long long> b;
    rep(i,n){
        int tmp;
        cin >> tmp;
        b.emplace_back(tmp);
    }
    /*
    配列xを用意し、x[n+1]=a[n+1]
    x[n] = a[n]-max(b[n]-x[n+1],0)
    count += min(a[n]+x[n+1], b[n])
    x[n-1] = max(x[n]+a[n-1]-b[n-1],0)
    ...
    x[1] = max(x[2]+x[1]-b[1], 0)
    count += min(a[1])+x[2], b[1])
    まで繰り返す。
    */
    long long zero = 0;
    long long x[n+10];
    rep(i,n+1){
        x[i] = zero;
    }
    x[n] = a[n];
    long long count = 0;

    for(int i=n-1; i>=0; i--){
        x[i] = max(a[i]-max(b[i]-x[i+1],zero),zero);
        count += min(a[i]+x[i+1], b[i]);
    }
    cout << count << endl;
}

int main(){
  solve();
  return 0;
}