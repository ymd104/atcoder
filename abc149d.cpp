#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){

    int n,k;
    cin >> n >> k;
    int r,s,p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    ll ans = 0;
    rep(i,t.size()){
        if(i<k){
            if(t[i]=='r') ans += p;
            if(t[i]=='s') ans += r;
            if(t[i]=='p') ans += s;
        }
        else if(t[i]!=t[i-k]){
            if(t[i]=='r') ans += p;
            if(t[i]=='s') ans += r;
            if(t[i]=='p') ans += s;
        }
        else{
            t[i] = 'w';
        }
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
