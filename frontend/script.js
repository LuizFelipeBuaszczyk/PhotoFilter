import { Canvas } from './canvas.js';
import { createOption } from './utils.js';

import Range from './components/range.js'; 
import SelectMorphologicalFeature from './components/SelectMorphologicalFeature.js';
import ButtonFeature from './components/ButtonFeature.js';

// Eventos

document.getElementById('inputImage')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage')    
})

document.getElementById('inputImage2')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage2')    
})

document.getElementById('enable2Images')
    .addEventListener('change', (event) => {
    activeOperationsBetweenTwoImages(event.target.checked)
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

function activeOperationsBetweenTwoImages(active){
    const section = document.getElementById('featureButtons');
    section.replaceChildren();

    if (active) {
        showButtonsFeatureBetweenImages(section);        
    } else {
        showButtonsFeatureOneImage(section);
    }

    // Atribuindo eventos
    for (const button of section) {
        button.addEventListener('click', (event) => {
            event.preventDefault();
            manageSelectFeature(event.target.value);
        })
    }
}

function showButtonsFeatureOneImage(section){
    section.append(ButtonFeature('arithmeticButton', 'arithmetic', 'Aritmética'));
    section.append(ButtonFeature('invertButton', 'invert', 'Inverção'));
    section.append(ButtonFeature('convolutionalButton', 'convolutional', 'Convolução'));
    section.append(ButtonFeature('borderDetectionButton', 'borderDetection', 'Bordas'));
    section.append(ButtonFeature('morphologicalButton', 'morphological', 'Operações Morfológicas'));
}

// TODO Aplicar eventos click 
function showButtonsFeatureBetweenImages(section) {
    section.append(ButtonFeature('arithmeticButton', 'arithmetic', 'Aritmética'));
    section.append(ButtonFeature('logicButton', 'logic', 'Lógica'));
    section.append(ButtonFeature('diffButton', 'diff', 'Diferença'));
    section.append(ButtonFeature('linearButton', 'linear', 'Linear'));
}

function manageSelectFeature(selectedFeature) {
    const selectOperations = document.getElementById('selectFeatures');
    selectOperations.options.length = 0;
    selectOperations.hidden = false;

    const parameterSection = document.getElementById('parameterSection');
    parameterSection.replaceChildren();

    switch (selectedFeature) {
        case 'arithmetic':
            showArithmeticOperations(selectOperations, parameterSection);
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
        case 'logic':
            showLogicOperations(selectOperations);
            break;
        case 'diff':
            showDiffOperations(selectOperations);
            break;
        case 'linear':
            showLinearButton(selectOperations);
            break;
        default:
            throw "Invalid selectFeature"
    }
}


// 1 Image Operations
function showArithmeticOperations(selectOperations, parameterSection){
    const check = document.getElementById('enable2Images').checked; 
    const className = 'valueRange';

    selectOperations.add(createOption('addValue', className, 'Adicionar'));
    selectOperations.add(createOption('subtValue', className, 'Subtrair'));
    selectOperations.add(createOption('multValue', className, 'Multiplicação'));
    selectOperations.add(createOption('divValue', className, 'Divisão'));
   
    if (!check) {
        const range = Range('rangeForm', 0, 255, 1, 'Valor: 128');
        parameterSection.append(range);
    }
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

    const range = Range('rangeForm', 3, 29, 2, 'Valor: 17');
    parameterSection.append(range);
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

    const range = Range('rangeForm', 0, 255, 1, 'Valor: 128');
    parameterSection.append(range);

    const selectMorphologicalFeatures = SelectMorphologicalFeature('selectFeatureOptions', null);
   parameterSection.append(selectMorphologicalFeatures); 
}

// 2 Image operations
function showLogicOperations(selectOperations) {
    const className = 'valueRange';    

    selectOperations.add(createOption('andValue', className, 'AND'));
    selectOperations.add(createOption('orValue', className, 'OR'));
    selectOperations.add(createOption('xorValue', className, 'XOR'));
    selectOperations.add(createOption('notValue', className, 'NOT'));
}

function showDiffOperations(selectOperations) {
    selectOperations.hidden = true;
    return; 
}

function showLinearButton(selectOperations) {
    const className = 'valueRange';

    selectOperations.add(createOption('averageValue', className, 'Média'));
    selectOperations.add(createOption('blendingValue', className, 'Média'));
}
