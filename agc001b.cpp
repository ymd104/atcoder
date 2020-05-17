#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;


ll ans;


ll dist(ll a, ll b){
    if(a<b) return dist(b,a);
    if(a%b==0){
        return (2*b)*(a/b)-b;
    }
    else{
        return (2*b)*(a/b) + dist(b,a%b);
    }
}


void solve(){

    ll n,x;
    cin >> n >> x;
    if(n==2*x){
        cout << 3*x << endl;
        return;
    }

    ans = 0;

    if(n>2*x){
        ans += (n+2*x);
        ans += dist(x,n-2*x);
    }
    else{
        ans += n;
        ans += dist(x,n-x);
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
