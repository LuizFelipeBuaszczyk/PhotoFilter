import { transformIMGtoMATRIX, fetchAPI } from "./utils.js";


export default class ImageEngineGateway {

    constructor() {
        this.endpoint = 'http://localhost:8080';
    }

    addValue(image, value) {
        const endpoint = `${this.endpoint}/process/add?value=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    subtValue(image, value) {
        const endpoint = `${this.endpoint}/process/subt?value=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    multiplyValue(image, value) {
        const endpoint = `${this.endpoint}/process/mult?value=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    divValue(image, value) {
        const endpoint = `${this.endpoint}/process/div?value=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    invertHorizontal(image) {
        const endpoint = `${this.endpoint}/invert/horizontal`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    invertVerticle(image) {
        const endpoint = `${this.endpoint}/invert/vertical`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    convolutionAverage(image, kernelSize) {
        const endpoint = `${this.endpoint}/convolutional/mean?kernel=${kernelSize}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    convolutionMin(image, kernelSize) {
        const endpoint = `${this.endpoint}/convolutional/min?kernel=${kernelSize}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }
    
    convolutionMax(image, kernelSize) {
        const endpoint = `${this.endpoint}/convolutional/max?kernel=${kernelSize}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    convolutionMedian(image, kernelSize) {
        const endpoint = `${this.endpoint}/convolutional/median?kernel=${kernelSize}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    convolutionOrder(image, kernelSize, value) {
        const endpoint = `${this.endpoint}/convolutional/order?kernel=${kernelSize}&selectedvalue=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    convolutionConservativeSuavization(image, kernelSize) {
        const endpoint = `${this.endpoint}/convolutional/median?conservativeSomoothing?kernel=${kernelSize}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    convolutionGaussian(image, kernelSize, sigma) {
        const endpoint = `${this.endpoint}/convolutional/gaussian?kernel=${kernelSize}&sigma=${sigma}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    borderPrewit(image) {
        const endpoint = `${this.endpoint}/borderDetection/prewit`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    } 

    borderSobel(image) {
        const endpoint = `${this.endpoint}/borderDetection/sobel`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    borderLaplacian(image) {
        const endpoint = `${this.endpoint}/borderDetection/laplacian`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    morphologicalDilatation (image, kernelSize, kernelFormat){
        const endpoint = `${this.endpoint}/morphological/dilation?kernel=${kernelSize}&type=${kernelFormat}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    morphologicalErosion (image, kernelSize, kernelFormat){
        const endpoint = `${this.endpoint}/morphological/erosion?kernel=${kernelSize}&type=${kernelFormat}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    morphologicalOpening (image, kernelSize, kernelFormat){
        const endpoint = `${this.endpoint}/morphological/opening?kernel=${kernelSize}&type=${kernelFormat}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));

    }

    morphologicalClosing (image, kernelSize, kernelFormat){
        const endpoint = `${this.endpoint}/morphological/closing?kernel=${kernelSize}&type=${kernelFormat}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));

    }

    morphologicalOutline (image, kernelSize, kernelFormat){
        const endpoint = `${this.endpoint}/morphological/outline?kernel=${kernelSize}&type=${kernelFormat}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));

    }


}
