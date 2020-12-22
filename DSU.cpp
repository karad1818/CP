struct DSU{
    // forest starts from 1....n
    // rank defines size of tree
    vector<int>rank;
    vector<int>parent;
    vector<int>mn;
    int component;
    void init(int n){
        component=n;
        rank.assign(n+1,1);
        mn.assign(n+1,1);
        rank[0]=0;
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i]=i,mn[i]=i;
    }
    int get_parent(int x){
        return (parent[x]==x?x:parent[x]=get_parent(parent[x]));
    }
    int get_min(int x){
        return mn[get_parent(x)];
    }
    int get_size(int x){
        return rank[get_parent(x)];
    }
    bool merge(int x,int y){
        x=get_parent(x);
        y=get_parent(y);
        if(x==y){
            return false;
        }
        if(rank[y]>rank[x]){
            swap(x,y);
        }
        mn[x]=min(mn[x],mn[y]); //any operation you can perform like this
        parent[y]=x;
        rank[x]+=rank[y];
        rank[y]=0;
        component--;
        return true;
    }
};
