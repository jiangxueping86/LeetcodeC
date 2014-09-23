#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <unordered_set>
using namespace std;
void find_right_word(vector<string> &answers,string answer, string s, unordered_set<string> &dict){
               if(s=="") {
                   answers.push_back(answer);
                   return;
               }
               unordered_set<string>::iterator itr=dict.begin();
               string sentence;
               for(;itr!=dict.end();itr++){
                   string word=*itr;
                   int index=s.find(word);
                   if(index==0){
                     answer=answer+" "+word;
                     string next_string=s.substr(index+word.size());
                      find_right_word(answers,answer,next_string,dict);
                     } else {
                         int index=answer.find(word);
                         if(index>0){
                            answer=answer.substr(0,index-1);
                         } else {
                            answer=answer.substr(0,0);
                         }
                     }
                 }
                 return;
             }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
             vector<string> answers;
             string answer;
             find_right_word(answers,answer,s,dict);
             return answers;
    }
int main(){
 string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
 unordered_set<string> dict;
 dict.insert("a");
 dict.insert("aa");
 dict.insert("aaa");
 dict.insert("aaaa");
 dict.insert("aaaaa");
 dict.insert("aaaaaa");
 dict.insert("aaaaaaa");
 dict.insert("aaaaaaaa");
 dict.insert("aaaaaaaaa");
 dict.insert("aaaaaaaaaa"); 
 vector<string> anwer=wordBreak(s, dict);
 for(int i=0;i<anwer.size();i++){
   std::cout<<anwer[i]<<std::endl;
 }
 return 0;
}
