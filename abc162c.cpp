#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll gcd( ll a, ll b )
{
    ll temp;

    if( a < b ) { temp = a; a = b; b = temp; }
    if( b < 1 ) return -1;

    if( a % b == 0 ) return b;
    return gcd( b, a % b );
}

void solve(){

    ll k;
    cin >> k;
    ll ans = 0;
    rep(i,k){
        rep(j,k){
            rep(l,k){
                ans += (gcd(gcd(i+1,j+1), l+1));
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
