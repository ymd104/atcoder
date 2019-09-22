#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){
    ll x;
    cin >> x;
    ll tmp = x/11;
    //cout << tmp << endl;
    ll tmp2 = x-tmp*11;
    //cout << tmp2 << endl;
    /*
    tmp2が0の時2*tmp
    tmp2が1~6の時2*tmp*1
    tmp2が7~10の時2*tmp+2
    */
    ll tmp3;
    if(tmp2==0) tmp3=0;
    else if(1<=tmp2 && tmp2 <=6) tmp3 = 1;
    else tmp3=2;
    //cout << tmp3 << endl;

    cout << 2*tmp+tmp3 << endl; 
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
