#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
0 1 2 3 4 5 6 7 8 9

1
1
2*1
3*1
4*2*1
5*3*1
6*4*2*1
7*5*3*1

奇数は0
偶数は、(n/2)!の5の倍数
*/

ll b5(ll x){
    ll count=0;
    ll tmp = x;
    while(tmp>=5){
        tmp /= 5;
        count++;
    }
    ll a = 0;
    rep(i,count){
        cout << i << " " << (x/(ll)(pow(5,i+1)) ) << endl;
        a += (x/(ll)(pow(5,i+1)));
    }
    return a;
}


void solve(){

    ll n;
    cin >> n;
    ll ans=0;
    if(n%2==1){
        ans = 0;
    }
    else{
        ans = b5(n/2);
    }

    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
