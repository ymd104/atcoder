#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
ab
ab
->2倍

ab
ac
->2倍

ab
cb
->1倍

ab
cd
->3倍
*/

void solve(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    ll ans;
    if(s[0]==t[0]) ans = 3;
    else ans = 6;
    for(int i=1; i<n; i++){
        char c1,c2,c3,c4;
        c1 = s[i-1];
        c2 = t[i-1];
        c3 = s[i];
        c4 = t[i];
        if(c1==c2) ans = ans * 2 % MOD;
        if(c1!=c2&c3!=c4&&c1!=c3) ans = ans * 3 % MOD;
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

