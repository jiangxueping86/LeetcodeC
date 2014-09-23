#include<iostream>

using namespace std;
int lengthOfLastWord(const char *s) {
        int count=0;
        for(const char *p=s;;p++){
            if(*p=='\0'){
                break;
            }
            if(*p!=' '){
                count++;
            } else if(*p==' '&&*(p+1)!='\0') {
              std::cout<<"test"<<std::endl;  
              count=0;
            } else {
                
            }
        }
        return count;
    }
int main(){
 char s[]="a ";
 std::cout<<lengthOfLastWord(s)<<std::endl;

return 0;
}
