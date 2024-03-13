function generateEmptyGrid() {
    const gridContainer = document.getElementById('sudoku-grid');
    gridContainer.innerHTML = ''; // Clear previous grid if any

    for (let row = 0; row < 9; row++) {
        for (let col = 0; col < 9; col ++) {
            const cell = document.createElement('div');
            cell.className = 'sudoku-cell';
            gridContainer.appendChild(cell);
        }
    }
}

document.addEventListener('DOMContentLoaded', generateEmptyGrid)

function uploadImage() {
    const imageInput = document.getElementById('sudokuImage');
    if (imageInput.files.length === 0) {
        alert('Please select an image first!');
        return;
    }


const formData = new FormData();
formData.append('sudokuImage', imageInput.files[0]);

fetch('/upload', {
    method: 'POST',
    body: formData
})
.then(response => response.json())
.then(data => {
    displaySudokuSolution(data.solution);
})
.catch(error => console.error(error));
}

function displaySudokuSolution(solution) {
    const cells = document.querySelectorAll('.sudoku-cell');
    solution.forEach((row, rowIndex) => {
        row.forEach((num, colIndex) => {
            const cellIndex = rowIndex * 9 + colIndex;
            cells[cellIndex].textContent = num === 0 ? '' : num;
        });
    });
}