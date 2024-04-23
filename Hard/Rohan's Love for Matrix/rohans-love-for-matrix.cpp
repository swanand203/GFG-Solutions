//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        if (n <= 2) return 1;
        vector<vector<long long>> base = {{1, 1}, {1, 0}};
        vector<vector<long long>> result = power(base, n - 2);
        return (result[0][0] + result[0][1]) % 1000000007;
    }
    
private:
    vector<vector<long long>> multiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
        vector<vector<long long>> c(2, vector<long long>(2, 0));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % 1000000007) % 1000000007;
                }
            }
        }
        return c;
    }
    
    vector<vector<long long>> power(const vector<vector<long long>>& base, int exp) {
        if (exp == 1) return base;
        vector<vector<long long>> half_power = power(base, exp / 2);
        vector<vector<long long>> result = multiply(half_power, half_power);
        if (exp % 2 == 1) result = multiply(result, base);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends