#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;


void solve(){
  double w, h, x, y;
  cin >> w >> h >> x >> y;
  
  double ans;
  ans = w*h/2;
  cout << ans << endl;
  if(2*x == w && 2*y == h) cout << "1" << endl;
  else cout << "0" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}