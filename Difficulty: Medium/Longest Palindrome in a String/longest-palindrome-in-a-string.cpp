//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool check(int i, int j, string& s) {
        
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string &s) {
        
        
        int n = s.length();
        string ans =  "";
        string t = "";
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(i,j,s)){
                    t = s.substr(i,j-i+1);
                    if(t.length() > ans.length()){
                        ans = t;
                        t = "";
                    }
                }
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends