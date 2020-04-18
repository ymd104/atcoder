#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int d[1010];
int c[1010];
int dp[1010][1010];

void solve(){

    int n,m;
    cin >> n >> m;
    rep(i,n){
        cin >> d[i];
    }
    rep(i,m){
        cin >> c[i];
    }
    rep(i,1010){
        rep(j,1010){
            dp[i][j]=INF;
        }
    }
    rep(i,1010){
        dp[0][i]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=min(dp[i-1][j-1]+d[i-1]*c[j-1], dp[i][j-1]);
        }
    }
    int mi=INF;
    rep(i,m+1){
        mi=min(dp[n][i],mi);
    }

    /*
    rep(i,n){
        rep(j,m){
            if(dp[i+1][j+1]!=INF) cout << dp[i+1][j+1] << " ";
            else cout << "?? ";
        }
        cout << endl;
    }
    */

    cout << mi << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
