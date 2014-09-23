#include <iostream>
#include <vector>
#include <string>
using namespace std;
  bool is_palindrome(string &str){
        int size=str.size();
        for(int k=0;k<size;k++){
           if(str[k]!=str[size-k-1]) {
             return false;
           }
         }
         return true;
    }
    //recursive call to getsubstring
   void getsubstring(string s,int &cut, vector<int> &answer){
            if(s=="") {
                answer.push_back(cut);
                return;
            }
            for(int j=1;j<=s.size();j++){
              string part=s.substr(0,j);
               if(j!=s.size())
                cut++;
              if(is_palindrome(part)){
                  string next_string;
                  if(j==s.size()){
                     next_string="";
                  } else {
                     next_string=s.substr(j);
                  }
                  int prev_cut=cut;
                  getsubstring(next_string,cut,answer);
                  cut=prev_cut;
              }
            }
    }
    int minCut(string s) {
        vector<int> answer;
        int cut=0;
        getsubstring(s,cut,answer);
        int min=answer[0];
        for(int i=1;i<answer.size();i++){
            if(min>answer[i]) min=answer[i];
        }
        return min;
    }
int main() {
   string str="ababababababababababababcbabababababababababababa";
   std::cout<<minCut(str)<<std::endl;


return 0;

}
