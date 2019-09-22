#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

ll dp[60][60][3000];

void solve(){
    int n,a;
    cin >> n >> a;
    vector<int> x;
    rep(i,n){
        int tmp;
        cin >> tmp;
        x.emplace_back(tmp);
    }
    /*dpで解く
    dp[j][k][s]：x1,...,xjからk枚を選んで総和をsにする場合の数
    dp[j][k][s]=dp[j-1][k][s] + dp[j-1][k-1][s-xj]
    ただし、
    j=0:0
    k=0:0
    s<xj:dp[j-1][k][s]
    dp[0][0][0]:1とする
    dp[n][k][k*A]を全てのkについて計算して総和をとる
    */
    
    

    for(int i=0; i<=n; i++){
      for(int j=0; j<=n; j++){
        for(int k=0; k<=n*a; k++){
          if(i==0||j==0||k==0) dp[i][j][k]=0;
          if(j==0&&k==0) dp[i][j][k]=1;
        }
      }
    }

    dp[0][0][0]=1;

    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        for(int k=1; k<=n*a; k++){
          if(k<x[i-1]) dp[i][j][k]=dp[i-1][j][k];
          else dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i-1]];
          //cout << "i:" << i << " j:" << j << " k:" << k << " dp[i][j][k]:" << dp[i][j][k] << endl;
        }
      }
    }

    ll count = -1;
    rep(i,n+1){
      count += dp[n][i][i*a];
    }
    cout << count << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
