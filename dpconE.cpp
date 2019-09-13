#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
ナップサック問題
dp[i][j]:品物v[0]~v[i-1]までを使って価値をj以上にするときの重さの最小値
dp[i][j]=
min(dp[i-1][j-v[i-1].second]+v[i-1].first, dp[i-1][j])
ただし、j<v[i-1].secondのときはdp[i-1][j]をそのまま返す
*/

//関数の内側にあるとダメらしい。関数フレームのスタック領域の問題？
const int maxn = 110;
const int maxv = 100005;
ll dp[maxn][maxv];

void solve(){
    int n,w;
    cin >> n >> w;
    vector<pair<ll,ll>> v;
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        v.emplace_back(make_pair(a,b));
    }
    
    rep(i,maxn){
        rep(j, maxv){
            dp[i][j] = INF;
        }
    }

    rep(i,maxv){
        dp[0][i]=INF;
    }
    rep(i,n+1){
        dp[i][0]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=100000; j++){
            if(j<v[i-1].second) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=min(dp[i-1][j], dp[i-1][j-v[i-1].second] + v[i-1].first);
            }
            //if(j<=12) cout << "i:" << i << " j:" << j << " " << dp[i][j] << endl;
        }
    }
    ll ans = 0;
    rep(i,maxv){
        if(dp[n][i] <= w) ans = i;
    }
    cout << ans << endl;
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
