# CodeAlpha C Programming Internship Tasks

This folder contains three completed C programs based on the supplied CodeAlpha task sheet.

## Files

1. `task1_calculator.c` — Addition, subtraction, multiplication and division using `switch`.
2. `task2_matrix_operations.c` — Matrix addition, multiplication and transpose using functions and 2D arrays. Matrix dimensions are limited to 10 x 10.
3. `task3_student_management.c` — Menu-driven student records: add, display, search, update and delete. Uses a structure and binary file storage (`students.dat`).

## Compile and run (VS Code terminal with GCC)

Open this folder in VS Code. In the terminal, compile one program at a time:

```bash
gcc task1_calculator.c -o calculator
./calculator
```

```bash
gcc task2_matrix_operations.c -o matrix
./matrix
```

```bash
gcc task3_student_management.c -o students
./students
```

On Windows PowerShell, run the generated executable as `./calculator.exe`, `./matrix.exe`, `./students.exe`, or `.

## Important notes

- Run each program from this folder so its `.dat` data file is created in the same folder.
- The student and banking programs save data between runs. Keep the `.dat` files if you want to keep the records.
- Task 4 is an educational simulation only. It is not connected to a real bank and must not be used for real money or real customer data.
- Test each menu option and invalid-input case before submitting. Understand the code and be ready to explain it; do not claim testing you have not performed.

## Suggested test cases

- Calculator: `12 3`, then choices 1, 2, 3 and 4; also test division by zero and an invalid choice.
- Matrix: addition of 2x2 matrices; multiplication of compatible 2x2 matrices; transpose of a 2x3 matrix.
- Student system: add two records, display, search one ID, update it, delete it, then display again.
- Banking system: create account, deposit 500, check balance, withdraw 150, check balance (expected 350), and restart to verify saved balance.

## Submission checklist from the supplied task sheet

- Upload complete source code to GitHub in a repository named `CodeAlpha_ProjectName`.
- Post a video explanation on LinkedIn with the GitHub repository link.
- Submit through the submission form shared in the relevant WhatsApp group.
- The sheet says to complete any 2 or 3 of the 4 tasks; it also says submitting only one task is incomplete.
