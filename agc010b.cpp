#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll a[100010];
ll d[100010];

void solve(){
    
    ll n;
    cin >> n;
    ll sum=0;
    rep(i,n){
        cin >> a[i];
        sum+=a[i];
    }
    a[n]=a[0];
    ll tmp = n*(n+1)/2;
    if(sum%tmp!=0){
        cout << "NO" << endl;
        return;
    }
    ll k = sum/(tmp);
    rep(i,n){
        d[i]=a[i+1]-a[i]-k;
    }

    bool b = true;
    rep(i,n){
        if(d[i]>0||abs(d[i])%n!=0) b=false;
    }

    cout << (b?"YES":"NO") << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
