import { createOption } from '../utils/utils.js'

export default function SelectMorphologicalFeature(id, className) {
    const select = document.createElement('select');

    select.id = id;
    select.className = className;

    const optionClassName = null;

    select.add(createOption('1', optionClassName, 'Quadrado')); 
    select.add(createOption('2', optionClassName, 'Diamante'));
    select.add(createOption('3', optionClassName, 'Linha Horizontal')); 
    select.add(createOption('4', optionClassName, 'Linha Vertical'));

    return select;
}
