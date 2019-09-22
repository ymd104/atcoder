#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){
    ll n,m;
    cin >> n >> m;
    ll count=0;
    if(n>=m/2) {
        count += m/2;
    }
    else{
        ll rest = m-2*n;
        count += n;
        count += rest/4;
    }
    cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
