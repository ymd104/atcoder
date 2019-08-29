#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

/*
    バイトがn件あり、m日後までに受け取れる報酬の総和を最大化する。
    例：m=4、(4,3),(4,1),(2,2)
    ペア(a,b)について、
    ペアをaの値でソートし、頭から順に実行していく。
    ただし、残りi日のタイミングでiより大きいaを持つペアは消す。
    forループ。i=0からスタートし、i=m-1の間で、ペアの配列を順番に走査。
    配列のaがm-i<aであれば、配列の頭を削除し、続ける。
*/
/*
void solve(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        v.emplace_back(make_pair(a,b));
    }
    sort(v.rbegin(), v.rend());
    cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << " " << endl;
    int sum = 0;
    int pointer = 0;
    for(int i=0; i<m; i++){
        //int a = v[pointer].first;
        //int b = v[pointer].second;
        while(m-i<v[pointer].first){
            pointer++;
        }
        sum += v[pointer].second;
        pointer++;
    }
    cout << sum << endl;
}
*/
/*
これは正しくない。
*/

/*
正しいやり方。
制約の厳しい方から順に見ていく。すなわち、
i=1~mについて、a<=iを満たすペアの中で最もbが大きいものを取り出し、bを加算。
*/

void solve(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v1;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        v1.emplace_back(make_pair(a,-b));
    }
    //第一要素は昇順、第二要素は降順
    sort(v1.begin(), v1.end());
    vector<pair<int,int>> v;
    rep(i,n){
        int a,b;
        a = v1[i].first;
        b = v1[i].second;
        v.emplace_back(make_pair(a,-b));
    }
    int sum = 0;
    int pointer = 0;
    priority_queue<int> q;
    for(int i=1; i<=m; i++){
        //cout << "start!!!" << endl;
        //cout << i << " " << pointer << " " << v.at(pointer).first << " " << v.at(pointer).second << endl;
        while(pointer < v.size() && v.at(pointer).first <= i){
            //cout << "v.size:" << v.size() << " pointer:" << pointer << endl;
            q.push(v.at(pointer).second);
            pointer++;
        }
        if(!q.empty()) {
            //cout << "q.top():"<< q.top() << endl;
            sum += q.top();
            q.pop();
        }
    }
    cout << sum << endl;
}

int main(){
  solve();
  return 0;
}