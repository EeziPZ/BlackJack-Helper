#include <stdio.h>
#include <stdlib.h>

//Notes.
//When the program tells you to hit, ask the user what card they got after.

int main()
{
    char card1A[3]; //A for Array
    char card2A[3];
    char dealerHandA[3];
    int card1;      //Will move Array value into int when I know what it is!
    int card2;
    int playerHand;  //Total value of the users hand
    int dealerHand;  //Value of the dealers card
    int ace = 0; //Changes to 1 if there is an Ace
    int hit = 0; //Changes to 1 when its a hit/double to allow the user to enter another card
    int split = 0; //Changes to 1 when the user splits. Allows 2 more cards to be entered.
    printf("Enter your hand:\n"); //Get the first 2 card values
    scanf(" %s", &card1A);
    scanf(" %s", &card2A);
    printf("Please enter the dealers card.\n"); //Get the dealers visible card
    scanf(" %s", &dealerHandA);

    //------Work out what the cards are and place them into an int var------

    if (card1A[0] == 'A'){ //Find out if the first card is an Ace
        printf("Card 1 is an ace\n");
        card1 = 11; //Sets the value of card1 to the highest Ace value
        ace = 1;  //Will be used for an if statement to determine a soft hand
    }else if(card1A[0] == 'J' || card1A[0] == 'Q' || card1A[0] == 'K'){
        card1 = 10;
    }else{
        sscanf(card1A, "%d", &card1); //Sets the value of the Array to the card1 variable
    }


    if (card2A[0] == 'A'){ //Find out if the second card is an Ace
        printf("Card 2 is an ace\n");
        card2 = 11;  //Sets the value of card2 to the highest Ace value
        ace = 1;    //Will be used for an if statement to determine a soft hand
    }else if(card2A[0] == 'J' || card2A[0] == 'Q' || card2A[0] == 'K'){
        card2 = 10;
    }else{
        sscanf(card2A, "%d", &card2); //Sets the value of the Array to the card2 variable
    }

    if (dealerHandA[0] == 'A'){ //Find out if the dealers card is an Ace
        printf("Dealer has an ace\n");
        dealerHand = 11; //Sets the value of dealerhand to the highest Ace value
    }else if(dealerHandA[0] == 'J' || dealerHandA[0] == 'Q' || dealerHandA[0] == 'K'){
        card1 = 10;
    }else{
        sscanf(dealerHandA, "%d", &dealerHand); //Sets the value of the Array to the dealerhand variable
    }

    playerHand = card1 + card2;
    printf("%d\n", playerHand);

    if (playerHand == 21){
        printf("BlackJack\n");
        return 0;
    }

    //---------------------Double Hand Below-------------------------

    if (card1 == card2 && card1A[0] == card2A[0]){
        if (card1 != 11){ //finds out if its an ace
            printf("Its a pair of %d's\n", card1); //prints the value if its not an ace
        }else{
            printf("Its a pair of Ace's\n"); //prints the value if it is an ace
        }

        if(dealerHand == 2){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");
            }else if (card1 == 4){
                printf("Hit\n");
            }else {
                printf("Split\n");
            }


        }else if(dealerHand == 3){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");
            }else if (card1 == 4){
                printf("Hit\n");
            }else {
                printf("Split\n");
            }

        }else if(dealerHand == 4){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");
            }else if (card1 == 4){
                printf("Hit\n");
            }else {
                printf("Split\n");
            }

        }else if(dealerHand == 5){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");
            }else {
                printf("Split\n");
            }

        }else if(dealerHand == 6){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");
            }else {
                printf("Split\n");
            }

        }else if(dealerHand == 7){

            if(card1 == 10 || card1 == 9){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");
            }else if(card1 == 4 || card1 == 6){
                printf("Hit\n");
            }else{
                printf("Split\n");
            }

        }else if(dealerHand == 8){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");
            }else if(card1 == 11 || card1 == 9 || card1 == 8){
                printf("Split\n");
            }else{
                printf("Hit\n");
            }

        }else if(dealerHand == 9){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");
            }else if(card1 == 11 || card1 == 9 || card1 == 8){
                printf("Split\n");
            }else{
                printf("Hit\n");
            }

        }else if(dealerHand == 10){

            if(card1 == 10 || card1 == 9){
                printf("STAND\n");
            }else if(card1 == 11 || card1 == 8){
                printf("Split\n");
            }else{
                printf("Hit\n");
            }

        }else if(dealerHand == 11){

            if(card1 == 10 || card1 == 9){
                printf("STAND\n");
            }else if(card1 == 11 || card1 == 8){
                printf("Split\n");
            }else{
                printf("Hit\n");
            }

        }
    }

    //---------------------Soft Hand Below----------------------------

    if (ace == 1 && card1 != card2){  //Checks if one of the cards is an ace and that there are no doubles

        if (dealerHand == 2){

            if(playerHand <= 20 && playerHand >= 18){
                printf("Stand\n");
            }else{
                printf("Hit\n");
            }
        }

        if (dealerHand == 3){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else if(playerHand <= 18 && playerHand >= 17){
                printf("Double\n");
            }else{
                printf("Hit\n");
            }
        }

        if (dealerHand == 4){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else if(playerHand <= 18 && playerHand >= 15){
                printf("Double\n");
            }else{
                printf("Hit\n");
            }
        }

        if (dealerHand == 5){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else{
                printf("Double\n");
            }
        }

        if (dealerHand == 6){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else{
                printf("Double\n");
            }
        }

        if (dealerHand == 7){

            if(playerHand <= 20 && playerHand >= 18){
                printf("Stand\n");
            }else{
                printf("Hit\n");
            }
        }

        if (dealerHand == 8){

            if(playerHand <= 20 && playerHand >= 18){
                printf("Stand\n");
            }else{
                printf("Hit\n");
            }
        }

        if (dealerHand == 9){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else{
                printf("Hit\n");
            }
        }

        if (dealerHand == 10){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else{
                printf("Hit\n");
            }
        }

        if (dealerHand == 11){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else{
                printf("Hit\n");
            }
        }



    }





    //---------------------Hard Hand Below----------------------------


   if (ace == 0 && card1A[0] != card2A[0]){ //Makes sure there are no aces and no double


    if(dealerHand == 2){

            if(playerHand >= 13){
                printf("STAND\n");
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }


    }else if(dealerHand == 3){

            if(playerHand >= 13){
                printf("STAND\n");
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }else if(dealerHand == 4){

            if(playerHand >= 12){
                printf("STAND\n");
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }else if(dealerHand == 5){

            if(playerHand >= 12){
                printf("STAND\n");
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }else if(dealerHand == 6){

            if(playerHand >= 12){
                printf("STAND\n");
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }else if(dealerHand == 7){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }else if(dealerHand == 8){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }else if(dealerHand == 9){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }else if(dealerHand == 10){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if(playerHand > 10 && playerHand < 12){
                printf("Double\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }else if(dealerHand == 11){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if (playerHand > 4){
                printf("Hit");
            }

    }

   }


    return 0;
}
