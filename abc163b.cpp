#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[1000010];

void solve(){

    ll n,m;
    cin >> n >> m;
    ll sum = 0;
    rep(i,m){
        cin >> a[i];
        sum += a[i];
    }

    if(n>=sum) cout << n-sum << endl;
    else cout << -1 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
