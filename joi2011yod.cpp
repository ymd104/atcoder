#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
*/
ll dp[110][25];
ll num[110];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> num[i];
    }
    rep(i,110){
        rep(j,25){
            dp[i][j]=0;
        }
    }
    rep(i,25){
        dp[0][i]=0;
    }
    dp[0][num[0]]=1;

    for(ll i=1; i<n-1; i++){
        rep(j,21){
            if(j-num[i]>=0&&j-num[i]<=20) dp[i][j] += dp[i-1][j-num[i]];
            if(j+num[i]>=0&&j+num[i]<=20) dp[i][j] += dp[i-1][j+num[i]];
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    

    cout << dp[n-2][num[n-1]] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
