#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;
ll INF2 = 100000000000000009;

struct ver{
    ll p;
    ll q;
    ll r;
};

void solve(){

    ll n,m;
    cin >> n >> m;
    ver v[m];
    rep(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -c;
        v[i]=ver{a,b,c};
    }
    ll dis[n];
    rep(i,n){
        dis[i]=INF2;
    }
    dis[0]=0;

    rep(i,n){
        rep(j,m){
            ver tmp = v[j];
            dis[tmp.q]=min(dis[tmp.q],dis[tmp.p]+tmp.r);
        }
    }

    ll dis2[n];
    rep(i,n){
        dis2[i]=dis[i];
    }
    rep(j,m){
        ver tmp = v[j];
        dis[tmp.q]=min(dis[tmp.q],dis[tmp.p]+tmp.r);
    }

    bool b=true;
    /*
    rep(i,n){
        if(dis[i]!=dis2[i]){
            b=false;
            break;
        }
    }
    */
    if(dis2[n-1]!=dis[n-1]) b=false;

    if(b){
        cout << -dis[n-1] << endl;
    }
    else{
        cout << "inf" << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
