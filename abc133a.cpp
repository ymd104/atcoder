#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int n;
    int a,b;
    cin >> n >> a >> b;
    cout << min(n*a,b) << endl;
}

int main(){
  solve();
  return 0;
}