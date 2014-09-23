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
   void getsubstring(string s,vector<string> &getpart, vector<vector<string> > &answer){
            if(s=="") {
                answer.push_back(getpart);
                return;
            }
            for(int j=1;j<=s.size();j++){
              string part=s.substr(0,j);
              if(is_palindrome(part)){
                  vector<string> prev_getpart=getpart;
                  getpart.push_back(part);
                  string next_string;
                  if(j==s.size()){
                     next_string="";
                  } else {
                     next_string=s.substr(j);
                  }
                  getsubstring(next_string,getpart,answer);
                  getpart=prev_getpart;
              }
            }
    }
    vector<vector<string> > partition(string s) {
        vector<string> getpart;
        vector<vector<string> > answer;
        getsubstring(s,getpart,answer);
        return answer;
    }
int main() {
   string str="aab";
  vector<vector<string> > answer= partition(str);
  for(int i=0;i<answer.size();i++){
    for(int j=0;j<answer[i].size();j++){
      std::cout<<answer[i][j]<<"   ";
    }
    std::cout<<std::endl;
  }

return 0;

}

