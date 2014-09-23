#include<iostream>
#include<string>
using namespace std;
     bool searchS(string &s2, string &s3){//s2 is smaller than s3
       int h=0;
        for(int i=0;i<s2.length();i++){
            int j=h;
            for(; j<s3.length();j++){
                if(s3[j]==s2[i])  {
                    s3[j]='*';
                    h=j+1;
                    break;
                }
            }
            if(j==s3.length()) return false;
        }
        return true;
     }

    bool searchS1(int i,int begin, string &s1, string &s2, string &s3){
       std::cout<<i<<" "<<begin<<std::endl;
       if(begin>s3.size()) return false;
       if(i>=s1.size()) return true;
       if(s1.size()-i>s3.size()-begin) return false;
            int j=begin;
            int end;
            string s3_tmp=s3;
            for(; j<s3.length();j++){
                if(s3[j]==s1[i])  {
                    s3[j]='*';
                    end=j+1;
                    break;
                }
            }
            if(j==s3.length()) return false;
        if(searchS1(i+1,end,s1,s2,s3)&&searchS(s2,s3)){
             return true;
        } else {
           s3=s3_tmp;
           searchS1(i,end,s1,s2,s3);
        }

    }
bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()==0&&s2.length()==0&&s3.length()==0) return true;
        if(s3.length()!=s1.length()+s2.length()) return false;
        return searchS1(0,0,s1,s2,s3);    
}

int main(){
 string s1="ef";
 string s2="gh";
 string s3="ehgf";
 std::cout<<isInterleave(s1, s2, s3)<<std::endl; 

}
