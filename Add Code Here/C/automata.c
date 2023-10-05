#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256

int sufffix(char *pat, int M, int state, int x) {
    if (state < M && x == pat[state]) 
        return state + 1;

    int ns, i;
    for (ns = state; ns > 0; ns--) {
        if (pat[ns - 1] == x) {
            for (i = 0; i < ns - 1; i++) {
                if (pat[i] != pat[state - ns + 1 + i])
                    break;
            }
            if (i == ns - 1)
                return ns;  
                
        }
    }
    return 0;
}

void computeTF(char *pat, int M, int TF[][NO_OF_CHARS]) {
    int state, x;
    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
            TF[state][x] = sufffix(pat, M, state, x);
}

void FiniteAutomatonMatcher(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int delta[m + 1][NO_OF_CHARS];

    computeTF(pattern, m, delta);

    int i, state = 0;
    for (i = 0; i < n; i++) {
        state = delta[state][text[i]];
        if (state == m) {
            printf("Pattern occurs with shift %d\n", i - m + 1);
        }
    }
}

int main() {
    char txt[100];  
    char pat[100];  
    printf("Enter the text: ");
    scanf("%[^\n]%*c", txt);
    printf("Enter the pattern: ");
    scanf("%[^\n]%*c", pat);
    printf("Occurrences of the pattern:\n");
    FiniteAutomatonMatcher(txt, pat);
    return 0;
}