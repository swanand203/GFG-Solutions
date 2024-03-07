//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        string answer;
        int i=0,j=0;
        int cur=0;
        while(i<n and j<n)
        {
            string str = s.substr(i,j-i+1);
            if(s.find(str,j+1)!=string::npos)
            {
                int len = str.size();
                if(len>cur)
                {
                    cur=len;
                    answer=str;
                }
                j++;
            }
            else
                i++;
        }
        if(answer.empty())
            return "-1";
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends