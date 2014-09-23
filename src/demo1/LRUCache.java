package demo1;

import java.util.LinkedList;
import java.util.List;

public class LRUCache {
    class Pair<L,R>{
        private L l;
        private R r;
        public Pair(L l, R r){
        	this.l=l;
        	this.r=r;
        }
        public L getL(){
        	return l;
        }
        public R getR(){
        	return r;
        }
    }
    int capacity;
    List<Pair<Integer,Integer>> cache;
    public LRUCache(int capacity) {
        this.capacity=capacity;
        cache=new LinkedList<Pair<Integer,Integer>>();
    }
    
    public int get(int key) {
        int result=-1;
        for(int i=0;i<cache.size();i++){
        	if(cache.get(i).getL()==key){
        		Pair<Integer,Integer> find=cache.get(i);
        		cache.remove(i);
        		cache.add(find);
        		result=find.getR();
        	}
        }
        return result;
    }
    
    public void set(int key, int value) {
        if(get(key)!=-1){
        	return;
        } 
        if(cache.size()==capacity){
        	cache.remove(0);
        }
        cache.add(new Pair<Integer,Integer>(key,value));
    }
    public void printCache(){
    	for(int i=0;i<cache.size();i++){
    		System.out.println(String.format("%3d%3d",cache.get(i).getL(),cache.get(i).getR()));
    	}
    	System.out.println();
    }
    public static void main(String[] args){
    	LRUCache lru=new LRUCache(10);
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
    }
}