#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll h[100010];
//vector<ll> adj[100010];
ll ma[100010];
ll hi[100010];

void solve(){

    ll n,m;
    cin >> n >> m;
    rep(i,n){
        cin >> h[i];
    }
    rep(i,n){
        ma[i]=0;
        hi[i]=i;
    }
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        //adj[a].emplace_back(b);
        //adj[b].emplace_back(a);
        ma[a]=max(ma[a],h[b]);
        ma[b]=max(ma[b],h[a]);
    }

    ll ans = 0;
    rep(i,n){
        if(ma[i]<h[i]) ans++;
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
