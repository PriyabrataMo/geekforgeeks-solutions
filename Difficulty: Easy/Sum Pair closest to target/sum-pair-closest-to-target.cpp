//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int mindiff = INT_MAX;
        vector<int>ans;
        int i = 0;int j = n-1;
        while(i<j)
        {
            int diff = abs(target - (arr[i] + arr[j]));
            if(diff<mindiff)
            {
                mindiff = diff;
                if(ans.empty())
                {ans.push_back(arr[i]);ans.push_back(arr[j]);}
                ans[0] = arr[i];
                ans[1] = arr[j];
            }
            
            if(arr[i]+ arr[j] <= target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
       return ans;
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends