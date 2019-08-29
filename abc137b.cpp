#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int k,x;
    cin >> k >> x;
    int mi,ma;
    mi = x-k+1;
    ma = x+k-1;
    while(mi<=ma){
        cout << mi << " ";
        mi++;
    }
    cout << endl;
}


int main(){
  solve();
  return 0;
}