#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int t[210];
int a[210];
int b[210];
int c[210];
int dp[210][210];

void solve(){

    int d,n;
    cin >> d >> n;
    rep(i,d){
        cin >> t[i];
    }
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    rep(i,210){
        rep(j,210){
            dp[i][j]=0;
        }
    }
    rep(i,n){
        if(a[i]<=t[0]&&t[0]<=b[i]) dp[0][i]=0;
        else dp[0][i]=-INF;
    }

    for(int i=1; i<d; i++){
        rep(j,n){
            int tmp=0;
            rep(k,n){
                if(a[j]<=t[i]&&t[i]<=b[j]){
                    tmp=max(tmp, dp[i-1][k]+abs(c[j]-c[k]));
                }
            }
            dp[i][j]=tmp;
        }
    }

    /*
    rep(i,d){
        rep(j,n){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    int ans=0;
    rep(i,n){
        ans = max(dp[d-1][i],ans);
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
