#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>

// Function prototypes
int clearInputBuffer();
int isBufferEmpty();
int isValidOperation(char op[]);
int isValidDouble(const char *str);
int getValidDouble(double *num);
int getValidInteger(int *num);

void printMenu();
void printResult(double result);

int main() {
    double num1, num2, result;
    int num;
    char operation[2];
    printMenu();
    while (1) {
        printf("Enter operation: ");
        if (scanf(" %1s", operation) != 1 || !isValidOperation(operation) || !isBufferEmpty()) {
            printf("Invalid operation!\n");
            clearInputBuffer();
            continue;
        }
        if (strcmp(operation, "x") == 0 || strcmp(operation, "X") == 0) {
            printf("Exiting the calculator.\n");
            break;
        }
        switch (operation[0]) {
            case '+': case '-': case '*': case '/': case '%': case '^':
                printf("Enter first double: ");
                if (!getValidDouble(&num1)) continue;
                printf("Enter second double: ");
                if (!getValidDouble(&num2)) continue;
                break;
            case 'r': case 'l':
                printf("Enter double: ");
                if (!getValidDouble(&num1)) continue;
                break;
            case 's': case 'c': case 't': case 'o': case 'e': case 'q':
                printf("Enter number for trigonometric operations (in degrees): ");
                if (!getValidDouble(&num1)) continue;
                break;
            case '!':
                printf("Enter an integer: ");
                if (!getValidInteger(&num)) continue;
                break;
        }
        switch (operation[0]) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': result = num2 == 0 ? NAN : num1 / num2; break;
            case '%': result = num2 == 0 ? NAN : fmod(num1, num2); break;
            case '^': 
                if (num1 < 0 && num2 != floor(num2)) result = NAN;
                else if (num1 == 0 && num2 < 0) result = NAN;
                else if (num1 == 0 && num2 == 0) result = NAN;
                else if ((num1 > 0 && num2 > 1000 && num1 != 1) || (num1 < 0 && num2 > 1000 && num1 != -1)) result = NAN;
                else result = pow(num1, num2);
                break;
            case 'r': result = num1 < 0 ? NAN : sqrt(num1); break;
            case 'l': result = num1 <= 0 ? NAN : log10(num1); break;
            case 's': case 'c': case 't': case 'o': case 'e': case 'q': {
                double radians = num1 * (M_PI / 180);
                switch (operation[0]) {
                    case 's': result = sin(radians); break;
                    case 'c': result = cos(radians); break;
                    case 't': result = cos(radians) == 0 ? NAN : tan(radians); break;
                    case 'o': result = tan(radians) == 0 ? NAN : 1.0 / tan(radians); break;
                    case 'e': result = cos(radians) == 0 ? NAN : 1.0 / cos(radians); break;
                    case 'q': result = sin(radians) == 0 ? NAN : 1.0 / sin(radians); break;
                }
                break;
            }
            case '!': 
                if (num < 0 || num > 20) result = -1;
                else {
                    long long fact = 1;
                    for (int i = 1; i <= num; i++) fact *= i;
                    result = fact;
                }
                break;
        }
        printResult(result);
    }
    return 0;
}

// Input and validation functions
int clearInputBuffer() {
    int ch, extraValuesDetected = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) if (ch != ' ' && ch != '\t') extraValuesDetected = 1;
    return extraValuesDetected;
}
int isBufferEmpty() {
    int ch = getchar();
    if (ch != EOF && ch != '\n') ungetc(ch, stdin);
    return ch == EOF || ch == '\n';
}
int isValidOperation(char op[]) {
    return strchr("+-*/%^rl!sctoeqxX", op[0]) != NULL;
}
int isValidDouble(const char *str) {
    char *end;
    double val = strtod(str, &end);
    if (*end != '\0' || val > DBL_MAX || val < -DBL_MAX || (val != 0.0 && val < DBL_MIN && val > 0)) return 0;
    return 1;
}
int getValidDouble(double *num) {
    char input[400];
    if (scanf("%399s", input) != 1 || strlen(input) >= 399 || clearInputBuffer()) return 0;
    if (!isValidDouble(input)) return 0;
    *num = strtod(input, NULL);
    return 1;
}
int getValidInteger(int *num) {
    char input[400];
    if (scanf("%399s", input) != 1 || strlen(input) >= 399 || clearInputBuffer()) return 0;
    char *end;
    *num = strtol(input, &end, 10);
    return *end == '\0';
}

// Output functions
void printMenu() {
    printf("\nScientific Calculator\n");
    printf("+ -> Add          - -> Subtract      * -> Multiply\n");
    printf("/ -> Divide       %% -> Modulus       ^ -> Power\n");
    printf("r -> Square Root  l -> Log (base 10)\n");
    printf("s -> Sine         c -> Cosine        t -> Tangent\n");
    printf("o -> Cotangent    e -> Secant        q -> Cosecant\n");
    printf("! -> Factorial    x -> Exit\n");
}
void printResult(double result) {
    if (isnan(result)) printf("Result is Not a Number\n");
    else if (result > DBL_MAX || result < -DBL_MAX) printf("Overflow! Result exceeds the limits of double.\n");
    else if (result != 0 && result < DBL_MIN && result > 0) printf("Underflow! Result is too small (subnormal number).\n");
    else if (fabs(result) > 1e15 || fabs(result) < 1e-15) printf("Result: %.15e\n", result);
    else if (fmod(result, 1) == 0) printf("Result: %.0f\n", result);
    else printf("Result: %f\n", result);
}