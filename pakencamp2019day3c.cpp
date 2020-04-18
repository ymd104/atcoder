#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[110][110];

void solve(){

    int n,m;
    cin >> n >> m;
    rep(i,n){
        rep(j,m){
            cin >> a[i][j];
        }
    }
    ll ans=0;
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            ll tmp=0;
            rep(k,n){
                tmp += max(a[k][i], a[k][j]);
            }
            ans = max(ans,tmp);
        }
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
