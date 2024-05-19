//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int n, int k, int arr[]) {
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 && abs(arr[left - 1] - k) < abs(arr[left] - k)) {
            return arr[left - 1];
        } else {
            return arr[left];
        }
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends