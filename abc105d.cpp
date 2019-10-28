#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
累積和s[0] s[1] s[2]... s[n-1]
の中から、
・mで割った余りが等しいもの同士をxC2する
・余りが0であるものの個数を足す
m=3について、
1 4 6 2 2
は、
1 5 11 13 15
3で割った余りは
0 1 1 2 2
だから、
1+1+1=3

*/

void solve(){
    ll n,m;
    cin >> n >> m;
    ll a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    
    ll ans = 0;
    //累積和計算
    ll sum[n+10];
    sum[0]=a[0];
    for(ll i=1; i<n; i++){
        sum[i] = sum[i-1]+a[i];
    }
    rep(i,n){
        sum[i] = sum[i]%m;
    }
    sort(sum,sum+n);

    ll count1=0;
    rep(i,n){
        if(sum[i]==0) count1++;
        else break;
    }
    ans += count1;
    ll pointer = 0;
    ll count = 1;
    while(pointer<n){
        if(sum[pointer]==sum[pointer+1]){
            pointer++;
            count++;
        }
        else{
            ans += count*(count-1)/2;
            count=1;
            pointer++;
        }
    }
    cout << ans << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
