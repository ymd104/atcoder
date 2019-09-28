#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
. 1 2 3 4 5 6 7 8 9

1 0 1 1 1 1 1 1 1 1
2 0 0 2 2 2 2 2 2 2
3 0 1 0 3 3 3 3 3 3
4 0 0 1 0 4 4 4 4 4
5 0 1 2 1 0 5 5 5 5
6 0 0 0 2 1 0 6 6 6
7 0 1 1 3 2 1 0 7 7
8 0 0 2 0 3 2 1 0 8
9 0 1 0 1 4 3 2 1 0

k+1~nについて、すなわちi=1=n-kについて、
nを(k+i)で割った商をt、あまりをrとすれば、
t*i+(k以上r以下の数の個数)
*/

void solve(){
    int n,k;
    cin >> n >> k;
    ll ans=0;
    for(int i=1; i<=n-k; i++){
        int t;
        int r;
        t = n/(k+i);
        r = n%(k+i);
        if(k!=0) ans += t*i + max(0, r-k+1);
        else ans += t*i + max(0, r-k);
        //cout << "t:" << t << " r:" << r << " b:" << k+i << " " << t*i << " " <<  max(0, r-k) << endl;
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

