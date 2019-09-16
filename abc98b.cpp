#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

int num(string a, string b){
    int as,bs;
    as = a.size();
    bs = b.size();
    set<char> sta, stb, result;
    rep(i,as){
        sta.insert(a[i]);
    }
    rep(i,bs){
        stb.insert(b[i]);
    }

    set_intersection(sta.begin(), sta.end(),
                        stb.begin(), stb.end(),
                        std::inserter(result, result.end()));
    return result.size();

}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 0;
    for(int i=0; i<n; i++){
        string t1,t2;
        t1 = s.substr(0,i+1);
        t2 = s.substr(i+1,n-1);
        //cout << t1 << " " << t2 << endl;
        m = max(m, num(t1,t2));
    }
    //cout << num("aab","bca") << endl;
    cout << m << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
