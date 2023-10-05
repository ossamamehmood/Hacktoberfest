#include <stdio.h>
#include <string.h>

void lps_func(char* txt, int* Lps) {
    Lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < strlen(txt)) {
        if (txt[i] == txt[len]) {
            len++;
            Lps[i] = len;
            i++;
            continue;
        } else {
            if (len == 0) {
                Lps[i] = 0;
                i++;
                continue;
            } else {
                len = Lps[len - 1];
                continue;
            }
        }
    }
}

void KMP(char* pattern,  char* text, int* lcs_array) {
    int n = strlen(text);
    int m = strlen(pattern);
    int Lps[m];
    
    lps_func(pattern, Lps); 

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) { 
            printf("%d ", i - m); 
            lcs_array[m - 1] = i - m;
            j = Lps[j - 1]; 
        } else if (i < n && pattern[j] != text[i]) { 
            if (j == 0)        
                i++;
            else
                j = Lps[j - 1];  
        }
    }
}

int main() {
    char text[100];
    char pattern[100];
    int lcs_array[100];

    for (int i = 0; i < 100; i++) {
        lcs_array[i] = 0;
    }

    printf("Enter the text: ");
    scanf("%[^\n]%*c", text);
    printf("Enter the pattern: ");
    scanf("%[^\n]%*c", pattern);

    printf("Occurrences of the pattern at :\n");
    KMP(pattern, text, lcs_array);

    if (lcs_array[strlen(pattern) - 1] == 0) {
        printf("Pattern is not found\n");
    } else {
        printf("\nLPS array: ");
        for (int i = 0; i < strlen(pattern); i++) {
            printf("%d ", lcs_array[i]);
        }
        printf("\n");
    }
    return 0;
}


