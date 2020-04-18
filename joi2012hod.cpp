#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[500010];
ll b[500010];
ll x[500010];
ll sum[5010][5010];
//sum[i][j]:i-1,j-1

void solve(){

    ll n,m;
    cin >> n >> m;
    rep(i,5010){
        rep(j,5010){
            sum[i][j]=0;
        }
    }
    rep(i,m){
        cin >> a[i] >> b[i] >> x[i];
        rep(j,x[i]+1){
            sum[a[i]+j][b[i]]++;
            sum[a[i]+x[i]+1][b[i]+x[i]+1-j]--;
        }
    }

    /*
    rep(i,n+2){
        rep(j,n+2){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    */

    ll ans = 0;
    for(ll i=1; i<=n+1; i++){
        for(ll j=0; j<=n+1-i; j++){
            sum[i+j][1+j]=sum[i+j-1][j]+sum[i+j][1+j];
            if(sum[i+j][1+j]>0) ans++;
        }
    }

    /*
    rep(i,n+2){
        rep(j,n+2){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    */

   cout << ans << endl;

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
