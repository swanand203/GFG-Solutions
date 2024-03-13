//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        int n=mat.size(), i = 0, j=0, counter =0, up = 1;
        vector<int> ans;
        
        while (counter<n*n){
            
            if (up){
                
                while (i>=0 && j<n){
                    ans.push_back(mat[i][j]);
                    counter++;
                    if (j==n-1){
                        i++;
                        break;
                    }
                    else if (i==0){
                        j++;
                        break;
                    }
                    i--;
                    j++;
                }
                
                up^=1;
            }
            
            else{
                
                while (i<n && j>=0){
                    ans.push_back(mat[i][j]);
                    counter++;
                    if (i==n-1){
                        j++;
                        break;
                    }
                    else if (j==0){
                        i++;
                        break;
                    }
                    i++;
                    j--;
                }
                
                up^=1;
            }
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends