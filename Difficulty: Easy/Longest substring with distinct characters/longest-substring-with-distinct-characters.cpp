//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
         int i = 0;
        int j = 0;
        int l = 1;
        vector<int> count(26,0);
        int n = s.size();
        while(i<n and j <n)
        {count[s[j] - 'a']++;
         
         if(count[s[j]- 'a'] >1)
         {
             while(count[s[j] - 'a']>1)
             {
                 count[s[i] - 'a']--;
                 i++;
             }
         }
            l = max(l, j-i+1);
            j++;
        }
        return l;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends