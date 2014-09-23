#include <iostream>
#include <map>
using namespace std;
struct Node{
        Node* next;
        Node* prev;
        pair<int,int> key_value;
        Node(int key, int value):key_value(make_pair(key,value)),next(NULL),prev(NULL){}
        Node(pair<int,int> &kv):key_value(kv),next(NULL),prev(NULL){}
    };
class LRUCache{
    Node* head;
    Node* tail;
    int size;
    int cp;
  public: 
    LRUCache(int capacity) {
        cp=capacity;
        size=0;
        head=NULL;
        tail=NULL;
    }
    
    int get(int key) {
        Node* p=head;
        while(p!=NULL){
            std::cout<<"test"<<std::endl;
            if((p->key_value).first==key) {
                int val=(p->key_value).second;
                if(p!=tail && p!=head){
                  p->prev->next=p->next;
                  p->next->prev=p->prev;
                  tail->next=p;
                  p->prev=tail;
                  p->next=NULL;
                  tail=p;
                } else if(p==head&&p!=tail){
                    p->next->prev=NULL;
                    head=p->next;
                    p->next=NULL;
                    tail->next=p;
                    p->prev=tail;
                    tail=p;
                }
                return val;
            }
            p=p->next;
        }
        return -1;
    }
    
    void set(int key, int value) {
       std::cout<<key<<" "<<value<<std::endl;
        pair<int,int> aim=make_pair(key,value);
       Node* p=head;
       while(p!=NULL){
           if(p->key_value==aim) { 
               return;
           }
           p=p->next;
       }
       if(size==cp){
           Node* tmp=head;
           head=head->next;
           if(head)
           head->prev=NULL;
           delete tmp;
           size--;
       }
       Node* newNode=new Node(aim);
       if(size==0){
           head=newNode;
           tail=newNode;
       } else {
          tail->next=newNode;
          newNode->prev=tail;
          tail=newNode;
       }
       size++;
      std::cout<<size<<std::endl;
      std::cout<<key<<" "<<value<<std::endl;
   } 
};
int main(){
 LRUCache test(1);
test.set(2,1);
std::cout<<test.get(2)<<std::endl;
std::cout<<"test......"<<std::endl;
test.set(3,2);
//std::cout<<"test......"<<std::endl;
std::cout<<test.get(2)<<std::endl;

 return 0;
}
