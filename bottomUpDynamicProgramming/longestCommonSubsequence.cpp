#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int getLongestCommonSubsequenceBetween(string a, string b){
    int dp[a.length()+1][b.length()+1];
    for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++){
            if(i == 0 || j == 0)
                dp[i][j]=0;
            else if(a[i-1] != b[j-1])
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j] = 1+dp[i-1][j-1];
        }
    }
    return dp[a.length()][b.length()];
}


int main(){
    string a ="abcdaf";
    string b ="acbcf";
    cout<<getLongestCommonSubsequenceBetween(a,b)<<endl;
}

