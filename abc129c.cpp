#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

void solve(){
  long n,m;
  cin >> n >> m;
  long a[m];
  rep(i,m){
    long k;
    cin >> k;
    a[i]=k;
  }
  long vec[n+1];
  vec[0] = 1;
  int j=0; //壊れた床へのポインタ
  if(a[0]==1) {vec[1]=0; 
               j=1;
              }
  else vec[1] = 1;
  for(int i=2; i<=n; i++){
    if(a[j]==i) {vec[i]=0; 
    j++;}
    else{
      vec[i]=(vec[i-1]+vec[i-2]) % 1000000007;
    }
  }
  //rep(i,n+1) cout << vec[i] << endl;
  cout << vec[n] << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}