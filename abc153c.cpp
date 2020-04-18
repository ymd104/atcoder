#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll h[200010];

void solve(){
  ll n,k;
  cin >> n >> k;
  ll sum = 0;
  rep(i,n){
      cin >> h[i];
  }
  sort(h,h+n,greater<ll>());
  ll rest = k;
  ll ans = 0;
  rep(i,n){
      if(k>=1){
          k--;
      }
      else{
          ans += h[i];
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
