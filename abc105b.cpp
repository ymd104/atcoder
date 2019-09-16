#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


/*
 1  2  3  4  5  6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28

1 2 3 5 6 9 10 13 17 
*/
void solve(){
    int n;
    cin >> n;
    set<int> st{1,2,3,5,6,9,10,13,17};
    if(st.count(n)==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
