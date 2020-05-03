#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

bool b[110];

void solve(){

    ll n,k;
    cin >> n >> k;
    rep(i,110){
        b[i]=false;
    }
    rep(i,k){
        ll d;
        cin >> d;
        rep(j,d){
            ll t;
            cin >> t;
            b[t-1]=true;
        }
    }

    ll ans =0;
    rep(i,n){
        if(!b[i]) ans++;
    }

    cout << ans << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
