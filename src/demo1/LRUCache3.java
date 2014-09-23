package demo1;
import java.util.HashMap;
import java.util.Map;


public class LRUCache3 {
    private int capacity;
    private Node head;
    private Node end;
    private int size;
    private HashMap<Integer,Node> mp;
	    class Node{
	        private int key;
	        private int value;
	        private Node next;
	        private Node prev;
	        public Node(int key,int value){
	            this.key=key;
	        	this.value=value;
	            next=prev=null;
	        }
	    }
	    public LRUCache3(int capacity) {
	        this.capacity=capacity;
	        mp=new HashMap<Integer,Node>();
	        head=end=null;
	    }
	    
	    public int get(int key) {
	        int result=-1;
	        Node tmp;
	        	if(mp.containsKey(key)){
	        		tmp=mp.get(key);
	        		result=tmp.value;
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
	        return result;
	    }
	    
	    public void set(int key, int value) {
	        int calValue=get(key);
	        if(calValue!=-1){
	            if(value!=calValue){
	        	   head.value=value;
	            }
	            return;
	        } 
	        if(size==capacity){
	        	int endKey=end.key;
	        	if(size==1){
	        	   head=end=null;
	        	} else {
	        	   end.prev.next=null;
	        	   end=end.prev;
	        	}
	        	size--;
	        	mp.remove(endKey);
	        }
	        Node newNode=new Node(key,value);
	        if(head!=null){
	          newNode.next=head;
	          head.prev=newNode;
	          head=newNode;
	        } else {
	          head=end=newNode;
	        }
	        mp.put(key,newNode);
	        size++;
	    }
	    public void printCache(){
	    	for(Map.Entry<Integer, Node> entry:mp.entrySet()){
	    		System.out.println(String.format("%3d%3d", entry.getKey(), entry.getValue().value));
	    	}
	    	System.out.println();
	    }
}
