#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // For math operations
#include <string.h>  // For string comparison
#include <float.h>   // For DBL_MAX, DBL_MIN

// Mathematical operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double mod(double a, double b);
double power(double a, double b);
double squareRoot(double a);
double logBase10(double a);
double trigonometricOperation(double a, char operation);
long long factorial(int a);

// Input and validation functions
int clearInputBuffer();             // Function to clear any leftover characters in the input buffer
int isBufferEmpty();                // Function to check if the input buffer is empty
int isValidOperation(char op[]);    // Helper function to validate operation input
int isValidDouble(const char *str); // Helper function to validate if a string is a number
int getValidDouble(double *num);    // Function to get valid number input
int getValidInteger(int *num);      // Function to get a valid integer input for factorial

// Output functions
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
            break;  // Exit the program
        }

        switch (operation[0]) {  // We only need to check the first character
            case '+': case '-': case '*': case '/': case '%': case '^':
                // Handling addition, subtraction, multiplication, division, modulus, exponentiation
                printf("Enter first double: ");
                if (!getValidDouble(&num1)) continue;
                printf("Enter second double: ");
                if (!getValidDouble(&num2)) continue;
                break;

            case 'r': case 'l':  // Square root or logarithm operation
                printf("Enter double: ");
                if (!getValidDouble(&num1)) continue;
                break;

            case 's': case 'c': case 't': case 'o': case 'e': case 'q':  // Trigonometric operations
                printf("Enter number for trigonometric operations (in degrees): ");
                if (!getValidDouble(&num1)) continue;
                break;

            case '!':  // Factorial operation
                printf("Enter an integer: ");
                if (!getValidInteger(&num)) continue;
                break;
            // Default case not needed since operation is checked before switch case
        }

        // Perform the selected operation and print the result
        switch (operation[0]) {  // Again, check only the first character
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            case '%':
                result = mod(num1, num2);
                break;
            case '^':
                result = power(num1, num2);
                break;
            case 'r':
                result = squareRoot(num1);
                break;
            case 'l':
                result = logBase10(num1);
                break;
            case 's': case 'c': case 't': case 'o': case 'e': case 'q':
                result = trigonometricOperation(num1, operation[0]);
                break;
            case '!':
                result = factorial(num);
                break;
            // Default case not needed
        }
        // Print the result
        printResult(result);
    }
    return 0;
}

// Mathematical operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error! Division by zero.\n");
        return NAN;
    }
    return a / b;
}

double mod(double a, double b) {
    if (b == 0) {
        printf("Error! Division by zero.\n");
        return NAN;
    }
    return fmod(a, b);
}

double power(double a, double b) {
    // Case 1: Negative base with a fractional exponent
    if (a < 0 && b != floor(b)) {
        printf("Error! Negative base with fractional exponent results in NaN.\n");
        return NAN;
    }
    // Case 2: Zero raised to a negative power
    if (a == 0 && b < 0) {
        printf("Error! 0 cannot be raised to a negative power.\n");
        return NAN;
    }

    // Case 3: Zero raised to the power of zero (optional: can return 1 or NAN depending on context)
    if (a == 0 && b == 0) {
        printf("Error! 0 raised to the power of 0 is indeterminate.\n");
        return NAN;
    }
    // Case 4: Overflows
    if ((a > 0 && b > 1000 && a!=1) || (a < 0 && b > 1000 && a!=-1)) {
        printf("Overflow! Exponentiation result exceeds limits.\n");
        return NAN;
    }
    return pow(a, b);
}

double squareRoot(double a) {
    if (a < 0) {
        printf("Error! Cannot compute square root of a negative number.\n");
        return NAN;
    }
    return sqrt(a);
}

double logBase10(double a) {
    if (a <= 0) {
        printf("Error! Logarithm undefined for non-positive values.\n");
        return NAN;
    }
    return log10(a);
}

double trigonometricOperation(double a, char operation) {
    double radians = a * (M_PI / 180);  // Convert degrees to radians
    switch (operation) {
        case 's': return sin(radians);
        case 'c': return cos(radians);
        case 't':
            if (cos(radians) == 0) {
                printf("Error! Tangent is undefined at %.2f degrees (cos(x) = 0).\n", a);
                return NAN;  // Tangent is undefined when cos(x) = 0
            }
            return tan(radians);
        case 'o':
            if (tan(radians) == 0) {
                printf("Error! Cotangent is undefined at %.2f degrees (tan(x) = 0).\n", a);
                return NAN;  // Cotangent is undefined when tan(x) = 0
            }
            return 1.0 / tan(radians);
        case 'e':
            if (cos(radians) == 0) {
                printf("Error! Secant is undefined at %.2f degrees (cos(x) = 0).\n", a);
                return NAN;  // Secant is undefined when cos(x) = 0
            }
            return 1.0 / cos(radians);
        case 'q':
            if (sin(radians) == 0) {
                printf("Error! Cosecant is undefined at %.2f degrees (sin(x) = 0).\n", a);
                return NAN;  // Cosecant is undefined when sin(x) = 0
            }
            return 1.0 / sin(radians);
        // Default case not needed since it is handled in main switch case
    }
}

long long factorial(int a) {
    if (a < 0) {
        printf("Error! Factorial is not defined for negative integers.\n");
        return -1;
    }
    if (a > 20) {
        printf("Error! Factorial of numbers greater than 20 cause overflow.\n");
        return -1;
    }
    if (a == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}
// Input and validation functions

int clearInputBuffer() {
    int ch;
    int extraValuesDetected = 0;

    // Loop to read and discard characters until a newline or EOF
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ' && ch != '\t') {
            extraValuesDetected = 1;  // If anything other than space/tab is found, extra input detected
        }
    }

    return extraValuesDetected;  // Return 1 if extra values were detected, 0 otherwise
}

int isBufferEmpty() {
    int ch = getchar(); // Check the first character in the buffer
    if (ch != EOF && ch != '\n') {
        ungetc(ch, stdin); // Put the character back if it's not an empty buffer
        return 0;  // The buffer is not empty
    }
    return 1;  // The buffer is empty
}

int isValidOperation(char op[]) {
    return (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 ||
            strcmp(op, "/") == 0 || strcmp(op, "%") == 0 || strcmp(op, "^") == 0 ||
            strcmp(op, "r") == 0 || strcmp(op, "l") == 0 || strcmp(op, "!") == 0 ||
            strcmp(op, "s") == 0 || strcmp(op, "c") == 0 || strcmp(op, "t") == 0 ||
            strcmp(op, "o") == 0 || strcmp(op, "e") == 0 || strcmp(op, "q") == 0 ||
            strcmp(op, "x") == 0 || strcmp(op, "X") == 0);
}

int isValidDouble(const char *str) {
    char *end;
    double val =strtod(str, &end);
    // Check if the conversion was successful and the entire string was used

    if (*end != '\0') {
        printf("Invalid Double!\n");
        return 0;  // Invalid double if there's anything left in the string
    }

    // Check if the value is within the bounds of a valid double
    if (val > DBL_MAX || val < -DBL_MAX) {
        printf("Error: Double is out of range (greater than DBL_MAX or less than -DBL_MAX).\n");
        return 0;  // Invalid if the number is out of bounds
    }

    // Check if the value is smaller than DBL_MIN but larger than 0 (subnormal numbers)
    if (val != 0.0 && (val < DBL_MIN && val > 0)) {
        printf("Error: Double is too small (subnormal number).\n");
        return 0;  // Invalid if the value is smaller than DBL_MIN but greater than zero
    }

    return 1;  // Valid double if all checks pass
}

int getValidDouble(double *num) {
    char input[400];  // Buffer to store the user's input as a string

    // Read the input as a string
    if (scanf("%399s", input) != 1  || strlen(input)>=399) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return 0;  // Return 0 if input is invalid
    }
    // Check if there is anything left in the input buffer (e.g., extra spaces or values)
    if (clearInputBuffer()) {
        printf("Error: Space and Tab not allowed.\n");
        return 0;  // Return 0 if extra values were detected
    }

    // Validate if the input is a valid number
    if (!isValidDouble(input)) {
        return 0;  // Return 0 if input is invalid
    }

    // Input is converted to double
    *num = strtod(input, NULL);

    return 1;  // Return 1 if the input is valid
}

int getValidInteger(int *num) {
    char input[400];  // Buffer to store the user's input as a string

    // Read the input as a string
    if (scanf("%399s", input) != 1 || strlen(input)>=399) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return 0;  // Return 0 if input is invalid
    }

    // Check if there is anything left in the input buffer (e.g., extra spaces or values)
    if (clearInputBuffer()) {
        printf("Error: Space and Tab not allowed.\n");
        return 0;  // Return 0 if extra values were detected
    }

    // Validate if the input is a valid integer
    char *end;
    *num = strtol(input, &end, 10);
    if (*end != '\0') {
        printf("Invalid integer! Please try again.\n");
        return 0;  // Return 0 if input is invalid
    }

    return 1;  // Return 1 if the input is valid
}
// Output functions

void printMenu() {
    printf("\nScientific Calculator\n");
    printf("+ -> Add\n");
    printf("- -> Subtract\n");
    printf("* -> Multiply\n");
    printf("/ -> Divide\n");
    printf("%% -> Modulus\n");
    printf("^ -> Power\n");
    printf("r -> Square Root\n");
    printf("l -> Log (base 10)\n");
    printf("s -> Sine\n");
    printf("c -> Cosine\n");
    printf("t -> Tangent\n");
    printf("o -> Cotangent\n");
    printf("e -> Secant\n");
    printf("q -> Cosecant\n");
    printf("! -> Factorial\n");
    printf("x -> Exit\n");
}

void printResult(double result) {
    if (isnan(result))
            printf("Result is Not a Number\n");
    else if (result > DBL_MAX || result < -DBL_MAX)
        printf("Overflow! Result exceeds the limits of double.\n");
    else if (result != 0 && result < DBL_MIN && result > 0)
        printf("Underflow! Result is too small (subnormal number).\n");
    else if (fabs(result) > 1e15 || fabs(result) < 1e-15)
        printf("Result: %.15e\n", result);
    else if (fmod(result,1)==0)   // or condition can be result == (long long)result
        printf("Result: %.0f\n", result);
     else
        printf("Result: %f\n", result);
}

