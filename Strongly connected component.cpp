struct Tarjan{
    vector<ll>id,pre,lowlink;
    vector<ll>scc[100010];  //stores meta graph that are created.
    stack<ll>st;
    ll numSCC,n,m;  //numSCC is a number of SCC.
    ll preNum;
    vector<ll>adj[100010];
    void input(){
        cin>>n;
        cin>>m;
        while(m--){
            ll a,b;
            cin>>a>>b;
            adj[a].pb(b);
        }
    }
    void init(){
        id.assign(2*n,0);
        pre.assign(2*n,-1);
        lowlink.assign(2*n,0);
        numSCC=1;
        preNum=0;
        while(st.size())
            st.pop();
    }
    void Solve(){
        for(int i=1;i<=n;i++){
            if(pre[i]==-1){
                dfs(i);
            }
        }
    }
    void dfs(ll node){
        pre[node]=preNum++;
        lowlink[node]=pre[node];
        st.push(node);
        for(auto i : adj[node]){
            //forward edge
            if(pre[i]==-1){
                dfs(i);
            }
            //backedge
            lowlink[node]=min(lowlink[node],lowlink[i]);
        }
        //we are at root
        if(lowlink[node]==pre[node]){
            while(true){
                ll s=st.top();
                st.pop();
                //set id for SCC
                id[s]=numSCC;
                scc[numSCC].pb(s);
                //set lowlink as max
                lowlink[s]=INT_MAX;
                //if we are at root break;
                if(s==node)
                    break;
            }
            numSCC++;
        }
    }
};
