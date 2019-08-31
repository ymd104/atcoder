#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

void solve(){
  int p,q,r;
  cin >> p >> q >> r;
  int a ;
  a = max(max(p,q), r);
  cout << p+q+r-a << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}