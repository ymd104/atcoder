#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int n;
    cin >> n;
    double a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    double sum = 0;
    rep(i,n){
        sum += 1.0/a[i];
    }
    cout << setprecision(10) << 1.0/sum << endl;
    // setprecision でcoutの表示桁数を指定
}

int main(){
  solve();
  return 0;
}
