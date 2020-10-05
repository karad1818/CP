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
        if(head->left==NULL and head->right==NULL){
            if(head->val > val){
                newNode(head->left,val);
            }else{
                newNode(head->right,val);
            }
        }else{
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
};
