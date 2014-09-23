package demo1;

import java.util.Random;

public class QuickSort {
	    public void swap(ListNode n1, ListNode n2){
	        int x=n1.val;
	        n1.val=n2.val;
	        n2.val=x;
	    }
	    public void quickSort(ListNode start, ListNode end){
	        if(start==end){
	            return;
	        }
	        ListNode tmp=start;
	        
	        int size=1;
	       
	        while(tmp!=end.next){
	            tmp=tmp.next;
	            size++;
	        }
	        
	        Random random=new Random();
	        int x=random.nextInt(size-1);
	        int i=0;
	        tmp=start;
	        while(i<x){
	            tmp=tmp.next;
	            i++;
	        }
	        swap(start,tmp);
	        
	        ListNode prev=start;
	        ListNode prevp=prev;
	        ListNode p=start.next;
	        tmp=p;
	        while(tmp!=end.next){
	            if(tmp.val<start.val){
	                if(tmp!=p){
	                    swap(tmp,p);
	                }
	                    prevp=prev;
	                    prev=p;
	                    p=p.next;
	            }
	            tmp=tmp.next;
	        }
	        if(start!=prev)
	        swap(start,prev);
	        quickSort(start,prevp);
	        if(p!=end.next)
	        quickSort(p,end);
	    }
	    public ListNode sortList(ListNode head) {
	        if(head==null||head.next==null) return head;
	        ListNode tmp=head;
	        while(tmp.next!=null){
	            tmp=tmp.next;
	        }
	        quickSort(head,tmp);
	        return head;
	    }
	    public void printList(ListNode head){
	    	ListNode tmp=head;
	    	while(tmp!=null){
	    		System.out.print(String.format("%3d",tmp.val));
	    		tmp=tmp.next;
	    	}
	    	System.out.println();
	    }
}
