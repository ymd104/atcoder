#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

bool oddDigit(int i){
    int count = 1;
    while(i>=10){
        i /= 10;
        count++;
    }
    return count%2==1;
}

void solve(){
    int n;
    cin >> n;
    int count = 0;
    for(int i=n; i>=1; i--){
        if(oddDigit(i)) count++;
    }
    cout << count << endl;
}

int main(){
  solve();
  return 0;
}
