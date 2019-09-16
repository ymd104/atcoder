#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


int digitsum(int a){
    int sum=0;
    while(a!=0){
        sum += a%10;
        a = a/10;
    }
    return sum;
}

void solve(){
    int n;
    cin >> n;
    if(n%digitsum(n)==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
