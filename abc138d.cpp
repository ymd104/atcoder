#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

/*
    1. c1,c2,...,cn=0とする
    2. 各クエリ(pj,xj):頂点pjおよびその子である全ての頂点にxjを加算する　について、cjにxjを加算
    3. ciについて、順番にiの親の値を加算

    エッジ(a,b)が与えられていたとして、aがbの親であるとは限らない
    例：
    1 2
    2 4
    3 4
    そのため、明示的に根に近い頂点から展開する必要がある
    ちなみに上のテストケース
    4 3
    1 2
    2 4
    3 4
    1 1000
    3 10
    4 100
    は、
    1000
    1000
    1110
    1100
    となるはずである
*/

void solve(){
    int n,q;
    cin >> n >> q;
    /*
    n = 4;
    q = 3;
    */
    vector<pair<int,int>> edge;
    
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        edge.emplace_back(make_pair(a,b));
    }
    
    /*
    edge.emplace_back(make_pair(1,2));
    edge.emplace_back(make_pair(2,3));
    edge.emplace_back(make_pair(2,4));
    */
    vector<pair<int,int>> query;
    
    rep(i,q){
        int p,x;
        cin >> p >> x;
        query.emplace_back(make_pair(p,x));
    }
    
    /*
    query.emplace_back(make_pair(2,10));
    query.emplace_back(make_pair(1,100));
    query.emplace_back(make_pair(3,1));
    */

    int c[n+10];
    rep(i,n+1){
        c[i] = 0;
    }
    rep(i,q){
        int p = query[i].first;
        c[p] += query[i].second;
    }

    //親を返すような配列を作る. この配列eは、e[i]=(iの親).
    int e[n+10];
    e[1] = 1;
    /*
    for(int i=0; i<n; i++){
        int a,b;
        a = edge[i].first;
        b = edge[i].second;
        e[b] = a;
    }
    */
    //edge[i]の頂点のどちらが親に近いかがわからない.
    //もしedge[i].firstがそれまでに走査した辺の右辺部分に現れていないのであれば、親ではない.
    //現れたかどうかをチェックする配列check[i]を用意する.
    bool check[n+10];
    rep(i,n+1){
        check[i]=false;
    }
    check[1] = true;
    for(int i=0; i<n; i++){
        int a,b;
        a = edge[i].first;
        b = edge[i].second;
        if(a==1){
            e[b] = a;
            check[b] = true;
        }
        else if(check[a]==false){
            e[a] = b;
            check[a] = true;
        }
        else{
            e[b] = a;
            check[b] = true;
        }
    }
    //cout << e[1] << " " << e[2] << " " << e[3] << " " << e[4] << endl;
    
    
    //根までの距離が近い順に並び替えるため、配列d[i]=(頂点iの根までの距離)を作る.
    int d[n+10];
    d[0]=0;
    d[1]=0;
    //各頂点jについて、d[j]=その頂点の親の距離+1.
    //親のdが未計算の場合、困る. そのため、エッジを順番に走査し、
    //エッジの片方のみが必ず距離が計算済みであるため、
    //頂点jの距離が計算済みかどうかをbool calculated[j]で保持.
    //edge(a,b)について、aが計算済みならaが親であり、d[b]=d[a]+1;
    bool calculated[n+10];
    rep(i,n+1){
        calculated[i]=false;
    }
    calculated[1]=true;
    for(int i=0; i<n-1; i++){
        int a = edge[i].first;
        int b = edge[i].second;
        if(calculated[a]==true){
            d[b] = d[a]+1;
            calculated[b] = true;
        }
        else{
            d[a] = d[b]+1;
            calculated[a] = true;
        }
    }
    
    //cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << endl;

    vector<pair<int,int>> distance;
    for(int i=1; i<=n; i++){
        distance.emplace_back(make_pair(d[i],i));
    }
    sort(distance.begin(), distance.end());

    //cout << distance[0].second << " " << distance[1].second << " " << distance[2].second << " " << distance[3].second <<  endl;


    for(int i = 1; i<n; i++){
        //各distance[i].secondについて、distance[i].secondの親の頂点jを探し出し、cjをciに加算する
        int j;
        int k = distance[i].second;
        //親の検索
        j = e[k];
        c[k] += c[j];
    }
    
    /*
    for(int i = 2; i<=n; i++){
        //各iについて、iの親の頂点jを探し出し、cjをciに加算する
        int j;
        //親の検索
        j = e[i];
        c[i] += c[j];
    }
    */

    rep(i,n){
        cout << c[i+1] << " ";
    }
    cout << endl;
}

int main(){
  solve();
  return 0;
}






//わかんないのでACしているコード読みます


#include <bits/stdc++.h>
using namespace std;


vector<int> ans;
vector<int> vec[200005]; 

/*
関数の引数内に代入文がある。
以下のコード
void dfs(int i, int p=1){
    cout << i + p << endl;
}
int main(void){
    dfs(2,3);
}
を参照する。このとき、
・dfs(1)->2を印字
・dfs(2,3)->５を印字
もう理解できるだろうけれど、引数を2つ指定しなければp=1で計算され、指定するとその値で計算するようだ。
*/
/*
２文目のは範囲for文と呼ばれるもので、
for(変数：配列)で、配列の中身を前から順に代入してループを回してくれる。
以下、分かりやすい例。
int ar[] = {1, 2, 3, 4, 5, 6, 7};
for(int x : ar) {
    cout << x << "\n";     // 1 2 3・・・7 と順に表示される
}
下のコードでは、変数uにvec[v]の中身を順番に代入していっている。
ちなみにvecは静的配列の動的配列。
*/
/*
3文目。continueはループを抜けた上で次のループへ移る文。
breakは完全にループを抜けてしまう文であったため、continueとは異なる。
*/
//4文目のatは[]による参照と概ね同じ。ただしこちらは範囲外山椒のときに例外を返す。
void dfs(int v ,int p = -1){
  for(int u : vec[v]){
    if(u==p) continue;
    ans.at(u) += ans.at(v);
    dfs(u,v);
  }
  
}

int main() {
  int n, q;
  cin >> n;
  cin >> q;
  
  
  /*
    何をしているかがわかりにくいので、例を挙げてやってみようと思う。
    エッジ：
    1 2
    2 3
    2 4

    このとき、vec[0]=1
    vec[1]=0,2,3
    vec[2]=1
    vec[3]=1
    すなわち、vec[i]は頂点i+1が繋がっている頂点(から1を引いたもの)の集合.
  */
  for (int i = 0; i < n - 1; i ++){
    int a, b;
    cin >> a;
    cin >> b;
    --a;
    --b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  
  
  ans.resize(n);

  for (int i = 0; i < q; i ++){
    int p, x;
    cin >> p;
    cin >> x;
    --p;
    
    ans[p] += x;
    
  }

  dfs(0);
  
  for(int i; i < n; i++){
    cout << ans[i] << endl;
  }
  

  
}
