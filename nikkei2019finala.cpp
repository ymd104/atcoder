#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[3010];
ll sum[3010]; //sum[i]: a[0]からa[i-1]までの総和

//a[i]+a[i+1]+a[i+2]+...+a[j]=sum[j+1]-sum[i]

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
        if(i==0) sum[i+1]=a[i];
        else sum[i+1]=sum[i]+a[i];
    }
    for(ll k=1; k<=n; k++){
        //sum[1]-sum[0], sum[2]-sum[1], ... ,  sum[n]-sum[n-1]
        ll ans = 0;
        for(ll j=k; j<=n; j++){
            ans = max(ans, sum[j]-sum[j-k]);
        }
        cout << ans << endl;
    }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
