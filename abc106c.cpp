#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

void solve(){
    string s;
    ll k;
    cin >> s >> k;
    int t = s.size();
    int tmp =min((ll)t, k);
    bool b=true;
    char c;
    rep(i,tmp){
        if(s[i]!='1') {
            b = false;
            c = s[i];
            break;
        }
    }
    if(b) cout << "1" << endl;
    else cout << c << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
