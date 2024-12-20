//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int rows = matrix.size();      // Number of rows
        int cols = matrix[0].size();  // Number of columns

        // Initialize boundaries
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        vector<int> result;  // To store the spiral order traversal

        // Loop until the boundaries meet
        while (top <= bottom && left <= right) {
            
            // Traverse left to right
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++; // Shift top boundary downward
            
            // Traverse top to bottom
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--; // Shift right boundary leftward
            
            // Check if there are rows left
            if (top <= bottom) {
                // Traverse right to left
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Shift bottom boundary upward
            }
            
            // Check if there are columns left
            if (left <= right) {
                // Traverse bottom to top
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Shift left boundary rightward
            }
        }

        return result;  // Return the spiral order
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends