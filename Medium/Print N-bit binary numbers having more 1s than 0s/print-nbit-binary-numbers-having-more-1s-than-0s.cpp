//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    vector<string>v;
    
    void solve(int num_0,int num_1, string s, int n ){
        if(s.length() == n){
            if(num_1 >= num_0){
                v.push_back(s);
                return;
            }
        }
        if(num_1 >= num_0){
            solve(num_0 , num_1+1, s+"1", n);
            solve(num_0+1 , num_1, s+"0", n);
        }
    }
    
vector<string> NBitBinary(int n)
{
    solve(0,0,"",n);
    return v;
}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends