import ImageEngineGateway from "./ImageEngineGateway.js";

export default class ImageProcessingController {
    
    constructor (){
        this.sectionFeature = sectionFeature;
        this.engine = new ImageEngineGateway();
    }
    
    async proccess(){
        const feature = document.querySelector('#featureButtons :checked').value;
       
        switch (feature) {
            case 'arithmetic':
                return await this._arithmetic();
            case 'invert':
                return await this._invert();
            case 'convolutional':
                return await this._convolutional();
            case 'border':
                return await this._border();
            case 'morphological':
                return await this._morphological();
            case 'convert':
                return await this._convert();
            default:
                throw "Opção inválida";
        }
    }

    _arithmetic() {
        const option = document.getElementById('selectFeatures').value;
        const imageCanva = document.getElementById('showInputImage');
        const value = document.getElementById('range').value;
    
        switch (option) {
            case 'addValue':
                return this.engine.addValue(imageCanva, value);
            case 'subtValue':
                return this.engine.subtValue(imageCanva, value);
            case 'multValue':
                return this.engine.multiplyValue(imageCanva, value);
            case 'divValue':
                return this.engine.divValue(imageCanva, value);
            default:
                throw `Opção inválida para aritmética: ${option}`;
        }
       
    }

    _invert() {
        const option = document.getElementById('selectFeatures').value;
        const imageCanva = document.getElementById('showInputImage');
        
        switch (option) {
            case 'horizontalValue':
                return this.engine.invertHorizontal(imageCanva);
            case 'verticleValue':
                return this.engine.invertVerticle(imageCanva);
            default:
                throw `Opção inválida para inverção: ${option}`;
        }
    }

    _convolutional() {
        const option = document.getElementById('selectFeatures').value;
        const imageCanva = document.getElementById('showInputImage');
        const kernelSize = document.getElementById('range').value;
        const inputValue = document.getElementById('inputValue') ? document.getElementById('inputValue').value : null;

        switch (option) {
            case 'meanValue':
                return this.engine.convolutionAverage(imageCanva, kernelSize);
            case 'minValue':
                return this.engine.convolutionMin(imageCanva, kernelSize);
            case 'maxValue':
                return this.engine.convolutionMax(imageCanva, kernelSize);
            case 'medianValue':
                return this.engine.convolutionMedian(imageCanva, kernelSize);
            case 'orderValue':
                return this.engine.convolutionOrder(imageCanva, kernelSize, inputValue);
            case 'conservativeSomoothingValue':
                return this.engine.convolutionConservativeSuavization(imageCanva, kernelSize);
            case 'gaussianValue':
                return this.engine.convolutionGaussian(imageCanva, kernelSize, inputValue); 
            default:
                throw `Opção inválida para convolução: ${option}`;
        }
    }

    _border() {
        const option = document.getElementById('selectFeatures').value;
        const imageCanva = document.getElementById('showInputImage');
    
        switch (option) {
            case 'prewitValue':
                return this.engine.borderPrewit(imageCanva);
            case 'sobelValue':
                return this.engine.borderSobel(imageCanva);
            case 'laplacianValue':
                return this.engine.borderLaplacian(imageCanva);
            default:
                throw `Opção inválida para detecção de borda: ${option}`;
        }
    }

    _morphological() {
        const option = document.getElementById('selectFeatures').value;
        const imageCanva = document.getElementById('showInputImage');
        const kernelSize = document.getElementById('range').value;
        const type = document.getElementById('selectFeatureOptions').value;

        switch (option) {
            case 'dilationValue':
                return this.engine.morphologicalDilatation(imageCanva, kernelSize, type);
            case 'erosionValue':
                return this.engine.morphologicalErosion(imageCanva, kernelSize, type);
            case 'openingValue':
                return this.engine.morphologicalOpening(imageCanva, kernelSize, type);
            case 'closingValue':
                return this.engine.morphologicalClosing(imageCanva, kernelSize, type);
            case 'outlineValue':
                return this.engine.morphologicalOutline(imageCanva, kernelSize, type);
            default:
                throw `Opção inválida para operação morfológica: ${option}`;
        }
    }

    _convert() {
        const option = document.getElementById('selectFeatures').value;
        const imageCanva = document.getElementById('showInputImage');
        
        switch (option) {
            case 'grayScaleValue':
                return this.engine.convertToGrayScale(imageCanva);
            case 'binaryScaleValue':
                return this.engine.convertToBinaryScale(imageCanva);
            default:
                throw `Opção inválida para conversão de escala: ${option}`;
        }
    }
}
