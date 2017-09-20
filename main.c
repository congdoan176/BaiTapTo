#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main() {
    while (true) {
        int choice;
        printf("-----------------Menu-----------------\n");
        printf("1. Danh sach sinh vien.\n");
        printf("2. Add new student.\n");
        printf("3. Exit.\n");
        printf("--------------------------------------\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 3) {
            printf("End program.");
            break;
        }
        switch (choice) {
            case 1:
                // do something.
                printf("Show student list.\n");
                showStudent();
                break;
            case 2:
                // do something.
                addStudent();
                break;
            default:
                //
                printf("Please enter a number from 1 to 5.\n");
                break;
        }
    }
}

showStudent() {
    FILE*myFileRead=fopen("namedoan.txt","r");
    char charArr[100];
    while(fgets(charArr,100,myFileRead)){
        printf("%s",charArr);
    }
    fclose(myFileRead);
}

addStudent() {
    char name[100];
    char birthday[100];
    char phone[100];
    bool isValidName = false; // Kiểm tra tính hợp lệ của tên.
    printf("Add new student.\n");
    while (!isValidName){ // Nếu tên không hợp lệ thì tiếp tục bắt nhập.
        printf("Please enter name: \n");
        fgets(name, sizeof(name), stdin);
        int lengthOfName = strlen(name) - 1;
        if (lengthOfName < 3) {
            printf("Name is too short. Please enter number between 3 to 15 character.\n");
        } else if (lengthOfName > 15) {
            printf("Name is too long. Please enter number between 3 to 15 character.\n");
        } else {
            isValidName = true;
        }
    }
    printf("Please enter birthday: \n");
    fgets(birthday, sizeof(birthday), stdin);

    printf("Please enter phone: \n");
    fgets(phone, sizeof(phone), stdin);

    printf("Name: %s \n", name);
    printf("Birthday: %s \n", birthday);
    printf("Phone: %s \n", phone);
    FILE*myFile=fopen("namedoan.txt","a");
    fputs(name,myFile);
    fputs(birthday,myFile);
    fputs(phone,myFile);
    fclose(myFile);
}