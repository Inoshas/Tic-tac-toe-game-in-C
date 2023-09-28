#include<stdio.h>

// Declare all void functions::
void getelements();
void printarray();


// Global variable:
static int user[]={1,2};
char array[3][3] = {{'-',  '-', '-'}, {'-',  '-' , '-'}, {'-', '-' , '-'}};
int col=0, row=0;


int count=1;
int main(){
    printf("Note that the first player marked with X and the second player marked with 0");

    int i=0;

   do{
    printf("\nelement %d", count);

    if (count%2!=0){
        getelements(user[0]);
    }   
    else{
        getelements(user[1]);
    
    }
    // This is to check diagonal, vertical ad hhorizontal matches::: 
      if (count >4){
        if ((array[0][0]== array[1][1]) && (array[1][1]==array[2][2] )  && (array[0][0] != '-'))
            {
            printf("matching");
            }
        else if ((array[0][2]== array[1][1]) && (array[1][1]==array[2][0] )  && (array[0][2] != '-'))
            {
                printf("matching");
            } 
        else{
            printf(" We need function here to go with rows and columns")
        }
      }

   }while(count<=9);
    //print_elements();
    return 0;
}

void getelements(int user_val){
    printf(" \n Enter poition player %d:", user_val);
    scanf("%d %d" , &col, &row);
    if  (array[col][row]=='-' && (col>=0 && col <=2) && (row >= 0 &&row <=2)){

         if (user_val==1 ){
        array[col][row]= 'x';}
        else{ 
        array[col][row]= '0'; } 
        count ++;
    } 
    else {
        printf("Not a valid entry: enter again");}

   
    
     

    //----------------------------------------------------------------
    // This print the array nicely and we need it every iteration:
 printf("\n \n");
    //printarray(array);
    for (int i = 0 ; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%c ", array[i][j]);
        }
         printf("\n");
       
    }
//----------------------------------------------------
  
}

/*
void printarray(char tets_array){
  printf("array %c", tets_array );  
}
   */





