#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
奇数数列および偶数数列をソートして、最大個数要素および次に多い要素のペアを確保する
*/

void solve(){
    int n;
    cin >> n;
    vector<int> v1, v2;
    bool odd = true;
    rep(i,n){
        int tmp;
        cin >> tmp;
        if(odd) {
            v1.emplace_back(tmp);
            odd = false;
        }
        else{
            v2.emplace_back(tmp);
            odd = true;
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int pointer=0;
    int p2 = 0;
    int s = v1.size();
    vector<pair<int,int>> a1,a2;
    a1.emplace_back(make_pair(1,v1[0]));
    while(pointer<s-1){
        if(v1[pointer]!=v1[pointer+1]){
            a1.emplace_back(make_pair(1, v1[pointer+1]));
            p2++;
        }
        else{
            a1[p2].first++;
        }
        pointer++;
    }
    pointer = 0;
    p2 = 0;
    a2.emplace_back(make_pair(1,v2[0]));
    while(pointer<s-1){
        if(v2[pointer]!=v2[pointer+1]){
            a2.emplace_back(make_pair(1, v2[pointer+1]));
            p2++;
        }
        else{
            a2[p2].first++;
        }
        pointer++;
    }
    //cout << a1[0].first << " " << a1[0].second << endl;
    //cout << a2[0].first << " " << a2[0].second << endl;

    sort(a1.rbegin(), a1.rend());
    sort(a2.rbegin(), a2.rend());
    //cout << a1[0].first << " " << a1[0].second << endl;
    //cout << a2[0].first << " " << a2[0].second << endl;

    if(a1.size()!=1 && a2.size()!=1){
        if(a1[0].second!=a2[0].second){
            cout << n-(a1[0].first+a2[0].first) << endl;
        }
        else{
            cout << n - max(a1[0].first+a2[1].first, a1[1].first+a2[0].first) << endl;
        }
    }
    else{
        if(a1.size()!=1){
            if(a1[0].second!=a2[0].second){
                cout << n-(a1[0].first+a2[0].first) << endl;
            }
            else{
                cout << n - a1[1].first+a2[0].first << endl;
            }
        }
        else if(a2.size()!=1){
            if(a1[0].second!=a2[0].second){
                cout << n-(a1[0].first+a2[0].first) << endl;
            }
            else{
                cout << n - a1[0].first+a2[1].first << endl;
            }
        }
        else{
            if(a1[0].second!=a2[0].second){
                cout << n-(a1[0].first+a2[0].first) << endl;
            }
            else{
                cout << n/2 << endl;
            }
        }
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
