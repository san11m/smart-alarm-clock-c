#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void displayTime() {
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);
    //accessing the hour, minitues, second
    printf("Current Time: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}

int main() {
    int alarmHour, alarmMinute;
    time_t currentTime;
    struct tm *localTime;

    // getting the current time
    time(&currentTime);
    localTime = localtime(&currentTime);

    printf("Welcome to the Smart Alarm Clock\n");

    while (1) {
        displayTime();
        printf("Set the alarm (HH MM): ");
        scanf("%d %d", &alarmHour, &alarmMinute);

        if (alarmHour == localTime->tm_hour && alarmMinute == localTime->tm_min) {
            printf("Alarm rings!\n");
            // implementation of alarm actions here
            printf("Snooze for 5 minutes (y/n)? ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                sleep(600); // snooze for 10 minutes (600 seconds)
                printf("Snooze ended. ");
            } else {
                printf("Alarm dismissed. ");
                break;
            }
        } else {
            printf("Alarm set for %02d:%02d\n", alarmHour, alarmMinute);
        }
    }

    return 0;
}
