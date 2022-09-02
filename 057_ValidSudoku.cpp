bool isValid(int matrix[9][9], int row, int col, int n) {
    for (int c = 0; c < 9; c++) {
        if (matrix[row][c] == n) return false;
    }
    
    for (int r = 0; r < 9; r++) {
        if (matrix[r][col] == n) return false;
    }
    
    int x = 3 * (row / 3);
    int y = 3 * (col / 3);
    for (int r = x; r < x + 3; r++) {
        for (int c = y; c < y + 3; c++) {
            if (matrix[r][c] == n) return false;
        }
    }
    
    return true;
}
bool solver(int matrix[9][9], int row, int col) {
    if (col == 9) {
        row++;
        col = 0;
    }
    
    if (row == 9) return true;
    
    bool flag = false;
    if (matrix[row][col] == 0) {
        for (int n = 1; n <= 9; n++) {
            if (isValid(matrix, row, col, n)) {
                matrix[row][col] = n;
                flag = flag || solver(matrix, row, col + 1);
                matrix[row][col] = 0;
            }
        }
    }
    else flag = flag || solver(matrix, row, col + 1);
    
    return flag;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solver(matrix, 0 , 0);
}