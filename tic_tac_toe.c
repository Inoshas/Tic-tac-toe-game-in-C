#include<stdio.h>

// Declare all void functions::
void getelements();
void check_match();
void printwinner();


// Global variable:
int user[]={1,2};
char array[3][3] = {{'-',  '-', '-'}, {'-',  '-' , '-'}, {'-', '-' , '-'}};
int col=0, row=0 , match_count=0, count=0;
char winner;


// Main function goes here::
int main(){
    printf("\n\nNote that the first player marked with X and the second player marked with 0");
    
   do{
    getelements();
    // We need to check from 5th attemp onward, there is no matches before that::
    // We can check diagonal, then vertical and horizontal
        if (count >4){
            check_match();
            if (match_count==1){
                break;
            }
            
            }     
    }while(count<9);

    printwinner();
    return 0;
}

// This function mainly Used to fill the array and check the validily of the elements:
void getelements() {
    printf("\n Enter player %d position:", (count % 2) + 1); // Determine the current player based on count
    scanf("%d %d", &col, &row);

    // Check entry validity
    if (array[col][row] == '-' && col >= 0 && col <= 2 && row >= 0 && row <= 2) {
        // 'x' for Player 1 and '0' for Player 2
        array[col][row] = (count % 2 == 0) ? 'x' : '0'; // Use count to determine the player
        count++;
    } else {
        printf("Not a valid entry. Please enter again.\n");
    }


    // This print the array nicely and we need it every iteration:
    printf("\n \n");
    for (int i = 0 ; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%c ", array[i][j]);
        }
         printf("\n");    
    }
//----------------------------------------------------
  
}



void check_match(){
    // Vertical::
    for (int i= 0; i<3; i++){
        if ((array[i][0]==array[i][1]) && (array[i][1]==array[i][2]) && array[i][0]!='-')
        {
            match_count=1;
            winner=array[i][0];
            }
     } 

     // Horizontal:: 

    if  (match_count !=1){ 
          for (int i= 0; i<3; i++){
        if ((array[0][i]==array[1][i]) && (array[1][i]==array[2][i]) && (array[1][i]!='-' ) )
        {
        match_count=1;
        winner=array[0][i];
        }
     }
    } 

     // Diagonal:: 
   if  (match_count !=1){ 
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
}


    // This is to print the winner :::
void printwinner(){
   
    if (winner=='x'){
        printf("***Player One WON *****\n  Good Job!");
    }
    else if(winner=='0'){
        printf("***Player two WON *****\n  Good Job!");
    }
    else{
        printf("Better luck next time");
  }

}

   





