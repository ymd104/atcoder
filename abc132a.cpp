#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)


void solve(){
  string s;
  cin >> s;
  bool b;
  b = (s[0]==s[1] && s[2]==s[3] && s[0]!=s[2]) || (s[0]==s[2] && s[1]==s[3] && s[0]!=s[1]) || (s[0]==s[3] && s[1]==s[2] && s[0]!=s[1]);
  if(b) cout << "Yes" << endl;
  else cout << "No" << endl; 
}

int main(){
  solve();
  return 0;
}