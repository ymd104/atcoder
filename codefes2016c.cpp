#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


/*
sの中で、
・aまでの距離がk以下であるもののうち、もっとも左にあるものを選ぶ
・全てaになれば、もっとも右にあるもので残りを回す
*/


void solve(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int i=0;
    int siz = s.size();
    while(i<siz){
        if((26-(s[i]-'a'))<=k&&s[i]!='a'){
            k = k-(26-(s[i]-'a'));
            //cout << k << endl;
            s[i]='a';
            //i=0;
            //break;
        }
        else{
            i++;
        }
    }
    char c = s[siz-1];
    //c-'a'とkの和が26を超えていたら、26で割った余りをとる
    c = ((c-'a')+k)%26 + 'a';
    s[siz-1] = c;

    cout << s << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
