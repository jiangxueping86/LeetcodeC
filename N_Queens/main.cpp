#include<iostream>
#include<vector>
#include<string>
using namespace std;

    void setQ(int row,int n, vector<vector<string> > &answer, vector<string> part){
      //  for(int i=0;i<part.size();i++){
      //     std::cout<<part[i]<<std::endl;
      //  }
      //  std::cout<<row<<std::endl;
        if(row>=n) {
            answer.push_back(part);
            return;
        }
        for(int i=0;i<n;i++){
            if(row==0||row>0&&part[row-1][i]!='Q'&&part[row-1][i+1]!='Q'){
                if(i>0&&row>0&&part[row-1][i-1]=='Q') continue;
                part[row][i]='Q';
                setQ(row+1,n,answer,part);
                part[row][i]='.';
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        string str="";
        for(int i=0;i<n;i++){
            str += ".";
        }
        vector<vector<string> > answer;
        vector<string> part(n,str);
        setQ(0,n,answer,part);
            return answer;
    }

int main(){
 vector<vector<string> > answer=solveNQueens(8);
 for(int i=0;i<answer.size();i++){
   for(int j=0;j<answer[0].size();j++){
     std::cout<<answer[i][j]<<std::endl;
   }
  std::cout<<std::endl;
 }
 


return 0;

}
