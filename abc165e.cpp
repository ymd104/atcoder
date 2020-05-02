#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;


void solve(){

    ll n,m;
    cin >> n >> m;
    if(m%2==0){
        rep(i,m/2){
            cout << n-i << " " << n-m+i << endl;
            cout << 1+i << " " << m-i << endl;
        }
    }
    else{
        cout << n << " " << n-m << endl;
        for(ll i=0; i<m/2; i++){
            cout << 1+i << " " << m-i << endl;
            cout << n-i-1 << " " << n-m+i+1 << endl;
        }
    }

    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
