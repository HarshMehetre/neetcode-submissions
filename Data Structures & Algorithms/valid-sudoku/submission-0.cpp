class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Track seen digits for rows, columns, and 3x3 sub-boxes
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                int val = board[r][c] - '1'; // Map '1'-'9' to index 0-8
                int boxIndex = (r / 3) * 3 + (c / 3); // Map 2D position to 3x3 box index (0-8)

                // Check if value already exists in row, column, or sub-box
                if (rows[r][val] || cols[c][val] || boxes[boxIndex][val]) {
                    return false;
                }

                // Mark the value as seen
                rows[r][val] = true;
                cols[c][val] = true;
                boxes[boxIndex][val] = true;
            }
        }

        return true;
    }
};
