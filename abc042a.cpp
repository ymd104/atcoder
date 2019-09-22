#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    string ans = "NO";
    if(a==5&&b==5&&c==7) ans = "YES";
    if(a==5&&b==7&&c==5) ans = "YES";
    if(a==7&&b==5&&c==5) ans = "YES";
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}