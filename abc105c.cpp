#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
偶数なら末尾は0、奇数なら末尾は1
それを取り除いた残りの数について、-2で割って繰り返す
*/

string s;

void base2(ll x){
    if(x==1||x==0) s += (to_string(x));
    else{
        if(x%2==0) {
            s += (to_string(0));
            base2(x/(-2));
        }
        else {
            s += (to_string(1));
            base2((x-1)/(-2));
        }
    }
}

void solve(){
    int n;
    cin >> n;
    base2(n);
    reverse(s.begin(), s.end());
    cout << s << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
