#include<iostream>


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

   struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


 TreeNode* sortedListToBST(ListNode *& list, int start, int end) {
  if (start > end) return NULL;
  // same as (start+end)/2, avoids overflow
  int mid = start + (end - start) / 2;
  TreeNode *leftChild = sortedListToBST(list, start, mid-1);
  TreeNode *parent = new TreeNode(list->val);
  parent->left = leftChild;
  list = list->next;
  parent->right = sortedListToBST(list, mid+1, end);
  std::cout<<parent->val<<std::endl;
  return parent;
}

TreeNode* sortedListToBST(ListNode *head) {
    ListNode* tmp=head;
    int n=0;
    while(tmp!=NULL){
        tmp=tmp->next;
        n++;
    }
  return sortedListToBST(head, 0, n-1);
}

int main(){
 ListNode* p=new ListNode(0);
 ListNode* head=p;
 int i=1; 
 while(i<4){
  p->next=new ListNode(i);
  p=p->next;
    i++;
 }
  sortedListToBST(head);
  return 0;
}

