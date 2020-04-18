#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<pair<int,int>> adj[5010];
vector<int> ad[5010];
int eachdist[5010][5010];
int dis[5010];
bool visit[5010];

int c[5010];
int r[5010];

void solve(){

    int n,k;
    cin >> n >> k;
    //n:街の数、k:道路の数
    rep(i,n){
        int x,y;
        cin >> x >> y;
        c[i]=x;
        r[i]=y;
    }
    
    rep(i,k){
        int p,q;
        cin >> p >> q;
        p--;
        q--;
        ad[p].emplace_back(q);
        ad[q].emplace_back(p);
    }

    //枝のコストが1なので幅優先.

    rep(i,n){
        rep(j,n){
            eachdist[i][j]=INF;
        }
    }

    rep(i,n){

        rep(j,n){
            visit[j]=false;
        }
        queue<int> q;
        q.push(i);
        eachdist[i][i]=0;
        visit[i]=true;
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            for(auto e:ad[tmp]){
                if(visit[e]) continue;
                eachdist[i][e]=eachdist[i][tmp]+1;
                visit[e]=true;
                q.push(e);
            }
        }

    }


    /*
    rep(i,n){
        rep(j,n){
            cout << eachdist[i][j] << " ";
        }
        cout << endl;
    }
    */

    //ここまで幅優先


    rep(i,n){
        //街iのタクシーの最大距離r[i]
        //街iからの街jの最短距離eachdist[i][j]
        //eachdist[i][j]<=r[i]なる街jについて、adj[i]に<c[i],j>を追加
        rep(j,n){
            if(i==j) continue;
            if(eachdist[i][j]<=r[i]){
                eachdist[i][j]=c[i];
            }
            else{
                eachdist[i][j]=INF;
            }
        }
    }    

    /*
    rep(i,n){
        rep(j,n){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */

    rep(i,n){
        rep(j,n){
            if(eachdist[i][j]!=INF){
                adj[i].emplace_back(make_pair(j, eachdist[i][j]));
            }
        }
    }

    

    rep(i,n){
        dis[i]=INF;
        visit[i]=false;
    }

    int r=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push(make_pair(0,r));
    visit[r]=true;
    dis[r]=0;
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        int d = p.first;
        int node = p.second;
        if(dis[node]!=d) continue;
        visit[node] = true;
        for(auto e: adj[node]){
            //cout << e.first << " " << e.second << endl;
            if(!visit[e.first]){
                int x = e.first;
                int distance = e.second;
                if (dis[x]<=dis[node]+distance) continue;
                dis[x]=dis[node]+distance;
                q.push(make_pair(dis[x],x));
            }
        }
    }
    
    cout << dis[n-1] << endl;

    /*
    rep(i,n){
        cout << dis[i] << " ";
    }
    cout << endl;
    */
    

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
