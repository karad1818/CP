struct segTree{
    //gives answer for range [l,r).  r is not inclusive.
    ll size;
    arr Tree,lazy;
    
    /*    Inialization    */
    void init(ll n){
        size=1;
        while(size<n) size*=2;
        Tree.assign(2*size,0LL);
        lazy.assign(2*size,0LL);
    }
    
    /*    Bulding a Tree    */
    void build(arr &a,ll index,ll l,ll r){
        if(r-l==1){
            if(l<(int)a.size())
                Tree[index]=a[l];
            return ;
        }
        ll mid=(l+r)>>1;
        build(a,index*2+1,l,mid);
        build(a,index*2+2,mid,r);
        Tree[index]=Tree[2*index+1]+Tree[2*index+2];
    }
    void build(arr &a){
        build(a,0,0,size);
    }
    
    /*  Point Updates  */
    void setPoint(ll setIndex,ll val,ll index,ll l,ll r){
        if(r-l==1){
            Tree[index]=val; //wants to increament then do Tree[index]+=val;
            return ;
        }
        ll mid=(l+r)/2;
        if(setIndex<mid){
            setPoint(setIndex,val,2*index+1,l,mid);
        }else{
            setPoint(setIndex,val,2*index+2,mid,r);
        }
        Tree[index]=Tree[2*index+1]+Tree[2*index+2];
    }
    void setPoint(ll index,ll val){
        setPoint(index,val,0,0,size);
    }
    
    /*   Range Updates   */
    void setRange(ll index,ll l,ll r,ll lx,ll rx,ll val){
        if(l>=rx or r<=lx)  return ;
        if(rx-lx==1){
            Tree[index]=val;  //wants to increament then do Tree[index]+=val;
            return ;
        }
        ll mid=(lx+rx)>>1;
        setRange(2*index+1,l,r,lx,mid,val);
        setRange(2*index+2,l,r,mid,rx,val);
        Tree[index]=Tree[2*index+1]+Tree[2*index+2];
    }
    void setRange(ll l,ll r,ll val){
        setRange(0,l,r,0,size,val);
    }
    
    /*   Lazy Range Updates   */
    void setRangeLazy(ll index,ll l,ll r,ll lx,ll rx,ll val){
        if(lazy[index]){
            if(rx-lx!=1){
                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }
            Tree[index]=lazy[index]*(rx-lx);  //wants to increament then do Tree[index]+=val;
            lazy[index]=0;
        }
        if(l>=rx or r<=lx)  return ;
        if(l<=lx and r>=rx){
            Tree[index]=val*(rx-lx);          //wants to increament then do Tree[index]+=val;
            if(rx-lx!=1){
                //for creating a lazy value
                lazy[2*index+1]+=val;
                lazy[2*index+2]+=val;
            }
            return ;
        }
        ll mid=(lx+rx)>>1;
        setRangeLazy(2*index+1,l,r,lx,mid,val);
        setRangeLazy(2*index+2,l,r,mid,rx,val);
        Tree[index]=Tree[2*index+1]+Tree[2*index+2];
    }
    void setRangeLazy(ll l,ll r,ll val){
        setRangeLazy(0,l,r,0,size,val);
    }
    
    /*   Lazy Range Query   */
    ll answerLazy(ll index,ll l,ll r,ll lx,ll rx){
        if(lazy[index]){
            if(rx-lx!=1){
                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }
            Tree[index]=lazy[index];  //wants to increament then do Tree[index]+=val;
            lazy[index]=0;
        }
        if(l >= rx or r <= lx)  return 0;
        if(l<=lx and r>=rx){
            return Tree[index];
        }
        ll mid=(lx+rx)/2;
        ll left=answerLazy(2*index+1,l,r,lx,mid);
        ll right=answerLazy(2*index+2,l,r,mid,rx);
        return left+right;
    }
    ll answerLazy(ll l,ll r){
        return answerLazy(0,l,r,0,size);
    }
    
    /*   Answer of range   */
    ll answer(ll l,ll r,ll index,ll lx,ll rx){
        if(l >= rx or r <= lx)  return 0;
        if(l<=lx and r>=rx){
            return Tree[index];
        }
        ll mid=(lx+rx)/2;
        ll left=answer(l,r,2*index+1,lx,mid);
        ll right=answer(l,r,2*index+2,mid,rx);
        return left+right;
    }
    ll answer(ll l,ll r){
        return answer(l,r,0,0,size);
    }
};
