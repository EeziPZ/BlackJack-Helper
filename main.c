#include <stdio.h>
#include <stdlib.h>

int cardValue(char cardA[0]);

int main()
{
    int play = 0;

do { //So the game keeps going after a hand

    char card1A[3]; //A for Array
    char card2A[3];
    char dealerHandA[3];
    char newCardA[3]; //For when the player hits
    char playAgain; //Holds the answer for if the player wants to play again.
    int card1;      //Will move Array value into int when I know what it is!
    int card2;
    int newCard;
    int playerHand;  //Total value of the users hand
    int dealerHand;  //Value of the dealers card
    int ace = 0; //Changes to 1 if there is an Ace
    int hit = 0; //Changes to 1 when its a hit/double to allow the user to enter another card
    int split = 0; //Changes to 1 when the user splits. Allows 2 more cards to be entered.
    int loop = 0; //Repeats the loop if its equal to 1
    int cardDouble = 0; // Used to prevent the code from running the double and hard section.
    int splitTest = 0;

    printf("Please enter your first card\n");
    scanf(" %s", &card1A);      //Gets the value for card1
        //system("cls"); //Used to clear screen on Windows
        system("clear"); //Used to clear screen on Unix
    printf("Please enter your second card\n");
    scanf(" %s", &card2A);     //Gets the value for card2
        //system("cls"); //Used to clear screen on Windows
        system("clear"); //Used to clear screen on Unix
    printf("Please enter the dealers card.\n"); //Get the dealers visible card
    scanf(" %s", &dealerHandA);
        //system("cls"); //Used to clear screen on Windows
        system("clear"); //Used to clear screen on Unix

    //------Work out what the cards are and place them into an int var------

    if (card1A[0] == 'A' || card2A[0] == 'A'){ //Find out if there is an Ace
       ace = 1;  //Will be used for an if statement to determine a soft hand
    }

    card1 = cardValue(card1A); //Gets the value from the function and adds it to card1
    card2 = cardValue(card2A); //Gets the value from the function and adds it to card2
    dealerHand = cardValue(dealerHandA); //Gets the value from the function and adds it to dealerHand

    playerHand = card1 + card2;

    //---------------------Double Hand Below-------------------------

    if (card1 == card2 && card1A[0] == card2A[0]){ //Checks if the value is the same and if the first digit is the same (For J Q K and A)
        cardDouble = 1; // Sets this to one so that the program does not run through the hard hand code.

        if(dealerHand == 2){

            if(card1 == 10){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 5){
                printf("Double\n\n");
                splitTest = 1;
            }else if (card1 == 4){
                hit = 1;
                splitTest = 2;
            }else {
                printf("Split\n\n");
                split = 2;  // Split is 2 because the loop has to run twice because the player will have two hands.
            }


        }else if(dealerHand == 3){

            if(card1 == 10){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 5){
                printf("Double\n\n");
                splitTest = 1;
            }else if (card1 == 4){
                hit = 1;
                splitTest = 2;
            }else {
                printf("Split\n\n");
                split = 2;
            }

        }else if(dealerHand == 4){

            if(card1 == 10){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 5){
                printf("Double\n\n");
                splitTest = 1;
            }else if (card1 == 4){
                hit = 1;
                splitTest = 2;
            }else {
                printf("Split\n\n");
                split = 2;
            }

        }else if(dealerHand == 5){

            if(card1 == 10){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 5){
                printf("Double\n\n");
                splitTest = 1;
            }else {
                printf("Split\n\n");
                split = 2;
            }

        }else if(dealerHand == 6){

            if(card1 == 10){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 5){
                printf("Double\n\n");
                splitTest = 1;
            }else {
                printf("Split\n\n");
                split = 2;
            }

        }else if(dealerHand == 7){

            if(card1 == 10 || card1 == 9){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 5){
                printf("Double\n\n");
                splitTest = 1;
            }else if(card1 == 4 || card1 == 6){
                hit = 1;
                splitTest = 2;
            }else{
                printf("Split\n\n");
                split = 2;
            }

        }else if(dealerHand == 8){

            if(card1 == 10){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 5){
                printf("Double\n\n");
                splitTest = 1;
            }else if(card1 == 11 || card1 == 9 || card1 == 8){
                printf("Split\n\n");
                split = 2;
            }else{
                hit = 1;
                splitTest = 2;
            }

        }else if(dealerHand == 9){

            if(card1 == 10){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 5){
                printf("Double\n\n");
                splitTest = 1;
            }else if(card1 == 11 || card1 == 9 || card1 == 8){
                printf("Split\n\n");
                split = 2;
            }else{
                hit = 1;
                splitTest = 2;
            }

        }else if(dealerHand == 10){

            if(card1 == 10 || card1 == 9){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 11 || card1 == 8){
                printf("Split\n\n");
                split = 2;
            }else{
                hit = 1;
                splitTest = 2;
            }

        }else if(dealerHand == 11){

            if(card1 == 10 || card1 == 9){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(card1 == 11 || card1 == 8){
                printf("Split\n\n");
                split = 2;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }
    }

    //---------------------Soft Hand Below----------------------------

    do { //Start of the loop

        loop = 0; //So the loop only repeats if hit becomes 1;

        if (playerHand == 21){
            printf("Blackjack\n\n");
            splitTest = 1;

        }

        if (playerHand > 21 && ace == 0){
            printf("Bust\n\n");
            splitTest = 1;

        }

        if (playerHand > 21 && ace > 0 && cardDouble == 0){
            playerHand = playerHand - 10;
            ace --;
        }

    if (ace == 1 && cardDouble == 0 && playerHand < 21){  //Checks if one of the cards is an ace

        if (dealerHand == 2){

            if(playerHand <= 20 && playerHand >= 18){
                printf("Stand\n\n");
                splitTest = 1;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }

        if (dealerHand == 3){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand <= 18 && playerHand >= 17){
                printf("Double\n\n");
                splitTest = 1;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }

        if (dealerHand == 4){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand <= 18 && playerHand >= 15){
                printf("Double\n\n");
                splitTest = 1;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }

        if (dealerHand == 5){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n\n");
                splitTest = 1;
            }else{
                printf("Double\n\n");
                splitTest = 1;
            }
        }

        if (dealerHand == 6){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n\n");
                splitTest = 1;
            }else{
                printf("Double\n\n");
                splitTest = 1;
            }
        }

        if (dealerHand == 7){

            if(playerHand <= 20 && playerHand >= 18){
                printf("Stand\n\n");
                splitTest = 1;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }

        if (dealerHand == 8){

            if(playerHand <= 20 && playerHand >= 18){
                printf("Stand\n\n");
                splitTest = 1;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }

        if (dealerHand == 9){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n\n");
                splitTest = 1;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }

        if (dealerHand == 10){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n\n");
                splitTest = 1;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }

        if (dealerHand == 11){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n\n");
                splitTest = 1;
            }else{
                hit = 1;
                splitTest = 2;
            }
        }
    }

    //---------------------Hard Hand Below----------------------------

   if (ace == 0 && cardDouble == 0 && playerHand < 21){ //Makes sure there are no aces

    if(dealerHand == 2){

            if(playerHand >= 13){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand >= 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 3){

            if(playerHand >= 13){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 4){

            if(playerHand >= 12){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 5){

            if(playerHand >= 12){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 6){

            if(playerHand >= 12){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 7){

            if(playerHand >= 17){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 8){

            if(playerHand >= 17){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 9){

            if(playerHand >= 17){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 10){

            if(playerHand >= 17){
                printf("Stand\n\n");
                splitTest = 1;
            }else if(playerHand > 10 && playerHand < 12){
                printf("Double\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }

    }else if(dealerHand == 11){

            if(playerHand >= 17){
                printf("Stand\n\n");
                splitTest = 1;
            }else if (playerHand > 4){
                hit = 1;
                splitTest = 2;
            }
    }

   }

   if (hit == 1){  //If the player is told to hit, the following code will run.
            //system("cls"); //Used to clear screen on Windows
            system("clear"); //Used to clear screen on Unix
        printf("Hit\n"); //Desplays what you must do because the clear screen removes it.
        printf("Enter new card\n");
        scanf(" %s", &newCardA);

        if (newCardA[0] == 'A'){ //Find out if there is an Ace
            ace = 1;  //Will be used for an if statement to determine a soft hand
        }
        newCard = cardValue(newCardA); //Gets the value from the function and adds it to newCard

        playerHand = newCard + playerHand;

        //system("cls"); //Used to clear screen on Windows
        system("clear"); //Used to clear screen on Unix

        hit = 0; //So the loop only repeats if hit becomes 1;
        cardDouble = 0; //So that it can run through the hard/soft section.
        loop = 1;
   }

   if (split > 0 && splitTest != 2){

        if (split == 2 && splitTest == 0){
            printf("(First Hand)\n");
            printf("Enter new card\n");
            scanf(" %s", &newCardA);

            if (newCardA[0] == 'A'){ //Find out if there is an Ace
                ace = 1;  //Will be used for an if statement to determine a soft hand
            }
            newCard = cardValue(newCardA); //Gets the value from the function and adds it to newCard

            playerHand = card1 + newCard;

            //system("cls"); //Used to clear screen on Windows
            system("clear"); //Used to clear screen on Unix


            cardDouble = 0; // So the code can run for hard and soft hands.
            loop = 1;
        }

        if (split == 1 && splitTest == 1){

            printf("(Second Hand)\n");
            printf("Enter new card\n");
            scanf(" %s", &newCardA);

            if (newCardA[0] == 'A'){ //Find out if there is an Ace
                ace = 1;  //Will be used for an if statement to determine a soft hand
            }
            newCard = cardValue(newCardA); //Gets the value from the function and adds it to newCard

            playerHand = card1 + newCard;

            //system("cls"); //Used to clear screen on Windows
            system("clear"); //Used to clear screen on Unix

            cardDouble = 0; // So the code can run for hard and soft hands.
            loop = 1;
            splitTest = 2;
        }

        split --;
   }

} while (loop == 1);

        printf("Do you want to play again? (Y/N)\n");
        scanf(" %c", &playAgain);
        if (playAgain == 'Y'){
            play = 1; //Lets the loop go again.
            //system("cls"); //Used to clear screen on Windows
            system("clear"); //Used to clear screen on Unix
        }else{
            printf("You chose to end the game\n");
            return 0;
        }

} while (play == 1);

}

int cardValue(char cardA[0]) {
    int card;

    if (cardA[0] == 'A'){
        card = 11;
    }else if(cardA[0] == 'J' || cardA[0] == 'Q' || cardA[0] == 'K'){
        card = 10;
    }else{
        sscanf(cardA, "%d", &card);
    }

    return card;
}
