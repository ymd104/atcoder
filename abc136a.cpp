#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(0, c-(a-b));
}

int main(){
  solve();
  return 0;
}

