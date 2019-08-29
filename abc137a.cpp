#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int a,b;
    cin >> a >> b;
    cout << max(a+b, max(a-b, a*b)) << endl;
}


int main(){
  solve();
  return 0;
}