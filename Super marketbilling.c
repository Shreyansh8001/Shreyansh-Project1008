#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 10
struct User {
    char username[50];
    char password[50];
};

int isDuplicate(struct User users[], int count, char* username) {
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0) return 1;
    }
    return 0;
}

void registerUser(struct User users[], int* count, FILE* file) {
    if (*count >= MAX_USERS) { printf("Max users reached!\n"); return; }
    struct User newUser;
    printf("Username: "); scanf("%s", newUser.username);
    if (isDuplicate(users, *count, newUser.username)) { printf("Duplicate username!\n"); return; }
    printf("Password: "); scanf("%s", newUser.password);
    users[*count] = newUser; (*count)++;
    fprintf(file, "%s,%s\n", newUser.username, newUser.password);  // Save to file
    printf("Registered!\n");
}

int loginUser(struct User users[], int count, char* username, char* password) {
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) return 1;
    }
    return 0;
}

int main() {
    struct User users[MAX_USERS];
    int userCount = 0;
    FILE* file = fopen("users.txt", "a+");  // Persistent storage
    // Load existing users (simplified; in real, parse file)
    char line[100]; while (fgets(line, sizeof(line), file) && userCount < MAX_USERS) { /* Parse logic here */ }

    int choice;
    char username[50], password[50];
    while (1) {
        printf("\n1. Register 2. Login 3. Exit\nChoice: "); scanf("%d", &choice);
        if (choice == 1) registerUser(users, &userCount, file);
        else if (choice == 2) {
            printf("Username: "); scanf("%s", username);
            printf("Password: "); scanf("%s", password);
            if (loginUser(users, userCount, username, password)) printf("Login success!\n");
            else printf("Invalid!\n");
        } else if (choice == 3) break;
        else printf("Invalid choice!\n");
    }
    fclose(file);
    printf("Secure system with validation.\n");
    return 0;
}
make this correction code