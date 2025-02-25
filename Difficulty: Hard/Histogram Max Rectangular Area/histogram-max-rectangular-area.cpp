//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
               int maxArea = 0;
        vector<int> nse(arr.size()),pse;
        stack<int> nsh, psh;
        //pse
        for(int i=0;i<arr.size();i++){
            while(!psh.empty() && arr[psh.top()] >= arr[i]){
                psh.pop();
            }
            if(psh.empty()){
                pse.emplace_back(-1);
            }
            else
                pse.emplace_back(psh.top());
            psh.push(i);
        }
        //nse
        for(int i = arr.size()-1;i>=0;i--){
            while(!nsh.empty() && arr[nsh.top()] >= arr[i]){
                nsh.pop();
            }
            if(nsh.empty()){
                nse[i] = arr.size();
            }
            else
                nse[i] = nsh.top();
            nsh.push(i);
        }
        for(int i=0;i<arr.size();i++){
            int la = pse[i], ra = nse[i];
            maxArea = max(arr[i] * (ra - la - 1), maxArea);
        }
        return maxArea;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends