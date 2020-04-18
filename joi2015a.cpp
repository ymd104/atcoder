#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll p[100010];
ll a[100010];
ll b[100010];
ll c[100010];
ll sum[100010];

void solve(){

    ll n,m;
    cin >> n >> m;
    rep(i,m){
        cin >> p[i];
        p[i]--;
    }
    rep(i,n-1){
        cin >> a[i] >> b[i] >> c[i];
    }

    rep(i,100010){
        sum[i]=0;
    }
    rep(i,m-1){
        if(p[i]<p[i+1]){
            sum[p[i]]++;
            sum[p[i+1]]--;
        }
        else{
            sum[p[i+1]]++;
            sum[p[i]]--;
        }
        
    }
    rep(i,n-1){
        sum[i+1]=sum[i]+sum[i+1];
    }

    /*
    rep(i,n-1){
        cout << sum[i] << " ";
    }
    cout << endl;
    */

    ll ans = 0;
    rep(i,n-1){
        ll count = sum[i];
        ans += min(a[i]*count, b[i]*count+c[i]);
    }

    cout << ans << endl;

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
