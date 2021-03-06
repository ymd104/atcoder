#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1e9;
    rep(i,n-2){
        string st = s.substr(i,3);
        int tmp = stoi(st);
        ans = min(ans, abs(tmp-753));
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
