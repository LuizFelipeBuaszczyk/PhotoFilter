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

    _set_image_to_buffer(image, ptr) {
        const image_buffer = new Uint8Array(image);
        const buffer_length = image_buffer.length;
        const view_image = new Uint8Array(this.memory.buffer, ptr, buffer_length);
        view_image.set(image_buffer);

        return buffer_length;
    }

    addValue(image, value) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_add_value(ptr, buffer_length, value);
        if (result == -1) throw "Erro ao somar valor!";

        return this._read_image_in_memory(result, buffer_length); 
    }

    subtValue(image, value) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_subt_value(0, buffer_length, value);
        if (result == -1) throw "Erro ao subtrair valor!";

        return this._read_image_in_memory(result, buffer_length); 
    }

    multiplyValue(image, value) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_multiply_value(ptr, buffer_length, value);
        if (result == -1) throw "Erro ao multiplicar valor!";

        return this._read_image_in_memory(result, buffer_length); 
    }

    divValue(image, value) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_div_value(ptr, buffer_length, value);
        if (result == -1) throw "Erro ao dividir valor!";

        return this._read_image_in_memory(result, buffer_length);     
    }

    invertHorizontal(image) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_invert_horizontal(ptr, buffer_length);
        if (result == -1) throw "Erro ao inverter horizontalmente!";
        return this._read_image_in_memory(result, buffer_length);         
    }

    invertVerticle(image) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_invert_vertical(ptr, buffer_length);
        if (result == -1) throw "Erro ao inverter verticalmente!";
        return this._read_image_in_memory(result, buffer_length);
    }

    convolutionAverage(image, kernel_size) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convolution_average(ptr, buffer_length, kernel_size);
        if (result == -1) throw "Erro ao realizar a covolução média!";
        return this._read_image_in_memory(result, buffer_length);
    }

    convolutionMin(image, kernel_size) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convolution_min(ptr, buffer_length, kernel_size);
        if (result == -1) throw "Erro ao realizar a convolução miníma!";
        return this._read_image_in_memory(result, buffer_length);
    }
    
    convolutionMax(image, kernel_size) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convolution_max(ptr, buffer_length, kernel_size);
        if (result == -1) throw "Erro ao realizar a convolução máxima!";
        return this._read_image_in_memory(result, buffer_length);
    }

    convolutionMedian(image, kernel_size) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convolution_median(ptr, buffer_length, kernel_size);
        if (result == -1) throw "Erro ao realizar a convolução mediana!";
        return this._read_image_in_memory(result, buffer_length);
    }

    convolutionOrder(image, kernel_size, order_value) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convolution_order(ptr, buffer_length, kernel_size, order_value);
        if (result == -1) throw "Erro ao realizar a convolução ordem!";
        return this._read_image_in_memory(result, buffer_length);
    }

    convolutionConservativeSuavization(image, kernel_size) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convolution_conservative_smoothing(ptr, buffer_length, kernel_size);
        if (result == -1) throw "Erro ao realizar a convolução suavização conservativa!";
        return this._read_image_in_memory(result, buffer_length);
    }

    convolutionGaussian(image, kernel_size, sigma) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convolution_gaussian(ptr, buffer_length, kernel_size, sigma);
        if (result == -1) throw "Erro ao realizar a convolução gaussiana!";
        return this._read_image_in_memory(result, buffer_length);
    }

    borderPrewit(image) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_border_detection_prewit(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar detecção de borda prewit!";
        return this._read_image_in_memory(result, buffer_length);   
    } 

    borderSobel(image) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_border_detection_sobel(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar detecção de borda sobel!";
        return this._read_image_in_memory(result, buffer_length);     
    }

    borderLaplacian(image) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_border_detection_laplacian(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar detecção de borda laplacian!";
        return this._read_image_in_memory(result, buffer_length);         
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
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convert_to_grayscale(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar a conversão para escala de cinza";
        return this._read_image_in_memory(result, buffer_length);
    }

    convertToBinaryScale(image){
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_convert_to_binaryscale(ptr, buffer_length, 128);
        if (result == -1) throw "Erro ao realizar a conversão para escala binária";
        return this._read_image_in_memory(result, buffer_length);
    }

    // 2 Images
    addImages(image1, image2) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image1, ptr); 
        const buffer_length_image2 = this._set_image_to_buffer(image2, buffer_length);
        const result = this.engine.exports.image_add_image(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar soma entre duas imagens";
        return this._read_image_in_memory(result, buffer_length);
    }

    subtImages(image1, image2) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image1, ptr); 
        const buffer_length_image2 = this._set_image_to_buffer(image2, buffer_length);
        const result = this.engine.exports.image_subt_image(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar subtração entre duas imagens";
        return this._read_image_in_memory(result, buffer_length);    
    }

    logicAND(image1, image2) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image1, ptr); 
        const buffer_length_image2 = this._set_image_to_buffer(image2, buffer_length);
        const result = this.engine.exports.image_logic_and_image(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar a operação lógica AND entre duas imagens";
        return this._read_image_in_memory(result, buffer_length);
    }

    logicOR(image1, image2) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image1, ptr); 
        const buffer_length_image2 = this._set_image_to_buffer(image2, buffer_length);
        const result = this.engine.exports.image_logic_or_image(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar a operação lógica OR entre duas imagens";
        return this._read_image_in_memory(result, buffer_length);    
    }

    logicXOR(image1, image2) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image1, ptr); 
        const buffer_length_image2 = this._set_image_to_buffer(image2, buffer_length);
        const result = this.engine.exports.image_logic_xor_image(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar a operação lógica XOR entre duas imagens";
        return this._read_image_in_memory(result, buffer_length);
    }

    logicNOT(image) {
        const ptr = 0;
        const buffer_length = this._set_image_to_buffer(image, ptr); 
        const result = this.engine.exports.image_logic_not(ptr, buffer_length);
        if (result == -1) throw "Erro ao realizar a operação lógica NOT na imagem";
        return this._read_image_in_memory(result, buffer_length);
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
