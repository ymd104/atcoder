#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
ポインタi,j
i=j=0から出発し、t[j]==s[i]となるまでiを加算する
iが一周したら-1を出力
*/

void solve(){
    string s,t;
    cin >> s >> t;
    ll i=0;
    ll j=0;
    ll ss = s.size();
    ll ts = t.size();
    ll ans = 0;
    while(j<ts){
        while(s[i]==t[j]){
            i++;
            ans++;
        }
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}