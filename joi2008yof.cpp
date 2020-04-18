#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<pair<ll,ll>> adj[100010];
ll dis[110];
bool visit[110];

void solve(){

    ll n,k;
    cin >> n >> k;
    vector<ll> ans;

    ll nodenumber=0;

    rep(count,k){

    ll tmp;
    cin >> tmp;

    if(tmp==1){
        ll x,y,z;
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].emplace_back(make_pair(y,z));
        adj[y].emplace_back(make_pair(x,z));
        nodenumber++;
    }

    else{

        ll a,b;
        cin>>a>>b;
        a--;
        b--;

    rep(i,n){
        dis[i]=INF;
        visit[i]=false;
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push(make_pair(0,a));
    visit[a]=true;
    dis[a]=0;
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        ll d = p.first;
        ll node = p.second;
        if(dis[node]!=d) continue;
        visit[node] = true;
        for(auto e: adj[node]){
            if(!visit[e.first]){
                ll x = e.first;
                ll distance = e.second;
                if (dis[x]<=dis[node]+distance) continue;
                dis[x]=dis[node]+distance;
                q.push(make_pair(dis[x],x));
            }
        }
    }
    

    if(dis[b]!=INF) ans.emplace_back(dis[b]);
    else ans.emplace_back(-1);

    /*
    rep(i,nodenumber){
        cout << dis[i] << " ";
    }
    cout << endl;
    */

    }


    }

    for(auto e:ans){
        cout << e << endl;
    }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
