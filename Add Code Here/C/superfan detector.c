#include <stdio.h>
#include <string.h>

int main() {
    printf("Are you a superfan of 'Stranger Things' or a fake fan?\n\n");
    printf("Answer these questions to find out.\n\n");

    char answer[10];

    printf("Does someone know telekinesis? 🧠🔥 (yes/no) ");
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0 || strcmp(answer, "Yes") == 0 || strcmp(answer, "YES") == 0) {
        printf("Great! You're on the right track! 🎉\n");
        printf("Who knows telekinesis? 🧠🔦 (character name) ");

        char character[50];
        scanf("%s", character);

        if (strcmp(character, "eleven") == 0 || strcmp(character, "Eleven") == 0) {
            printf("You're definitely a superfan! 🌟🎉\n");
        } else {
            printf("Hmm, you're missing out on an awesome character! 🙃\n");
        }
    } else {
        printf("Oh no, you're not a superfan! 😢\n");
    }

    return 0;
}
