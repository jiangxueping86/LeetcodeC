#include <iostream>
#include <string>
using namespace std;
int main(){
  string str="My name is";
  string h="is";
  int index=str.find(h);
  string s=str.substr(1); 
 std::cout<<s<<std::endl;
 std::cout<<(int)'1'<<std::endl;
 return 0;
}
