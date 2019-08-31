#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

/*
しゃくとり法
ヘッドとテールr,lを用意。
0 1 2 3 4
 6 1 2 7
lがn-1になるまで、以下を繰り返す。
1. a[l]+a[l+1]+...+a[r]>=kのとき、rからn-1までのn-r+1をansに足し、l++
2. そうでないとき、r++

k=10
6 1 2 7
0. l=0, r=1
1. sum=a[0]=6. 6<10だからr=2, sum=7
2. 7<10だからr=3. sum=9
3. 9<10だからr=
*/

void solve(){
    ll n,k;
    cin >> n >> k;
    ll a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    ll ans = 0;
    ll l=0;
    ll r=1;

    ll sum = a[0];
    //cout << "sum:" << sum << " l:" << l << " r:" << r << endl; 
    while(l<n&&r<=n){
        if(sum>=k){
            ans += n-r+1;
            sum -= a[l];
            l++;
        }
        else{
            sum += a[r];
            r++;
        }
        //cout << "sum:" << sum << " l:" << l << " r:" << r << endl; 
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}