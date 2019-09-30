#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*

*/

void solve(){
    int n,q;
    cin >> n >> q;

    vector<pair<int, pair<int,int>>> vp;
    set<int> xs;

    rep(i,n){
        int s,t,x;
        cin >> s >> t >> x;
        vp.emplace_back(make_pair(s-x,make_pair(1,x)));
        vp.emplace_back(make_pair(t-x,make_pair(-1,x)));
    }

    sort(vp.begin(), vp.end());

    int pointer=0;
    rep(i,q){
        int d;
        cin >> d;
        while(vp[pointer].first<=d){
            if(pointer>=vp.size()) break;
            int typ = vp[pointer].second.first;
            int xtmp = vp[pointer].second.second;
            if(typ==1) xs.insert(xtmp);
            else xs.erase(xtmp);
            pointer++;
        }
        if(!xs.empty()) cout << *(xs.begin()) << endl;
        else cout << -1 << endl;
        //cout << *(xs.begin()) << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}