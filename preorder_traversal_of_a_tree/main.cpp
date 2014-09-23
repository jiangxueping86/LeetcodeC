 stack<TreeNode*> sta;
        if(root!=NULL){
         sta.push(root);
        }
        vector<int> answer;
        while(!sta.empty()){
            TreeNode* p=sta.top();
            sta.pop();
            answer.push_back(p->val);
             if(p->right!=NULL){
                sta.push(p->right);
            }
            if(p->left!=NULL){
                sta.push(p->left);
            } 
           
        }
        return answer;
