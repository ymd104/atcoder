#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*

i番目の料理以外を食べてj分以内に完食するものの最大値を計算し、全探索
dp1[i][j]:1~iまでの料理を用いて、j分以内に完食するときの満足度の最大値
dp2[i][j]:i~nまでの料理を用いて、j分以内に完食するときの満足度の最大値

求める値は、max( dp1[i-1][t-1] + dp2[i+1][t-1] )
各dp1,dp2は、

dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j-a[i]])
dp1[0][a[0]] = b[0]
k < a[0] : dp1[0][k] = 0
k > a[0] : dp1[0][k] = b[0]
dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j-a[i]])
dp2[n-1][a[n-1]] = b[n-1]
k < a[n-1] : dp2[n-1][k] = 0
k > a[n-1] : dp2[n-1][k] = b[n-1]

*/

ll dp1[3010][3010];
ll dp2[3010][3010];

void solve(){
    int n,t;
    cin >> n >> t;
    vector<ll> a;
    vector<ll> b;
    rep(i,n){
        int a_,b_;
        cin >> a_ >> b_;
        a.push_back(a_);
        b.push_back(b_);
    }
    rep(i,3010){
        rep(j,3010){
            dp1[i][j]=0;
            dp2[i][j]=0;
        }
    }
    rep(i,n){
        rep(j,t){
            if(i==0){
                if(j>=a[i]) dp1[i][j]=b[i];
            }else{
                if(j<a[i]) dp1[i][j] = dp1[i-1][j];
                else dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j-a[i]]+b[i]);
            }
            //cout << "i:" << i << ", j:" << j << ", dp1[i][j]:" << dp1[i][j] << endl;
        }
    }

    for(ll i=n-1; i>=0; i--){
        rep(j,t){
            if(i==n-1){
                if(j>=a[i]) dp2[i][j]=b[i];
            }else{
                if(j<a[i]) dp2[i][j] = dp2[i+1][j];
                else dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j-a[i]]+b[i]);
            }
            //cout << "i:" << i << ", j:" << j << ", dp2[i][j]:" << dp2[i][j] << endl;
        }
    }

    ll ans = 0;
    rep(i,n){
        ll ans_tmp = 0;
        rep(j,t){
            if(i==0) ans_tmp = max(ans_tmp, dp2[i+1][t-j-1]+b[i]);
            else {
                if(i==n-1) ans_tmp = max(ans_tmp, dp1[i-1][j]+b[i]);
                else ans_tmp = max(ans_tmp, dp1[i-1][j]+dp2[i+1][t-j-1]+b[i]);
            }
        }
        //cout << i << " " << ans << endl;
        ans = max(ans,ans_tmp);

    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
