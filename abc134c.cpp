#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int n;
    cin >> n;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    /*
    a[0], a[1], ..., a[n-1]
    a[0], a[1], ..., a[i]までの数の最大値をb[i]とする。要素数はn-1で、b[n-1]が最大。なお、使わない
    a[i], ..., a[n-2], a[n-1]の最大値をc[i]とする。要素数はn-1で、c[n-1]が最大。なお、a[0]は使わない
    */
    int b[n+10];
    int c[n+10];
    b[0]=a[0];
    c[n-1]=a[n-1];
    for(int i=1; i<n; i++){
        b[i]=max(b[i-1], a[i]);
    }
    for(int i=n-2; i>=0; i--){
        c[i]=max(c[i+1], a[i]);
    }
    /*
    c[1], max(b[0], c[2]), max(b[1], c[3]), ..., max(b[n-3], c[n-1]), b[n-2]
    */
    cout << c[1] << endl;
    for(int i=1; i<=n-2; i++){
        cout << max(b[i-1], c[i+1]) << endl;
    }
    cout << b[n-2] << endl;
    
}

int main(){
  solve();
  return 0;
}