#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

void solve(){

    ll n,a,b;
    cin >> n >> a >> b;
    if(abs(a-b)%2==0){
        cout << (abs(a-b))/2 << endl;
    }
    else{
        cout << min((b+a-1)/2, (n-b+n-a+1)/2) << endl;
    }
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
