#include <stdio.h>
#include <stdlib.h>

int cardValue(char cardA[0]);

int main()
{
    //1 = HIT //2 = DOUBLE //3 = SPLIT //4 = STAND
   int table[33][10] = { //BlackJack Strategy Table
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //0///5
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1///6
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //2///7
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //3///8
        {1, 2, 2, 2, 2, 1, 1, 1, 1, 1}, //4////9
        {2, 2, 2, 2, 2, 2, 2, 2, 1, 1}, //5///10
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, //6///11
        {1, 1, 4, 4, 4, 1, 1, 1, 1, 1}, //7///12
        {4, 4, 4, 4, 4, 1, 1, 1, 1, 1}, //8///13
        {4, 4, 4, 4, 4, 1, 1, 1, 1, 1}, //9///14
        {4, 4, 4, 4, 4, 1, 1, 1, 1, 1}, //10//15
        {4, 4, 4, 4, 4, 1, 1, 1, 1, 1}, //11//16
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, //12//17
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, //13//18
        {1, 1, 1, 2, 2, 1, 1, 1, 1, 1}, //14//Soft 13
        {1, 1, 1, 2, 2, 1, 1, 1, 1, 1}, //15//Soft 14
        {1, 1, 2, 2, 2, 1, 1, 1, 1, 1}, //16//Soft 15
        {1, 1, 2, 2, 2, 1, 1, 1, 1, 1}, //17//Soft 16
        {1, 2, 2, 2, 2, 1, 1, 1, 1, 1}, //18//Soft 17
        {4, 2, 2, 2, 2, 4, 4, 1, 1, 1}, //19//Soft 18
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, //20//Soft 19
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, //21//Soft 20
        {3, 3, 3, 3, 3, 3, 1, 1, 1, 1},  //22//Pair 2
        {3, 3, 3, 3, 3, 3, 1, 1, 1, 1}, //23//Pair 3
        {1, 1, 1, 3, 3, 1, 1, 1, 1, 1}, //24//Pair 4
        {2, 2, 2, 2, 2, 2, 2, 2, 1, 1}, //25//Pair 5
        {3, 3, 3, 3, 3, 1, 1, 1, 1, 1}, //26//Pair 6
        {3, 3, 3, 3, 3, 3, 1, 1, 1, 1}, //27//Pair 7
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, //28//Pair 8
        {3, 3, 3, 3, 3, 4, 3, 3, 4, 4}, //29//Pair 9
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, //30//Pair 10
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, //31//Pair A
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  //32//For ending something.
   };  //0//1//2//3//4//5//6//7//8//9//

    int play = 0;

do { //So the game keeps going after a hand

    char card1A[3]; //A for Array
    char card2A[3];
    char dealerHandA[3];
    char newCardA[3]; //For when the player hits
    char playAgain; //Holds the answer for if the player wants to play again.
    int card1;      //Will move Array value into int when I know what it is!
    int card2;
    int x; //x axis for the table
    int y; //y axis for the table
    int tableOut; //Holds the output value.
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

    y = dealerHand - 2; // Sets the Y axis for the table.

    if(card1 == card2 && card1A[0] == card2A[0]){ //Used for Pair hands
        cardDouble = 1; // Sets this to one so that the program does not run through the hard hand code.
        x = card1 + 20;
    }

do {
    loop = 0; //So the loop only repeats if hit becomes 1;
    tableOut = 0;

    if (playerHand == 21){
        printf("Blackjack\n\n");
        splitTest = 1;
        x = 32;
    }

    if (playerHand > 18 && playerHand < 21){
        x = 13;
    }

    if (playerHand > 21 && ace == 0){
        printf("Bust\n\n");
        splitTest = 1;
        x = 32;
    }

    if (playerHand > 21 && ace > 0 && cardDouble == 0){
        playerHand = playerHand - 10;
        ace --;
    }

    if(cardDouble != 1 && ace == 0 && playerHand < 19){ //Used for normal hands (hard hand)
        x = playerHand - 5;
    }

    if(cardDouble != 1 && ace > 0 && playerHand < 21){ //Used for soft hands
        x = playerHand + 1;
    }

    tableOut = table[x][y];

    if (tableOut == 1){
        hit = 1;
        splitTest = 2;
    }else if (tableOut == 2){
        printf("DOUBLE\n");
        splitTest = 1;
        x = 32;
    }else if (tableOut == 3){
        printf("SPLIT\n");
        split = 2;
    }else if (tableOut == 4){
        printf("STAND\n");
        splitTest = 1;
        x = 32;
    }

   if (hit == 1){  //If the player is told to hit, the following code will run.
            //system("cls"); //Used to clear screen on Windows
            system("clear"); //Used to clear screen on Unix
        printf("HIT\n"); //Desplays what you must do because the clear screen removes it.
        printf("Enter new card\n");
        scanf(" %s", &newCardA);

        if (newCardA[0] == 'A'){ //Find out if there is an Ace
            ace ++;  //Will be used for an if statement to determine a soft hand
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
                ace ++;  //Will be used for an if statement to determine a soft hand
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
                ace ++;  //Will be used for an if statement to determine a soft hand
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

//------------My Functions-----------------

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
