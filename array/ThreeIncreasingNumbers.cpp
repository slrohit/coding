#include <iostream>
#include <algorithm>
using namespace std;
struct triplet{
    int i,j,k;
};


// O(1) space solution
triplet findTripletInIncreasingOrder(int arr[], int n){
    triplet ans = {-1,-1,-1};
    ans.i = 0;
    int temp = -1;
    for(int idx=1;idx<n;idx++){
        if(ans.j == -1){
            if( arr[idx] > arr[ans.i] )
                ans.j = idx;
            else
                ans.i = idx;
        }else if(arr[idx] > arr[ans.j]){
            ans.k = idx;
            return ans;
        }else if(arr[idx] < arr[ans.j]){
            if(temp != -1){
                if(arr[idx] > temp){
                    ans.i = temp;
                    ans.j = arr[idx];
                }else{
                    temp = arr[idx];
                }
            }else{
                temp = arr[idx];
            }
        }
    }
    ans.i=ans.j=ans.k=-1;
    return ans;
}

// O(n) space solution
triplet findTripletInIncreasingOrder2(int arr[], int n){
    triplet ans = {-1,-1,-1};
    int leftMin[n];leftMin[0]=0;

    for(int i=1;i<n;i++){
        if( arr[i] < arr[leftMin[i-1]] ){
            leftMin[i]=i;
        }else{
            leftMin[i] = leftMin[i-1];
        }
    }

    int rightMax[n];rightMax[n-1]=n-1;

    for(int i=n-2;i>=0;i--){
        if( arr[i] > arr[rightMax[i+1]] ){
            rightMax[i]=i;
        }else{
            rightMax[i] = rightMax[i+1];
        }
    }

    for(int i=1;i<n-1;i++){
        if(leftMin[i] < i && rightMax[i] > i){
            ans.i = leftMin[i]; ans.j = i; ans.k = rightMax[i];
            return ans;
        }
    }

    ans.i=ans.j=ans.k=-1;
    return ans;
}



int main(){
    int a[9] = {3, 2, 5, 1, 4, 7, 9, 6, 8};
    triplet ans = findTripletInIncreasingOrder2(a,9);
    cout<<ans.i<<" "<<ans.j<<" "<<ans.k<<endl;
    ans = findTripletInIncreasingOrder(a,9);
    cout<<ans.i<<" "<<ans.j<<" "<<ans.k<<endl;
}

