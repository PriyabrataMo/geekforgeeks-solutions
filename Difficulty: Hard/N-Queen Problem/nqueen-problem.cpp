//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> temp;
    int t = 0;
    bool val(vector<vector<int>> &board , int r , int c){
        for(int i=0;i<r;i++){
            if(board[i][c]==1) return false;
        }
        for(int i=1;i<t;i++){
            int nr1 = r-i;
            int nc1 = c-i;
            int nr2 = r-i;
            int nc2 = c+i;
            // if(r==2&&c==2){
            //     cout<<nr1<<" "<<nc1<<" "<<nr2<<" "<<nc2<<" "<<endl;
            // }
            if(nr1>=0&&nr1<t&&nc1>=0&&nc1<t){
                if(board[nr1][nc1]==1){
                    return false;
                }
            }
            if(nr2>=0&&nr2<t&&nc2>=0&&nc2<t){
                if(board[nr2][nc2]==1){
                    return false;
                }
            }
        }
        //cout<<"true: "<<r<<" "<<c<<endl;
        return true;
    }
    
    
    void func(vector<vector<int>> &board , int r ){
        if(r==t){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<t;i++){
            if(val(board , r,i)){
                temp.push_back(i+1);
                board[r][i]=1;
                func(board , r+1);
                temp.pop_back();
                board[r][i]=0;
            }
            
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n+1 , vector<int>(n+1 , 0));
        t = n;
        func(board , 0);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends