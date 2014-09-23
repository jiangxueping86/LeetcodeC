package demo1;

import java.util.ArrayList;
import java.util.List;

public class solution {
	 public String reverseString(String s) {
         if(s.length()==0||s.length()==1) return s;
        char[] arr=s.toCharArray();
        int n=arr.length;
        for(int i=0;i<n/2;i++){
        	if(arr[i]==arr[n-i-1]) {
        		continue;
        	}
            char c=arr[i];
            arr[i]=arr[n-i-1];
            arr[n-i-1]=c;
        }
        return new String(arr);
    }
    public String trim(String s){
        StringBuffer sb=new StringBuffer(s);
        int i=0;
        while(i<sb.length()&&sb.charAt(i)==' '){
            i++;
        }
        sb.delete(0,i);
        i=sb.length()-1;
        while(i>=0&&sb.charAt(i)==' '){
        	i--;
        }
        if(i>=0)
        sb.delete(i+1, sb.length());
        i=0;
        while(i<sb.length()){
        	if(sb.charAt(i)==' '){
        	    int j=i+1;
        		while(j<sb.length()&&sb.charAt(j)==' '){
        		  j++;	
        		}
        		sb.delete(i+1,j);
        	}
        	i++;
        }
        return sb.toString();
    }
    public String reverseWords(String s) {
         if(s.length()==0) return s;
         String st=trim(s);
         if(st.isEmpty()) return st;
        st=reverseString(st);
        if(st.length()==0||st.length()==1) return st;
        StringBuffer res=new StringBuffer();
        List<String> items=new ArrayList<String>();
        StringBuffer tmp=new StringBuffer();
        for(int i=0;i<st.length();i++){
            if(st.charAt(i)==' '){
                items.add(tmp.toString());
                tmp=new StringBuffer();
            } else {
                tmp.append(st.charAt(i));
            }
        }
        items.add(tmp.toString());
        for(int i=0;i<items.size()-1;i++){
            res.append(reverseString(items.get(i))+" ");
        }
        res.append(reverseString(items.get(items.size()-1)));
        return res.toString();
    }
}