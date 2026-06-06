import ImageEngineGateway from "./ImageEngineGateway.js";

export default class ImageProcessingController {
    
    constructor (){
        this.sectionFeature = sectionFeature;
        this.engine = new ImageEngineGateway();
    }
    
    async proccess(){
        const feature = document.querySelector('#featureButtons :checked').value;
       
        let response = undefined;
        switch (feature) {
            case 'arithmetic':
                response = await this._arithmetic();
                break;
            case 'invert':
                response = await this._invert();
                break;
            case 'convolutional':
                response = await this._convolutional();
                break;
            default:
                throw "Opção inválida";
        }

        return response;
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

        // TODO conservative smoothing e order precisam de mais um valor.
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
}
