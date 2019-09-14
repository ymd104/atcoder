#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int l,r;
    cin >> l >> r;
    vector<int> v;
    if(r-l>2019){
        cout << 0 << endl;
    }
    else{
    for(int i=l; i<=r; i++){
        v.emplace_back(i%2019);
    }
    int m = (v[0]*v[1])%2019;
    int n=v.size();
    rep(i,n){
        rep(j,n){
            if(i!=j){
                m = min(m, (v[i]*v[j])%2019);
            }
        }
    }
    cout << m << endl;
    }
}

int main(){
  solve();
  return 0;
}