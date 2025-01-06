# Scientific Calculator

This program is a Scientific Calculator written in C that supports a variety of mathematical operations, input validation, and error handling. It allows users to perform basic arithmetic operations, power calculations, square roots, logarithms, trigonometric functions, and more, while also handling edge cases like division by zero, negative square roots, and invalid input.

## Features

The program supports the following operations:

### Basic Arithmetic Operations:
- **Addition (+)**
- **Subtraction (-)**
- **Multiplication (*)**
- **Division (/)**
- **Modulus (%)**
- **Power (^)**

### Mathematical Functions:
- **Square Root (r)**
- **Logarithm (base 10) (l)**
- **Trigonometric Operations (input in degrees):**
  - **Sine (s)**
  - **Cosine (c)**
  - **Tangent (t)**
  - **Cotangent (o)**
  - **Secant (e)**
  - **Cosecant (q)**

### Factorial:
- **Factorial (!)**

### Exit the Calculator:
- **Exit (x)**

## How to Use

1. **Start the Program**: Upon running the program, a menu will be displayed listing all available operations.
2. **Enter an Operation**: You can select an operation by typing the corresponding character. The program will prompt for inputs based on the operation selected.
3. **Provide Input**:
   - For arithmetic operations (+, -, *, /, %, ^), you'll be asked to input two numbers.
   - For square root (r) and logarithm (l), you'll be asked to input one number.
   - For trigonometric functions (s, c, t, o, e, q), input the angle in degrees.
   - For the factorial (!), provide an integer.
4. **Get the Result**: The program will calculate and print the result. If there is an error (e.g., division by zero, invalid input, etc.), the program will provide a relevant error message.
5. **Exit the Calculator**: To exit, type `x`.

## Input Validation Logic

The input validation logic ensures that the program accepts valid operations and numbers from the user. Below is a breakdown of how the program validates operations and numerical inputs:

### 1. **Validate the Operation (isValidOperation)**
- The program checks if the input operation is one of the valid operations: `+`, `-`, `*`, `/`, `%`, `^`, `r`, `l`, `!`, `s`, `c`, `t`, `o`, `e`, `q`, `x`, or `X`.
- If the input matches any of the above operations, the function returns `1` to indicate a valid operation; otherwise, it returns `0`.

### 2. **Validate a Valid Integer Input (getValidInteger)**
- The function reads the user input as a string.
- It checks if the input can be successfully converted to an integer.
- The function ensures that there are no leftover characters in the input buffer after the conversion.
- If the input is a valid integer, the function returns `1`; otherwise, it returns `0` and prompts the user to input a valid integer again.

### 3. **Validate a Valid Double Input (getValidDouble)**
- The function reads the user input as a string.
- It checks if the input can be successfully converted to a valid double.
- The function ensures that the input is within the valid range for double values, avoiding overflows and underflows.
- If the input is valid, the function returns `1`; otherwise, it returns `0` and prompts the user to input a valid double again.

These validation checks ensure that the user provides only valid operations and numeric values, preventing errors during calculations.

## Error Handling Logic in Mathematical Functions

The error handling logic in the mathematical functions ensures that incorrect operations or invalid inputs are properly handled, and appropriate messages are displayed to the user.

### 1. **Addition, Subtraction, Multiplication**
- No specific error handling is required because they work with any valid numbers.
- The function simply returns the result of the two inputs.

### 2. **Division**
- **Error Handling: Division by Zero**
  - If the second operand is zero, division is not possible. The program will print an error message: `"Error! Division by zero."`
  - The function returns a special value (e.g., `NaN`) to indicate an error.

### 3. **Modulus**
- **Error Handling: Modulo by Zero**
  - If the second operand is zero, modulus is not possible. The program will print an error message: `"Error! Division by zero."`
  - The function returns `NaN` to indicate an error.

### 4. **Power**
- **Error Handling: Special Cases in Exponentiation**
  - **Negative base with fractional exponent**: If the base is negative and the exponent is not an integer, the result is undefined. The program prints an error message: `"Error! Negative base with fractional exponent results in NaN."`
  - **Zero raised to a negative exponent**: The program checks if the base is zero and the exponent is negative, as this results in an error. The program displays the message: `"Error! 0 cannot be raised to a negative power."`
  - **Zero raised to zero**: The program checks if both the base and the exponent are zero, which is an indeterminate case. The program prints an error message: `"Error! 0 raised to the power of 0 is indeterminate."`
  - **Overflow**: If the result of exponentiation exceeds the allowable range for a double, the program prints an overflow error: `"Overflow! Exponentiation result exceeds limits."`

### 5. **Square Root**
- **Error Handling: Square Root of Negative Numbers**
  - The square root of a negative number is undefined in real numbers. If the input is negative, the program prints an error message: `"Error! Cannot compute square root of a negative number."`
  - The function returns `NaN` to indicate an error.

### 6. **Logarithm (Base10)**
- **Error Handling: Logarithm of Non-positive Numbers**
  - Logarithms are only defined for positive numbers. If the input is zero or negative, the program prints an error message: `"Error! Logarithm undefined for non-positive values."`
  - The function returns `NaN` to indicate an error.

### 7. **Trigonometric Operations**
- **Error Handling for Undefined Operations:**
  - **Tangent**: If the cosine of the angle is zero, the tangent is undefined, and the program prints an error: `"Error! Tangent is undefined at (angle) degrees (cos(x) = 0)."`
  - **Cotangent**: If the tangent of the angle is zero, the cotangent is undefined, and the program prints an error: `"Error! Cotangent is undefined at (angle) degrees (tan(x) = 0)."`
  - **Secant**: If the cosine of the angle is zero, the secant is undefined, and the program prints an error: `"Error! Secant is undefined at (angle) degrees (cos(x) = 0)."`
  - **Cosecant**: If the sine of the angle is zero, the cosecant is undefined, and the program prints an error: `"Error! Cosecant is undefined at (angle) degrees (sin(x) = 0)."`

### 8. **Factorial**
- **Error Handling for Factorial Input:**
  - **Negative Input**: Factorial is not defined for negative integers, and the program prints an error: `"Error! Factorial is not defined for negative integers."`
  - **Overflow for Large Numbers**: The factorial of numbers greater than 20 causes an overflow, so the program prints an error: `"Error! Factorial of numbers greater than 20 causes overflow."`

## Output Formatting

The output is formatted in a readable way:

- For results that are not numbers (NaN), the program will indicate that the result is "Not a Number."
- For very large or small numbers, the program will display them in scientific notation with precision.
- For integer results, the program will display them without decimals.
- Results that are within the valid range for double values are shown with appropriate formatting.

## License

This program is open source. Feel free to modify or distribute it under the terms of your preferred license.
