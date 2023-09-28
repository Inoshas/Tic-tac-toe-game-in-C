#include<stdio.h>

// Declare all void functions::
void getelements();
void printarray();
void check_diagonal();
void check_horizontal();
void check_vertical();


// Global variable:
static int user[]={1,2};
char array[3][3] = {{'-',  '-', '-'}, {'-',  '-' , '-'}, {'-', '-' , '-'}};
int col=0, row=0 , match_count=0;
char winner;


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
        // This is to check diagonal, vertical and hhorizontal matches::: 
        if (count >4){
            check_diagonal();
            if (match_count==1){
                break;
            }
            else {
                check_horizontal();
                if (match_count==1){
                break;}
                else {
                    check_vertical();
                    if (match_count==1){
                break;}
                }
            }
            }     
    }while(count<=9);
  
  if (winner=='x'){
    printf("***Player One WON *****\n  Good Job!");
  }
  else if(winner=='0'){
    printf("***Player two WON *****\n  Good Job!");
  }
  else{
    printf(" Better luck next time");
  }
    return 0;
}

// This function mainly enter valid values to array:
void getelements(int user_val){
    printf(" \n Enter  player %d position:", user_val);
    scanf("%d %d" , &col, &row);
    // check entry validity:
    if  (array[col][row]=='-' && (col>=0 && col <=2) && (row >= 0 &&row <=2)){
 // 'x' for user 1 and '0' for user 2:
         if (user_val==1 ){
        array[col][row]= 'x';}
        else{ 
        array[col][row]= '0'; } 
        count ++;
    } 
    else {
        printf("Not a valid entry: enter again");
    }

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


void check_vertical(){  
   for (int i= 0; i<3; i++){
        if ((array[i][0]==array[i][1]) && (array[i][1]==array[i][2]) && array[i][0]!='-')
        {
            match_count=1;
            winner=array[i][0];}
     }
   
}

void check_horizontal(){
   for (int i= 0; i<3; i++){
        if ((array[0][i]==array[1][i]) && (array[1][i]==array[2][i]) && array[1][i]!='-')
        {
        match_count=1;
        winner=array[0][i];}
     } 
}

void check_diagonal(){

    if ((array[0][0]== array[1][1]) && (array[1][1]==array[2][2] )  && (array[0][0] != '-'))
            {
            match_count=1;
            winner=array[0][0];
            }
        else if ((array[0][2]== array[1][1]) && (array[1][1]==array[2][0] )  && (array[0][2] != '-'))
            {
                match_count=1;
                winner=array[0][2];
            } 
}

   





