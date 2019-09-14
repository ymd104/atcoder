#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;


/*
sからtへの写像を考えた時、あるx,yでx=yかつf(x)!=f(y)だとよくない
*/

void solve(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    string ans = "Yes";
    unordered_map<char,char> hash;
    rep(i,n){
        hash[s[i]] = t[i];
    }
    rep(i,n){
        if(hash[s[i]]!=t[i]) ans = "No";
    }

    unordered_map<char,char> hash2;
    rep(i,n){
        hash2[t[i]] = s[i];
    }
    rep(i,n){
        if(hash2[t[i]]!=s[i]) ans = "No";
    }

    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
