#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<pair<int,int>> ad[110];
bool b[11000];
//b[i]:頂点iを通る最短経路があるかどうか
int l[110][110];

int n=0;

void dij(int i, int j){

    int d[110];
    int prev[110];
    rep(k,110){
        d[k]=INF;
    }
    d[i]=0;
    rep(k,110){
        prev[k] = -1;
    }
    prev[i]=i;
    set<int> st;
    rep(i,n){
        st.insert(i);
    }

    //cout << "#" << endl;

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

        //cout << i << ", " << j << ", u:" << u << endl;

        

        //int u=q.top();
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

    /*
    rep(i,3){
        cout << d[i] << " " << prev[i] << endl;
    }
    */

    int edger = j;
    int edgel = prev[j];
    while(edger!=i){
        if(l[edgel][edger]!=-1){
            b[l[edgel][edger]] = true;
        }
        else{
            b[l[edger][edgel]] = true;
        }
        edgel = prev[edgel];
        edger = edgel;
    }



}




void solve(){

    int n_,m;
    cin >> n_ >> m;
    n=n_;
    vector<pair<int,int>> verlist;
    rep(i,110){
        rep(j,110){
            l[i][j]=-1;
        }
    }
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        ad[a].emplace_back(make_pair(b,c));
        ad[b].emplace_back(make_pair(a,c));
        verlist.emplace_back(make_pair(a,b));
        l[a][b]=verlist.size()-1;
        l[b][a]=verlist.size()-1;
    }

    for(int x=0; x<n-1; x++){
        for(int y=x+1; y<n; y++){
            dij(x,y);
            //cout << "end" << endl;
        }
    }

    //cout << "cal" << endl;

    int ans = 0;
    rep(i,m){
        if(!b[i]) ans++;
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
