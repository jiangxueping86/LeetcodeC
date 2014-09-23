#include<iostream>
using namespace std;
  bool Valid(int start, int end, string &s){
        std::cout<<start<<" "<<end<<std::endl;
        int n=end-start+1;
        if(n%2!=0) return false;
        int i=start;
        int j=end;
        while(i<j){
           if(!(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']'||s[i]=='{'&&s[j]=='}')){
               return false;
           }
           i++;
           j--;
        }
        return true;
    }
    bool isValid(string s) {
        int n=s.length();
        int i=0;
        int j;
        if(n%2!=0) return false;
     while(i<n){
        if(s[i]=='('){
            j=i+1;
           while(j<n){
              if(s[j]==')') break;
              j++;
           }
        } else if(s[i]=='['){
             j=i+1;
           while(j<n){
              if(s[j]==']') break;
              j++;
           }
        } else if(s[i]=='['){
             j=i+1;
           while(j<n){
              if(s[j]==']') break;
              j++;
           }
        } else {
            return false;
        }
        if(j>=n) return false;
        if(!Valid(i,j,s)) return false;
        i=j+1;
    }
        return true;
    }
int main(){
 string s="()[]{}";
 std::cout<<isValid(s)<<std::endl;
return 0;
}
