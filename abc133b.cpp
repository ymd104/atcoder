#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

void solve(){
  int n,d;
  cin >> n >> d;
  double x[15][15];
  rep(i,n){
    rep(j,d){
      cin >> x[i][j];
    } 
  }
  int count = 0;
  for(int i=0; i<n; i++){
    for(int k=0; k<n; k++){
    double sum = 0;
    rep(j,d){
      sum += pow((x[k][j] - x[i][j]), 2); 
    }
    if(sum == pow((int)sqrt(sum),2) && i!=k){
      count++; 
    }
    }
  }
  cout << count/2 << endl;
}

int main(){
  solve();
  return 0;
}