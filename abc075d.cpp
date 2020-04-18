#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;



void solve(){

    ll n,k;
    cin >> n >> k;
    vector<ll> x,y;
    rep(i,n){
        ll p,q;
        cin >> p >> q;
        x.emplace_back(p);
        y.emplace_back(q);
    }

    ll ans = 4*INF*INF;
    rep(u,n){
        rep(d,n){
            rep(l,n){
                rep(r,n){
                    if(u==d||l==r) continue;
                    ll count=0;
                    rep(i,n){
                        if(y[u]<=y[i]&&y[i]<=y[d]&&x[l]<=x[i]&&x[i]<=x[r]){
                            count++;
                        }
                    }
                    if(count>=k){
                        ans = min(ans, ll(abs(y[d]-y[u])*abs(x[r]-x[l])) );
                    }
                }
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
