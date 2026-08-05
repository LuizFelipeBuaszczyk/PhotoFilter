import ImageEngineGateway from "./ImageEngineGateway.js";

export default class ImageProcessingController {
    
    constructor (){
        this.engine = new ImageEngineGateway();
    }
   
    set_first_image(buffer) {
        this.first_image = buffer;
    }

    set_second_image(buffer) {
        this.second_image = buffer;
    }

    async proccess(feature, option){
       
        switch (feature) {
            case 'arithmetic':
                return await this._arithmetic(option);
            case 'invert':
                return await this._invert(option);
            case 'convolutional':
                return await this._convolutional(option);
            case 'border':
                return await this._border(option);
            case 'morphological':
                return await this._morphological(option);
            case 'convert':
                return await this._convert(option);
            case 'logic':
                return await this._logic(option);
            case 'linear':
                return await this._linear(option);
            case 'histogram':
                return await this._histogram(option);
            default:
                throw `Opção inválida: ${feature}`;
        }
    }

    _arithmetic(option) {
        const value = document.getElementById('range') ? document.getElementById('range').value : 0;

        switch (option) {
            case 'addValue':
                return this.engine.addValue(this.first_image, value);
            case 'subtValue':
                return this.engine.subtValue(this.first_image, value);
            case 'multValue':
                return this.engine.multiplyValue(this.first_image, value);
            case 'divValue':
                return this.engine.divValue(this.first_image, value);
            case 'addImages':
                return this.engine.addImages(this.first_image, this.second_image);
            case 'subtImages':
                return this.engine.subtImages(this.first_image, this.set_second_image);
            default:
                throw `Opção inválida para aritmética: ${option}`;
        }
       
    }

    _invert(option) {
        switch (option) {
            case 'horizontalValue':
                return this.engine.invertHorizontal(this.first_image);
            case 'verticleValue':
                return this.engine.invertVerticle(this.first_image);
            default:
                throw `Opção inválida para inverção: ${option}`;
        }
    }

    _convolutional(option) {
        const kernelSize = document.getElementById('range').value;
        const inputValue = document.getElementById('inputValue') ? document.getElementById('inputValue').value : null;

        switch (option) {
            case 'meanValue':
                return this.engine.convolutionAverage(this.first_image, kernelSize);
            case 'minValue':
                return this.engine.convolutionMin(this.first_image, kernelSize);
            case 'maxValue':
                return this.engine.convolutionMax(this.first_image, kernelSize);
            case 'medianValue':
                return this.engine.convolutionMedian(this.first_image, kernelSize);
            case 'orderValue':
                return this.engine.convolutionOrder(this.first_image, kernelSize, inputValue);
            case 'conservativeSomoothingValue':
                return this.engine.convolutionConservativeSuavization(this.first_image, kernelSize);
            case 'gaussianValue':
                return this.engine.convolutionGaussian(this.first_image, kernelSize, inputValue); 
            default:
                throw `Opção inválida para convolução: ${option}`;
        }
    }

    _border(option) {
    
        switch (option) {
            case 'prewitValue':
                return this.engine.borderPrewit(this.first_image);
            case 'sobelValue':
                return this.engine.borderSobel(this.first_image);
            case 'laplacianValue':
                return this.engine.borderLaplacian(this.first_image);
            default:
                throw `Opção inválida para detecção de borda: ${option}`;
        }
    }

    _morphological(option) {
        const imageCanva = document.getElementById('showInputImage');
        const kernelSize = document.getElementById('range').value;
        const type = document.getElementById('selectFeatureOptions').value;

        switch (option) {
            case 'dilationValue':
                return this.engine.morphologicalDilatation(this.first_image, kernelSize, type);
            case 'erosionValue':
                return this.engine.morphologicalErosion(this.first_image, kernelSize, type);
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

    _convert(option) {
        
        switch (option) {
            case 'grayScaleValue':
                return this.engine.convertToGrayScale(this.first_image);
            case 'binaryScaleValue':
                return this.engine.convertToBinaryScale(this.first_image);
            default:
                throw `Opção inválida para conversão de escala: ${option}`;
        }
    }

    _logic(option) {

        switch (option) {
            case 'andValue':
                return this.engine.logicAND(this.first_image, this.second_image);
            case 'orValue':
                return this.engine.logicOR(this.first_image, this.second_image);
            case 'xorValue':
                return this.engine.logicXOR(this.first_image, this.second_image);
            case 'notValue':
                return this.engine.logicNOT(this.first_image);
            default:
                throw `Opção inválida para operação lógica: ${option}`;
        }
    }

    _linear(option) {
        const inputValue = document.getElementById('inputValue') ? document.getElementById('inputValue').value : null;

        switch (option) {
            case 'averageValue':
                return this.engine.linearAverage(this.first_image, this.second_image);
            case 'blendingValue':
                return this.engine.linearBlending(this.first_image, this.second_image, inputValue);
            default: 
                throw `Opção inválida para operação linear: ${option}`;
        }
    }

    _histogram(option) {
        const imageCanva = document.getElementById('showInputImage');

        switch (option) {
            case 'equalizeHistogramValue':
                return this.engine.equalizeHistogram(this.first_image); 
            case 'visualizeHistogramValue':
                return this.engine.visualizeHistogram(imageCanva);
            default:
                throw `Opção inválida para operação de histograma: ${option}`
        }
    }
}
