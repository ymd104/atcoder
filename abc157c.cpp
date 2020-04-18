#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){

    int n;
    int m;
    cin >> n >> m;
    vector<int> s;
    vector<int> c;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        s.emplace_back(x);
        c.emplace_back(y);
    }

    rep(i,1000){
        auto st = to_string(i);
        if(st.size()!=n) continue;
        bool b=true;
        rep(j,m){
            if(s[j]>st.size()) {
                b=false;
                break;
            }
            if(st[s[j]-1] != (c[j] +'0')) {
                b=false;
                break;
            }
        }
        if(b){
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
