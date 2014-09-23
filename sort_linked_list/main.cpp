#include <iostream>
 // Definition for singly-linked list.
   struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
   };
   void insert(ListNode* &p, ListNode* &head){
        if(head==NULL){
            head=p;
            head->next=NULL;
            return;
        }
        std::cout<<"test"<<std::endl;
        ListNode* tmp=head;
        ListNode* prevs=tmp;
        while(tmp!=NULL&&(tmp->val<p->val)){
            prevs=tmp;
            tmp=tmp->next;
        }
        std::cout<<p->val<<std::endl;
        if(tmp==NULL){
              prevs->next=p;
              p->next=NULL;
        }else if(tmp==head){
            p->next=head;
            head=p;
        } else {
               p->next=tmp->next;
               tmp->next=p; 
        }
    }
    ListNode *insertionSortList(ListNode *head) {
        ListNode* tmp=head;
        ListNode* newhead=NULL;
        ListNode* next;
        while(tmp!=NULL){
            next=tmp->next;
            insert(tmp,newhead);
            tmp=next;
        }
        return newhead;
    }

   ListNode* merge(ListNode* lst1, ListNode* lst2){
         ListNode* newhead;
         ListNode* p1=lst1;
         ListNode* p2=lst2;
         std::cout<<p1->val<<" "<<p2->val<<std::endl;
         if(p1->val>p2->val||!lst1){
             newhead=p2;
             p2=p2->next;
         } else{
             newhead=p1;
             p1=p1->next;
         }
         ListNode *p=newhead;
         while(p1!=NULL||p2!=NULL){
                 //std::cout<<"test "<<std::endl;
             if(p1!=NULL&&(p2==NULL||p1->val<p2->val)){
                 //std::cout<<"test "<<p1->val<<std::endl;
                 p->next=p1;
                 p=p->next;
                 p1=p1->next;
             } else {
                 p->next=p2;
                 p=p->next;
                 p2=p2->next;
             }
         }
         p->next=NULL;
         std::cout<<"test "<<newhead->val<<std::endl;
         return newhead;
     }
     ListNode* merge_sort(ListNode* head){
         ListNode* tmp=head;
         int k=0;
         while(tmp!=NULL){
             tmp=tmp->next;
             k++;
         }
         //std::cout<<"test "<<k<<std::endl;
         if(k==0||k==1) return head;
       
         int m=k/2;
         int i=0;
         ListNode* med=head;
         while(i<m-1){
             med=med->next;
             i++;
         }
         ListNode* head2=med->next;
         med->next=NULL;
        ListNode* newhead1= merge_sort(head);
        ListNode* newhead2= merge_sort(head2);
        return merge(newhead1,newhead2);
     }
    ListNode *sortList(ListNode *head) {
        return merge_sort(head);
    }
int main(){

 ListNode* head=new ListNode(3);
 ListNode* p=new ListNode(2);
 ListNode* p1=new ListNode(4);
 head->next=p;
 p->next=p1;
/* ListNode* newhead=sortList(head);
 ListNode* tmp=newhead;
 while(tmp!=NULL){
   std::cout<<tmp->val<<std::endl;
   tmp=tmp->next; 
 }
 delete head;
delete p;
delete p1;
*/
 insertionSortList(head);
 ListNode* tmp=head;
 while(tmp!=NULL){
   std::cout<<tmp->val<<std::endl;
   tmp=tmp->next;
 }
 
return 0;
}
