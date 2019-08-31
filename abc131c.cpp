#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

ll gcd(ll p, ll q) {
  if(p<q) return gcd(q,p);
    if (q == 0)
        return p;
 
    return gcd(q, p % q);
}
 
ll lcm(ll p, ll q){
   return p * q / gcd(p,q) ;
}

void solve(){
  int n,l;
  cin >> n >> l;
  int m=max(l,-l);
  int pointer = 1;
  int sum = 0;
  for(int i=1;i<=n;i++){
     int tmp = l+i-1;
     if(m > max(tmp, -tmp)) {
       m = max(tmp,-tmp);
       pointer = i;
     }
     sum += tmp;
  }
  cout << sum-(l+pointer-1) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}