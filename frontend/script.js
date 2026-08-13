import { Canvas } from './components/canvas.js';
import { createInput, createOption, drawImage, drawHistogram } from './utils/utils.js';

import Range from './components/range.js'; 
import SelectMorphologicalFeature from './components/SelectMorphologicalFeature.js';
import FieldsetFeature from './components/FieldsetFeature.js';
import Notification from './components/notification.js';
import ImageProcessingController from './ImageProcessingController.js' ;

// GLOBAIS
let SELECTED_FEATURE = 'arithmetic';
let SELECTED_OPTION = 'addValue';
let OPERATION_WITH_2_IMAGES = false;
const GATEWAY = new ImageProcessingController(); 
const NOTIFIER = new Notification(); 

// Eventos
document.getElementById('inputImage')
    .addEventListener('change', (event) => {
    loadImageToCanvas(event.target.files[0], 'showInputImage', GATEWAY.set_first_image.bind(GATEWAY)); 
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
    .addEventListener('click', proccessImage);

document.getElementById('saveImageButton')
    .addEventListener('click', saveImage);

function loadImageToCanvas(file, canvasId, set_function) {
    if (!file) throw "File é obrigatório";

    const reader = new FileReader();
    reader.onload = function(e) {
        const image = new Image();
        image.src = e.target.result;
        image.onload = function () {
            const canvas = new Canvas(canvasId, 250, 250);
            canvas.drawImageCanvas(image);
            set_function(canvas.pixels.data);
        }
    }
    reader.readAsDataURL(file);
}

function activeOperationsBetweenTwoImages(active){
    const fieldset = document.getElementById('featureButtons');
    fieldset.replaceChildren();
    
    OPERATION_WITH_2_IMAGES = active;

    if (OPERATION_WITH_2_IMAGES) {
        createSecondImageInput();
        showButtonsFeatureBetweenImages(fieldset);        
    } else {
        removeSecondImageInput();
        showButtonsFeatureOneImage(fieldset);
    }
     
}
activeOperationsBetweenTwoImages(OPERATION_WITH_2_IMAGES);


function createSecondImageInput() {
    const form = document.getElementById('formInputImages');
    const image_div = document.createElement('div');
    image_div.id = 'inputImage2Container';
    image_div.className = 'imageDiv';

    const h2 = document.createElement('h2');
    h2.textContent = 'Imagem de Entrada 2';

    const input = createInput('inputImage2', 'file', null, 'image2');
    image_div.append(h2, input);

    const canvas = document.createElement('canvas');
    canvas.id = 'showInputImage2';
    canvas.className = 'imgStyle';
    canvas.width = 250;
    canvas.height = 250;
    
    image_div.append(canvas);
    form.append(image_div);

    input.addEventListener('change', (event) => {
        loadImageToCanvas(event.target.files[0], 'showInputImage2', GATEWAY.set_second_image.bind(GATEWAY));
    });
}

function removeSecondImageInput() {
    document.getElementById('inputImage2Container')?.remove();
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
    
    radioButtons.push({
        'id' : 'convertButton',
        'value': 'convert',
        'labelText': 'Conversão de Escala'
    })

    radioButtons.push({
        'id': 'logicButton',
        'value': 'logic',
        'labelText': 'Lógica'
    });

    radioButtons.push({
        'id': 'histogramButton',
        'value': 'histogram',
        'labelText': 'Histograma'
    });

    SELECTED_FEATURE = 'arithmetic'
    FieldsetFeature(fieldset, radioButtons);
    manageSelectFeature(SELECTED_FEATURE);
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
        'id': 'linearButton',
        'value': 'linear',
        'labelText': 'Linear'
    });
    
    SELECTED_FEATURE = 'arithmetic'
    FieldsetFeature(fieldset, radioButtons);
    manageSelectFeature(SELECTED_FEATURE);
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
        case 'convert':
            showConvertOperations(selectOperations);
            break;
        case 'logic':
            showLogicOperations(selectOperations);
            break;
        case 'linear':
            showLinearOperations(selectOperations);
            break;
        case 'histogram':
            showHistogramOperations(selectOperations);
            break;
        default:
            throw "Invalid selectFeature"
    }
}

// 1 Image Operations
function showArithmeticOperations(selectOperations, parameterSection){
    const className = 'valueRange';
    
    if (OPERATION_WITH_2_IMAGES) {
        selectOperations.add(createOption('addImages', className, 'Adicionar'));
        selectOperations.add(createOption('subtImages', className, 'Subtrair'));

    } else {
        selectOperations.add(createOption('addValue', className, 'Adicionar'));
        selectOperations.add(createOption('subtValue', className, 'Subtrair'));
        selectOperations.add(createOption('multValue', className, 'Multiplicação'));
        selectOperations.add(createOption('divValue', className, 'Divisão'));
   
        const range = Range('rangeForm', 0, 255, 1, 128);
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

    const range = Range('rangeForm', 3, 29, 2, 17);
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

    const range = Range('rangeForm', 3, 29, 2, 17);
    parameterSection.append(range);

    const selectMorphologicalFeatures = SelectMorphologicalFeature('selectFeatureOptions', null);
    parameterSection.append(selectMorphologicalFeatures); 
}

function showConvertOperations(selectOperations) {
    const className = 'valueRange';

    selectOperations.add(createOption('grayScaleValue', className, 'Escala de Cinza'));
    selectOperations.add(createOption('binaryScaleValue', className, 'Escala Binária'));
}

function showHistogramOperations(selectOperations) {
    const className = 'valueRange';

    selectOperations.add(createOption('equalizeHistogramValue', className, 'Equalizar'));
}

// 2 Image operations
function showLogicOperations(selectOperations) {
    const className = 'valueRange';    

    if (OPERATION_WITH_2_IMAGES) {
        selectOperations.add(createOption('andValue', className, 'AND'));
        selectOperations.add(createOption('orValue', className, 'OR'));
        selectOperations.add(createOption('xorValue', className, 'XOR'));
    }
    else {
        selectOperations.add(createOption('notValue', className, 'NOT'));
    }
}

function showLinearOperations(selectOperations) {
    const className = 'valueRange';

    selectOperations.add(createOption('averageValue', className, 'Média'));
    selectOperations.add(createOption('blendingValue', className, 'Blending'));
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
        case 'linear':
            showLinearParameters(parameterSection);
            break;
    } 
}

function showArithmeticParameters(parameterSection) {

    if (!OPERATION_WITH_2_IMAGES) {
        const range = Range('rangeForm', 0, 255, 1, 128);
        parameterSection.append(range);
    }
}

function showConvolutionalParameters(parameterSection) {
    const range = Range('rangeForm', 3, 29, 2, 17);
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
    const range = Range('rangeForm', 3, 29, 2, 17);
    parameterSection.append(range);   

    const selectMorphologicalFeatures = SelectMorphologicalFeature('selectFeatureOptions', null);
    parameterSection.append(selectMorphologicalFeatures); 
}

function showLinearParameters(parameterSection) {
    
    switch (SELECTED_OPTION) {
        case 'blendingValue':
            const inputBlendingValue = createInput('inputValue', 'number', null, 5);
            parameterSection.append(inputBlendingValue);
            break;
    }
} 

async function proccessImage(){
    const feature = document.querySelector('#featureButtons :checked').value;
    const option = document.getElementById('selectFeatures').value;

    if (OPERATION_WITH_2_IMAGES) {
        if (!GATEWAY.first_image) return alert("Selecione a primeira imagem antes de processar");
        if (!GATEWAY.second_image) return alert("Selecione a segunda imagem antes de processar");
    } else if (!GATEWAY.first_image) {
        return alert("Selecione uma imagem antes de processar");
    }

    try {
        const response = await GATEWAY.proccess(feature, option);
        // TODO -- Adaptação para o endpoint de histogram, será corrigido no refactor do backend
        await drawImage(response.image ? response.image : response, 'canvas');
    } catch (error) {
        NOTIFIER.showError(error);
    }
}

function saveImage() {
    const canvas = document.getElementById('canvas');
    const imagemDataURL = canvas.toDataURL('image/png');

    const link = document.createElement('a');
    link.href = imagemDataURL;
    link.download = 'imagem_canvas.png'; 
    link.click(); 
}
