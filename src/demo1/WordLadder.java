package demo1;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class WordLadder {
	public static int ladderLength(String start, String end, Set<String> dict) {
        if(start.equals(end)||dict.size()==0||start.length()==0) { return 0;}
        Queue<String> current=new LinkedList<String>();
        Queue<String> next=new LinkedList<String>();
        current.offer(start);
        int step=1;
        dict.remove(start);
        while(!current.isEmpty()){
          while(!current.isEmpty()){
           String x=current.poll();
           char[] word=x.toCharArray();
           for(int k=0;k<word.length;k++){
        	   char original=word[k];
            for(char i='a';i<='z';i++){
                if(word[k]==i){ continue;}
                word[k]=i;
                String tempStr=String.copyValueOf(word);
                //System.out.println(tempStr);
                if(tempStr.equals(end)){
                    return step+1;
                }
                if(dict.contains(tempStr)){
                	//System.out.println(tempStr);
                    next.offer(tempStr);
                    dict.remove(tempStr);
                }
              }
              word[k]=original;
             }
            }
            current=next;
            next=new LinkedList<String>();
            step++;
        }
       // System.out.println("test");
        return 0;
    }
	public static void main(String[] args) {
		String start="hot";
		String end="dog";
		Set<String> dict=new HashSet<String>();
		dict.add("hot");
		dict.add("dog");
		dict.add("dot");
		System.out.println(ladderLength(start, end, dict));
		char[] test=start.toCharArray();
		test[0]='s';
		System.out.println(String.copyValueOf(test));
		System.out.println(start);
		for(String str:dict){
			System.out.println(str);
		}
		
	}

}
