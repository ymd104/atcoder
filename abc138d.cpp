#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<int> adj[200010];
int sum[200010];
bool visit[200010];

void solve(){

    int n,q;
    cin >> n >> q;
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    rep(i,n){
        sum[i]=0;
    }
    rep(i,q){
        int p,x;
        cin >> p >> x;
        p--;
        sum[p] += x;
    }

    stack<int> st;
    st.push(0);
    rep(i,n){
        visit[i]=false;
    }
    visit[0]=true;
    while(!st.empty()){
        int tmp;
        tmp = st.top();
        st.pop();
        visit[tmp]=true;
        for(auto e: adj[tmp]){
            if(!visit[e]){
                sum[e] += sum[tmp];
                st.push(e);
            }
        }
    }

    rep(i,n){
        cout << sum[i] << " "; 
    }
    cout << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
