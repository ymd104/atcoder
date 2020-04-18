#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<pair<int,int>> vec;

void solve(){

    int k;
    cin >> k;
    rep(i,k){
        int t1,t2;
        cin >> t1 >> t2;
        vec.emplace_back(make_pair(t1,t2));
    }

    // 昇順にソート済みの入力
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7};

    do {
        bool b=true;
        bool c=true;
        rep(i,k){
            if(v[vec[i].second]!=vec[i].first){
                b=false;
                break;
            }
        }
        if(!b) continue;
        rep(i,8){
            rep(j,8){
                bool ans=true;
                int x1,x2,y1,y2;
                x1 = i;
                y1 = v[i];
                x2 = j;
                y2 = v[j];
                if(x1!=x2){
                    if(x1+y1==x2+y2) ans=false;
                    if(x1-y1==x2-y2) ans=false;
                }
                if(!ans) c=false;
            }
        }
        if(c) break;
    } while (next_permutation(v.begin(), v.end()));

    rep(i,8){
        rep(j,8){
            if(v[j]==i) cout << "Q";
            else cout << ".";
        }
        cout << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
