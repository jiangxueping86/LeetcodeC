#include<iostream>
#include<vector>
#include<string>
using namespace std;
int minimumTotal(vector<vector<int> > &triangle) {
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                  triangle[i][j] += triangle[i-1][j];
                } else {
                   if(i==j) {
                    std::cout<<"test..."<<triangle[i][j]<<" "<<triangle[i-1][j-1]<<std::endl;
                    triangle[i][j] += triangle[i-1][j-1];
                  }else {
                    triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
                 }
                }
            }
        }
        sort(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
        return triangle[triangle.size()-1][0];
    }

int main(){
 vector<vector<int> > triangle;
 vector<int> tmp;
 tmp.push_back(1);
 triangle.push_back(tmp);
 tmp.clear();
 tmp.push_back(2);
 tmp.push_back(3);
 triangle.push_back(tmp);
  for(int i=0;i<triangle.size();i++){
     for(int j=0;j<triangle[i].size();j++){
        std::cout<<triangle[i][j]<<" ";
     }
    std::cout<<std::endl;
  }
 std::cout<<minimumTotal(triangle)<<std::endl; 

 return 0;
}
