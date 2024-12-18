//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool func(vector<int> &arr, int m , int k){
        int c = 1;
        int s = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>m) return false;
            
            if(s+arr[i]>m){
                c++;
                s=arr[i];
                if(c>k) return false;
            }
            else{
                s+=arr[i];
            }
            
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n) return -1;
        if(k==n) return *max_element(arr.begin() , arr.end());
        int s = 0;
        int maxi = -1;
        for(auto it:arr){
            s+=it;
            maxi = max(maxi , it);
        }
        int l = maxi;
        int r = s;
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            // cout<<m<<endl;
            if(func(arr , m , k)){
                ans = m;
                r = m-1;
                
            }
            else {
                l = m+1;
            }
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends