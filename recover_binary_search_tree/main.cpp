#include<iostream>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
     void inorder_tranversal(TreeNode* p, bool &found1, bool &found2, TreeNode* &first, TreeNode* &second, TreeNode* &rem){
        if(p==NULL||found1&&found2) return;
        inorder_tranversal(p->left, found1, found2,first,second,rem);
        if(rem==NULL){
            rem=p;
            cout<<"test"<<std::endl;
        } else {
           //cout<<"test"<<std::endl;
           if(p->val<rem->val&&!found1){
              first=rem;
              cout<<first->val<<std::endl;
              found1=true;
           } else if(p->val<rem->val&&found1){
            found2=true;
            second=p;
           }
           rem=p;
        }
        inorder_tranversal(p->right,found1,found2,first,second,rem);
    }
    void recoverTree(TreeNode *root) {
          if(!root) return;
          TreeNode* first=NULL,*rem=NULL,*second=NULL;
          bool found1=false, found2=false;
        inorder_tranversal(root, found1, found2, first,second,rem);
        if(!found1&&!found2) { 
           cout<<"test"<<std::endl; 
           return;}
        if(found1&&!found2) {
           cout<<"test....."<<std::endl;
            if(first==root) second=root->right;
            else second=root;
        }
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
int main(){
 TreeNode* root=new TreeNode(0);
 root->left=new TreeNode(1);
 recoverTree(root);
 cout<<root->val<<" "<<root->left->val<<std::endl; 
return 0;
}
