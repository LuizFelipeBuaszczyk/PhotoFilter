

export function createOption(value, className, text){

    const option = document.createElement('option');
    option.value = value;
    option.className = className;
    option.text = text;

    return option;
}
