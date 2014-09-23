#include<iostream>
#include<vector>

using namespace std;
void combination(int sum, int index, vector<vector<int> >& answer, vector<int> part, vector<int> &candidate, int target){
        if(sum>target){
            return;
        } else if(sum==target){
            answer.push_back(part);
            return;
        } else {
            while(index<candidate.size()){
               int prev=sum;
               sum += candidate[index];
               part.push_back(candidate[index]);
               combination(sum,index,answer,part,candidate,target);
               part.pop_back();
               index++;
               sum=prev;
            }
        }
          
    }
    
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> part;
        vector<vector<int> > answer;
        if(candidates.size()==0) return answer;
        sort(candidates.begin(),candidates.end());
        combination(0,0,answer,part,candidates,target);
        return answer;
    }
int main(){
  vector<vector<int> > answer;
  vector<int> cand;
  cand.push_back(1);
  cand.push_back(2);
  
  answer=combinationSum(cand,2);
  for(int i=0;i<answer.size();i++){
    for(int j=0;j<answer[i].size();j++){
       std::cout<<answer[i][j]<<" ";
    }
    std::cout<<std::endl;
 }

return 0;
}
