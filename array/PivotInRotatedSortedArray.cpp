#include <iostream>
using namespace std;

int findPivotIndexInRotatedSortedArray(int arr[], int n){
    int low = 0, high = n-1;
    while(low <= high){
        if(arr[low] <= arr[high])
            return low;
        int mid = low + (high-low)/2;
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;

        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;

        if(arr[mid] <= arr[high])
            high = mid-1;
        else if(arr[mid] >= arr[low])
            low = mid+1;
    }
    return -1;
}

int main(){
    int arr[] = {11,12,15,18,2,5,6,8};
    int n = 8;
    cout<<findPivotIndexInRotatedSortedArray(arr,n);
}
