#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){

    long double a;
    long double b;
    long double x;
    cin >> a >> b >> x;
    if(2*x>=a*a*b){
        cout << setprecision(12) << atan(2*(a*a*b-x)/(a*a*a))/M_PI*180 << endl;
    }
    else{
        cout << setprecision(12) << atan((a*b*b)/(2*x))/M_PI*180 << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
