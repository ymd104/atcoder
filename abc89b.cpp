#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

void solve(){
    int n;
    cin >> n;
    char s[n+10];
    rep(i,n){
        cin >> s[i];
    }
    set<char> st;
    rep(i,n){
        st.insert(s[i]);
    }
    if(st.size()==4) cout << "Four" << endl;
    else cout << "Three" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
