#include<iostream>
#include<vector>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
void display(ListNode* head);
ListNode *reverseLinkedList(ListNode *&head){
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* p=head;
        ListNode* q=head->next;
        ListNode* w=q->next;
        p->next=NULL;
        while(q){
        q->next=p;
        p=q;
        q=w;
        if(w)
          w=w->next;
        }
        return p;
    }
  ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head||!head->next||k==0||k==1) return head;
        ListNode* p=head;
        int i=1;
        ListNode* q;
        ListNode* next_round=NULL;
        ListNode* prev_round=NULL;
        ListNode* current_round=NULL;
        while(p){
            i=1;
            q=p;
           while(i<k){
             q=q->next;
             if(!q) break;
             i++;
           }
           if(!q) break;
           next_round=q->next;
           q->next=NULL;
           current_round=reverseLinkedList(p);//After reverse, p is the end and current_round is the head
           if(prev_round){
              prev_round->next=current_round;
           } else{
               head=current_round;
           }
           prev_round=p;
           p=next_round;
        }
       if(prev_round){
        prev_round->next=p;
       }
        return head;
    }
void display(ListNode* head){
  while(head!=NULL){
    std::cout<<head->val<<" ";
    head=head->next; 
 }
  std::cout<<std::endl;
}
int main(){
 ListNode* head=new ListNode(1);
 ListNode* p=head;
 for(int i=2;i<3;i++){
   p->next=new ListNode(i);
   p=p->next;
 }
 display(head);
 //ListNode* newhead=reverseLinkedList(head);
 //display(newhead);  
 ListNode* newhead2=reverseKGroup(head, 3); 
 display(newhead2); 
return 0;
}
