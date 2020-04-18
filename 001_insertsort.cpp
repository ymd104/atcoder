#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[110];

void solve(){
    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    
    rep(i,n-1){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;

    rep(i,n){
        if(i==0) continue;
        int key = a[i];
        int j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;

        rep(i,n-1){
        cout << a[i] << " ";
        }
        cout << a[n-1] << endl;
    }
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
