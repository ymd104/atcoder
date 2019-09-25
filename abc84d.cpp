#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
1~100000までの数それぞれについて、
・1以上i以下の数で、2017に似ている数の個数
を保持するs[i]を定義し、各クエリでs[r]-s[l-1]を計算する
*/

bool isprime(int x){
    int threshold = sqrt(x)+1;
    if(x==2) return true;
    for(int i=2; i<=threshold; i++){
        if(x%i==0) {
            return false;
        }
    }
    return true;
}

int s[100010];

void solve(){
    int q;
    cin >> q;
    rep(i,100001){
        if(i==0) s[i]=0;
        else if(i==1) s[i]=0;
        else if(i==2) s[i]=0;
        else{
            if(isprime(i)&&isprime((i+1)/2)) s[i]=s[i-1]+1;
            else s[i]=s[i-1];
        }
    }
    /*
    rep(i,100){
        cout << 2*i+3 << ":" << s[2*i+3] << endl;
    }
    cout << endl;
    */
    vector<int> ans;
    rep(i,q){
        int l,r;
        cin >> l >> r;
        ans.emplace_back(s[r]-s[l-1]);
    }
    rep(i,q){
        cout << ans[i] << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

