#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[200010];

void solve(){

    ll n;
    cin >> n;
    set<ll> st;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    cout << (st.size()==n? "YES": "NO") << endl;
 
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
