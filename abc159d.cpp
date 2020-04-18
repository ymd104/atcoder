#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[200010];
ll s[200010];
//s[i]でiと描かれたボールの数

void solve(){


    ll n;
    cin >> n;
    rep(i,n+2){
        s[i]=0;
    }
    rep(i,n){
        cin >> a[i];
        s[a[i]]++; 
    }

    ll sum=0;
    rep(i,n+2){
        sum += (s[i]*(s[i]-1)/2);
    }

    rep(i,n){
        //cout << s[i] << " ";
    }
    //cout << endl;
    //cout << sum << endl;

    rep(i,n){
        ll p = s[a[i]];
        cout << sum - p*(p-1)/2 + (p-1)*(p-2)/2 << endl;
    }


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
