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
    
    convertToGrayScale(image){
        const endpoint = `${this.endpoint}/convert/8bit`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    convertToBinaryScale(image){
        const endpoint = `${this.endpoint}/convert/1bit`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    // 2 Images
    addImages(image1, image2) {
        const endpoint = `${this.endpoint}/add`;

        const body = transformIMGtoMATRIX(image1) + '\n' + 'S' + transformIMGtoMATRIX(image2);
        return fetchAPI(endpoint, 'POST', body);
    }

    subtImages(image1, image2) {
        const endpoint = `${this.endpoint}/subt`;

        const body = transformIMGtoMATRIX(image1) + '\n' + 'S' + transformIMGtoMATRIX(image2);
        return fetchAPI(endpoint, 'POST', body);
    }

    logicAND(image1, image2) {
        const endpoint = `${this.endpoint}/logic/and`;

        const body = transformIMGtoMATRIX(image1) + '\n' + 'S' + transformIMGtoMATRIX(image2);
        return fetchAPI(endpoint, 'POST', body);
    }

    logicOR(image1, image2) {
        const endpoint = `${this.endpoint}/logic/or`;

        const body = transformIMGtoMATRIX(image1) + '\n' + 'S' + transformIMGtoMATRIX(image2);
        return fetchAPI(endpoint, 'POST', body);
    }

    logicXOR(image1, image2) {
        const endpoint = `${this.endpoint}/logic/xor`;

        const body = transformIMGtoMATRIX(image1) + '\n' + 'S' + transformIMGtoMATRIX(image2);
        return fetchAPI(endpoint, 'POST', body);
    }

    logicNOT(image) {
        const endpoint = `${this.endpoint}/logic/not`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }
    
    diferenceImages(image1, image2) {
        const endpoint = `${this.endpoint}/diference`;

        const body = transformIMGtoMATRIX(image1) + '\n' + 'S' + transformIMGtoMATRIX(image2);
        return fetchAPI(endpoint, 'POST', body);
    }

    linearAverage(image1, image2) {
        const endpoint = `${this.endpoint}/linear/average`;

        const body = transformIMGtoMATRIX(image1) + '\n' + 'S' + transformIMGtoMATRIX(image2);
        return fetchAPI(endpoint, 'POST', body);       

    }

    linearBlending(image1, image2, value) {
        const endpoint = `${this.endpoint}/linear/blending?value=${value}`;

        const body = transformIMGtoMATRIX(image1) + '\n' + 'S' + transformIMGtoMATRIX(image2);
        return fetchAPI(endpoint, 'POST', body);       
    }

    equalizeHistogram(image) {
        const endpoint = `${this.endpoint}/histogram/equalize`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    visualizeHistogram(image) {
        const endpoint = `${this.endpoint}/histogram`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }
}
