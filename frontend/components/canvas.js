const DEFAULT_WIDTH_CANVAS = 250;


export class Canvas {

    constructor (id, width, height) {
        if (!id) throw "O id do canvas deve ser passado."

        this.id = id;
        this.width = width ? width : DEFAULT_WIDTH_CANVAS;
        this.height = height ? height : DEFAULT_WIDTH_CANVAS;
    }
    
    drawImageCanvas(image) {

        const canvas = document.getElementById(this.id);
        const ctx = canvas.getContext('2d');

        canvas.width = this.width;
        canvas.height = this.height;

        ctx.drawImage(image, 0, 0, canvas.width, canvas.height);
    }
}



