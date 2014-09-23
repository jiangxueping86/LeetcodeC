#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;
 string getbinary(int d,int len){
        string str="";
        while (d>0){
            //std::cout<<char((d%2)+'0')<<std::endl;
            str=str+char((d%2)+'0');
            d=d/2;
        }
        for(int i=0;i<len-str.size();i++){
         str='0'+str;   
        }
        return str;
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(),S.end());
        vector<vector<int> > res;
        int n = S.size();
        for (int i=0;i<pow(double(2),n);i++){
            string str = getbinary(i,n);
            std::cout<<"test"<<str<<std::endl;
            vector<int> ss;
            for (int j=0;j<n;j++){
                if (str[j]=='1'){
                    ss.push_back(S[j]);
                }
            }
            res.push_back(ss);
        }
        return res;
     }

int main(){
vector<int> s;
s.push_back(1);
s.push_back(2);
s.push_back(3); 
vector<vector<int> > answer=subsets(s);
 for(int i=0;i<answer.size();i++){
   for(int j=0;j<answer[i].size();j++){
      std::cout<<answer[i][j]<<" ";
   }
   std::cout<<std::endl;
 }
 return 0;

}
