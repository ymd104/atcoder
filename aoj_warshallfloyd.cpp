#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;
ll IINF = INF*INF;

ll adj[110][110];
ll adjtmp[110][110];

void solve(){

    ll v,e;
    cin >> v >> e;
    rep(i,v){
        rep(j,v){
            adj[i][j]=IINF;
        }
    }
    rep(i,e){
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x][y]=z;
        //adj[y][x]=z;
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

    rep(i,v){
        rep(j,v){
            adjtmp[i][j]=adj[i][j];
        }
    }

    for (ll k = 0; k < v; k++){       // 経由する頂点
        for (ll i = 0; i < v; i++) {    // 始点
            for (ll j = 0; j < v; j++) {  // 終点
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    bool notnegativecycle = true;
    rep(i,v){
        rep(j,v){
            if(adjtmp[i][j]!=adj[i][j]) notnegativecycle = false;
        }
    }
    if(!notnegativecycle) {
        cout << "NEGATIVE CYCLE" << endl;
        return;
    }

    rep(i,v){
        rep(j,v){
            if(j==v-1){
                if(adj[i][j]<INF*100000) cout << adj[i][j];
                else cout << "INF";
            }
            else{
                if(adj[i][j]<INF*100000) cout << adj[i][j] << " ";
                else cout << "INF" << " ";
            }
        }
        cout << endl;
    }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
