//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int pos = -1;
        int l = 0;
        int r = arr.size()-1;
        while(l<=r){
            
            int m = l+(r-l)/2;
            if(arr[m]==key) return m;
            if(arr[l]<=arr[m]){
                if(arr[l]<=key&&arr[m]>=key){
                    r = m-1;
                }
                else {
                    l = m+1;
                }
            }
            if(arr[r]>=arr[m]){
                if(arr[m]<=key&&arr[r]>=key){
                    l = m+1;
                }
                else {
                    r = m-1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends