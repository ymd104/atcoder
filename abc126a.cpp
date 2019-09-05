#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

void solve(){
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    s[k-1] = s[k-1] + 32;
    cout << s << endl; 
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}