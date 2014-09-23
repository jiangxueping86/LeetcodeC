#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
 int maxArray(int A[], int left, int right, int& maxV);
 int maxSubArray(int A[], int n) {  
     // Start typing your C/C++ solution below  
     // DO NOT write int main() function  
     int maxV = INT_MIN;  
     return maxArray(A, 0, n-1, maxV);      
   }  
   int maxArray(int A[], int left, int right, int& maxV)  
   {
    // std::cout<<left<<" "<<right<<std::endl;  
     if(left>right)  
        return INT_MIN;  
      int mid = (left+right)/2;  
      int lmax = maxArray(A, left, mid -1, maxV);  
      int rmax = maxArray(A, mid + 1, right, maxV);  
      maxV = max(maxV, lmax);  
      maxV = max(maxV, rmax);  
      int sum = 0, mlmax = 0; //set mlmax=0 considering only A[mid] 
      for(int i= mid -1; i>=left; i--)  //add left elements of mid 
      {  
        sum += A[i];  
        if(sum > mlmax)  
          mlmax = sum;  
      }  
      sum = 0; int mrmax = 0;  
      for(int i = mid +1; i<=right; i++)  
      {  
        sum += A[i];  
        if(sum > mrmax)  
          mrmax = sum;  
      }  
      maxV = max(maxV, mlmax + mrmax + A[mid]);//mlmax+mrmax+A[mid] is the maximum sum from left to right element including A[mid] but not include other singles elements like A[other_index] which were considered already in maxV;
      std::cout<<left<<" "<<right<<std::endl;
      for(int i=left;i<=right;i++){
       std::cout<<A[i]<<" ";
      }  
      std::cout<<std::endl;
      std::cout<<maxV<<std::endl;
      std::cout<<std::endl;
      return maxV;  
    }
int main(){
  int A[]={-2,1,-3,4,-1,2,1,-5,4};
  std::cout<<maxSubArray(A,9)<<std::endl;
  
}  
