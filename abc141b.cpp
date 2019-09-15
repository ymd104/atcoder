#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    string s;
    cin >> s;
    int siz = s.size();
    int a,b;
    a=0;
    b=1;
    bool c=true;
    while(a<siz){
      if(s[a]=='L') c=false;
      a = a+2;
    }
    while(b<siz){
      if(s[b]=='R') c=false;
      b = b+2;
    }
    if(c) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
