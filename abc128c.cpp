#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

/*
全探索
*/
string binary(int bina, int num){
    string ans = "";
    for (int i = 0; i<num ; i++)
    {
        ans = to_string(bina%2) + ans;
        bina = bina/2;
    }
    return ans;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<pair<int, vector<int>>> vec;
    rep(i,m){
        int k;
        vector<int> v;
        cin >> k;
        rep(j,k){
            int s;
            cin >> s;
            v.emplace_back(s);
        }
        vec.emplace_back(make_pair(k,v));
    }
    vector<int> p;
    rep(i,m){
        int tmp;
        cin >> tmp;
        p.emplace_back(tmp);
    }
    bool b[n];
    rep(i,n){
        b[i] = false;
    }
    /*
    配列bを整数値iで表現する。
    i -> bの変換
    iを二進法表記

    各bのパターンについて、
    vecの各要素vec[j]={s[0],s[1],...,s[k-1]}を考え、
    int tmp=0;
    b[s[x]]==trueならtmp++
    tmpの偶奇がp[j]に一致すればok。
    これが任意のjで成立すれば、count++
    */
    
    int count = 0;
    rep(i,pow(2,n)){
        rep(j,n){
            char chr=binary(i,n)[j];
            if(chr=='1') b[j]=true;
            else b[j]=false;
        }
        //cout << binary(i,n) << endl;

        bool ok=true;
        rep(j,m){
            int k=vec[j].first;
            vector<int> s = vec[j].second;
            int tmp=0;
            rep(x,k){
                if(b[s[x]-1]==true) tmp++;
            }
            //cout << "i:" << binary(i,n) << ", " << j << "番目の電球：" << tmp << endl;
            if(tmp%2!=p[j]) ok=false;
        }
        if(ok) count++;
    }

    cout << count << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}