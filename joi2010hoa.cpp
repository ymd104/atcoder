#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[100010];
ll sum[100010];

void solve(){

    ll n,m;
    cin >> n >> m;
    a[0]=0;
    sum[0]=0;
    rep(i,n-1){
        cin >> a[i+1];
        //a[i]:街iと街i-1の距離
        sum[i+1] = sum[i] + a[i+1];
        //sum[i]:街0から街iまでの距離
        //sum[j]-sum[i]:街iとjとの距離
    }

    /*
    rep(i,n){
        cout << sum[i] << endl;
    }
    */

    int pointer = 0;
    ll ans = 0;
    rep(i,m){
        int x;
        cin >> x;
        ans = (ans + abs(sum[pointer+x]-sum[pointer]))%100000;
        pointer += x;
    }

    cout << ans << endl;

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
