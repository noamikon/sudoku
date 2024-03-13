const path = require('path')
const express = require('express')
const multer = require('multer')
const { createWorker } = require('tesseract.js')
const { fileURLToPath } = require('url')
const TextToGrid = require('../utils/sudoku.js')
const sudokuModule = require('../build/Release/obj.target/mySudokuModule.node')
const { backTrackingSolver } = require('../algorithms/sudoku-solvers.js')


// const __filename = fileURLToPath(import.meta.url)
// const __dirname = path.dirname(__filename)
const uploadsPath = path.join(__dirname, '..', 'uploads/');

const app = express()
const PORT = process.env.PORT || 3001

const storage = multer.diskStorage({
    destination: (req, file, cb) => {
        cb(null, uploadsPath)
    },
    filename: (req, file, cb) => {
        cb(null, file.fieldname + '-' + Date.now() + path.extname(file.originalname))
    }
})

const upload = multer({ storage: storage })

const worker = createWorker()


app.post('/upload', upload.single('sudokuImage'), async (req, res) => {
    const imagePath = req.file.path

    const processedImagePath = "./uploads/processed.png"
    sudokuModule.fillSudokuWithZeros(req.file.path, processedImagePath)

    try {
        await worker.load()
        await worker.loadLanguage('eng')
        await worker.initialize('eng')
        const { data: { text } } = await worker.recognize(processedImagePath)
        console.log(text)
        const grid = TextToGrid(text)
        console.log(grid)
        const solvedPuzzle = backTrackingSolver(grid)
        console.log(solvedPuzzle)

        res.json({ message: 'Sudoku recognized', solution: grid })
    } catch (error) {
        console.log(error)
        res.status(500).json({ message: 'Error processing image', error: error.message })
    } finally {
        await worker.terminate()
    }

    console.log(`Received image: ${imagePath}`)

})

const publicDirectoryPath = path.join(__dirname, '../public')
app.use(express.static(publicDirectoryPath))

app.listen(PORT, () => {
    console.log(`Server is up on port ${PORT}`)
})