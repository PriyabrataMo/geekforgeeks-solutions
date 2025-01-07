//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int t) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<r){
            if(arr[l]+arr[r]==t){
                if(arr[l]==arr[r]){
                    ans+=((r-l+1)*(r-l))/2;
                    return ans;
                }
                else{
                    int lc = 0 , rc= 0;
                    int ele = arr[l];
                    while(l<r&&arr[l]==ele){
                        lc++;
                        l++;
                    }
                    ele = arr[r];
                    while(r>=l&&arr[r]==ele){
                        rc++;
                        r--;
                    }
                    // cout<<lc<<" "<<rc<<endl;
                    ans+=lc*rc;
                    // cout<<ans<<endl;
                }
                
            }
            else if(arr[l]+arr[r]>t){
                r--;
            }
            else l++;
            // cout<<l<<" "<<r<<endl;
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends