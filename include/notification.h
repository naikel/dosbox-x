#define NOTIFICATION_MAX_CHARS   91
#define NOTIFICATION_TIMEOUT      2

struct SDL_Notification {
    bool enabled;
    char message[NOTIFICATION_MAX_CHARS];
    long start;
    unsigned int scale = 1;
};

extern SDL_Notification notification;
void Notification_setScale(unsigned int s);
unsigned int Notification_getScale();
void Notification_send(const char *message);
void Notification_check();
