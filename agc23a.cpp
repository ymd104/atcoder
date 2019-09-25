#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;



void solve(){
    ll n;
    cin >> n;
    ll a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    //累積和
    ll s[n+10];
    rep(i,n)
    if(i==0) s[i]=a[0];
    else{
        s[i]=s[i-1]+a[i];
    }
    /*s[r]-s[l-1]=a[l]+...+a[r]
    総和が0になる部分列は、等しいs[i]の組の数
    sをソートし、同じ値の個数のCをとる
    
    1 3 -4 2 2 -2
    1 4 0  2 4 2

    0があるごとに1を足す
    0が複数あるときは？

    1 3 -4 2 -2 3 -3
    1 4  0 2 0  3  0
    通常通り足せば良さそう

    */

    sort(s,s+n);
    /*rep(i,n){
        cout << s[i] << endl;
    }*/

    ll ans=0;
    ll tmp=1;
    rep(i,n){
        if(s[i]==0) ans++;
    }
    for(int i=1; i<n; i++){
        if(s[i-1]==s[i]) tmp++;
        else{
            ans += tmp*(tmp-1)/2;
            tmp=1;
        }
    }
    ans += tmp*(tmp-1)/2;
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

