#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll w[310];
ll dp[310][310];
vector<ll> v;

void solve(){

    while(true){
    ll n;
    cin >> n;
    if(n==0) break;
    rep(i,n){
        cin >> w[i];
    }
    rep(i,310){
        rep(j,310){
            dp[i][j]=0;
        }
    }

    for(ll i=1; i<n; i++){
        for(ll j=0; j<n-i; j++){
            ll x=j;
            ll y=i+j;
            if(dp[x+1][y-1]==y-x-1&&abs(w[x]-w[y])<=1){
                dp[x][y]=y-x+1;
            }
            else{
                ll ans = 0;
                rep(k,y-x){
                    ans=max(ans, dp[x][x+k]+dp[x+k+1][y]);
                }
                dp[x][y]=ans;
            }
        }
    }

    /*
    rep(i,n){
        rep(j,n){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    v.emplace_back(dp[0][n-1]);


    }

    for(auto e:v){
        cout << e << endl;
    }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
