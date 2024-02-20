//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        unordered_map<char, int> umap;
        
        for (char i : s) umap[i]++;
        
        for (string str : dictionary) {
            size_t found = s.find(str);
            
            while (found != string::npos) {
                for (char ch : str) umap[ch]--;
                found = s.find(str, found + 1);
            }
        }
        
        for (auto it : umap) {
            if (it.second > 0)
                return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends