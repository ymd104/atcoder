/*
有向グラフにおけるトポロジカルソート(abc139e.cppより)
ve[i]:頂点iの先にある頂点の集合(vector<int>)
v[i]:頂点iへと繋がっている頂点の集合(vector<int>)
sortedがトポロジカルソートされた頂点の数列
*/
    vector<int> sorted;
    stack<int> st;
    rep(i,n){
        if(v[i].empty()){
            sorted.emplace_back(i);
            st.push(i);
        }
    }
    //入次数を管理する
    int g[n+10];
    rep(i,n){
        g[i] = v[i].size();
    }
    while(!stac.empty()){
        int tmp = stac.top();
        st.pop();
        for(int i:ve[tmp]){
            g[i]--;
            if(g[i]==0) {
                sorted.emplace_back(i);
                st.push(i);
            }

        }
    }

    //閉路検出. 最終的に取り出した数列に閉路があるなら-1を出力してreturnする
    if(sorted.size()!=n){
        cout << -1 << endl;
        return;
    }

    //最長パスの長さをmに格納する
    int d[n+10];
    fill(d,d+n+10,0);

    for(int i:sorted){
        for(int j:ve[i]){
            d[j] = max(d[j],d[i]+1);
        }
    }

    int m=0;
    rep(i,n){
        m = max(m,d[i]);
    }