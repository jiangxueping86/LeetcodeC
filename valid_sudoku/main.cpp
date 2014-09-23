#include<iostream>
#include<vector>

using namespace std;
 bool isValidSudoku(char** board) {
        //map<char, bool> row;
        //map<char, bool> col;
        //map<char, bool> block;
       for(int i=0;i<9;i++){
           vector<bool> row(10,false);
           vector<bool> col(10,false);
           //row.clear();
           //col.clear();
           for(int j=0;j<9;j++){
             if(board[i][j]!='.'){
                 if(row[board[i][j]]){
                     return false;
                 } else{
                     row[board[i][j]]=true;
                 }
             }
             if(board[j][i]!='.'){
                 if(col[board[j][i]]){
                     return false;
                 } else{
                     col[board[j][i]]=true;
                 }
             }
           }
       }
       
       for(int ii=0;ii<=6;ii+=3){
           for(int jj=0;jj<=6;jj+=3){
               vector<bool> block(10,false);
               //block.clear();
               for(int i=ii;i<ii+3;i++){
                   for(int j=jj;j<jj+3;j++){
                       if(board[i][j]!='.'){
                           if(block[board[i][j]]){
                               return false;
                           }else{
                               block[board[i][j]]=true;
                           }
                       }
                   }
               }
           }
       }
       return true;
    }
int main(){
  char board[][9]={{.,8,7,6,5,4,3,2,1},{2,.,.,.,.,.,.,.,.},{3,.,.,.,.,.,.,.,.},{4,.,.,.,.,.,.,.,.},{5,.,.,.,.,.,.,.,.},{6,.,.,.,.,.,.,.,.},{7,.,.,.,.,.,.,.,.},{8,.,.,.,.,.,.,.,.},{9,.,.,.,.,.,.,.,.}};
  
   std::cout<<isValidSudoku(board)<<std::endl;
return 0;

}
