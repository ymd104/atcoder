#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    double n,d;
    cin >> n >> d;
    cout << ceil(n/(2*d+1)) << endl;
}

int main(){
  solve();
  return 0;
}