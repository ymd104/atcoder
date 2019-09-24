#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
全体の最大公約数の倍数かつ最大値より小さければ作れる
*/

int gcd( int a, int b )
{
    int temp;

    if( a < b ) { temp = a; a = b; b = temp; }
    if( b < 1 ) return -1;

    if( a % b == 0 ) return b;
    return gcd( b, a % b );
}

void solve(){
    int n,k;
    cin >> n >> k;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    int g=a[0];
    int m=a[0];
    for(int i=1;i<n;i++){
        g=gcd(g,a[i]);
        m=max(m,a[i]);
    }
    if(k%g==0&&m>=k){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
