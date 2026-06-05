import { transformIMGtoMATRIX, fetchAPI } from "./utils.js";


export default class ImageEngineGateway {

    constructor() {
        this.endpoint = 'http://localhost:8080';
    }

    addValue(image, value) {
        const endpoint = `${this.endpoint}/process/add?value=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    subtValue(image, value) {
        const endpoint = `${this.endpoint}/process/subt?value=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    multiplyValue(image, value) {
        const endpoint = `${this.endpoint}/process/mult?value=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }

    divValue(image, value) {
        const endpoint = `${this.endpoint}/process/div?value=${value}`;
        return fetchAPI(endpoint, 'POST', transformIMGtoMATRIX(image));
    }
}
