# CSC 106 — C Programming Lab Assessments

This project contains two C programs: a right-angled triangle checker and an integer palindrome checker. Each program runs independently in the terminal.

## Requirements

- A C compiler such as GCC, available in your terminal.
- A text editor such as Visual Studio Code.
- The source files `triangle.c` and `palindrome.c`.

Open the folder containing the source files in VS Code, then open **Terminal → New Terminal**. Run the commands below from that folder. If your files are named `index.c` in separate folders, open each program's folder and replace its source filename in the compile command with `index.c`.

## Assessment 1: Right-angled triangle checker

### Purpose

The program accepts two angles in whole degrees, calculates the third angle, checks whether the angles form a valid triangle, and determines whether it is right-angled.

### Compile and run in Windows PowerShell

```powershell
gcc -std=c11 -Wall -Wextra triangle.c -o triangle.exe
.\triangle.exe
```

Enter two whole numbers separated by a space, for example `30 60`. You can also enter the first number, press Enter, then enter the second number. The program uses one prompt and waits until it has read both values. This input layout is a user-interface choice; it is not required by memory allocation.

### Example

```text
Enter two angles in whole degrees: 30 60
The third angle is 90 degrees.
It is a right-angled triangle.
```

### How it works

1. Read `angle1` and `angle2` and check that two integer conversions succeeded.
2. Reject either angle if it is less than or equal to 0, or greater than or equal to 180.
3. Calculate `angle3 = 180 - (angle1 + angle2)`.
4. Reject the triangle if `angle3` is less than or equal to 0.
5. If any angle equals 90, report a right-angled triangle; otherwise, report that it is not right-angled.

### Pseudocode

```text
START
    PROMPT for two whole-number angles
    READ angle1, angle2
    IF reading two integers fails
        DISPLAY invalid-input message
        STOP with status 1
    END IF
    IF either angle is outside 1 to 179
        DISPLAY invalid-triangle message
        STOP
    END IF
    angle3 ← 180 - (angle1 + angle2)
    IF angle3 <= 0
        DISPLAY invalid-triangle message
    ELSE
        DISPLAY angle3
        IF any angle equals 90
            DISPLAY right-angled triangle
        ELSE
            DISPLAY not a right-angled triangle
        END IF
    END IF
END
```

### Suggested tests

| Input | Expected result |
| --- | --- |
| `30 60` | Third angle 90; right-angled |
| `90 45` | Third angle 45; right-angled |
| `60 60` | Third angle 60; not right-angled |
| `90 90` | Invalid triangle |
| `-30 60` | Invalid triangle |
| `180 10` | Invalid triangle |
| `hello` | Invalid input |

## Assessment 2: Integer palindrome checker

### Purpose

The program checks whether an integer reads the same forwards and backwards. For example, `121` is a palindrome, while `123` is not. Zero and single-digit nonnegative integers are palindromes. Negative integers are treated as not palindromes.

### Compile and run in Windows PowerShell

```powershell
gcc -std=c11 -Wall -Wextra palindrome.c -o palindrome.exe
.\palindrome.exe
```

### Example

```text
Enter an integer: 121
121 is a palindrome.
```

### How it works

1. Read an integer into `number` and check that the conversion succeeded.
2. If the number is negative, report that it is not a palindrome.
3. Copy the original value into `remaining`, keeping `number` unchanged for comparison.
4. Extract the last digit with `remaining % 10`.
5. Append that digit to `reversed` using `reversed * 10 + digit`.
6. Remove the last digit using integer division: `remaining / 10`.
7. Repeat until `remaining` becomes 0, then compare `reversed` with `number`.

For `121`, the reversed value develops as `1 → 12 → 121`. The variable `reversed` uses `long long`, providing room for the reversed digits of a typical 32-bit `int`.

### Pseudocode

```text
START
    reversed ← 0
    PROMPT for an integer
    READ number
    IF reading an integer fails
        DISPLAY invalid-input message
        STOP with status 1
    END IF
    IF number < 0
        DISPLAY not a palindrome
        STOP
    END IF
    remaining ← number
    WHILE remaining > 0
        digit ← remaining MOD 10
        reversed ← reversed × 10 + digit
        remaining ← remaining DIV 10
    END WHILE
    IF reversed = number
        DISPLAY palindrome
    ELSE
        DISPLAY not a palindrome
    END IF
END
```

### Suggested tests

| Input | Expected result |
| --- | --- |
| `121` | Palindrome |
| `1221` | Palindrome |
| `123` | Not a palindrome |
| `0` | Palindrome |
| `7` | Palindrome |
| `10` | Not a palindrome |
| `-121` | Not a palindrome |
| `hello` | Invalid input |

## Functions and C features used

| Function or feature | Role |
| --- | --- |
| `main(void)` | Entry point of each program; contains its input, processing, and output logic. |
| `printf(...)` | Displays prompts and results. `%d` prints an `int`; `\n` starts a new line. |
| `scanf(...)` | Reads input. The triangle program expects two successful conversions; the palindrome program expects one. |
| `<stdio.h>` | Declares standard input/output functions, including `printf` and `scanf`. |
| `&` in `scanf` | Supplies the address of a variable so the function can store input there. |
| `if` / `else` | Selects the appropriate validation or result message. |
| `while` | Repeats digit extraction in the palindrome program. |
| `%` and `/` | Find the remainder and perform integer division to process digits. |
| `return 0` / `return 1` | End the program. These programs return 1 for a failed input conversion and 0 for completed classifications, including invalid triangle angles. |

Both programs use local variables and do not allocate memory dynamically. The only function defined by each program is `main`; `printf` and `scanf` are library functions.

## Input limitations

- Enter whole numbers within your compiler's `int` range. On typical Windows GCC installations, this is −2,147,483,648 to 2,147,483,647.
- The programs check `scanf` conversion counts, but do not fully validate an entire input line. Extra trailing characters may remain unread; for example, the palindrome program can read the integer part of `121abc` as `121`.
- Decimal angles are not supported.
- The palindrome program checks a numeric value, not a string. Leading zeros are not preserved: `00100` is read as `100`.
- Each program processes one case and exits. Run it again for another test.

## Troubleshooting

- **GCC is not recognized:** confirm that GCC is installed and its executable folder is in your PATH, then reopen the terminal.
- **PowerShell cannot find the program:** compile successfully first, then run `.\triangle.exe` or `.\palindrome.exe` from the correct folder. Do not type placeholder text such as “enter program name.”
- **A path contains spaces:** use PowerShell's call operator with a quoted path, for example `& "C:\My Programs\triangle.exe"`.
- **A DLL error appears:** note the exact missing DLL or error code and check the GCC installation/runtime. A successful compilation alone does not confirm that the executable can run.

On Linux or macOS with GCC available, omit `.exe` in the output name and run `./triangle` or `./palindrome` instead.
