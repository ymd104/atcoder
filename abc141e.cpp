#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*
ll dp[3010][3010];
 
ll lcs(string s, string t){
    int n,m;
    n = s.size();
    m = t.size();
    rep(i,n+1){
        dp[i][0] = 0;
    }
    rep(j,m+1){
        dp[0][j] = 0;
    }
 
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else if(dp[i-1][j] > dp[i][j-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i][j-1]; 
        }
    }
    return dp[n][m];
}
*/

ll dp[5010][5010];

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,n){
      dp[i][0]=0;
      dp[0][i]=0;
    }
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(i>=j) dp[i][j]=0;
        else if(s[i-1]==s[j-1] && i + dp[i-1][j-1]<j) dp[i][j] = dp[i-1][j-1]+1;
        else dp[i][j]=0;

        //cout << i << " " << j << " " << dp[i][j] << endl;
      }
    }
    ll ma = 0;
    rep(i,n){
      rep(j,n){
        ma = max(ma, dp[i+1][j+1]);
      }
    }
    cout << ma << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
