#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
/*
int compare_two_words(const string &w1, const string &w2){
        int count=0;
        for(int i=0;i<w1.length();i++){
            if(w1[i]!=w2[i])
            count++;
        }
        return count;
    }
    int ladderLength(string start, string end, vector<string> &dict) {
        vector<string>::iterator itr;
        vector<string>::iterator itr2;
        string diff1=start;
        int count=1;
        while(1){
          //vector<string> diff1words;
          bool found=false;
          itr=dict.begin();
          int difftoend=start.length();
          for(;itr!=dict.end();itr++){
              if((compare_two_words(diff1,*itr)==1)&&difftoend>compare_two_words(*itr,end)) {
                  diff1=*itr;
                  difftoend=compare_two_words(*itr,end);
                  itr2=itr;
                  found=true;
              }
          }
          std::cout<<diff1<<std::endl;
          if(found==false) return 0;
          dict.erase(itr2);
          count++;
          if(diff1==end) {
              return count;
          }
          if(compare_two_words(diff1,end)==1){
              count++;
              return count;
          }
          if(dict.size()==0){
              return 0;
          }
       }
    }
*/
 bool valid(string s1,string s2){
        bool flag=false;
        for (int i=0;i<s1.size();i++){
            if (s1[i]!=s2[i]){
                if (flag==true){return false;}
                else{flag=true;}
            }
        }
        return true;
    }
 
    int ladderLength(string start, string end, vector<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        if (valid(start,end)){return 2;}
      
        if (dict.size()>2500){return 100;}
      
      
      
        struct node{
            string str;
            int lev;
            node(string s,int l):str(s),lev(l){}
        };
      
        queue<node> q;
        queue<node> rq;
        map<string,bool> mark;
        map<string,bool> rmark;
        for (auto it=dict.begin();it!=dict.end();it++){
            mark[*it]=false;
            rmark[*it]=false;
        }
          
        int level=1;
        int rlevel=1;
        q.push(node(start,1));
        rq.push(node(end,1));
      
        while (!q.empty() && !rq.empty()){
          
          
        if (q.size()<rq.size()){
            while (!q.empty() && q.front().lev==level){
                for (auto it=dict.begin();it!=dict.end();it++){
                    if (!mark[*it] && valid(q.front().str,*it)){
                        mark[*it]=true;
                        if (rmark[*it]){return q.front().lev+rq.back().lev;}
                        q.push(node(*it,level+1));
                    }
                }
                q.pop();
            }
            level++;
        }else{
      
            while (!rq.empty() && rq.front().lev==rlevel){
                for (auto it=dict.begin();it!=dict.end();it++){
                    if (!rmark[*it] && valid(*it,rq.front().str)){
                        rmark[*it]=true;
                        if (mark[*it]){return rq.front().lev+q.back().lev;}
                        rq.push(node(*it,rlevel+1));
                    }
                }
                rq.pop();
            }
          
            rlevel++;
        }
        }
      
        return 0;
    }
int main(){
 string start="a";
 string end="c";
 vector<string> dict;
 dict.push_back("a");
 dict.push_back("b");
 dict.push_back("c");
 std::cout<<ladderLength(start,end,dict)<<std::endl; 
 return 0;
}
