//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int ind = 0;
        int j = 0 , i = 0;
        int n = a.size();
        int m = b.size();
        int ele = -1;
        while(i<n&&j<m){
            
            if(a[i]<b[j]){
                ele = a[i];
                i++;
                
            }
            else{
                ele = b[j];
                j++;
                
            }
            ind++;
            if(ind == k) return ele;
        }  
        while(i<n){
            ele = a[i];
            ind++;
            if(ind == k) return ele;
            i++;
        }
        while(j<m){
            
            ele = b[j];
            ind++;
            if(ind == k) return ele;
            j++;
        }
        return ele;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends