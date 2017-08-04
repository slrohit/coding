#include <iostream>

using namespace std;

enum DIRECTION {LEFT_TO_RIGHT, TOP_TO_BOTTOM , RIGHT_TO_LEFT , BOTTOM_TO_TOP };

void print2DArrayInSpriralOrder(int arr[][5], int n, int m){
    int top = 0, bottom = n-1, left = 0, right = m-1;
    DIRECTION dir = LEFT_TO_RIGHT;
    while(top <= bottom && left <= right){
        switch(dir){
            case LEFT_TO_RIGHT:
                for(int i=left; i<=right;i++)
                    cout<<arr[top][i]<<" ";
                top++;
                dir = TOP_TO_BOTTOM;
                break;
            case TOP_TO_BOTTOM:
                for(int i= top; i<=bottom; i++)
                    cout<<arr[i][right]<<" ";
                right--;
                dir = RIGHT_TO_LEFT;
                break;
            case RIGHT_TO_LEFT:
                for(int i=right; i>= left ; i--)
                    cout<<arr[bottom][i]<<" ";
                bottom--;
                dir = BOTTOM_TO_TOP;
                break;
            case BOTTOM_TO_TOP:
                for(int i=bottom;i>=top;i--)
                    cout<<arr[i][left]<<" ";
                left++;
                dir = LEFT_TO_RIGHT;
                break;
        }
    }
}

int main(){
    int arr[4][5] = {
        {3,4,5,1,2},
        {5,6,7,3,1},
        {1,3,9,8,4},
        {0,2,7,6,5}
    };

    cout<<"2D array"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Spriral Order"<<endl;
    print2DArrayInSpriralOrder(arr,4,5);
}
