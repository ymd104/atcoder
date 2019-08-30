#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)


void solve(){
  int n;
  cin >> n;
  int p[n+10];
  rep(i,n) {cin >> p[i];}
  
  int count=0;
  for(int i=1; i<n-1; i++){
    if( (p[i-1]<p[i]&&p[i]<p[i+1]) ||  (p[i-1]>p[i]&&p[i]>p[i+1]) ) {
       count++;
    }
  }
  cout << count << endl;
}

int main(){
  solve();
  return 0;
}