#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string s) {
        if(s==" ") return true;
        int i=0;
        int j=s.length()-1-i;
        while(i<j){
            while(((s[i]<'0'||(int)s[i]<'A'&&s[i]>'9'||(int)s[i]>'z'))&&i<=j) i++;
            while((s[j]<'0'||(int)s[j]<'A'&&s[j]>'9'||(int)s[j]>'z')&&(j>=i)) j--;
            if(i>j) break;
            if(s[i]!=s[j]&&abs(s[i]-s[j])!='a'-'A')
              return false;
                 i++;
                 j--;
        }
        return true;
    }
int main(){
  string s="''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''";
  std::cout<<isPalindrome(s)<<std::endl;

  return 0;

}