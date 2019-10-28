#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
dpab[i]:先頭からi文字目までのabの数
dpa[i]:先頭からi文字目までのaの数

dpa[0]= s[0]=='A'or'?'のとき1　それ以外は0
dpab[0]=0

dpa[i]= s[i]=='A'or'?'のときdpa[i-1]+1　それ以外はdpa[i-1]
dpab[i]= s[i]=='B'or'?'のときdpa[i-1]+1 それ以外はdpab[i-1]
文字列を頭からみていって、s[i]=='C'or'?'のときans = (ans + dpab[i-1]) % MOD
*/

ll dpa[100010];
ll dpab[100010];

void solve(){
    string s;
    cin >> s;
    ll n = s.size();
    fill(dpa,dpa+n+10,0);
    fill(dpab,dpab+n+10,0);
    ll ans = 0;
    dpa[0] = s[0]=='A'||s[0]=='?'? 1:0;
    for(ll i=1; i<n; i++){
        if(s[i]=='A'||s[i]=='?') dpa[i]=(dpa[i-1]+1)%MOD;
        else dpa[i]=dpa[i-1];
    }

    for(ll i=1; i<n; i++){
        if(s[i]=='B'||s[i]=='?') dpab[i]=(dpab[i-1]+dpa[i-1])%MOD;
        else dpab[i]=dpab[i-1];
    }

    rep(i,n){
        if(s[i]=='?') ans = (ans*3) % MOD;
        if(s[i]=='C'||s[i]=='?') ans = (ans + dpab[i-1]) % MOD;
    }

    rep(i,n){
        cout << "dpa[" << i << "]:" << dpa[i] << endl;
    }
    rep(i,n){
        cout << "dpab[" << i << "]:" << dpab[i] << endl;
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
