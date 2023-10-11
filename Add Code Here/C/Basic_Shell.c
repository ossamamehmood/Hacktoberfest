#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    char *tok;
    char *args[MAX_LEN];
    system("clear");

    printf("Welcome to ShellVinayak\n\nDeveloped by Vinayak\n\nA simple Linux shell for basic commands\n\nSource code: 'https://github.com/vivekutture/Linux-Shell.git'\n\n\033[1mTo exit, enter \033[3m\033[4mexit\033[m \n\n");

    while (1) {
        memset(args, '\0', MAX_LEN);
        printf("\033[1;32m ||| SHELL NAME ||| \033[1;34m~\033[1;32m\033[m$ ");

        fgets(str, MAX_LEN, stdin);

        if (strcmp(str, "\n") == 0) {
            continue;
        }

        int len = strlen(str);
        str[len - 1] = '\0';

        if (strcmp(str, "exit") == 0) {
            break;
        }

        tok = strtok(str, " ");
        int i = 0;
        while (tok != NULL) {
            args[i++] = tok;
            tok = strtok(NULL, " ");
        }

        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args) != 0) {
                perror("\nCommand not Found ");
                sleep(2);
                system("clear");
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            printf("\nProcess doesn't exist\nExiting...");
            break;
        } else {
            wait(0);
        }
    }
    exit(0);
}
