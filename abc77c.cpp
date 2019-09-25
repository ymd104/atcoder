#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;



void solve(){
    ll n;
    cin >> n;
    ll a[n+10], b[n+10], c[n+10];
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    rep(i,n){
        cin >> c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);

    ll ans = 0;
    rep(i,n){
        ll center = b[i];
        auto IterA = lower_bound(a, a+n, center);
        auto IterC = upper_bound(c, c+n, center);
        ll acount, ccount;
        acount = IterA - a;
        ccount = c+n- IterC;
        ans += acount*ccount;
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

