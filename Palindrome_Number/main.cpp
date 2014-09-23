#include <iostream>
#include<cmath>
using namespace std;
bool isPalindrome(int nn) {
        if(nn==0) return true;
        long x=nn;
        int digits=1;
        int i=1;
        std::cout<<abs(x/digits)<<std::endl;
        while(abs(x/digits)>=10){
             std::cout<<digits<<std::endl;
             digits *= 10;
             i++;
        }
        //digits /= 10;
       // std::cout<<digits<<" "<<i<<std::endl;
        int d2=10;
        int numDigits=i;
        int y=x;
        for(int j=0;j<numDigits/2;j++){
            //std::cout<<x/digits<<" "<<y%d2<<std::endl;
            if(x/digits!=y%d2){
                return false;
            }
            y=y/d2;
            digits /= 10;
        }
        return true;
    }


int main() {
 int A=-2147483648;
 std::cout<<abs(A)<<" "<<isPalindrome(A)<<std::endl;
 return 0;
}
