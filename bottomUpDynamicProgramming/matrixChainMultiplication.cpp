#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int getMinimumMultiplicationCostOfMatrices(int p[], int n){
    int dp[n][n];
    for(int i=0;i<n;i++)dp[i][i]=0;

    for(int l=2;l<n;l++){
        for(int i=0;i<n-l+1;i++){
            int j = i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    return dp[1][n-1];
}


int main(){
    int matrixChain[] = {2,3,6,4,5};// represent order of 4 matrices { 2x3,3x6,6x4,4x5}
    int noOfMatrices = 4;
    cout<<getMinimumMultiplicationCostOfMatrices(matrixChain,noOfMatrices+1)<<endl;
}


