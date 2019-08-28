#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int n;
    cin >> n;
    double v[n+10];
    rep(i,n){
        cin >> v[i];
    }
    sort(v,v+n);
    double sum = v[0];
    for(int i=1; i<n; i++){
        sum = (sum + v[i])/2;
    }
    cout << setprecision(10) << sum << endl; 
}

int main(){
  solve();
  return 0;
}
