#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
各ペアについて、和がxを超えていれば、右を減らす
右が0なら左をxまで減らす
*/

void solve(){
    int n,x;
    cin >> n >> x;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    ll count = 0;
    for(int i=1; i<n; i++){
        if(a[i-1]+a[i]>x&&a[i-1]<=x) {
            count += (a[i]+a[i-1]-x);
            a[i]=x-a[i-1];
        }
        else if(a[i-1]+a[i]>x&&a[i-1]>x){
            count += a[i];
            count += a[i-1]-x;
            a[i]=0;
            a[i-1] = x;
        }
    }
    cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
