#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

//昇順かどうかを返す関数を作ったが、今回はこんなもの使わなくてもできる
bool sorted(vector<int> *p){
    vector<int> v = *p;
    int siz = v.size();
    bool ans=true;
    for(int i=1; i<siz; i++){
        if(v[i-1] > v[i]) ans = false;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p;
    rep(i,n){
        int tmp;
        cin >> tmp;
        p.emplace_back(tmp);
    }
    //cout << sorted(&p) << endl;
    int count=0;
    rep(i,n){
        if(p[i]!=i+1) count++;
    }
    if(count==0||count==2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
  solve();
  return 0;
}