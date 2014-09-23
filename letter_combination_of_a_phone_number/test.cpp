#include<iostream>
#include<string>

using namespace std;
int main(){
   
   string str("abc");
   string pr=str;
   std::cout<<pr<<std::endl;
   pr=pr+'c';
   std::cout<<pr<<std::endl;
}
