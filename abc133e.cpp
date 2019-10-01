#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
任意の頂点について、
・その頂点と繋がっている全ての頂点について、それぞれ色が異なる
*/

ll p[100010];
//p[i]=nPi= n* (n-1) * (n-2) * ... * (n-i+1)
void cal(ll x){
    rep(i,100010){
        p[i]=0;
    }
    ll tmp=1;
    p[0]=1;
    for(ll i = 1; i<=x; i++){
        tmp = (tmp * (x-i+1)) % MOD;
        p[i]=tmp;
    }
}

void solve(){
    ll n,k;
    cin >> n >> k;
    vector<ll> ch[n+10];
    ll chn[n+10];
    rep(i,n+10){
        chn[i]=0;
    }
    vector<ll> pa[n+10];
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        ch[a].emplace_back(b);
        chn[a]++;     
        ch[b].emplace_back(a);
        chn[b]++;
    }
    rep(i,n+10){
        chn[i]--;
    }
    ll ans=k; //親に塗る
    cal(k-1);
    chn[1]++;
    ans = (ans * p[chn[1]])%MOD;

    /*
    rep(i,n){
        cout << chn[i+1] << endl; 
    }
    */
    /*
    rep(i,k){
        cout << p[i] << endl;
    }
    */
    
    

    cal(k-2);
    stack<ll> st;
    st.push(1);
    bool visited[n+10];
    rep(i,n+1){
        visited[i]=false;
    }
    visited[1]=true;
    while(!st.empty()){
        ll tmp = st.top();
        st.pop();
        for(ll i:ch[tmp]){
            if(!visited[i]){
                //cout << i << " " << chn[i] << endl;
                //cout << i << " " << ans << " " << p[chn[i]] << endl;
                ans = (ans * p[chn[i]])%MOD;
                st.push(i);
                visited[i]=true;
            }
        }
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}