#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

//string dp[3010][3010];
//stringでやるとTLEなどをした
ll dp[3010][3010];

void solve(){
    string s,t;
    cin >> s >> t;
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
    /*
    dp[i][j-1], dp[i-1][j]のうち、dp[i][j]に等しい方へとジャンプ。
    どちらも等しくなければ、s[i]を足す。
    */
    int a = n;
    int b = m;
    string ans="";
    while(a>0&&b>0){
        if(dp[a][b]!=dp[a-1][b] && dp[a][b]!=dp[a][b-1]) {
            ans = s[a-1] + ans;
            a = a-1;
            b = b-1;
        }
        else if (dp[a][b-1]==dp[a][b]) b = b-1;
        else a = a-1;
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
