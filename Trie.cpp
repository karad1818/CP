struct Trie{
    map<pair<ll,char>,ll>mp;  // it will store pointer of this location and data and it gives next node
    set<ll>end;
    ll last;
    void init(){
        last=0;
        mp.clear();
        end.clear();
    }
    void Create(string s){
        ll me=0;
        for(auto i : s){
            if(mp.count({me,i})){
                me=mp[{me,i}];
            }else{
                mp[{me,i}]=++last;
                me=last;
            }
        }
        end.I(me);
        return ;
    }
    bool Search(string s){
        ll me=0;
        for(auto i : s){
            if(mp.count({me,i})){
                me=mp[{me,i}];
            }else{
                return false;
            }
        }
        return end.count(me);
    }
    
};


//Using Node Structure


struct Node{
        char data;
        unordered_map<char,Node*>link;
        bool IsEnd;
        Node(char x){
            IsEnd=false;
            data=x;
        }
};
struct Trie{
    Node* root;
    
    Trie(){
        root= new Node('\0');
    }
    void Addword(string s){
        Node* temp=root;
        for(auto i : s){
            if(temp->link.count(i)){
                temp=temp->link[i];
            }else{
                Node* in = new Node(i);
                temp->link[i]=in;
                temp=in;
            }
        }
        temp->IsEnd=1;
    }
    bool IsPresent(string s){
        Node* temp=root;
        for(auto i : s){
            if(temp->link.count(i)){
                temp=temp->link[i];
            }else{
                return false;
            }
        }
        return temp->IsEnd;
    }
};
