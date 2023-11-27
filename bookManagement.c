#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nameOfBook[60];
char nameOfAut[50];
int pageNum;


void addBook()
{
    system("cls");
    printf("\t\t\tEnter the name of the book(don'make space): ");
    scanf("\t\t\t%s", &nameOfBook);
    printf("\t\t\tEnter name of the author of the book(don't make space): ");
    scanf("\t\t\t%s", &nameOfAut);
    printf("\t\t\tEnter number of pages in the book: ");
    scanf("\t\t\t%d", &pageNum);
    FILE *file1 = fopen("bookManage.txt", "a");
    if (file1 == NULL)
    {
        printf("\t\t\tError!!!");
    }
    else
    {
        fprintf(file1, "\t\t\t%s    %s      %d\n",nameOfBook ,nameOfAut, pageNum);
        printf("\t\t\tBook added to the library data\n");
    }
}

void bookDisplay()
{
    system("cls");
    printf("\t\t\tName                Author                                 Page\n");
    FILE *display = fopen("bookManage.txt", "r");
    if (display != NULL)
    {
        char c;
        while ((c = fgetc(display)) != EOF)
            putchar(c);

        fclose(display);
    }
    else
        printf("\t\t\tError");
}

void searchBook() {
    system("cls");
    char name[20];
    int final = 0;
    FILE *readFile = fopen("bookManage.txt", "r");
    if(readFile != NULL){
        printf("\t\t\tName of the book that you are searching for: ");
        scanf("%s",&name);
        printf("\t\t\t==================================================\n");
        printf("\t\t\tName                Author                                 Page\n");
        while(!feof(readFile)) {
            fscanf(readFile, "%s   %s   %d", nameOfBook, nameOfAut, &pageNum);
            if(strcmp(nameOfBook, name) == 0){
                printf("\t\t\t%s   %s   %d",nameOfBook, nameOfAut, pageNum);
                final = 1;
                break;
            }
        }
    }
    printf("\n\t\t\t==================================================\n");
     fclose(readFile);

}

void install() {
    system("cls");
    FILE *writeFile = fopen("temp.txt", "w");
    FILE *readFile = fopen("bookManage.txt", "r");
    if(writeFile != NULL){
        if(readFile != NULL){
            while(!feof(readFile)){
            fscanf(readFile, "%s   %s   %d", nameOfBook, nameOfAut, &pageNum);
            fprintf(writeFile, "\t\t\t%s    %s      %d\n",nameOfBook ,nameOfAut, pageNum);
            }
        }
    }
    remove("bookManage.txt");
    fclose(writeFile);
    fclose(readFile);

}

void update( char *ptr ) {
    system("cls");
    FILE *writeFile = fopen("bookManage.txt", "w");
    FILE *readFile = fopen("temp.txt", "r");
    if(writeFile != NULL){
        if(readFile != NULL){
            while(!feof(readFile)){
            fscanf(readFile, "%s   %s   %d", nameOfBook, nameOfAut, &pageNum);
            if(strcmp(ptr, nameOfBook)== 0){
                continue;
            }
            fprintf(writeFile, "\t\t\t%s    %s      %d\n",nameOfBook ,nameOfAut, pageNum);
            }
        }
    }
    remove("temp.txt");
    fclose(writeFile);
    fclose(readFile);
}

void deleteBook() {
    system("cls");
    char name[30];
    FILE *fileRead = fopen("bookManage.txt", "r");
    printf("\t\t\tEnter the book name: ");
    scanf("%s",&name);
    if(fileRead != NULL){
        while(!feof(fileRead)){
            fscanf(fileRead, "%s   %s   %d", nameOfBook, nameOfAut, &pageNum);
            if(strcmp(name, nameOfBook) == 0){
                fclose(fileRead);
                install();
                update(name);
                break;
            }
        }
    }
    printf("\t\t\t%s succesfly deleted from the library", nameOfBook);
}


int main()
{

    int option;

    printf("\t\t\tBook Management System\n\n");
    printf("\t\t\tFunctions\n");
    printf("\t\t\t1.Display Books\n");
    printf("\t\t\t2.Add Book\n");
    printf("\t\t\t3.Search Book\n");
    printf("\t\t\t4.Delete Book\n");
    printf("\t\t\t5.Exit\n");
    printf("\t\t\tOption: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        bookDisplay();
        break;
    case 2:
        addBook();
        break;
    case 3:
        searchBook();
        break;
    case 4:
        deleteBook();
        break;
    case 5:
        break;
    default:
        printf("\t\t\tWrong Option!!");
        break;
    }
    return 0;
}
