#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll x[1010];
ll y[1010];
ll z[1010];
ll sum[1010];

void solve(){

    ll n,m;
    cin >> n >> m;
    rep(i,n){
        cin >> x[i] >> y[i] >> z[i];
    }

    ll ans = 0;
    rep(i,2){
        rep(j,2){
            rep(k,2){
                rep(c,n){
                    ll xt,yt,zt;
                    if(i==1) xt=-x[c];
                    else xt=x[c];
                    if(j==1) yt=-y[c];
                    else yt=y[c];
                    if(k==1) zt=-z[c];
                    else zt=z[c];
                    sum[c]=xt+yt+zt;
                }
                sort(sum,sum+n,greater<ll>());
                ll anstmp = 0;
                rep(p,m){
                    anstmp += sum[p];
                }
                ans = max(ll(ans), ll(anstmp));
            }
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
