#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;


void solve(){
    int n;
    cin >> n;
    vector<pair<string, int>> v;
    unordered_map<int,int> mp;
    rep(i,n){
        string s;
        int p;
        cin >> s >> p;
        v.emplace_back(make_pair(s,-p));
        mp[p] = i+1;
    }
    sort(v.begin(),v.end());
    rep(i,n){
        cout << mp[-(v[i].second)] << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}