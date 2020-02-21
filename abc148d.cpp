#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*

左から、1 2 3 4 ...の部分列が存在するかどうか

3 1 4 1 5 9 2 6 5 3

0 1 1 1 1 1 2 2 2 3

*/


int a[200010];
int b[200010];

void solve(){

    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }

    rep(i,n){
        b[i]=-1;
    }

    if(a[0]==1){
        b[0]=1;
    }
    else{
        b[0]=0;
    }
    for(int i = 1; i<n; i++){
        if(b[i-1]+1==a[i]){
            b[i]=a[i];
        }
        else{
            b[i]=b[i-1];
        }
        //cout << i << " " << b[i] << endl;
    }
    if(b[n-1]!=0){
        cout << n-b[n-1] << endl;
    }
    else{
        cout << -1 << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
