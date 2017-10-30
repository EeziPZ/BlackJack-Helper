#include <stdio.h>
#include <stdlib.h>

//Notes.
//When the program tells you to hit, ask the user what card they got after.

int main()
{
    char card1A[3]; //A for Array
    char card2A[3];
    char dealerHandA[3];
    char newCardA[3]; //For when the player hits
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
    }else if(card1A[0] == 'J' || card1A[0] == 'Q' || card1A[0] == 'K'){ //Checks to see if J Q or K is entered, if it is then it sets the card value to 10
        card1 = 10;
    }else{
        sscanf(card1A, "%d", &card1); //Sets the value of the Array to the card1 variable
    }


    if (card2A[0] == 'A'){ //Find out if the second card is an Ace
        printf("Card 2 is an ace\n");
        card2 = 11;  //Sets the value of card2 to the highest Ace value
        ace = 1;    //Will be used for an if statement to determine a soft hand
    }else if(card2A[0] == 'J' || card2A[0] == 'Q' || card2A[0] == 'K'){ //Checks to see if J Q or K is entered, if it is then it sets the card value to 10
        card2 = 10;
    }else{
        sscanf(card2A, "%d", &card2); //Sets the value of the Array to the card2 variable
    }

    if (dealerHandA[0] == 'A'){ //Find out if the dealers card is an Ace
        printf("Dealer has an ace\n");
        dealerHand = 11; //Sets the value of dealerhand to the highest Ace value
    }else if(dealerHandA[0] == 'J' || dealerHandA[0] == 'Q' || dealerHandA[0] == 'K'){ //Checks to see if J Q or K is entered, if it is then it sets the card value to 10
        dealerHand = 10;
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

    if (card1 == card2 && card1A[0] == card2A[0]){ //Checks if the value is the same and if the first digit is the same (For J Q K and A)
        cardDouble = 1; // Sets this to one so that the program does not run through the hard hand code.
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
                hit = 1;
            }else {
                printf("Split\n");
                split = 2;  // Split is 2 because the loop has to run twice because the player will have two hands.
            }


        }else if(dealerHand == 3){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");

            }else if (card1 == 4){
                printf("Hit\n");
                hit = 1;
            }else {
                printf("Split\n");
                split = 2;
            }

        }else if(dealerHand == 4){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");

            }else if (card1 == 4){
                printf("Hit\n");
                hit = 1;
            }else {
                printf("Split\n");
                split = 2;
            }

        }else if(dealerHand == 5){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");

            }else {
                printf("Split\n");
                split = 2;
            }

        }else if(dealerHand == 6){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");

            }else {
                printf("Split\n");
                split = 2;
            }

        }else if(dealerHand == 7){

            if(card1 == 10 || card1 == 9){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");

            }else if(card1 == 4 || card1 == 6){
                printf("Hit\n");
                hit = 1;
            }else{
                printf("Split\n");
                split = 2;
            }

        }else if(dealerHand == 8){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");

            }else if(card1 == 11 || card1 == 9 || card1 == 8){
                printf("Split\n");
                split = 2;
            }else{
                printf("Hit\n");
                hit = 1;
            }

        }else if(dealerHand == 9){

            if(card1 == 10){
                printf("STAND\n");
            }else if(card1 == 5){
                printf("Double\n");

            }else if(card1 == 11 || card1 == 9 || card1 == 8){
                printf("Split\n");
                split = 2;
            }else{
                printf("Hit\n");
                hit = 1;
            }

        }else if(dealerHand == 10){

            if(card1 == 10 || card1 == 9){
                printf("STAND\n");
            }else if(card1 == 11 || card1 == 8){
                printf("Split\n");
                split = 2;
            }else{
                printf("Hit\n");
                hit = 1;
            }

        }else if(dealerHand == 11){

            if(card1 == 10 || card1 == 9){
                printf("STAND\n");
            }else if(card1 == 11 || card1 == 8){
                printf("Split\n");
                split = 2;
            }else{
                printf("Hit\n");
                hit = 1;
            }

        }
    }

    //---------------------Soft Hand Below----------------------------
    do { //Start of the loop

        loop = 0; //So the loop only repeats if hit becomes 1;

        if (playerHand == 21){
            printf("Blackjack");
            return 0;
        }

        if (playerHand > 21 && ace == 0){
            printf("Bust");
            return 0;
        }

        if (playerHand > 21 && ace > 0 && cardDouble == 0){
            playerHand = playerHand - 10;
            printf("%d\n", playerHand);
            ace --;
        }

    if (ace == 1 && cardDouble == 0){  //Checks if one of the cards is an ace

        if (dealerHand == 2){

            if(playerHand <= 20 && playerHand >= 18){
                printf("Stand\n");
            }else{
                printf("Hit\n");
                hit = 1;
            }
        }

        if (dealerHand == 3){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else if(playerHand <= 18 && playerHand >= 17){
                printf("Double\n");

            }else{
                printf("Hit\n");
                hit = 1;
            }
        }

        if (dealerHand == 4){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else if(playerHand <= 18 && playerHand >= 15){
                printf("Double\n");

            }else{
                printf("Hit\n");
                hit = 1;
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
                hit = 1;
            }
        }

        if (dealerHand == 8){

            if(playerHand <= 20 && playerHand >= 18){
                printf("Stand\n");
            }else{
                printf("Hit\n");
                hit = 1;
            }
        }

        if (dealerHand == 9){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else{
                printf("Hit\n");
                hit = 1;
            }
        }

        if (dealerHand == 10){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else{
                printf("Hit\n");
                hit = 1;
            }
        }

        if (dealerHand == 11){

            if(playerHand <= 20 && playerHand >= 19){
                printf("Stand\n");
            }else{
                printf("Hit\n");
                hit = 1;
            }
        }



    }





    //---------------------Hard Hand Below----------------------------


   if (ace == 0 && cardDouble == 0){ //Makes sure there are no aces


    if(dealerHand == 2){

            if(playerHand >= 13){
                printf("STAND\n");
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }


    }else if(dealerHand == 3){

            if(playerHand >= 13){
                printf("STAND\n");
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }else if(dealerHand == 4){

            if(playerHand >= 12){
                printf("STAND\n");
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }else if(dealerHand == 5){

            if(playerHand >= 12){
                printf("STAND\n");
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }else if(dealerHand == 6){

            if(playerHand >= 12){
                printf("STAND\n");
            }else if(playerHand > 8 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }else if(dealerHand == 7){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }else if(dealerHand == 8){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }else if(dealerHand == 9){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if(playerHand > 9 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }else if(dealerHand == 10){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if(playerHand > 10 && playerHand < 12){
                printf("Double\n");

            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }else if(dealerHand == 11){

            if(playerHand >= 17){
                printf("STAND\n");
            }else if (playerHand > 4){
                printf("Hit\n");
                hit = 1;
            }

    }

   }

   if (hit ==1){  //If the player is told to hit, the following code will run.
        printf("Enter new card\n");
        scanf(" %s", &newCardA);

        if (newCardA[0] == 'A'){ //Find out if the card is an Ace
            printf("New card is an ace\n");
            newCard = 11; //Sets the value of newCard to the highest Ace value
            ace = 1;  //Will be used for an if statement to determine a soft hand
        }else if(newCardA[0] == 'J' || newCardA[0] == 'Q' || newCardA[0] == 'K'){ //Checks to see if J Q or K is entered, if it is then it sets the card value to 10
            newCard = 10;
        }else{
            sscanf(newCardA, "%d", &newCard); //Sets the value of the Array to the card1 variable
        }

        playerHand = newCard + playerHand;

        printf("%d\n", playerHand);

        hit = 0; //So the loop only repeats if hit becomes 1;
        cardDouble = 0; //So that it can run through the hard/soft section.
        loop = 1;


   }

   if (split > 0){

        printf("Enter new card\n");
        scanf(" %s", &newCardA);

        if (newCardA[0] == 'A'){ //Find out if the card is an Ace
            printf("New card is an ace\n");
            newCard = 11; //Sets the value of newCard to the highest Ace value
            ace = 1;  //Will be used for an if statement to determine a soft hand
        }else if(newCardA[0] == 'J' || newCardA[0] == 'Q' || newCardA[0] == 'K'){ //Checks to see if J Q or K is entered, if it is then it sets the card value to 10
            newCard = 10;
        }else{
            sscanf(newCardA, "%d", &newCard); //Sets the value of the Array to the card1 variable
        }

        playerHand = card1 + newCard;
        printf("%d\n", playerHand);

        split --;
        cardDouble = 0; // So the code can run for hard and soft hands.
        loop = 1;
        //will have to think of something...
   }




} while (loop == 1);


    return 0;
}
