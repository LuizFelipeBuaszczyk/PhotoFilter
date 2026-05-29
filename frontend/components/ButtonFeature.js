
export default function ButtonFeature(id, value, text){
    const button = document.createElement('button');
    const className = 'featureButton';
        
    button.id = id;
    button.value = value;
    button.className = className;
    button.textContent = text;

    return button;
}
