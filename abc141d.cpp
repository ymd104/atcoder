#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int n,m;
    cin >> n >> m;
    int a[n+10];
    priority_queue<int> que;
    rep(i,n){
      cin >> a[i];
      que.push(a[i]);
    }
    /*
    rep(i,m){
      int ma = 0;
      int pointer = 0;
      rep(j,n){
        if(ma<a[j]) {
          pointer =j;
          ma = a[j];
        }
      }
      a[pointer] = a[pointer]/2;
    }
    ll sum=0;
    rep(i,n){
      sum += a[i];
    }
    cout << sum << endl;
    */
    rep(i,m){
      int tmp = que.top();
      que.pop();
      que.push(tmp/2);
    }
    ll sum = 0;
    rep(i,n){
      sum += que.top();
      que.pop();
    }
    cout << sum << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
