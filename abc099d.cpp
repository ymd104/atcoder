#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll d[33][33]; //d[i][j]:色iを色jに置き換えたときの違和感
ll grid[510][510];

void solve(){

    ll n,c;
    cin >> n >> c;
    rep(i,c){
        rep(j,c){
            cin >> d[i][j];
        }
    }
    rep(i,n){
        rep(j,n){
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }

    ll x[4][33];

    rep(i,4){
        rep(j,33){
            x[i][j]=0;
        }
    }

    rep(i,c){
        rep(a,n){
            rep(b,n){
                if((a+b)%3==0) x[0][i] += d[grid[a][b]][i];
                else if((a+b)%3==1) x[1][i] += d[grid[a][b]][i];
                else x[2][i] += d[grid[a][b]][i];
            }
        }
    }

    ll ans = INF; 
    rep(i,c){
        rep(j,c){
            rep(k,c){
                //座標の和が0:i, 1:j, 2:k
                if(i==j||j==k||i==k) continue;
                ll tmp = 0;
                tmp += x[0][i];
                tmp += x[1][j];
                tmp += x[2][k];
                ans = min(ans, tmp);
            }
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