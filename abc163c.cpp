#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[200010];
ll b[200010];

void solve(){

    ll n;
    cin >> n;
    rep(i,200010){
        a[i]=0;
        b[i]=0;
    }
    rep(i,n-1){
        cin >> a[i+1];
        a[i+1]--;
        b[a[i+1]]++;
    }

    rep(i,n){
        cout << b[i] << endl;
    }


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
