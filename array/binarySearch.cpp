#include <iostream>

using namespace std;

int binarySearch(int arr[], int sizeOfArr , int target, bool searchFirstOccurence=true){
    int low=0,high=sizeOfArr-1,mid,pos=-1;

    while( low <= high ){
        mid = low + (high-low)/2;
        if(arr[mid] == target){
            pos = mid;
            if(searchFirstOccurence)
                high = mid-1;
            else
                low = mid+1;
        }else if(arr[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return pos;
}

int main(){
    int arr[] = {2,3,3,3,3,4,5,5,5,6,6,6,6,7,8,9,9,9,9,10,13,13,13};
    int n = 23;

    cout<<binarySearch(arr,n,5)<<endl;
    cout<<binarySearch(arr,n,9,true)<<endl;
    cout<<binarySearch(arr,n,9,false)<<endl;
}
