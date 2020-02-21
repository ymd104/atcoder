#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*



*/


void solve(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    rep(i,s.length()){
        s[i] = (s[i] + n - 'A')%26 + 'A';
    }

    cout << s << endl;
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
