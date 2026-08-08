import { createLabel, createInput } from "../utils/utils.js";

/*
  RadioButton = {
      id,
      value,
      labelText,
  }
*/
export default function FieldsetFeature(fieldset, listRadioButtons){
    
    listRadioButtons.forEach(radioButton => {
        const input = createInput(radioButton.id, 'radio', radioButton.value, fieldset.id);

        const label = createLabel(`${radioButton.id}Label`, null, radioButton.labelText, radioButton.id);

        input.checked = radioButton.selected; 

        const wrapper = document.createElement('div');
        wrapper.className = 'feature-option';
        wrapper.append(input);
        wrapper.append(label);

        fieldset.append(wrapper);

    });

    return fieldset;
}
