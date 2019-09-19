#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

struct problems{
    int point;
    int number;
    int bonus;
};

void solve(){
    int d,g;
    cin >> d >> g;
    vector<problems> v;
    rep(i,d){
        struct problems p;
        p.point = (i+1)*100;
        cin >> p.number >> p.bonus;
        v.emplace_back(p);
    }

    /*
    制約が弱い。問題の難易度は100~1000, 問題数はそれぞれ100問以下。
    
    */
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
