#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

string st[200010];

void solve(){

    int n;
    cin >> n;
    map<string,int> mp;
    rep(i,n){
        cin >> st[i];
        if(mp.count(st[i])!=0) mp[st[i]]++;
        else mp[st[i]]=0;
    }

    vector<int> v;

    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        v.eb(itr->second);
    }

    sort(v.begin(), v.end(), greater<int>());
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if(itr->second==v[0]) cout << itr->first << endl;
    }


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
