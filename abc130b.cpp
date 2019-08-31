#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;


void solve(){
  int n,x;
  cin >> n >> x;
  int L[n+10];
  rep(i,n){
    cin >> L[i]; 
  }
  int count = 0;
  int sum = 0;
  while(sum <= x){
    sum += L[count];
    count ++ ;
  }
  cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}