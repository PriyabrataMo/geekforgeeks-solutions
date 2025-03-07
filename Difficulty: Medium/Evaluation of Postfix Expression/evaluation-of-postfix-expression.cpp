//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int evaluate(vector<string>& arr) {
        stack<int> st;
        
        for (string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int operand2 = st.top(); st.pop();
                int operand1 = st.top(); st.pop();
                int result;
                
                if (token == "+") result = operand1 + operand2;
                else if (token == "-") result = operand1 - operand2;
                else if (token == "*") result = operand1 * operand2;
                else if (token == "/") result = operand1 / operand2;  // Integer division (truncates towards zero)
                
                st.push(result);
            } else {
                st.push(stoi(token));  // Convert string to integer and push onto stack
            }
        }
        
        return st.top();  // The final result is the only element left in the stack
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends