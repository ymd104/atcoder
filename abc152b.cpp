#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

string render(int x, int y){
    string x_str = to_string(x);
    string ans = "";
    rep(i,y){
        ans = ans + x_str;
    }
    return ans;
}

void solve(){
  int a,b;
  cin >> a >> b;
  string ans = a<b ? render(a,b): render(b,a);
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
