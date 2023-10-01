#include <stdio.h>
#include <string.h>

int main() {
    char firstName[50];
    char lastName[50];

    printf("Enter your first name: ");
    scanf("%s", firstName);

    printf("Enter your last name: ");
    scanf("%s", lastName);

    // Generate a username by combining the first and last name
    char username[100];
    snprintf(username, sizeof(username), "%s%s", firstName, lastName);

    // Convert the username to lowercase (optional)
    for (int i = 0; username[i]; i++) {
        username[i] = tolower(username[i]);
    }

    printf("Your username is: %s\n", username);

    return 0;
}
