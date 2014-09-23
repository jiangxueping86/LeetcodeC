#include<iostream>
#include<vector>
using namespace std;
 void nextPermutation(vector<int> &num) {  
        int i,j,len=num.size();  
        for(i=len-2;i>=0;--i)  
        {  
            if(num[i+1]>num[i])  
            {  
                for(j=len-1;j>i-1;--j)if(num[j]>num[i])break;  
                swap(num[i],num[j]);
                 for(int h=0;h<num.size();h++){
                      std::cout<<num[h]<<" ";
                 }
                 std::cout<<std::endl;  
                reverse(num.begin()+i+1,num.end());  
                return;  
            }  
        }  
        reverse(num.begin(),num.end());  
        return;  
    }  

int main(){
 vector<int> A;
 A.push_back(1);
 A.push_back(2);
 A.push_back(4);
 A.push_back(3);
 nextPermutation(A);
 for(int i=0;i<A.size();i++){
   std::cout<<A[i]<<" ";
 }
 std::cout<<std::endl;
 return 0;
}
