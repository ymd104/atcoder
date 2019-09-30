#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  string ans="Yes";
  if(s[a]!='-') ans = "No";
  rep(i,a){
      char c = s[i];
      int tmp = c-'0';
      if(!(0<=tmp&&tmp<=9)) ans = "No"; 
  }
  rep(i,b){
      char c = s[a+1+i];
      int tmp = c-'0';
      if(!(0<=tmp&&tmp<=9)) ans = "No"; 
  }

  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}