#include <stdio.h>
#include <stdlib.h>

void printWelcome();
void printOptionMsg();
void insertStudent();
int printRecord();
void printAll();
int deleteRecord();


typedef struct _ {
    int batch;
    int regNo;
    char firstName[20];
    char lastName[20];
    float cGPA;
    struct _ *next; 
}student_t;

student_t *head = NULL;
student_t *current = NULL;

int main(){

    int num;
    printWelcome();
    printOptionMsg();
    
    while(1){
        if ((scanf("%d",&num))==1 && num<5 && num>-1){
            if (num==0){
                break;
                
            }else if(num ==1){
                insertStudent();
                printOptionMsg();

            }else if(num==2){
                printRecord();
                printOptionMsg();
                
            }else if(num==3){               
                printAll();
                printOptionMsg();
                
            }else{               
                deleteRecord();
                printOptionMsg();
            }
            
        }else{
            printOptionMsg();
        }
    }
    return 0;
}

void printWelcome(){
    printf("--------------------------------------------\n");
    printf("A VOLATILE STUDENT RECORD MAINTENANCE SYSTEM\n");
    printf("--------------------------------------------\n");
    printf("0. Quit\n");
    printf("1. Insert a Student Record\n");
    printf("2. Print a Student Record\n");
    printf("3. Print all Student Records\n");
    printf("4. Delete a Student Record\n");
   
}

void printOptionMsg(){
    printf("------------------\n");
    printf("ENTER OPTION [0-4]\n");
    printf("------------------\n");
    
}

void insertStudent(){
    
   student_t*add = (student_t*)malloc(sizeof(student_t));
   printf("Enter the batch (14/15/16/17): ");
   scanf("%d", &(add->batch));
   printf("Enter the registration number: ");
   scanf("%d", &(add->regNo));
   printf("Enter the first name         : ");
   scanf("%s", add->firstName);
   printf("Enter the last name          : ");
   scanf("%s", add->lastName);
   printf("Enter the cumulative GPA     : ");
   scanf("%f", &(add->cGPA));
   add->next = head;
   head=add;
   printf("\n");

}

int printRecord(){
    int uBatch, uReg;
    char  garbage_val;

    printf("Enter the Registration Number: ");
    scanf(" %c%c%d%c%d",&garbage_val,&garbage_val, &uBatch, &garbage_val,&uReg);
    student_t *current = head;
    if(head==NULL){
        printf("No student with the given Registration Number!\n");
        printf("\n");
        return 0 ;
        
    }
    while (current->batch!=uBatch && current->regNo!=uReg){ 
        if (current->next == NULL){
            printf("No student with the given Registration Number!\n");
            printf("\n");
            return 0;
        }else{
            current= current->next;
        }
    }
    
    printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",current->firstName, current->lastName, uBatch, uReg, current->cGPA);
    printf("\n");
    return 0;
}

void printAll(){
    student_t *ptr = head;
    while(ptr!= NULL){
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",ptr->firstName, ptr->lastName, ptr->batch, ptr->regNo, ptr->cGPA);
        ptr = ptr -> next;
    }
    printf("\n");
    
}

int deleteRecord(){
    
    int uBatch, uReg;
    char  garbage_val;
    
    printf("Enter the Registration Number: ");
    scanf(" %c%c%d%c%d",&garbage_val,&garbage_val, &uBatch, &garbage_val,&uReg);
    student_t *current = head;
    student_t *previous = NULL;
    
    if(head==NULL){
        printf("No student with the given Registration Number!\n");
        printf("\n");
        return 0;
    }
    
    while (current->batch!=uBatch && current->regNo!=uReg){ 
        if (current->next == NULL){
            printf("No student with the given Registration Number!\n");
            printf("\n");
            return 0;
        }else{
            previous= current;
            current= current->next;
        }
    }

    if(current == head){
        head = head->next;
    }else{
        previous->next = current ->next;
    }
    
    printf("Delete Successful!\n"); 
    printf("\n");
    return 0;
  
}