#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
    int n;
    cin >> n;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    int b[n+10];
    rep(i,n){
        b[i]=0;
    }
    for(int i=n-1; i>=0; i--){
        int k=n/(i+1);
        int sum = 0;
        for(int j=1; j<=k; j++){
            sum += b[j*(i+1)-1];
        }
        if(sum%2==a[i]){
            b[i]=0;
        }
        else{
            b[i]=1;
        }
    }
    int count = 0;
    rep(i,n){
        if(b[i]==1){
            count++;
        }
    }
    cout << count << endl;
    rep(i,n){
        if(b[i]==1){
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

int main(){
  solve();
  return 0;
}