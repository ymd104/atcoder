#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

/*

各山に降った雨を2*x[i]とすると、
x[0]+x[1]=a[0]
x[1]+x[2]=a[1]
x[2]+x[3]=a[2]
...
x[n-2]+x[n-1]=a[n-2]
x[n-1]+x[0]=a[n-1]

例えば、n=5とする
x[0]+x[1]=a[0]
x[1]+x[2]=a[1]
x[2]+x[3]=a[2]
x[3]+x[4]=a[3]
x[4]+x[0]=a[4]
aの総和をSとすると、
x[0]=a[0]+a[2]+a[4]-S/2

一般に、
x[0]=a[0]+a[2]+...+a[n-1]-S/2
以降、各i=1~n-1について、
x[i]=a[i-1]-x[x-1]
*/

void solve(){
    int n;
    cin >> n;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    int sum=0;
    rep(i,n){
        sum += a[i];
    }
    vector<int> x;
    int tmp=0;
    for(int i=0; i!=n+1; i += 2){
        tmp += a[i];
    }
    x.emplace_back(tmp - (sum)/2);
    for(int i=1; i<=n-1; i++){
        x.emplace_back(a[i-1]-x[i-1]);
    }
    x.emplace_back(a[n]-x[0]);

    rep(i,n){
        cout << 2 * x[i] << " ";
    }
    cout << endl;
}

int main(){
  solve();
  return 0;
}