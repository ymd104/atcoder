#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll adj[310][310];
ll adjtmp[310][310];

void solve(){

    ll n;
    cin >> n;
    ll sum=0;
    rep(i,n){
        rep(j,n){
            cin >> adj[i][j];
            adjtmp[i][j]=adj[i][j];
            sum += adj[i][j];
        }
    }

    sum = sum/2;

    for (ll k = 0; k < n; k++){       // 経由する頂点
        for (ll i = 0; i < n; i++) {    // 始点
            for (ll j = 0; j < n; j++) {  // 終点
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    bool ans = true;
    rep(i,n){
        rep(j,n){
            if(adj[i][j]!=adjtmp[i][j]) ans = false;
        }
    }

    if(!ans){
        cout << -1 << endl;
        return;
    }

    rep(i,n){
        rep(j,n){//iとjの経路について考える
            bool b = true;
            rep(k,n){
                if(i>=j || i==k || j==k) continue;
                if(adj[i][j]==adj[i][k]+adj[j][k]){
                    sum -= adj[i][j];
                    //cout << i << " " << j << " " << adj[i][j] << endl;
                    b=false;
                    break;
                }
            }
            //if(!b) break;
        }
    }

    cout << sum << endl;

    

    /*
    rep(i,v){
        rep(j,v){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */
    

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
