#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){
  ll n,m;
  cin >> n >> m;
  vector<pair<ll, vector<ll>>> v;
  vector<pair<long double,ll>> vt;
  rep(i,m){
    ll a;
    ll b;
    cin >> a >> b;
    vector<ll> vec;
    rep(i,b){
      ll c;
      cin >> c;
      vec.emplace_back(c);
    }
    long double t1,t2;
    t1 = (long double)a;
    t2 = (long double)b;
    v.emplace_back(make_pair(a, vec));
    vt.emplace_back(make_pair(t1/t2,i));
  }

  ll count[n+10];
  rep(i,n){
    count[i]=0;
  }
  
  rep(i,m){
    vector<ll> ve = v[i].second;
    ll n = ve.size();
    rep(j,n){
      count[ve[j]-1]++;
    }
  }

  bool t = true;
    rep(j,n){
      if(count[j]==0) t=false;
    }
  
  //sort(v.begin(),v.end(), greater<int>());
  sort(vt.begin(),vt.end());
  reverse(vt.begin(),vt.end());
  //cout << vt[0].first  << endl;
  //cout << count[0] << count[1] << endl;

  ll sum = 0;
  rep(i,m){
    ll tmp = vt[i].second;
    sum += v[tmp].first;
  }
  rep(i,m){
    ll tmp = vt[i].second;
    bool b=true;
    vector<ll> ve = v[tmp].second;
    ll n=ve.size();
    rep(j,n){
      if(count[ve[j]-1]<=1){
        b = false;
      }
    }
    if(b) {
      sum = sum - v[tmp].first;
      rep(j,n){
        count[ve[j]-1]--;
      }
    }
    
    
    if(!t){
      sum = -1;
      break;
    }
    
  }

  cout << sum << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}