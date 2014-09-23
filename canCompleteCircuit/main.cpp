#include<iostream>
#include<vector>
#include<string>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
     int sum;
     int i;
     for(int star=0;star<gas.size();star=i+1){
      sum=0;
      for(i=star;i<gas.size();i++){
          sum += gas[i]-cost[i];
          if(sum<0) {
              break;
          }
      }
      if(sum<0) continue;
      for(i=0;i<star;i++){
         sum += gas[i]-cost[i];
          if(sum<0) {
              break;
          } 
      }
      if(sum>0) return star;
     }
     return -1;
    }
int main(){
vector<int> gas;
gas.push_back(2);
gas.push_back(3);
vector<int> cost;
cost.push_back(4);
cost.push_back(4);
std::cout<<canCompleteCircuit(gas,cost)<<std::endl;
 


return 0;
}
