#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
dp[i][j]:コインをj枚投げた時、そのうちi枚が表になる確率
dp[1][1]=p1
dp[0][1]=1-p1

dp[i][j] = dp[i-1][j-1]*pi + dp[i][j-1]*(1-pi)
ただしdp[0][j]=dp[0][j-1]*(1-pi)
dp[j][j]=dp[j-1][j-1]*pj
*/

void solve(){
    int n;
    cin >> n;
    double p[n+10];
    rep(i,n){
        cin >> p[i]; 
    }

    double dp[n+10][n+10];
    dp[1][1]=p[0];
    dp[0][1]=1-p[0];
    for(int j=2; j<=n+1; j++){
        for(int i=0; i<=j; i++){
            if(i==0) dp[i][j]=dp[0][j-1]*(1-p[j-1]);
            else if (i==j) dp[i][j]=dp[j-1][j-1]*p[j-1];
            else dp[i][j] = dp[i-1][j-1]*p[j-1] + dp[i][j-1]*(1-p[j-1]);
        }
    }

    double ans = 0;
    for(int i=(n+1)/2; i<=n; i++){
        ans += dp[i][n];
    }
    cout << setprecision(10) << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
