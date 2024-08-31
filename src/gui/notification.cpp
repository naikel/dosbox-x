#include <ctime>
#include <string.h>

#include "notification.h"

SDL_Notification notification;

unsigned int Notification_getScale() {
    return notification.scale;
}

void Notification_setScale(unsigned int s) {
    if (s == 0) notification.scale = 1;
    if (s >= 2) notification.scale = 2;
}

void Notification_send(const char *message) {
    strncpy(notification.message, message, NOTIFICATION_MAX_CHARS);
    notification.message[NOTIFICATION_MAX_CHARS] = '\0';
    notification.enabled = notification.redraw = true;
    notification.start = std::time(nullptr);
}

void Notification_check() {
    if (notification.enabled) {
        notification.redraw = false;
        if ((notification.start + NOTIFICATION_TIMEOUT) < std::time(nullptr))
            notification.enabled = false;
    }
}
