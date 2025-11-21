        #include "functions.h"

        int check_brackets(const char *str) {
            if (str == NULL) return 2;
            char* stack = malloc(sizeof(char) * strlen(str));
            if (stack == NULL) {
                return 2;
            }
            int top = -1;       
            for (int i = 0; str[i] != '\0'; i++) {
                char c = str[i];
                
                if (c == '(' || c == '[' || c == '{' || c == '<') {
                    stack[++top] = c;
                }
                else if (c == ')' || c == ']' || c == '}' || c == '>') {
                    if (top == -1) {
                        free(stack);
                        return 0;  
                    }
                    char open = stack[top--];
                    if ((c == ')' && open != '(') ||
                        (c == ']' && open != '[') ||
                        (c == '}' && open != '{') ||
                        (c == '>' && open != '<')) {
                            free(stack);
                            return 0;  
                    }
                }
            }
            free(stack);
            return top == -1;  
        }

        //О, sizeof, sizeof(union)