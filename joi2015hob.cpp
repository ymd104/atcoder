#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[2100];
ll dp[4010][4010];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,4010){
        rep(j,4010){
            dp[i][j]=0;
        }
    }

    if((n-1)%2==0)
    rep(i,n){
        dp[i][i]=a[i];
    }
    
    for(ll x=1; x<2*n; x++){
        for(ll y=0; y<2*n-x; y++){
            ll i=y;
            ll j=x+y;
            if((x+2*y)%2==(n-1)%2){
                dp[i][j]=max(ll(dp[i+1][j]+a[i%n]), ll(dp[i][j-1]+a[j%n]));
            }
            else{
                if(a[i%n]>a[j%n]) dp[i][j]=dp[i+1][j];
                else dp[i][j]=dp[i][j-1];
            }
        }
    }

    /*
    rep(i,2*n){
        rep(j,2*n){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    ll ans = 0;
    rep(i,n){
        ans = max(ll(ans), ll(dp[i][n-1+i]));
    }

    cout << ans << endl;

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
