//Exponential search in bounded(finite) array
//Explanation - This is a searching algorithm which applies binary search in a selected part of the main array.

#include<iostream>
#include<vector>
using namespace std;


int binary_search(int arr[], int start, int end, int target)
{
    while(start<=end)
    {
        int mid = start+(end-start)/2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}
int exponential_search(int arr[], int n, int target)
{
    if(arr[0] == target)
    {
        return 0;
    }
    int i = 1;
    while((i < n) && (arr[i] <= target))
    {
        i *= 2;
    }

    int ans = binary_search(arr, (i/2), min(i, n-1), target);
    return ans;
}


int main()
{
    int arr[] = {5,6,8,10,12,15,18,23,27,31,35,37};
    int n = 12;
    int target = 27;
    int answer = exponential_search(arr, n, target);
    cout<<answer<<endl;

    return 0;
}
