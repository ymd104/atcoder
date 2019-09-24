#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


/*
a,b
c,d
e,f

a=0,b=0で固定すると、s=|cf-de|
さらに、c=10^9,d=1で固定すると、
s=|10^9*f-e|=|10^9*(f-1) + 10^9-e|
sを10^9で割った商をf-1,余りを10^9-eとすれば良い
ただし、s=10^18の時、fが10^9を超過する。この時、f=10^9,e=0とすればいい
*/


void solve(){
    ll s;
    cin >> s;
    ll a,b,c,d,e,f;
    a=0;
    b=0;
    c=1000000000;
    d=1;
    e=c-s%c;
    f=s/c+1;
    if(f>c) {
        f=c;
        e=0;
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
