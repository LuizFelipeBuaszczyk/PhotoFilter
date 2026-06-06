
export function createOption(value, className, text){

    const option = document.createElement('option');
    option.value = value;
    option.className = className;
    option.text = text;

    return option;
}

export function createRange(id, min, max, step, onInput) {
    const range = document.createElement('input');
    
    range.setAttribute("type", "range");
    range.id = id;
    range.min = min;
    range.max = max;
    range.step = step;
    range.oninput = (event) => onInput(event.target.value);

    return range;
}

export function createLabel(id, className, text, forLabel) {

    const label = document.createElement('label');

    label.id = id;
    label.className = className;
    label.textContent = text;
    label.for = forLabel;

    return label;
}

export function createInput(id, type, value, name, max) {
    const input = document.createElement('input');
    
    input.id = id;
    input.type = type;
    input.value = value;
    input.name = name;
    input.max = max;

    return input;
}

// TODO função legada, será descontinuada na migração para WebAssembly
export function transformIMGtoMATRIX(canvas) {
    var ctx = canvas.getContext('2d');

    // Aguardar a imagem ser carregada antes de processá-la
    var imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
        var data = imageData.data;

        // Criar a matriz
        var matrix = [];
        for (var y = 0; y < canvas.height; y++) {
            var row = [];
            for (var x = 0; x < canvas.width; x++) {
                // Cada pixel é representado por um array [r, g, b, a]
                var index = (y * canvas.width + x) * 4;
                var rgba = [
                    data[index],     
                    data[index + 1], 
                    data[index + 2], 
                    data[index + 3]  
                ];
                row.push(rgba);
            }
            matrix.push(row);
        }

        // Exibir a matriz no formato JSON 
        const matrixJSON = JSON.stringify(matrix, null, 2);
        return matrixJSON;
        //JSON ordem: [WIDTH][HEIGHT]
}

export async function fetchAPI(endpoint, method, body) {
    try {
        const response = await fetch(endpoint, {
            method: method,
            body: body
        })
        const data = await response.json();
        return data;
    } catch (error) {
        console.log(error);
    }
}

export function drawImage(imageData, canvasId){
    var canvas = document.getElementById(canvasId);
    var ctx = canvas.getContext('2d');

    const height = imageData.length;
    const width = imageData[0].length;
    canvas.width = width;
    canvas.height = height;

    const imageDataObj = ctx.createImageData(width, height);

    let i = 0;
    for(let y = 0; y < height; y++){
        for(let x = 0; x < width; x++){
            let pixel = imageData[y][x];
            imageDataObj.data[i++] = pixel[0]; // Red
            imageDataObj.data[i++] = pixel[1]; // Green
            imageDataObj.data[i++] = pixel[2]; // Blue
            imageDataObj.data[i++] = pixel[3]; // Alpha
        }
    }

    ctx.putImageData(imageDataObj, 0, 0);   
}


