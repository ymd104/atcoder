#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){

    string s;
    cin >> s;
    deque<char> d;
    rep(i,s.size()){
        d.push_back(s[i]);
    }
    ll q;
    cin >> q;
    ll e = 0;
    rep(i,q){
        ll t;
        cin >> t;
        if(t==1){
            e++;
            continue;
        }
        ll f;
        cin >> f;
        char c;
        cin >> c;
        if(e%2==0 && f==1) {
            d.push_front(c);
            continue;
        }
        if(e%2==1 && f==2) {
            d.push_front(c);
            continue;
        }
        d.push_back(c);
    }

    /*
    rep(i,d.size()){
        cout << d[i];
    }
    cout << endl;
    */

    string ans = "";
    ll x = d.size();
    rep(i,x){
        ans += d.front();
        d.pop_front();
    }
    
    if(e%2==1) reverse(ans.begin(), ans.end());
    //reverse(topst.begin(), topst.end());

    //cout << topst << s << endl;
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
