const NOTIFICATION_DURATION = 3000;

export default class Notification {

    constructor(containerId = 'notificationContainer') {
        this.container = document.getElementById(containerId);

        if (!this.container) throw `O container de notificação não foi encontrado: ${containerId}`;
    }

    show(message, type = 'error') {
        const notification = document.createElement('div');
        notification.className = `notification ${type}`;
        notification.textContent = message;

        this.container.append(notification);

        setTimeout(() => {
            notification.classList.add('notification-hidden');
            notification.addEventListener('transitionend', () => {
                notification.remove();
            }, { once: true });
        }, NOTIFICATION_DURATION);
    }

    showError(message) {
        this.show(message, 'error');
    }
}