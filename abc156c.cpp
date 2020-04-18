#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll x[110];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> x[i];
    }

    ll ans = INF;
    
    rep(i,101){
        ll tmp = 0;
        rep(j,n){
            tmp += (x[j]-i)*(x[j]-i);
        }
        ans = min(ans,tmp);
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
