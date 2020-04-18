#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int problem[100010];
bool p[100010];

void solve(){

  int n,m;
  cin >> n >> m;

  rep(i,n){
      problem[i]=0;
      p[i]=false;
  }

  rep(i,m){
      int no;
      cin >> no;
      no--;
      string st;
      cin >> st;
      if(!p[no]){
          if(st=="WA"){
              problem[no]++;
          }
          else{
              p[no]=true;
          }
      }
  }

  int ans1=0;
  int ans2=0;

  rep(i,n){
      ans1 += p[i];
      if(p[i]) ans2 += problem[i];
      //cout << p[i] << " " << problem[i] << endl;
  }

  cout << ans1 << " " << ans2 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
