#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll p[100010];
ll q[100010];
ll r[100010];

void solve(){

    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    rep(i,a){
        cin >> p[i];
    }
    rep(i,b){
        cin >> q[i];
    }
    rep(i,c){
        cin >> r[i];
    }
    sort(p,p+a,greater<ll>());
    sort(q,q+b,greater<ll>());
    sort(r,r+c,greater<ll>());

    priority_queue< ll,
      std::vector<ll>,
      std::greater<ll> > que;

      ll ans = 0;
    rep(i,x){
        que.push(p[i]);
        ans += p[i];
    }
    rep(i,y){
        que.push(q[i]);
        ans += q[i];
    }

    ll pointer=0;
    while(que.top()<r[pointer]){
        ans -= que.top();
        que.pop();
        ans += r[pointer];
        pointer++;
    }

    cout << ans << endl;



}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
