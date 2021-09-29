// C implementation of volatile student data record system
#include <stdio.h>
#include <stdlib.h>

// protyping functions
void printWelcome();
void printOptionMsg();
void insertStudent();
int printRecord();
void printAll();
int deleteRecord();

// structure to handle data
typedef struct _ {
    int batch;
    int regNo;
    char firstName[20];
    char lastName[20];
    float cGPA;
    struct _ *next; 
}student_t;

// initial pornters
student_t *head = NULL;
student_t *current = NULL;

int main(){

    int num;
    printWelcome();
    printOptionMsg();
    
    while(1){
        // handeling user functions
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

// function to print welcome meaage
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

// function to print a reusing message 
void printOptionMsg(){
    printf("------------------\n");
    printf("ENTER OPTION [0-4]\n");
    printf("------------------\n");
    
}

// function to insert studednt data to linked list
void insertStudent(){
    // create a link and allocating memory
    student_t*add = (student_t*)malloc(sizeof(student_t));
    
    // getting data from the user
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
    
    // point gathered data to first node
    add->next = head;
    
    // point first to new first node
    head=add;
    printf("\n");

}

// function to print specific data of a student
int printRecord(){
    // variables to handle user inputs
    int uBatch, uReg;
    char  garbage_val;

    printf("Enter the Registration Number: ");
    scanf(" %c%c%d%c%d",&garbage_val,&garbage_val, &uBatch, &garbage_val,&uReg);
    
    // start from the first link
    student_t *current = head;
    
    // if the list is empty
    if(head==NULL){
        printf("No student with the given Registration Number!\n");
        printf("\n");
        return 0 ;
        
    }
    
    // going through the list
    while (current->batch!=uBatch && current->regNo!=uReg){ 
        
        // if selected node is last one
        if (current->next == NULL){
            printf("No student with the given Registration Number!\n");
            printf("\n");
            return 0;
        }
        else{
            // going to the next link
            current= current->next;
        }
    }
    
    printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",current->firstName, current->lastName, uBatch, uReg, current->cGPA);
    printf("\n");
    return 0;
}

// function to print all student details
void printAll(){
    // starting from first link
    student_t *ptr = head;
    
    // going through the list
    while(ptr!= NULL){
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",ptr->firstName, ptr->lastName, ptr->batch, ptr->regNo, ptr->cGPA);
        ptr = ptr -> next;
    }
    printf("\n");
    
}

// function to delete student record
int deleteRecord(){
    // variables to handle user inputs
    int uBatch, uReg;
    char  garbage_val;
    
    printf("Enter the Registration Number: ");
    scanf(" %c%c%d%c%d",&garbage_val,&garbage_val, &uBatch, &garbage_val,&uReg);
    
    // start with first link
    student_t *current = head;
    student_t *previous = NULL;
    
    // if the list is empty
    if(head==NULL){
        printf("No student with the given Registration Number!\n");
        printf("\n");
        return 0;
    }
    
    // goingh through the list
    while (current->batch!=uBatch && current->regNo!=uReg){ 
        // if the current node is the last node
        if (current->next == NULL){
            printf("No student with the given Registration Number!\n");
            printf("\n");
            return 0;
        }else{
            // store the address to current link address
            previous= current;
            // going to the next link
            current= current->next;
        }
    }
    
    // updating the link
    if(current == head){
        // changing first point to next link
        head = head->next;
        
    }else{
        // bypass the current link
        previous->next = current ->next;
    }
    
    printf("Delete Successful!\n"); 
    printf("\n");
    return 0;
  
}