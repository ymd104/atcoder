#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll l[2010];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
      cin >> l[i];
    }
    l[n]=2000;
    sort(l,l+n);
    ll ans = 0;
    for(int i=n-1; i>=0; i--){
      for(int j=i-1; j>=0; j--){
        //l[0]~l[j-1]までの間で, l[i]-l[j]より大きいもの
        auto itr = upper_bound(l,l+n, l[i]-l[j]);
        //cout << "i: " << i << ", j:" << j << endl;
        //cout << *itr << endl;
        //cout << max(int(0), int(distance(itr,l+j))) << endl;
        ans += max(int(0), int(distance(itr,l+j)));
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
