#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int a,b;
    cin >> a >> b;
    if(a%2!=b%2) cout << "IMPOSSIBLE" << endl;
    else cout << (a+b)/2 << endl;
}

int main(){
  solve();
  return 0;
}