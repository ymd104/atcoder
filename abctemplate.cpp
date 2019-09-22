#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
  int n,k;
  cin >> n >> k;
  int p[n+10];
  vector<int> rev;
  bool b[n+10];
  rep(i,n){
    cin >> p[i];
    b[i]=false;
  }
  for(int i=1; i<n; i++){
    if(p[i-1]>p[i]) {
      rev.emplace_back(i-1);
      b[i-1] = true;
    }
  }
  b[n] = false;

  ll count=1;
  int bnum=0;
  int l=0;
  int r=k-1;
  bool tmp=false;
  rep(i,r){
    if(b[i]==true){
      tmp=true;
      bnum++;
    }
  }
  //if(tmp) count++;
  int flag=0;
  if(bnum==0) flag=1;
  int flag2 = 0;
  while(r<n){
    r++;
    l++;
    cout << l << ", " << r << " -> ";
    if(b[r-1]==true && b[l-1]==true) {
      count++;
      cout << "1" << endl;
    }
    else if(b[r-1]==true){
      count++;
      cout << "2" << endl;
      bnum = bnum+1;
    }
    else if(b[l-1]==true){
      count++;
      cout << "3" << endl;
      bnum = bnum-1;
    }
    else {
      cout << "4" << endl;
      flag2= 1;
    }
    if(bnum==0){
      if(flag==1){
        if(flag2==0)count--;
      }
      else{
        flag=1;
      }
    }

    flag2=0;
    cout << "----------" << count << endl;
    
  }
  ll t = max(count,(ll)1);
  cout << t << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}