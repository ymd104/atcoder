#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    char c = s[0];
    string t{c};
    for(int i=1; i<n; i++){
        if(s[i-1]=='B' && s[i]=='C') {
            t.pop_back();
            t = t + "D";
        }
        else {
            t = t + s[i];
        }
    }

    //ADDADA のような文字列を、DDDAAAにソートするのに必要な交換回数
    //これは、Aについて自分より右にあるDの数を数えると良い
    //逆に、各Dについて、自分より左にあるAの数ということになり、これは線型的に導出できる

    /*
    200000字のうち、66666字をA、残りをBC...に当てることを考える
    このとき、66666*66666が求める解となり、オーバーフローしうる
    */
    ll ans = 0;
    ll count = 0;
    rep(i,t.size()){
        if(t[i]=='B'||t[i]=='C'){
            count=0;
        }
        else if(t[i]=='A'){
            count++;
        }
        else{
            ans += count;
        }
    }

    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

