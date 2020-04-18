#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll x[200010];

void solve(){

    ll m;
    cin >> m;
    ll ans = 0;
    ll D=0;
    ll S=0;
    rep(i,m){
        ll d,c;
        cin >> d >> c;
        D += c;
        S += c*d;
    }
    ans = (D-1) + (S-1)/9;

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
