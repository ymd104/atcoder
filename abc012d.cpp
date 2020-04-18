#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll adj[310][310];
ll t[310];

void solve(){

    ll v,e;
    cin >> v >> e;
    rep(i,v){
        rep(j,v){
            adj[i][j]=INF;
        }
    }
    rep(i,e){
        ll x,y,z;
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x][y]=z;
        adj[y][x]=z;
    }
    rep(i,v){
        adj[i][i]=0;
    }

    for (ll k = 0; k < v; k++){       // 経由する頂点
        for (ll i = 0; i < v; i++) {    // 始点
            for (ll j = 0; j < v; j++) {  // 終点
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    /*
    rep(i,v){
        rep(j,v){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    rep(i,v){
        t[i]=0;
    }

    rep(i,v){
        rep(j,v){
            t[i]=max(t[i], adj[i][j]);
        }
    }

    ll ans = INF;
    rep(i,v){
        ans = min(ans, t[i]);
    }

    cout << ans << endl;    

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
