import { Canvas } from './canvas.js';
import { createInput, createOption, drawImage } from './utils.js';

import Range from './components/range.js'; 
import SelectMorphologicalFeature from './components/SelectMorphologicalFeature.js';
import FieldsetFeature from './components/FieldsetFeature.js';
import ImageProcessingController from './ImageProcessingController.js' ;

// GLOBAIS
let SELECTED_FEATURE = 'arithmetic';
let SELECTED_OPTION = 'addValue';

// Eventos
document.getElementById('inputImage')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage')    
});

document.getElementById('inputImage2')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage2')    
});

document.getElementById('enable2Images')
    .addEventListener('change', (event) => {
    activeOperationsBetweenTwoImages(event.target.checked)
});

document.getElementById('featureButtons')
    .addEventListener('change', (event) => {
    manageSelectFeature(event.target.value)
});

document.getElementById('selectFeatures')
    .addEventListener('change', (event) => {
    manageSelectParameters(event.target.value)
});

document.getElementById('proccessButton')
    .addEventListener('click', proccessImage)

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
    const fieldset = document.getElementById('featureButtons');
    fieldset.replaceChildren();

    if (active) {
        showButtonsFeatureBetweenImages(fieldset);        
    } else {
        showButtonsFeatureOneImage(fieldset);
    }
     
}

function showButtonsFeatureOneImage(fieldset){
    const radioButtons = [];

    radioButtons.push({
        'id': 'arithmeticButton',
        'value':'arithmetic',
        'labelText': 'Aritmética',
        'selected': true,
    });

    radioButtons.push({
        'id': 'invertButton',
        'value':'invert',
        'labelText': 'Inverção'
    });

    radioButtons.push({
        'id': 'convolutionalButton',
        'value':'convolutional',
        'labelText': 'Convolução'
    });

    radioButtons.push({
        'id': 'borderDetectionButton',
        'value':'border',
        'labelText': 'Bordas'
    });

    radioButtons.push({
        'id': 'morphologicalButton',
        'value':'morphological',
        'labelText': 'Operações Morfológicas'
    });

    FieldsetFeature(fieldset, radioButtons);
}

function showButtonsFeatureBetweenImages(fieldset) {
    const radioButtons = [];

    radioButtons.push({
        'id': 'arithmeticButton',
        'value': 'arithmetic',
        'labelText': 'Aritmética',
        'selected': true
    });

    radioButtons.push({
        'id': 'logicButton',
        'value': 'logic',
        'labelText': 'Lógica'
    });


    radioButtons.push({
        'id': 'diffButton',
        'value': 'diff',
        'labelText': 'Diferença'
    });


    radioButtons.push({
        'id': 'linearButton',
        'value': 'linear',
        'labelText': 'Linear'
    });

    FieldsetFeature(fieldset, radioButtons);
}

function manageSelectFeature(selectedFeature) {
    SELECTED_FEATURE = selectedFeature;

    const selectOperations = document.getElementById('selectFeatures');
    selectOperations.options.length = 0;
    selectOperations.hidden = false;

    const parameterSection = document.getElementById('parameterSection');
    parameterSection.replaceChildren();

    switch (SELECTED_FEATURE) {
        case 'arithmetic':
            showArithmeticOperations(selectOperations, parameterSection);
            break;
        case 'invert':
            showInvertOperations(selectOperations);
            break;
        case 'convolutional':
            showConvolutionalOperations(selectOperations);
            break;
        case 'border':
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

function manageSelectParameters(selectedOption) {
    SELECTED_OPTION = selectedOption
    const parameterSection = document.getElementById('parameterSection');
    parameterSection.replaceChildren();

    switch (SELECTED_FEATURE) {
        case 'arithmetic':
            showArithmeticParameters(parameterSection);
            break;
        case 'invert':
            break;
        case 'convolutional':
            showConvolutionalParameters(parameterSection);
            break;
        case 'morphological':
            showMorphologicalParameters(parameterSection);
            break;
    } 
}

function showArithmeticParameters(parameterSection) {
    const range = Range('rangeForm', 0, 255, 1, 'Valor: 128');
    parameterSection.append(range);   
}

function showConvolutionalParameters(parameterSection) {
    const range = Range('rangeForm', 3, 29, 1, 'Valor: 17');
    parameterSection.append(range);   
    
    switch (SELECTED_OPTION){
        case 'orderValue':
            const inputOrderValue = createInput('inputValue', 'number', null, 5);
            parameterSection.append(inputOrderValue);
            break;
        case 'gaussianValue':
            const inputGaussianValue = createInput('inputValue', 'number', null, 100);
            parameterSection.append(inputGaussianValue);
            break;
    }
}

function showMorphologicalParameters(parameterSection) {
    const range = Range('rangeForm', 0, 255, 1, 'Valor: 128');
    parameterSection.append(range);   

    const selectMorphologicalFeatures = SelectMorphologicalFeature('selectFeatureOptions', null);
    parameterSection.append(selectMorphologicalFeatures); 
}

async function proccessImage(){
    const gateway = new ImageProcessingController(); 

    try {
        const response = await gateway.proccess();
        await drawImage(response, 'canvas');
    } catch (error) {
        console.log(error)
    }
}
