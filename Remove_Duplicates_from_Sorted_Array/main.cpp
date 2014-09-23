#include<iostream>
using namespace std;
    int removeDuplicates(int A[], int n) {
        for(int i=0;i<n-1;i++){
            int j=i+1;
            while(A[i]==A[j]&&j<n){
              std::cout<<i<<" "<<j<<std::endl;
                A[j]=A[0]-1;
                j++;
            }
            i=j-1;
        }
        for(int i=0;i<n;i++){
          std::cout<<A[i]<<" ";
        }
        std::cout<<std::endl;
        int m=n;
        for(int i=1;i<n;i++){
            if(A[i]==A[0]-1){
              std::cout<<i<<std::endl;
                if(i!=m-1){
                  A[i]=A[i+1];
                  i--;
                }
                n--;
            }
        }
        return n;
    }

int main(){
  int A[]={1,1,2,2};
  std::cout<<removeDuplicates(A,4)<<std::endl;
  for(int i=0;i<4;i++){
          std::cout<<A[i]<<" ";
        }
        std::cout<<std::endl;
return 0;
}
