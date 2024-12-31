//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        vector<int> fre(1e5+2 , 0);
        for(auto it:arr){
            fre[it] = 1;
        }
        int ans = 0;
        int temp = 0;
        
        for(int i=0;i<=100001;i++){
            if(fre[i]>0){
                if(fre[i-1]>0){
                    temp++;
                }
                else{
                    temp=1;
                }
            }
            else{
                temp=0;
            }
            ans = max(ans , temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends