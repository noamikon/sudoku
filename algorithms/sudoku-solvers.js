//backtracking sudoku solver

function backTrackingSolver(board) {
  solveBacktracking(board);
  return board;
}

function solveBacktracking(board) {
    let empty = findEmpty(board);
    if (!empty) return true;
    let [row, col] = empty;
    for (let num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
        board[row][col] = num;
        if (solveBacktracking(board)) return true;
        board[row][col] = 0;
        }
    }
    return false;
}

function findEmpty(board) {
    for (let row = 0; row < 9; row++) {
        for (let col = 0; col < 9; col++) {
        if (board[row][col] === 0) return [row, col];
        }
    }
    return null;
}

function isValid(board, row, col, num) {
    for (let i = 0; i < 9; i++) {
        if (board[row][i] === num || board[i][col] === num) return false;
    }
    let startRow = row - row % 3;
    let startCol = col - col % 3;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
        if (board[i + startRow][j + startCol] === num) return false;
        }
    }
    return true;
}

// stochastic sudoku solver

function stochasticSolver(board) {
    solveStochastic(board);
    return board;
}

function solveStochastic(board) {
    let empty = findEmpty(board);
    if (!empty) return true;
    let [row, col] = empty;
    let nums = shuffle([1, 2, 3, 4, 5, 6, 7, 8, 9]);
    for (let num of nums) {
        if (isValid(board, row, col, num)) {
        board[row][col] = num;
        if (solveStochastic(board)) return true;
        board[row][col] = 0;
        }
    }
    return false;
}

function shuffle(arr) {
    for (let i = arr.length - 1; i > 0; i--) {
        let j = Math.floor(Math.random() * (i + 1));
        [arr[i], arr[j]] = [arr[j], arr[i]];
    }
    return arr;
}

// export { backTrackingSolver, stochasticSolver };
module.exports = { backTrackingSolver, stochasticSolver };