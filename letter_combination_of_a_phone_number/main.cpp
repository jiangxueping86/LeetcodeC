#include<iostream>
#include<string>
#include<vector>
using namespace std;
void letter(string & digits, vector<string> &letters, int k, string str, vector<string> & result){
    if(k>=digits.size()) {
        result.push_back(str);
    } else {
       for(int i=0;i<letters[digits[k]-'0'].size();i++){
           string prev=str;
           str=str+letters[digits[k]-'0'][i];
           letter(digits,letters,k+1,str,result);
           str=prev;
       }
    }
}
    vector<string> letterCombinations(string digits) {
       vector<string> letters;
       letters.push_back("O");
       letters.push_back("abc");
       letters.push_back("def");
       letters.push_back("ghi");
       letters.push_back("jkl");
       letters.push_back("mno");
       letters.push_back("pqrs");
       letters.push_back("tuv");
       letters.push_back("wxyz");
       vector<string> result;
       letter(digits, letters, 0, "",result);
       return result;
    }
int main() {
 string digits="324";
 vector<string> result=letterCombinations(digits);
 for(int i=0;i<result.size();i++){
     std::cout<<result[i]<<std::endl;
 }
return 0;
}
