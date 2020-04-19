#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

void solve(){

    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = k; i<=n+1; i++){
        ll x,y;
        x = i*(i-1)/2;
        y = i * (2*n-i+1) / 2;
        ans = (ans + y-x+1)%MOD;
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
