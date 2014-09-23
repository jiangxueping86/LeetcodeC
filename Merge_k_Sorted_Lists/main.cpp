#include<iostream>
#include<vector>
 //Definition for singly-linked list.
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 }; 
ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0) return NULL;
        ListNode* head;
        ListNode* p;
        int index=999;
        if(lists[0]){
         p=lists[0];
         index=0;
        }
        for(int i=1;i<lists.size();i++){
            if(lists[i]&&lists[i]->val<p->val){
                p=lists[i];
                index=i;
            }
        }
        if(index==999) return NULL;
        head=p;
        //std::cout<<head->val<<std::endl;
        lists[index]=lists[index]->next;
        while(1){
            index=999;
          if(lists[0]){
              p->next=lists[0];
             index=0;
          }
          for(int i=1;i<lists.size();i++){
            if(lists[i]&&(!p->next||lists[i]->val<p->next->val)){
                 p->next=lists[i];
                index=i;
            }
          }
          if(index==999) break;
          lists[index]=lists[index]->next;
          p=p->next;
        }
        return head;
    }
int main() {
  ListNode* p1=new ListNode(1);
  p1->next=new ListNode(3);
//  ListNode* p1=&p;
  vector<ListNode*> lists;
  lists.push_back(NULL);
  lists.push_back(p1);
  ListNode* q1=new ListNode(-1);
  q1->next=new ListNode(10); 
lists.push_back(q1); 

  for(int i=0;i<lists.size();i++){
    ListNode* tmp=lists[i];
    while(tmp){
     std::cout<<tmp->val<<" ";
     tmp=tmp->next;
    }
    std::cout<<std::endl;
  }
  ListNode* newhead=mergeKLists(lists);
  while(newhead){
    std::cout<<newhead->val<<" ";
    newhead=newhead->next;
  }
  std::cout<<std::endl;
return 0;
}
