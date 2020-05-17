#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll p[200010];
ll a[200010];
ll k[200010];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> p[i];
        k[p[i]]=i;
        a[i]=1;
    }

    set<ll> s;
    rep(i,n){
        decltype(s)::iterator it = s.find(p[i]-1);
        if (it != s.end()) { // 見つかった
            a[i]=a[k[p[i]-1]]+1;
        }
        s.insert(p[i]);
    }

    /*
    rep(i,n){
        cout << a[i] << " ";
    }
    cout << endl;
    */

    ll m=0;
    rep(i,n){
        m=max(a[i],m);
    }
    cout << n-m << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
