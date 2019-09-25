#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
3枚のカードは1枚に
2枚のカードはどれか1枚を犠牲にして1枚に
すなわち、
・3枚以上あるものは、そこから2を引く
・2枚のもののペアがあれば、1枚ずつ減らせる
・2枚のものが１つだけ残れば、1種類のカードを犠牲に
*/

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int awhere,zwhere;
    rep(i,n){
        if(s[i]=='Z') zwhere=i;
    }
    for(int i=n-1; i>=0; i--){
        if(s[i]=='A') awhere=i;
    }
    cout << zwhere-awhere+1 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

