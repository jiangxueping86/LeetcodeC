package demo1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

public class WordLadderII {
	    public static List<List<String>> findLadders(String start, String end, Set<String> dict) {
	        List<List<String>> result=new ArrayList<List<String>>();
	       if(dict.size()==0&&!start.equals(end)||start.length()==0) { return result;}
	       if(start.equals(end)){
	           List<String> tmp=new ArrayList<String>();
	           tmp.add(start);
	           tmp.add(end);
	           result.add(tmp);
	           return result;
	       }
	        HashMap<String,List<String>> map=new HashMap<String,List<String>>();
	        map.put(start,new ArrayList<String>());
	        dict.remove(end);
	        dict.remove(start);
	        for(String str:dict){
	            List<String> tmplist=new ArrayList<String>();
	            map.put(str,tmplist);
	        }
	        Queue<String> current=new LinkedList<String>();
	        Queue<String> next=new LinkedList<String>();
	        current.offer(start);
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
	                if(tempStr.equals(end)){
	                    map.get(x).add(tempStr);
	                    next.offer(tempStr);
	                }
	                if(dict.contains(tempStr)){
	                	if(!next.contains(tempStr))
	                    next.offer(tempStr);
	                    map.get(x).add(tempStr);
	                   // dict.remove(tempStr);
	                }
	             }
	              word[k]=original;
	            }
	           }
	          for(String y:next){
	        	  dict.remove(y);
	          }
	          
	          
	            current=next;
	            System.out.println(next);
	            if(next.contains(end)) break;
	            next=new LinkedList<String>();
	        }
	        if(current.isEmpty()) {
	        	return result;
	        }
	        buildPath(new ArrayList<String>(),start,end,result,map);
	        return result;
	    }
	    public static void buildPath(List<String> list, String s, String end, List<List<String>> result,HashMap<String,List<String>> map){
	        list.add(s);
	        if(s.equals(end)){
	            result.add(list);
	        } else {
	            for(String str:map.get(s)){
	                List<String> nl=new ArrayList<String>(list);
	                buildPath(nl,str,end,result,map);
	            }
	        }
	    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String start="red";
		String end="tax";
		Set<String> dict=new HashSet<String>();
		dict.add("ted");
		dict.add("tex");
		dict.add("red");
		dict.add("tax");
		dict.add("tad");
		dict.add("den");
		dict.add("rex");
		dict.add("pee");
		System.out.println(findLadders(start, end, dict));
	}
}
