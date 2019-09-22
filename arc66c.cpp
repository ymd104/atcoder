#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
偶数
123456
5,3,1,1,3,5

奇数
1234567
6,4,2,0,2,4,6

偶数ならpow(2,n/2)
奇数ならpow(2,(n-1)/2)
*/

void solve(){
    int n;
    cin >> n;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    sort(a,a+n);
    bool b=true;
    if(n%2==0){
        for(int i=0; i<n; i=i+2){
            if(a[i]!=i+1) b = false;
            if(a[i+1]!=i+1) b = false;
        }
    }
    else if(n%2==1){
        for(int i=0; i<n-1; i=i+2){
            if(a[i]!=i) b = false;
            if(a[i+1]!=i+2) b = false;
        }
        if(a[n-1]!=n-1) b = false;
    }
    ll ans;
    if(b){
        ans = 1;
        ll tmp = (n-(n%2))/2;
        while(tmp!=0){
            ans = (ans * 2) % MOD;
            tmp = tmp-1;
        }
    }
    else {
        ans = 0;
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
