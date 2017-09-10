#include <stdio.h>

int computeSum(int array[] , int size){
    int z=0;
    int sum=0;
    for(z ; z <size; z++){
        sum+=array[z];
    }
    return sum;
}

double avarage(int array[] , int size){
    int sum = computeSum(array , size);
    double returnValue = (double)sum / (double)size;
    return returnValue;
}

double avarage5(int array[] , int size){
    int sum = computeSum(array , size);
    double returnValue = (double)sum / (double)size;
    return returnValue;
}

double manualAvarage(int array[] , int size , int lessThan , int biggerThan){
    int sum = computeSum(array , size);
    double returnValue = (double)sum / (double)size;
    return returnValue;

}

int oddNumbers(int array[] , int size){
    int z=0;
    int sum=0;
    for(z ; z <size; z++){
        if(array[z]%2 != 0){
            sum+=array[z];
        }
    }
    return sum;
}

double divideAll(int array[] , int size , double numberToDivide){
    int sum = computeSum(array , size);
    return (double)sum/numberToDivide;
}

int greatesValue(int array[] , int size){
    int z=1;
    int sum=0;
    int greatest=array[0];
    for(z ; z <size; z++){
        if(array[z]>greatest){
            greatest=array[z];
        }
    }
    return greatest;
}

int greatesValueOdd(int array[] , int size){
    int greatest;
    int numberToStart;
    int checkOdd=0;
    int x=0;
    for(x;x<size;x++){
        if(array[x]%2 != 0 ){
            greatest=array[x];
            numberToStart=x;
            checkOdd=1;
            break;
        }
    }
    if(checkOdd == 0 ){
        printf("ERROR : There is no odd numbers in array!!!");
    }else if(numberToStart != size-1){
        int z=numberToStart;
        for(z; z<size;z++){
            if(array[z]%2 != 0 && array[z]>greatest){
                greatest=array[z];
            }
        }
    }else{
        greatest=array[numberToStart];
    }
    return greatest;
}

int computePositiveEven(int array[] , int size){
    int x=0;
    int returnValue=0;
    for(x;x<size;x++){
        if(array[x] %2 == 0 && array[x] > 0){
            returnValue++;
        }
    }
    return returnValue;
}

void positiveEvenAssigning(int array[] , int size , int newArray[] ){
    int var=0;
    int currentPosition=0;
    for(var;var<size;var++){
        if(array[var] %2 == 0 && array[var]>0){
            newArray[currentPosition] = array[var];
            currentPosition++;
        }
    }

}


int main(){
    int *myArray=(int*)malloc(10*sizeof(int));
    int arraySize = 10;
    int x=0;
    for(x; x<10; x++){
        myArray[x] =rand()%100-60;
        printf("%d ", myArray[x]);
    }
    printf(" \n");
    printf("Arithmetic avarage : %f\n" , avarage(myArray,arraySize));
    printf("Avarage <5 and >-5 : %f\n" , avarage5(myArray,arraySize));
    printf("Please input values for the manualAvarage function (1)lessThan,(2)biggerThan->");
    int lessThan,biggerThan;
    scanf("%d%d", &lessThan , &biggerThan);
    printf("\nAvarage <5 and >-5 : %f\n" , manualAvarage(myArray , arraySize , lessThan , biggerThan));
    printf("Sum of odd numbers : %d\n",oddNumbers(myArray , arraySize));
    printf("Sum divided by 3 : %f\n", divideAll(myArray , arraySize , 3));
    printf("Greatest value : %d\n",greatesValue(myArray , arraySize));
    printf("Greatest odd value : %d\n",greatesValueOdd(myArray , arraySize));
    /*printf("Quantity of positive even number : %d",computePositiveEven(myArray , arraySize));*/
    int sizeForEvenArray = computePositiveEven(myArray , arraySize);
    int *even=(int*)malloc(sizeForEvenArray*sizeof(int));
    positiveEvenAssigning(myArray,arraySize,even);
    int tmp=0;
    printf("Even array : ");
    for(tmp;tmp<sizeForEvenArray;tmp++){
        printf("%d{%d} ",tmp+1,even[tmp]);
    }


    return 0;
}
