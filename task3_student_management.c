/* CodeAlpha Task 3: Student Management System using structures and file handling */
#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "students.dat"
#define TEMP_FILE "students_temp.dat"

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

void addStudent(void) {
    FILE *fp = fopen(DATA_FILE, "ab");
    Student s;
    if (fp == NULL) { printf("Unable to open student file.\n"); return; }
    printf("Enter student ID: ");
    if (scanf("%d", &s.id) != 1) { printf("Invalid ID.\n"); fclose(fp); return; }
    printf("Enter student name (no more than 49 characters): ");
    scanf(" %49[^\n]", s.name);
    printf("Enter marks: ");
    if (scanf("%f", &s.marks) != 1 || s.marks < 0 || s.marks > 100) {
        printf("Invalid marks. Enter a value from 0 to 100.\n"); fclose(fp); return;
    }
    if (fwrite(&s, sizeof(Student), 1, fp) == 1) printf("Student added successfully.\n");
    else printf("Could not save student.\n");
    fclose(fp);
}

void displayStudents(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    Student s;
    int found = 0;
    if (fp == NULL) { printf("No student records found yet.\n"); return; }
    printf("\n%-10s %-30s %-10s\n", "ID", "NAME", "MARKS");
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("%-10d %-30s %-10.2f\n", s.id, s.name, s.marks);
        found = 1;
    }
    if (!found) printf("No student records found.\n");
    fclose(fp);
}

void searchStudent(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    Student s;
    int id, found = 0;
    if (fp == NULL) { printf("No student records found.\n"); return; }
    printf("Enter student ID to search: ");
    if (scanf("%d", &id) != 1) { printf("Invalid ID.\n"); fclose(fp); return; }
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == id) {
            printf("Found: ID=%d, Name=%s, Marks=%.2f\n", s.id, s.name, s.marks);
            found = 1; break;
        }
    }
    if (!found) printf("Student not found.\n");
    fclose(fp);
}

void updateStudent(void) {
    FILE *fp = fopen(DATA_FILE, "rb+");
    Student s;
    int id, found = 0;
    if (fp == NULL) { printf("No student records found.\n"); return; }
    printf("Enter student ID to update: ");
    if (scanf("%d", &id) != 1) { printf("Invalid ID.\n"); fclose(fp); return; }
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == id) {
            printf("Enter new name: "); scanf(" %49[^\n]", s.name);
            printf("Enter new marks: ");
            if (scanf("%f", &s.marks) != 1 || s.marks < 0 || s.marks > 100) {
                printf("Invalid marks.\n"); fclose(fp); return;
            }
            fseek(fp, -(long)sizeof(Student), SEEK_CUR);
            if (fwrite(&s, sizeof(Student), 1, fp) == 1) printf("Student updated.\n");
            else printf("Update failed.\n");
            found = 1; break;
        }
    }
    if (!found) printf("Student not found.\n");
    fclose(fp);
}

void deleteStudent(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp = fopen(TEMP_FILE, "wb");
    Student s;
    int id, found = 0, writeError = 0;
    if (fp == NULL || temp == NULL) {
        printf("Unable to open record files.\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }
    printf("Enter student ID to delete: ");
    if (scanf("%d", &id) != 1) { printf("Invalid ID.\n"); fclose(fp); fclose(temp); remove(TEMP_FILE); return; }
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == id) found = 1;
        else if (fwrite(&s, sizeof(Student), 1, temp) != 1) writeError = 1;
    }
    fclose(fp); fclose(temp);
    if (writeError) { printf("Delete failed while writing temporary file.\n"); remove(TEMP_FILE); return; }
    if (found) {
        if (remove(DATA_FILE) == 0 && rename(TEMP_FILE, DATA_FILE) == 0) printf("Student deleted.\n");
        else printf("Could not replace student data file.\n");
    } else { remove(TEMP_FILE); printf("Student not found.\n"); }
}

int main(void) {
    int choice;
    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n0. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return 1; }
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 0: printf("Exiting student system.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
