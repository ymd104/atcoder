#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ld p;

ld calc(ld x){
    ld tmp1 = (-1)*x/1.5;
    ld tmp2 = pow(2,tmp1);
    return 1 - p * tmp2 * log(2.0) / 1.5;
}

ld f(ld y){
    return y + pow(2, (-1)*y/1.5) * p;
}

void solve(){

    cin >> p;
    ld l=0;
    ld r=100;
    while(abs(r-l)>0.00000000001){
        ld m = (r+l)/2;
        if(calc(m)>0) r=m;
        else l=m;
    }
    cout << setprecision(12) << f(l) << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
