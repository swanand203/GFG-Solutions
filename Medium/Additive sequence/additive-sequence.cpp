//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string calculate(string &s,int st,int i,int j){
        //first string s[st-->i] and second string s[i+1-->j]
        int k1 = i,k2 = j;
        int carry = 0;
        string vals = "";
        while(k1>=st and k2 >= i+1){
            int t = (s[k1]-'0')+(s[k2]-'0')+carry;
            int val = t%10;
            carry = t/10;
            vals.push_back(char('0'+val));
            k1--;k2--;
        }
        while(k1>=st){
            int t = (s[k1]-'0')+carry;
            int val = t%10;
            carry = t/10;
            vals.push_back(char('0'+val));
            k1--;
        }
        while(k2>=i+1){
            int t = (s[k2]-'0')+carry;
            int val = t%10;
            carry = t/10;
            vals.push_back(char('0'+val));
            k2--;
        }
        if(carry==1){
            vals.push_back(char('0'+carry));
        }
        reverse(vals.begin(),vals.end());
        return vals;
    }
    bool checkRem(string &s,int st,int i,int j){
        bool f = true;
        
        while(j<s.size()){
            string val =  calculate(s,st,i,j);
            // cout << val << endl;
            int ind = j+1;
            int ind1 = 0;
            int k = 0;
            bool f1 = true;
            while(k < val.size()){
                if(ind<s.size() and val[ind1]!=s[ind]){
                    f1 = false;
                    break;
                }
                ind1++;ind++;k++;
            }
            if(f1 == false){
                return f1;
            }
            else{
                st = i+1;
                i = j;
                j = ind-1;
            }
        }
        
        return f;
    }
    bool solve(string &s,int st){
        bool F = false;
        for(int i=st;i<s.size();i++){//i is the end of first string
            if(F == true){
                break;
            }
            for(int j =i+1;j<s.size();j++){//j is the end of second string
                //first string s[st-->i] and second string s[i+1-->j]
                string val = calculate(s,st,i,j);
                if(s.size()-j-1 < val.size()){
                    break;
                }
                else{
                    int ind = j+1;
                    int ind1 = 0;
                    int k = 0;
                    bool f = true;
                    while(k < val.size()){
                        if(ind<s.size() and val[ind1]!=s[ind]){
                            f = false;
                            break;
                        }
                        ind1++;ind++;k++;
                    }
                    if(f==true){
                        //st,i,j is valid now check the remaining one
                        F |= checkRem(s,st,i,j);
                        // cout << "Hello World" << endl;
                        if(F==true){
                            break;
                        }
                    }
                }
            }
            if(F==true){
                break;
            }
        }
        return F;
    }
    bool isAdditiveSequence(string s) {
        return solve(s,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends