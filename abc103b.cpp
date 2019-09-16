#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


void solve(){
    string s,t;
    cin >> s >> t;
    int n = t.size();
    string ans = "No";
    rep(i,n){
        t = t[n-1] + t.substr(0, n-1);
        //cout << t << endl;
        if(s==t) ans = "Yes";
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
