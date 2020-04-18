#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){
  ll h;
  cin >> h;
  ll tmp=h;
  ll count = 0;
  while(tmp>=2){
    tmp/=2;
    count++;
  }
  cout << ll(powl(2,count)*2-1) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
