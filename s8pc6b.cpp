#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[32];
ll b[32];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    ll ans = ll(1000000009)*ll(1000000009);
    rep(i,n){
        rep(j,n){
            ll x,y;
            x = a[i];
            y = b[j];
            ll dis=0;
            rep(i,n){
                dis += (y-x - ll(2)*min(ll(0),a[i]-x) - ll(2)*min(ll(0),y-b[i]));
            }
            ans = min(ans, dis);
        }
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
