#include<iostream>
#include<vector>
using namespace std;
    bool noswap(int k, int i, const vector<int> num){
        for (int j=k;j<i;j++){
            if (num[j]==num[i]){
                return true;
            }
        }
        return false;
    }
 
    void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
        if (k==n){
            res.push_back(num);
        }else{
            for (int i=k;i<=n;i++){
                 
                if (noswap(k,i,num)){continue;}
                 
                int tmp = num[k];
                num[k]=num[i];
                num[i]=tmp;
                 
                perm(num,k+1,n,res);
                 
                tmp = num[k];
                num[k]=num[i];
                num[i]=tmp;
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        perm(num,0,(num.size()-1),res);
        return res;
    }
int main(){
 
  vector<int> num;
  num.push_back(1);
  num.push_back(2);
  num.push_back(1);
  num.push_back(1);
  vector<vector<int> > result=permuteUnique(num);
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++) {
       std::cout<<result[i][j]<<" ";
    }
    std::cout<<std::endl;
  }

 return 0;

}
