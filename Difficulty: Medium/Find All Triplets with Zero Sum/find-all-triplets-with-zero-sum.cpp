//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>>ans; 
        unordered_map<int,vector<int>>map; 
         for(int i= 0; i< arr.size(); i++){
             map[arr[i]].push_back(i) ; 
         }
         for(int i  = 0; i< arr.size(); i++){
             int val = arr[i]; 
             map[val].erase(map[val].begin()); 
             for(int j = i+1; j<arr.size(); j++){
                 int l = map[arr[j]][0]; 
                 map[arr[j]].erase(map[arr[j]].begin()); 
              int rem = 0-(val+arr[j]); 
             
             if(map.find(rem)!=map.end()){
                 int m =0; 
                 while(m<map[rem].size()){
                      if(i<j && j<map[rem][m] ){
                 vector<int>p; 
                 p.push_back(i); 
                 p.push_back(j); 
                 p.push_back(map[rem][m]); 
                 ans.push_back(p);
                 }
                   m++;
                 }
             }
             map[arr[j]].insert(map[arr[j]].begin(),l); 
             }
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends