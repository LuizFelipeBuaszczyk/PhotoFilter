

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

export function createLabel(id, className, text) {

    const label = document.createElement('label');

    label.id = id;
    label.className = className;
    label.textContent = text;

    return label;
}
