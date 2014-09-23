#include<iostream>
#include<vector>
using namespace std;
 int maxProfit(vector<int> &prices) {
        int sum=0;
        int size=prices.size();
        int i=0;
        for(;i<size-1;i++){
            if(prices[i+1]>prices[i]){
                sum += prices[i+1]-prices[i];
            }
        }
        return sum;
    }
int main(){
 vector<int> prices;
 std::cout<<maxProfit(prices)<<std::endl;
 return 0;
}
