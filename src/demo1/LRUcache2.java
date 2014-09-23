package demo1;


public class LRUcache2 {
	int capacity;
    Node head;
    Node end;
    int size;
	    class Node{
	        private int key;
	        private int value;
	        public Node next;
	        public Node prev;
	        public Node(int key, int value){
	        	this.key=key;
	        	this.value=value;
	            next=prev=null;
	        }
	        public int getValue(){
	        	return value;
	        }
	        public int getKey(){
	        	return key;
	        }
	    }
	    public LRUcache2(int capacity) {
	        this.capacity=capacity;
	        head=end=null;
	    }
	    
	    public int get(int key) {
	        int result=-1;
	        Node tmp=head;
	        while(tmp!=null){
	        	if(tmp.getKey()==key){
	        		result=tmp.getValue();
	        		if(tmp!=head){
	        			tmp.prev.next=tmp.next;
	        			if(tmp!=end)
	        			   tmp.next.prev=tmp.prev;
	        			else 
	        			   end=end.prev;
	        			tmp.next=head;
	        			head.prev=tmp;
	        			tmp.prev=null;
	        			head=tmp;
	                    
	        		}
	        	}
	        	tmp=tmp.next;
	        }
	        return result;
	    }
	    
	    public void set(int key, int value) {
	        if(get(key)!=-1){
	        	return;
	        } 
	        if(size==capacity){
	        	if(size==1){
	        	   head=end=null;
	        	} else {
	        	   end.prev.next=null;
	        	   end=end.prev;
	        	}
	        	size--;
	        }
	        Node newNode=new Node(key,value);
	        if(head!=null){
	          newNode.next=head;
	          head.prev=newNode;
	          head=newNode;
	        } else {
	          head=end=newNode;
	        }
	        size++;
	    }
	    public void printCache(){
	    	Node tmp=head;
	    	while(tmp!=null){
	    		System.out.println(String.format("%3d%3d", tmp.getKey(), tmp.getValue()));
	    		tmp=tmp.next;
	    	}
	    	System.out.println();
	    }
	    public static void main(String[] args){
	    	LRUcache2 lru=new LRUcache2(2);
	    	/*
	    	lru.set(1, 1);
	    	lru.set(2,2);
	    	lru.set(3,3);
	    	lru.set(4, 4);
	    	lru.printCache();
	    	lru.get(3);
	    	lru.printCache();
	    	lru.set(2,2);
	    	lru.printCache();
	    	lru.set(5,5);
	    	lru.set(6,6);
	    	lru.set(7,7);
	    	lru.set(8,8);
	    	lru.set(9,9);
	    	lru.set(10,10);
	    	lru.printCache();
	    	lru.set(4, 4);
	    	lru.printCache();
	    	lru.get(3);
	    	lru.printCache();
	    	lru.set(11,11);
	    	lru.printCache();
	    	*/
	    	lru.set(2,1);
	    	lru.set(1,1);
	    	lru.get(2);
	    	lru.set(4,1);
	    	lru.get(1);
	    	lru.get(2);
	    	lru.printCache();
	    }
	
}
