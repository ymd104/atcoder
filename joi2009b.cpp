#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll d[100010];
ll k[10010];

void solve(){

    ll di,n,m;
    cin >> di >> n >> m;
    d[0]=0;
    for(ll i=1; i<n; i++){
        cin >> d[i];
    }
    d[n]=di;
    sort(d,d+n+1);
    
    ll ans = 0;
    rep(i,m){
        cin >> k[i];
        auto it =lower_bound(d,d+n,k[i]);
        ll a=*it;
        it--;
        ll b=*it;
        ans += min(abs(a-k[i]), abs(b-k[i]));
    }

    cout << ans << endl;

    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
