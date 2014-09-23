#include<iostream>
#include<vector>
using namespace std;
void swap(int &i, int &j){
        int tmp=i;
        i=j;
        j=tmp;
    }
    void perm(int k, int n, vector<int> num, vector<vector<int> > &answer){
        if(k==n){
            answer.push_back(num);
        } else {
            for(int i=k;i<=n;i++){//the digits >= k could be swapped ....
               if(i==k||num[i]!=num[k]){
                 swap(num[i],num[k]);
                 perm(k+1,n,num,answer);
                 swap(num[i],num[k]);
               }
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > answer;
        if(num.size()==0) return answer;
        perm(0,num.size()-1,num,answer);
        return answer;
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
