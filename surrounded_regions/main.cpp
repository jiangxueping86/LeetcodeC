#include<iostream>
#include<vector>
using namespace std;
void solve(vector<vector<char> > &board) {
        if(board.size()<3||board[0].size()<3) return;
        vector<int> sti;
        vector<int> stj;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
                if(board[i][0]=='O'){
                    sti.push_back(i);
                    stj.push_back(0);
                }
        }
        for(int i=0;i<m;i++){
                if(board[i][n-1]=='O'){
                    sti.push_back(i);
                    stj.push_back(n-1);
                }
        }
         for(int j=0;j<n;j++){
                if(board[0][j]=='O'){
                    sti.push_back(0);
                    stj.push_back(j);
                }
        }
         for(int j=0;j<n;j++){
                if(board[m-1][j]=='O'){
                    sti.push_back(m-1);
                    stj.push_back(j);
                }
        }
        
        int k=0;
        while(k<sti.size()){
            int i=sti[k];
            int j=stj[k];
            board[i][j]='P';
            if(i-1>0&&board[i-1][j]=='O'){
                sti.push_back(i-1);
                stj.push_back(j);
            }
            if(i+1<m&&board[i+1][j]=='O'){
                sti.push_back(i+1);
                stj.push_back(j);
            }
            if(j-1>0&&board[i][j-1]=='O'){
                sti.push_back(i);
                stj.push_back(j-1);
            }
            if(j+1<n&&board[i][j+1]=='O'){
                  sti.push_back(i);
                stj.push_back(j+1);
            }
            k++;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                   std::cout<<"test...."<<std::endl;
                    board[i][j]='X';
                } 
                if(board[i][j]=='P'){
                    board[i][j]='O';
                }
            }
        }
       
    }

int main(){
 vector<vector<char> > board(3,vector<char>(3,'X'));
  board[1][1]='O';
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
          std::cout<<board[i][j]<<"  ";
      }
      std::cout<<std::endl;
  }
  std::cout<<std::endl;
  solve(board);
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
          std::cout<<board[i][j]<<"  ";
      }
      std::cout<<std::endl;
  }
 return 0;
}
