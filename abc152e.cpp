#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*

愚直に最大公約数でやろうとするとWAる
→N=100000、A_i=1000000だから最小公倍数がとんでもない巨大数になっているのでは?
最小公倍数を素因数分解された形で保持するとする

100 99 98
100*99*49
->99*49+4900+4950=14701

*/

ll gcd( ll a, ll b )
{
    ll temp;

    if( a < b ) { temp = a; a = b; b = temp; }
    if( b < 1 ) return -1;

    if( a % b == 0 ) return b;
    return gcd( b, a % b );
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}


//素因数分解
map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

//冪乗mod
ll f(ll a, ll x) {
  ll res = 1;
  while(x > 0) {
    if(x & 1) res = a * res % MOD;
    a = a * a % MOD;
    x >>= 1;
  }
  return res;
}


ll a[10010];

void solve(){
    //計算量推定

    ll n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }

    ll amax = 0;
    rep(i,n){
        amax = max(a[i],amax);
    }
    // n

    map<ll,ll> map_lcm;
    map_lcm = prime_factor(a[0]);
    // /n
    
    
    for(ll i=1; i<n; i++){
        auto map_tmp = prime_factor(a[i]);
        // /a

        //O(amax)は大きすぎる. 
        //最も効率がいいのは、map_lcm中にキーとして含まれるもののみの探索.

        auto begin = map_tmp.begin(), end = map_tmp.end();
        for (auto iter = begin; iter != end; iter++) {
        // first: key, second: value
            int key = (int)iter->first;
            ll at = iter->second;
            //cout << i << "  " << key << "  " << at << "  " << map_tmp[key] << endl;
            map_lcm[key] = max(map_lcm[key], at);
        }

        // lcmのkeyの数のオーダー. aは大きくとも/a程度の素因数を持つ. →/a
        
    }
    //ここでlcmが素因数分解表示されているはず
    //map_lcm[i]で素数iの数が表示される
    


    ll lcm_ans = 1;
    auto begin = map_lcm.begin(), end = map_lcm.end();
    for (auto iter = begin; iter != end; iter++) {
        // first: key, second: value
        int key = (int)iter->first;
        ll at = iter->second;
        lcm_ans = (lcm_ans*f(key,at)) % MOD;
    }

    ll ans = 0;
    rep(i,n){
        ans = (ans + lcm_ans*(f(a[i], MOD-2)))% MOD;
    }
    
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
