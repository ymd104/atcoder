#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

/*
N+sum(B)個ののカードをソートして大きいものN個をとる
*/

void solve(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    rep(i,n){
        int a;
        cin >> a;
        v.emplace_back(make_pair(-a,1));
    }
    rep(i,m){
        int b,c;
        cin >> b >> c;
        v.emplace_back(make_pair(-c,b));
    }
    sort(v.begin(), v.end());
    ll number = 0;
    ll sum=0;
    ll i=0;
    while(number < n){
        ll f = -v[i].first;
        ll s = v[i].second;
        //cout << "f:" << f << " s:" << s << endl;
        /*
        nとnumberとの差がfより大きければ全部足す
        そうでなければ
        */
        sum += min(n-number,s) * f;
        number += s;
        i++;
    }
    cout << sum << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}