#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int l,r;
    cin >> l >> r;
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=l; i<=r; i++){
        que.push(i%2019);
    }
    int a,b;
    a = que.top();
    que.pop();
    b = que.top();
    cout << a*b << endl;
}

int main(){
  solve();
  return 0;
}