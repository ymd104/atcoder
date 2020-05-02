#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll a[2020];
pair<ll,ll> p[2020];
ll dp[2020][2020];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
        p[i] = make_pair(-a[i],i);
    }
    sort(p,p+n);
    /*
    rep(i,n){
        cout << p[i].second << " ";
    }
    cout << endl;
    */
    rep(i,2020){
        rep(j,2020){
            dp[i][j]=0;
        }
    }
    rep(i,n){
        rep(j,n){
            if(i+j>n) continue;
            if(i==0&&j==0) continue;
            if(i==0){
                ll x = p[i+j-1].second;
                dp[i][j]=dp[i][j-1]+abs(x-(n-j))*a[x];
            }
            else if(j==0){
                ll x = p[i+j-1].second;
                dp[i][j]=dp[i-1][j]+abs(x-(i-1))*a[x];
            }
            else{
                ll x = p[i+j-1].second;
                dp[i][j]=max(dp[i-1][j]+abs(x-(i-1))*a[x], dp[i][j-1]+abs(x-(n-j))*a[x]);
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

    ll ans = 0;
    rep(i,n){
        ans = max(ans, dp[i][n-i]);
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
