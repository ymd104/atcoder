#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll p[1010];

void solve(){

    ll n,m;
    cin >> n >> m;
    rep(i,n){
        cin >> p[i];
    }
    vector<ll> add;
    for(ll i=0; i<n; i++){
        for(ll j=i; j<n; j++){
            add.emplace_back(p[i]+p[j]);
        }
    }
    rep(i,n){
        add.emplace_back(p[i]);
    }
    add.emplace_back(0);
    sort(add.begin(), add.end());

    /*
    rep(i,add.size()){
        cout << add[i] << " ";
    }
    cout << endl;
    */

    ll ans = 0;
    rep(i,add.size()){
        if(add[0]+add[i]>m) continue;
        ll tmp = m-add[i];
        auto it = upper_bound(add.begin(), add.end(), tmp);
        it--;
        if(*it+add[i]<=m) ans = max(ll(ans), ll(*it+add[i]));
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
