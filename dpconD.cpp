#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;

/*
ナップサック問題
dp[i][j]:品物v[0]~v[i-1]までを使って重さをj以下にするときの価値の最小値
dp[i][j]=
max(dp[i-1][j], dp[i-1][j-v[i].first]+v[i].second)
ただし、j<v[i].firstのときはdp[i-1][j]をそのまま返す
*/

void solve(){
    int n,w;
    cin >> n >> w;
    vector<pair<ll,ll>> v;
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        v.emplace_back(make_pair(a,b));
    }
    ll dp[110][w+10];
    rep(i,w+1){
        dp[0][i]=0;
    }
    rep(i,n+1){
        dp[i][0]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            //cout << "i:" << i << " j:" << j << endl;
            if(j<v[i-1].first) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-v[i-1].first] + v[i-1].second);
            }
        }
    }
    cout << dp[n][w] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
