

const TextToGrid = (text) => {
    // Replace 'O' with '0' in the text
    text = text.replace(/O/g, '0');
    text = text.replace(/o/g, '0');
    console.log(text)
    text = text.replace(/[^0-9]/g, '')
    console.log(text)
    // Initialize a 9x9 array filled with zeros
    const grid = Array.from({ length: 9 }, () => Array(9).fill(0));
    let row = 0;
    let col = 0;

    for (let i = 0; i < text.length; i++) {
        // Check for numeric characters and increment col

        grid[row][col] = parseInt(text[i]);
        col++;
        if (col === 9) {
            // Move to the next row at the end of a line or if col reached the end
            row++;
            col = 0;
        }
        
        // Break if we've filled the grid
        if (row === 9) break;
    }

    return grid;
}

module.exports = TextToGrid


// let myText = "3/0/0]8]0[1]0/0]2]\n2/0/1]0/3/0]6/0]4|\n0/0/0]2/0[4]0/0/0\n8/0/9]0]0/0[1]0]6]\n0/6/0[0/0]0]0]5]0]\n7/0/2|0/0/0[4/0/9|\n0/0/0[5]0[9]0]0/0|\n9/0/4[0/8/0[7]/0]5\n6/0/0[1/0/7[0]0]3\n";
/* console.log(myText);
myText = myText.replace(/[^0-9]/g, '')
console.log(myText) */
/* const myGrid = TextToGrid(myText)

for (let i = 0; i < 9; i++) {
    console.log(myGrid[i].join(","))
} */
// console.log(myGrid);

// exports { TextToGrid }