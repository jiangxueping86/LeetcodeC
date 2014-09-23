#include <iostream>
#include <map>
using namespace std;
struct Node{
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(int k, int value):key(k),val(value),next(NULL),prev(NULL){}
    };
class LRUCache{
    Node* head;
    Node* tail;
    map<int,Node*> content;
    //int size;
    int cp;
  public: 
    LRUCache(int capacity) {
        cp=capacity;
        head=NULL;
        tail=NULL;
    }
    void delete_head(){
          Node* tmp=head;
           head=head->next;
           if(head)
           head->prev=NULL;
           delete tmp;
    }    
    void insert_Node(Node* newNode){
       if(head==NULL){
           head=newNode;
           tail=newNode;
       } else {
          tail->next=newNode;
          newNode->prev=tail;
          tail=tail->next;
       }   
   }
   void  move_to_tail(Node* p){
                if(p==tail){
                   return;
               } else if(p!=head){
                  p->prev->next=p->next;
                  p->next->prev=p->prev;
                  tail->next=p;
                  p->prev=tail;
                  p->next=NULL;
                  tail=p;
                } else {
                    p->next->prev=NULL;
                    head=p->next;
                    p->next=NULL;
                    tail->next=p;
                    p->prev=tail;
                    tail=p;
                }
   }
    int get(int key) {
       if(content.find(key)!=content.end()){
          Node* aim=content[key];
          move_to_tail(aim);
          return aim->val;
       }
        return -1;
    }
    
    void set(int key, int value) {
       std::cout<<key<<" "<<value<<std::endl;
        pair<int,int> aim=make_pair(key,value);
       Node* p=head;
      if(content.find(key)!=content.end()){
         move_to_tail(content[key]);
         content[key]->val=value;
         return;
      } 
      if(content.size()==cp){
           content.erase(head->key);
           delete_head();
       }
       Node* newNode=new Node(key,value);
       content[key]=newNode;
       insert_Node(newNode);
   } 
};
int main(){
 LRUCache test(1);
test.set(2,1);
std::cout<<test.get(2)<<std::endl;
//test.set(3,2);
//std::cout<<"test......"<<std::endl;
//std::cout<<test.get(2)<<std::endl;

 return 0;
}
