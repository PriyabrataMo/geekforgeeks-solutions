//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('|| c=='{'||c=='['){
                st.push(c);
            }else{
                if(st.empty()) return false;
                
                char top=st.top();
                st.pop();
                
                if((c==')' && top!='(')||
                   (c=='}' && top!='{')||
                   (c==']' && top!='[')){
                       return false;
                   }
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends