import { transformIMGtoMATRIX, fetchAPI } from "./utils/utils.js";

const IMAGE_WIDTH = 250;

export default class ImageEngineGateway {

    constructor() {
        this.endpoint = 'http://localhost:8080';
        
        const _memory = new WebAssembly.Memory({initial:32}); 
        WebAssembly.instantiateStreaming(fetch("engine.wasm"), {
            js: {
                mem: _memory,
           }
        }).then(response => this._set_engine(response.instance));
    }

    _set_engine (instance) {
        this.engine = instance
        this.memory = this.engine.exports.memory;
    }

    _read_image_in_memory(ptr, size) {
        const view_image = new Uint8Array(this.memory.buffer, ptr, size);
        let image_matrix = [[]];
        let row_count = 0;
        let column_count = 0;
        for (let i=0; i<view_image.length;){
            image_matrix[row_count][column_count] = 
                {
                    'red': view_image[i++],
                    'green': view_image[i++],
                    'blue': view_image[i++],
                    'alpha': view_image[i++],
                };


            column_count++;
            
            if (column_count==IMAGE_WIDTH) {
                column_count = 0;
                row_count++;
                image_matrix.push([]);
            }
        }
        return image_matrix;
    }

    addValue(image, value) {
        const ptr = 0;
        const image_buffer = new Uint8Array(image);
        const buffer_length = image_buffer.length;
        const view_image = new Uint8Array(this.memory.buffer, ptr, buffer_length);
        view_image.set(image_buffer);

        const result = this.engine.exports.image_add_value(ptr, buffer_length, value);
        if (result == -1) throw "Erro ao somar valor!";

        return this._read_image_in_memory(result, buffer_length); 
    }

    subtValue(image, value) {
        const ptr = 0;
        const image_buffer = new Uint8Array(image);
        const buffer_length = image_buffer.length;
        const view_image = new Uint8Array(this.memory.buffer, ptr, buffer_length);
        view_image.set(image_buffer);

        const result = this.engine.exports.image_subt_value(ptr, buffer_length, value);
        if (result == -1) throw "Erro ao subtrair valor!";

        return this._read_image_in_memory(result, buffer_length); 
    }

    multiplyValue(image, value) {
        const ptr = 0;
        const image_buffer = new Uint8Array(image);
        const buffer_length = image_buffer.length;
        const view_image = new Uint8Array(this.memory.buffer, ptr, buffer_length);
        view_image.set(image_buffer);

        const result = this.engine.exports.image_multiply_value(ptr, buffer_length, value);
        if (result == -1) throw "Erro ao multiplicar valor!";

        return this._read_image_in_memory(result, buffer_length); 
    }

    divValue(image, value) {
        const ptr = 0;
        const image_buffer = new Uint8Array(image);
        const buffer_length = image_buffer.length;
        const view_image = new Uint8Array(this.memory.buffer, ptr, buffer_length);
        view_image.set(image_buffer);

        const result = this.engine.exports.image_div_value(ptr, buffer_length, value);
        if (result == -1) throw "Erro ao dividir valor!";

        return this._read_image_in_memory(result, buffer_length);     
    }

    invertHorizontal(image) {
        const ptr = 0;
        const image_buffer = new Uint8Array(image);
        const buffer_length = image_buffer.length;
        const view_image = new Uint8Array(this.memory.buffer, ptr, buffer_length);
        view_image.set(image_buffer);

        const result = this.engine.exports.image_invert_horizontal(ptr, buffer_length);
        if (result == -1) throw "Erro ao inverter horizontalmente!";
        return this._read_image_in_memory(result, buffer_length);         
    }

    invertVerticle(image) {
        const ptr = 0;
        const image_buffer = new Uint8Array(image);
        const buffer_length = image_buffer.length;
        const view_image = new Uint8Array(this.memory.buffer, ptr, buffer_length);
        view_image.set(image_buffer);

        const result = this.engine.exports.image_invert_vertical(ptr, buffer_length);
        if (result == -1) throw "Erro ao inverter verticalmente!";
        return this._read_image_in_memory(result, buffer_length);             }

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
