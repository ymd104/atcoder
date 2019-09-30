#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
コメントアウトされたものは同じ作業を下手な方法でやってTLEしたコード
実際DPには変わりないが、引数で与えるための文字列作成操作でO(n)溶かしてn^2で動いている
*/


ll p2[100010];
//p2[i]:2のi乗
/*

string all1(string s){
    string tmp="";
    rep(i,s.size()-1){
        tmp += "1";
    }
    return tmp;
}

string headcut(string s){
    if(s=="0") return "0";
    else{
        string tmp="";
        bool b=false;
        for(ll i=1; i<s.size(); i++){
            if(!b && s[i]=='1'){
                b=true;
                tmp = tmp + '1';
            }
            else if(b){
                tmp = tmp + s[i];
            }
        }
        if(!b) tmp = '0';
        return tmp;
    }
    
}

ll dp(string s){
    bool b=true;
    rep(i,s.size()){
        if(s[i]!='1') b=false;
    }
    if(b) return p2[s.size()];
    else if(s=="0") return 1;
    else{
        return ( dp(all1(s)) + 2*dp(headcut(s)) )%MOD;
    }
    
}
*/

void solve(){

    
    ll p=1;
    p2[0]=1;
    for(ll i=1; i<100010; i++){
        p2[i]=(p2[i-1]*3) % MOD;
    }
    
    string l;
    cin >> l;

    //cout << all1("1001001") << " " << headcut("1000") << endl;

    //cout << p2[0] << " " << p2[1] << " " << p2[2] << endl;
    /*
    ll ans = dp(l)%MOD;
    cout << ans << endl;
    */

    ll tmp = 1;
    ll siz = l.size();

    for(ll i=siz-1; i>=0; i--){
        if(l[i]=='1') tmp = (p2[siz-1-i] + tmp*2) % MOD;
    }

    cout << tmp << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}