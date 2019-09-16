#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


void solve(){
    string s;
    cin >> s;
    string ans = "AC";
    if(s[0]!='A') ans = "WA";
    
    int siz = s.size();
    int count = 0;
    for(int j=2; j<=siz-2; j++){
        if(s[j]=='C') count++;
    }
    if(count!=1) ans = "WA";

    bool b=true;
    rep(i,siz){
        char c = s[i];
        b = b && (c=='A'||c=='C'||('a'<=c&&c<='z'));
    }
    if(!b) ans = "WA";
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
