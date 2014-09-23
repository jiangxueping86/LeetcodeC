#include<iostream>
#include<vector>
using namespace std;
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > A(n,vector<int>(n,0));
        int num=1;
        int k=0;
        while(1){
            int i=k;
            while(i<n-k){
                A[k][i]=num;
            //    std::cout<<"1 "<<num<<std::endl;
                i++;
                num++;
            }
            if(num>n*n) break;
            int j=k+1;
            while(j<n-k){
                A[j][i-1]=num;
              //  std::cout<<"2 "<<num<<std::endl;
                j++;
                num++;
            }
            if(num>n*n) break;
             i=n-1-k;
             while(i>k){
                 A[n-1-k][i-1]=num;
                // std::cout<<"3 "<<num<<std::endl;
                 i--;
                 num++;
             }
             if(num>n*n) break;
               j=n-1-k-1;
             while(j>=k+1){
                A[j][i]=num;
                std::cout<<j<<" "<<i<<std::endl;
                std::cout<<1-k<<std::endl;
                std::cout<<num<<std::endl;
                j--;
                num++;
             }
             if(num>n*n) break;
             k++;
        }   
        return A;
    }
int main(){
 int n=4;
 vector<vector<int> > answer=generateMatrix(n);
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
     std::cout<<answer[i][j]<<" ";
   }
   std::cout<<std::endl;
 }

return 0;
}
