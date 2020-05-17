#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;


void solve(){

    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(k<=a) cout << k << endl;
    else if(a<k&&k<=a+b) cout << a << endl;
    else cout << a-(k-a-b) << endl;
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
