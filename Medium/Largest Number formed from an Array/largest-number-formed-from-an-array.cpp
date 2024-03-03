//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string printLargest(int n, vector<string> &arr) {
	    sort(arr.begin(), arr.end(), [](string &x, string &y) {
	        return x + y > y + x;
	    });
	    
	    string ans = "";
	    
	    for(auto i : arr){
	        for(auto j : i) {
	            if(ans.size() == 0 and j == '0')
	                continue;
	               
	            ans += j;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends