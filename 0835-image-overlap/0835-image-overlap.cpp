class Solution {
public:

    // Calculate overlap for ONE particular translation
    int countOverlaps(vector<vector<int>>& A,
                      vector<vector<int>>& B,
                      int rowOff,
                      int colOff) {

        int n = A.size();
        int count = 0;

        // Check every position of A
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                // A[i][j] moves to this position in B
                int B_i = i + rowOff;
                int B_j = j + colOff;

                // If new position is outside B, ignore it
                if (B_i < 0 || B_i >= n ||
                    B_j < 0 || B_j >= n) {
                    continue;
                }

                // Overlap occurs only when both are 1
                if (A[i][j] == 1 &&
                    B[B_i][B_j] == 1) {

                    count++;
                }
            }
        }

        return count;
    }


    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        int maxOverlap = 0;

        // Try every possible row movement
        for (int rowOff = -n + 1; rowOff < n; rowOff++) {

            // Try every possible column movement
            for (int colOff = -n + 1; colOff < n; colOff++) {

                // Calculate overlap for this movement
                int count = countOverlaps(
                    img1,
                    img2,
                    rowOff,
                    colOff
                );

                // Keep maximum overlap
                maxOverlap = max(maxOverlap, count);
            }
        }

        return maxOverlap;
    }
};