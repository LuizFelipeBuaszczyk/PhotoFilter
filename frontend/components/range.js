import { createRange, createLabel } from '../utils/utils.js';

function updateLabel(value) {
    const label = document.getElementById('labelRange');

    label.textContent = `Valor: ${value}`;
}

export default function Range(id, minValue, maxValue, step, value) {
    const rangeDiv = document.createElement(id);
    
    const label = createLabel('labelRange', 'label', `Valor: ${value}`); 
    const range = createRange('range', minValue, maxValue, step, updateLabel); 
    range.value = value;
   
    rangeDiv.append(label);
    rangeDiv.append(range);
    
    return rangeDiv;
}
