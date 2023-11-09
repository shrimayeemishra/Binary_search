//Exponential search to search in infinite(unbounded) array.
//Considering we have infinite array as{1,2,4,6,6,8,9,10,13,15,16,17,19,21,23,26,28,30,31,35,37,38,40,51,56,58,60,65,67,68,70}
//Target is 70

#include<iostream>
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


int unbounded_exponential_search(int arr[], int target)
{
    int i = 0;
    int j = 1;

    if(arr[i] == target)
    {
        return i;
    }
    if(arr[j] == target)
    {
        return j;
    }

    while(arr[j] <= target)
    {
        i = j;
        j *= 2;
    }

    return binary_search(arr, i, j, target);

}

int main()
{
    int arr[] = {1,2,4,6,6,8,9,10,13,15,16,17,19,21,23,26,28,30,31,35,37,38,40,51,56,58,60,65,67,68,70};
    int target = 70;
    cout<<unbounded_exponential_search(arr, target);
    return 0;
}