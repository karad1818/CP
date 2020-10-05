struct Node{
    ll val;
    Node* left;
    Node* right;
};
struct Tree{
    Node* head;
    void init(){
        head = new Node();
        head->val=INT_MAX;
        head->left=NULL;
        head->right=NULL;
    }
    void newNode(Node* &h,ll val){
        h = new Node();
        h->val=val;
        h->left=NULL;
        h->right=NULL;
        return ;
    }
    void CreateNode(Node* head,ll val){
        if(head->val>val){
            if(head->left==NULL){
                newNode(head->left,val);
            }else
                CreateNode(head->left,val);
        }else{
            if(head->right==NULL){
                newNode(head->right,val);
            }else
                CreateNode(head->right,val);
        }
    }
    void CreateNode(ll val){
        if(head->val==INT_MAX){
            head->val=val;
            return ;
        }
        CreateNode(head,val);
    }
    arr BFSTraversal(){
        arr ans;
        queue<Node*>q;
        q.push(head);
        while(!q.empty()){
            Node* x=q.front();
            ans.pb(x->val);
            q.pop();
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
        }
        return ans;
    }
    void InorderTraversal(Node* head,arr& ans){
        if(head->left){
            InorderTraversal(head->left,ans);
        }
        ans.pb(head->val);
        if(head->right){
            InorderTraversal(head->right,ans);
        }
    }
    arr InorderTraversal(){
        arr ans;
        InorderTraversal(head,ans);
        return ans;
    }
    void PreorderTraversal(Node* head,arr& ans){
        ans.pb(head->val);
        if(head->left){
            PreorderTraversal(head->left,ans);
        }
        if(head->right){
            PreorderTraversal(head->right,ans);
        }
    }
    arr PreorderTraversal(){
        arr ans;
        PreorderTraversal(head,ans);
        return ans;
    }
    void PostorderTraversal(Node* head,arr& ans){
        if(head->left){
            PostorderTraversal(head->left,ans);
        }
        if(head->right){
            PostorderTraversal(head->right,ans);
        }
        ans.pb(head->val);
    }
    arr PostorderTraversal(){
        arr ans;
        PostorderTraversal(head,ans);
        return ans;
    }
    
};
