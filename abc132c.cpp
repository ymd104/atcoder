#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)


void solve(){
  int n;
  cin >> n;
  int d[n+10];
  rep(i,n) {cin >> d[i];}
  
  sort(d,d+n);
  int mid = n/2;
  cout << d[mid] - d[mid-1] << endl;
}

int main(){
  solve();
  return 0;
}