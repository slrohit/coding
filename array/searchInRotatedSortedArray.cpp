#include <iostream>
using namespace std;

int searchInRotatedSortedArray(int arr[], int n, int target){
    int low = 0, high = n-1, mid;
    while( low <= high ){
        mid = low + (high-low)/2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] <= arr[high]){
            if(target > arr[mid] && target <= arr[high])
                low = mid+1;
            else
                high = mid-1;
        }else {
            if(target >= arr[low] && target < arr[mid])
                high = mid-1;
            else
                low = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {11,12,15,18,2,5,6,8};
    int n = 8;

    cout<<searchInRotatedSortedArray(arr,n,15)<<endl;
    cout<<searchInRotatedSortedArray(arr,n,6)<<endl;
    cout<<searchInRotatedSortedArray(arr,n,2)<<endl;
    cout<<searchInRotatedSortedArray(arr,n,10)<<endl;
}
