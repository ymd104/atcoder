#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;



ll gcd( ll a, ll b )
{
    ll temp;

    if( a < b ) { temp = a; a = b; b = temp; }
    if( b < 1 ) return -1;

    if( a % b == 0 ) return b;
    return gcd( b, a % b );
}

ll a[100010];

void solve(){

    ll n,m;
    cin >> n >> m;
    ll x;
    bool b=true;
    rep(i,n){
        cin >> a[i];
        if(i==0) x=a[i];
        else{
            x=x*a[i]/gcd(x,a[i]);
        }
        if(x>2*m){
            b=false;
            break;
        }
        //cout << x << endl;
    }
    
    ll l=x;
    if(!b){
        cout << 0 << endl;
        return;
    }

    //cout << l << endl;

    ll tmp = l/2;
    rep(i,n){
        if(tmp%a[i]!=(a[i]/2)){
            cout << 0 << endl;
            return;
        }
    }
    ll i=0;
    ll ans = 0;
    ans = (m/tmp+1)/2;

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
