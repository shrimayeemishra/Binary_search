#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    
    bool isPossible(int arr[], int N, int M, int mid)
    {
        int studentCount = 1;
        int pageSum = 0;
        
        for(int i = 0; i<N; i++)
        {
            if(pageSum + arr[i] <= mid)
            {
                pageSum += arr[i];
            }
            else{
                studentCount++;
                if(studentCount > M || arr[i] > mid)
                {
                    return false;
                }
                pageSum = arr[i];
            }
            
            if(studentCount > M)
            {
                return false;
            }
            
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N < M)
        {
            return -1;
        }
        
        int start = 1;
        int sum = 0;
        
        for(int i=0; i<N; i++)
        {
            sum += A[i];
        }
        
        int end = sum;
        int ans = -1;
        while(start <= end)
        {
            int mid = start+(end-start)/2;
            
            if(isPossible(A, N, M, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
