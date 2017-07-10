#include<iostream>
#include<algorithm>
using namespace std;

int knapSack(int wt[], int val[], int n, int W){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else{
                if(j < wt[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j] = max( val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
        }
    }
    return dp[n][W];
}


int main(){
    int weight[4] = {1,3,4,5};
    int value[4] ={1,4,5,7};
    int noOfItems = 4;
    int bagSize = 7;
    cout<<knapSack(weight, value, noOfItems, bagSize)<<endl;
}
