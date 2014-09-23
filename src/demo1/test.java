package demo1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		/*
		solution ss=new solution();
		String s=new String("   ");
		String res=ss.reverseWords(s);
         System.out.println(res.length());
         String s1=new String("  a  b ");
        System.out.println(ss.reverseWords(s1));
        */
		// System.out.println(ss.trim(s1));
 		//String res1=ss.reverseString(s1);
         // System.out.println(res1);
        
         // String sbb=new String("a b c");
         // System.out.println(sbb);
          //char[] charS=sbb.toCharArray();
          //System.out.println(charS);
        //  System.out.println(charS.toString());
          //System.out.println(new String(charS));
          //System.out.println(ss.reverseString(sbb.toString()));
          //System.out.println(ss.reverseString(sbb.toString()));
          //System.out.println(sbb.toString());
        QuickSort qs=new QuickSort();
        ListNode head=new ListNode(1);
        ListNode tmp=head;
        for(int i=99;i>=1;i--){
        	tmp.next=new ListNode(i);
        	tmp=tmp.next;
        }
        qs.printList(head);
        int j=0;
        Random random=new Random();
        while(j<0){
        int x=random.nextInt(100-1);
       // System.out.println(x);
        int i=0;
        tmp=head;
        while(i<x){
            tmp=tmp.next;
            i++;
        }
        qs.swap(head,tmp);
        j++;
        }
       
        qs.printList(head);
        long startTime = System.currentTimeMillis();
        qs.sortList(head);
        //qs.printList(head);
    	long endTime   = System.currentTimeMillis();
		long totalTime = endTime - startTime;
		System.out.println(totalTime);
		
		
		String abc="Hello";
		System.out.println(abc.substring(0,1));
		System.out.println(abc.substring(5).length());
		String[] s=new String[2];
		
		HashMap<Integer,Integer> mp=new HashMap<Integer,Integer>();
		mp.put(1, 1);
		for(Map.Entry<Integer, Integer> entry:mp.entrySet()){
			
		}
		
	}
	
	

}


