#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<int> vt[100010];
//vt[i]:i番目の頂点が隣接している辺のvにおけるナンバリング
//例えばvt[1]は頂点1を端点にもつ辺のリストである
int c[100010];

void solve(){

    int n;
    cin >> n;
    vector<pair<int,int>> v;
   
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v.eb(make_pair(a,b));
        vt[a].eb(i);
        vt[b].eb(i);
    }
    int ans = 0;
    rep(i,n){
        ans = max(int(ans), int(vt[i].size()));
    }

    
    rep(i,100010){
        c[i]=-1;
    }
    c[0]=1;
    //幅優先?
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        //tと隣接する全ての頂点について, その間の辺を探索
        vector<int> usednumber;
        usednumber.eb(c[t]);
        //cout << "!" << usednumber[0] << endl;
        for(auto e:vt[t]){
            cout << vt[t].size() << "?" << endl;
            //cout << "e" << e << endl;
            
            auto x = v[e].first;
            auto y = v[e].second;
            int next = x+y-t;
            if(c[next]!=-1) continue;
            //cout << "n:" << next << endl;
            int ex;
            for(int i=1; i<=ans; i++){
                bool b=true;
                cout << usednumber.size() << "!" << endl;
                for(auto j: usednumber){
                    cout << i << j << endl;
                    if(i==j) b=false;
                }
                if(b) {
                    ex = i;
                    break;
                }
            }
            cout << "ex: " << ex << endl;
            c[next] = ex;
            usednumber.eb(ex);
            q.push(next);
        }
    }

    rep(i,n-1){
        cout << c[i] << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
