import { Canvas } from './canvas.js';
import { createOption } from './utils.js';

// Eventos

document.getElementById('inputImage')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage')    
})

document.getElementById('inputImage2')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage2')    
})

const featureButtons = document.querySelectorAll('.featureButton');

featureButtons.forEach(button => {
    button.addEventListener('click', function (event) {
        event.preventDefault();
        manageSelectFeature(event.target.value);
    });
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

function manageSelectFeature(selectedFeature) {
    const selectOperations = document.getElementById('selectFeatures');
    selectOperations.options.length = 0;

    switch (selectedFeature) {
        case 'arithmetic':
            showArithmeticOperations(selectOperations);
            break;
        case 'invert':
            showInvertOperations(selectOperations);
            break;

        case 'convolutional':
            showConvolutionalOperations(selectOperations);
            break;

        case 'borderDetection':
            showBorderDetectionOperations(selectOperations);
            break;
        case 'morphological':
            showMorphologicalOperations(selectOperations);
            break;
        default:
            throw "Invalid selectFeature"
    }
}


function showArithmeticOperations(selectOperations){
    const className = 'valueRange';

    selectOperations.add(createOption('addValue', className, 'Adicionar'));
    selectOperations.add(createOption('subtValue', className, 'Subtrair'));
    selectOperations.add(createOption('multValue', className, 'Multiplicação'));
    selectOperations.add(createOption('divValue', className, 'Divisão'));
}

function showInvertOperations(selectOperations) {
    const className = 'valueRange';

    selectOperations.add(createOption('horizontalValue', className, 'Horizontal'));
    selectOperations.add(createOption('verticleValue', className, 'Vertical'));
}

function showConvolutionalOperations(selectOperations) {
    const className = 'valueRange';

    selectOperations.add(createOption('meanValue', className, 'Média'));
    selectOperations.add(createOption('minValue', className, 'Mínimo'));
    selectOperations.add(createOption('maxValue', className, 'Máximo'));
    selectOperations.add(createOption('medianValue', className, 'Mediana'));
    selectOperations.add(createOption('orderValue', className, 'Ordem'));
    selectOperations.add(createOption('conservativeSomoothingValue', className, 'Suavização Conservativa'));
    selectOperations.add(createOption('gaussianValue', className, 'Gaussiano'));
}

function showBorderDetectionOperations(selectOperations) {
    const className = 'valueRange';

    selectOperations.add(createOption('prewitValue', className, 'Prewit'));
    selectOperations.add(createOption('sobelValue', className, 'Sobel'));
    selectOperations.add(createOption('laplacianValue', className, 'Laplaciano'));
}

function showMorphologicalOperations (selectOperations) {
    const className = 'valueRange';

    selectOperations.add(createOption('dilationValue', className, 'Dilatação'));
    selectOperations.add(createOption('erosionValue', className, 'Erosão'));
    selectOperations.add(createOption('openingValue', className, 'Abertura'));
    selectOperations.add(createOption('closingValue', className, 'Fechamento'));
    selectOperations.add(createOption('outlineValue', className, 'Contorno'));
}
