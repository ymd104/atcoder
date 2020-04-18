#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll l[35];
ll dis[120010];

ll power(ll m, ll n){

    l[0]=m;
    for(ll i=1; i<30; i++){
        l[i] = (l[i-1]*l[i-1]) % MOD;
    }

    ll tmp = n;
    ll ans = 1;
    rep(i,35){
        if(tmp%2==1){
            ans = (ans*l[i]) % MOD;
        }
        tmp /= 2;
    }
    return ans;

}

ll a[120010];
ll c[120010];
ll sum[120010];

void solve(){

    ll N,Q;
    cin >> N >> Q;
    rep(i,N){
        cin >> a[i];
    }
    rep(i,Q){
        cin >> c[i];
        c[i]--;
    }


    for(ll i=1; i<N; i++){
        dis[i] = (power(a[i-1],a[i]))%MOD;
    }

    /*
    rep(i,N){
        cout << dis[i] << " ";
    }
    cout << endl;
    */

    //sum[1]:0~1の距離
    //sum[i]:0~iの距離
    sum[0]=0;
    for(ll i=1; i<N; i++){
        sum[i] = (sum[i-1] + dis[i])%MOD;
    }

    /*
    rep(i,N){
        cout << sum[i] << " ";
    }
    cout << endl;
    */

    ll answer = 0;
    answer = (answer + (sum[c[0]] ) % MOD)%MOD;
    rep(i,Q-1){
        if(c[i+1]>c[i]) answer = (answer + (sum[c[i+1]] - sum[c[i]] + MOD)%MOD)%MOD;
        else answer = (answer + (sum[c[i]] - sum[c[i+1]] + MOD)%MOD)%MOD;
    }
    answer = (answer + ((sum[c[Q-1]] )%MOD)) % MOD;

    cout << answer << endl;


}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
