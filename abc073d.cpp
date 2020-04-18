#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int r[10];
int a[30000];
int b[30000];
int c[30000];

int n;
vector<pair<int,int>> ad[210];
int lis[210][210];

int dij(int i, int j){
    int d[210];
    int prev[210];
    rep(k,210){
        d[k]=INF;
    }
    d[i]=0;
    rep(k,210){
        prev[k] = -1;
    }
    prev[i]=i;
    set<int> st;
    rep(i,n){
        st.insert(i);
    }

    while(!st.empty()){
        int mi = INF;
        int u;
        //stの中でd[u]が最大のuを拾ってくる
        auto itr = st.begin();
        rep(t,st.size()){
            int tmp = *itr;
            if(mi>d[tmp]){
                mi = d[tmp];
                u = tmp;
            }
            itr++;
        }

        st.erase(u);
        auto v=ad[u];
        rep(k,v.size()){
            auto p=v[k];
            int node = p.first;
            int dis = p.second;
            if(d[node]>d[u]+dis){
                d[node]=d[u]+dis;
                prev[node]=u;
            }
        }
    }

    return d[j];

}

void solve(){

    int N,M,R;
    cin >> N >> M >> R;
    n = N;
    rep(i,R){
        int tmp;
        cin >> tmp;
        tmp--;
        r[i]=tmp;
    }
    rep(i,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        ad[a].emplace_back(make_pair(b,c));
        ad[b].emplace_back(make_pair(a,c));
    }
    int ans = INF;

    rep(i,R){
        rep(j,R){
            lis[r[i]][r[j]] = dij(r[i],r[j]);
        }
    }


    vector<int> one_case;
    for (int i = 0; i < R; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }

    //cout << dij(0,2) << " " << dij(0,1) << endl;
 
    do {
        int tmp = 0;

        /*
        for (auto num : one_case) {
            cout << num << ", ";
        }
        cout << "\n";
        */

        for(int i=0; i<R-1; i++){
            tmp += lis[r[one_case[i]]][r[one_case[i+1]]];
            //cout << dij(one_case[r[i]],one_case[r[i+1]]) << endl;
        }
        ans = min(ans,tmp);
    } while (next_permutation(one_case.begin(), one_case.end()));
    // 順列の最後になるまで one_case を並び替えながらループ

    cout << ans << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
