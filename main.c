#include <stdio.h>
#include <stdlib.h>

int main()
{
    int card1;
    int card2;
    int playerHand;
    int dealerHand;
    printf("Enter your hand:\n");
    scanf(" %i", &card1);
    scanf(" %i", &card2);

    printf("%c\n", card1);

    if ((card1 == "A") || (card2 == "A")){
        printf("Its 1 or 11");
    }

    playerHand = card1 + card2;

    printf("You hand is %d\n", playerHand);

    printf("Please enter the dealers card.\n");
    scanf("%d", &dealerHand);

    //-------------------------------------------------


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


    return 0;
}
