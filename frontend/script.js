import { Canvas } from './canvas.js';

// Eventos

document.getElementById('inputImage')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage')    
})

document.getElementById('inputImage2')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage2')    
})

function loadImageToCanvas(file, canvasId) {
    if (!file) throw "File é obrigatório";

    const reader = new FileReader();
    reader.onload = function(e) {
        const image = new Image();
        image.src = e.target.result;
        image.onload = function () {
            const canvas = new Canvas(canvasId, 250, 250);
            canvas.drawImageCanvas(image);
        }
    }
    reader.readAsDataURL(file);
}
