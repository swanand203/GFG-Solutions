//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        map<int,int>mp;
        vector<vector<int>>res;
        set<pair<int,int>>st;
        for(int i=0;i<N;i++)
        {
            int f=++mp[arr[i]];
            int k=0;
           vector<int>ans;
            if(st.find({-f+1,arr[i]})!=st.end())
            {
                st.erase({-f+1,arr[i]});
            }
            st.insert({-f,arr[i]});
            
            for(auto it:st)
            {
                int x=it.second;
                ans.push_back(x);
                k++;
                if(k==K)
                 break;
            }
            res.push_back(ans);
            
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends