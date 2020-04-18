#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll sum[1000010];

void solve(){

    ll n;
    cin >> n;
    rep(i,1000001){
        sum[i]=0;
    }
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        sum[a]++;
        sum[b+1]--;
    }
    ll ans = sum[0];
    rep(i,1000000){
        sum[i+1]=sum[i+1]+sum[i];
        ans = max(sum[i+1],ans);
    }
    cout << ans << endl;

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
