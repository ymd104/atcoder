#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){

    int a,b,c;
    cin >> a >> b >> c;
    string ans = "No";
    if(a==b&&a!=c) ans = "Yes";
    if(a==c&&a!=b) ans = "Yes";
    if(c==b&&a!=c) ans = "Yes";

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
