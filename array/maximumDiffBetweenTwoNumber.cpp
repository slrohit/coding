#include <iostream>
using namespace std;

int maxDiff(int arr[], int n){
    int maxDiff = 0;
    int curMin = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i] > curMin)
            maxDiff = arr[i]-curMin;
        else
            curMin = arr[i];
    }
    return maxDiff;
}

int main(){
    int a[9] = {3, 2, 5, 1, 4, 7, 9, 6, 8};
    cout<<maxDiff(a,9)<<endl;
}
