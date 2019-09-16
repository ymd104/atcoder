#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

int divisor(int x){
    int count = 0;
    rep(i,x){
        if(x%(i+1)==0) count++;
    }
    return count;
}

void solve(){
    int n;
    cin >> n;
    int c = 0;
    rep(i,n){
        if((i+1)%2==1 && divisor(i+1)==8) c++;
    }
    cout << c << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
