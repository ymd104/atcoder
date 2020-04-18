#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[1000010];

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,n){
        a[i] = s[i]-'0';
    }

    if(n==2){
        cout << abs(a[0]-a[1]) << endl;
        return;
    }
    if(n==3){
        cout << abs(abs(a[0]-a[1]) - abs(a[1]-a[2])) << endl;
        return;
    }
    
    rep(i,3){
        rep(j,n-i-1){
            a[j]=abs(a[j+1]-a[j]);
        }
        rep(j,n-i-1){
            //cout << a[j];
        }
        //cout << endl;
    }
    
    //n-3要素の行列
    int b1=0;
    int b2=0;
    if(a[0]!=0) b1=a[0];
    if(a[n-4]!=0) b2=a[n-4];
    rep(i,n-3){
        if(i!=0&&a[i]!=0) b1=0;
        if(i!=n-4&&a[i]!=0) b2=0;
    }
    if(b1!=0) {
        cout << b1 << endl;
        return;
    }
    if(b2!=0) {
        cout << b2 << endl;
        return;
    }
    cout << 0 << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
