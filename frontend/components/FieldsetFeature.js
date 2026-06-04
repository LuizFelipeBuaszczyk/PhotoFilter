import { createLabel, createInput } from "../utils.js";

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

        fieldset.append(input);
        fieldset.append(label);

    });

    return fieldset;
}
