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
            default:
                throw "Opção inválida";
        }

        // Tratar response
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
}
