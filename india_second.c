#include <stdio.h>

struct Employee
{
    char name[20];
    char surname[30];
    int age;
    int salary;

}emp1,emp2,emp3;

int readEmployee(struct Employee *emp){
    int age2;
    int salary2;
    printf("Assign name ->");
    scanf("%s",emp->name);
    printf("Assign surname -> ");
    scanf("%s",emp->surname);
    printf("Assign age -> ");
    scanf("%d",&age2);
    emp->age=age2;
    printf("Assign salary -> ");
    scanf("%d",&salary2);
    emp->salary=salary2;
}

void writeEmployee(struct Employee *Employee){
    printf("\nName : %s\nSurname : %s\nAge : %d \nSalary : %d \n",Employee->name,Employee->surname,Employee->age,Employee->salary);
}

void displayArray(struct Employee *emp , int size){
    int x=0;
    for(x;x<size;x++){
        writeEmployee(&emp[x]);
    }
}

float arithmeticAvarage(struct Employee emp[] , int size){
    int x=0;
    int sum=0;
    for(x;x<size;x++){
        sum += emp[x].salary;
    }
    printf("\nArithmetic avarage of salaries : %f",(float)sum/(float)size);
    printf("\n");
    return (float)sum/(float)size;
}

void oldestEmployee(struct Employee emp[] , int size){
    int x=1;
    int oldest=0;
    for(x;x<size;x++){
        if(emp[oldest].age < emp[x].age){
            oldest=x;
        }
    }
    printf("Oldest Employee : %s %s",emp[oldest].name,emp[oldest].surname);
}

void maxSalaryEmployee(struct Employee emp[] , int size){
    int x=1;
    int highest=0;
    for(x;x<size;x++){
        if(emp[highest].salary < emp[x].salary){
            highest=x;
        }
    }
    printf("\nThe highest salary have : %s %s",emp[highest].name,emp[highest].surname);
}

void greaterThanAvarageSalary(struct Employee emp[] , int size , float avarage){
    int x=0;
    for(x;x<size;x++){
        if((float)emp[x].salary > avarage){
            writeEmployee(&emp[x]);
        }
    }
}

void printToFile(struct Employee emp[] , int size , FILE *file){
    int x=0;
    for(x;x<size;x++){
        fprintf(file,"Employee %d :\n",x);
        fprintf(file,"\nName : %s\nSurname : %s\nAge : %d \nSalary : %d \n",emp[x].name,emp[x].surname,emp[x].age,emp[x].salary);
    }
    printf("\n");
}


int main(){
    struct Employee Employees[5];
    int arraySize=3;
    printf("Assign value to the Employee 1 :\n");
    readEmployee(&emp1);
    printf("\nAssign value to the Employee 2 :\n");
    readEmployee(&emp2);
    printf("\nAssign value to the Employee 3 :\n");
    readEmployee(&emp3);
    printf("\n");
    Employees[0]=emp1;
    Employees[1]=emp2;
    Employees[2]=emp3;
    displayArray(&Employees,arraySize);
    arithmeticAvarage(&Employees,arraySize);
    oldestEmployee(&Employees,arraySize);
    maxSalaryEmployee(&Employees,arraySize);
    printf("\n Employees which have salaary greater than avarage : \n");
    greaterThanAvarageSalary(&Employees,arraySize,arithmeticAvarage(&Employees,arraySize));

    FILE *pFile;
    pFile = fopen("allEmployees.txt", "a");
    if(pFile==NULL){
        perror("Error opening file.");
    }
    else{
        printToFile(&Employees,arraySize,pFile);
    }

    fclose(pFile);
    return 0;
}

