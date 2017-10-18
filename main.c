#include <stdio.h>
#include <stdlib.h>

int main()
{
    int card1;
    int card2;
    int playerHand;
    int dealerHand;
    printf("Enter your hand:\n");
    scanf(" %d", &card1);
    scanf(" %d", &card2);

    playerHand = card1 + card2;

    printf("You hand is %d\n", playerHand);

    printf("Please enter the dealers card.\n");
    scanf("%d", &dealerHand);

    //-------------------------------------------------

    if(dealerHand == 2){

            if(playerHand >= 13){
                printf("STAND\n");
            }

    }else if(dealerHand == 3){

            if(playerHand >= 13){
                printf("STAND\n");
            }

    }else if(dealerHand == 4){

            if(playerHand >= 13){
                printf("STAND\n");
            }

    }else if(dealerHand == 5){

            if(playerHand >= 13){
                printf("STAND\n");
            }

    }else if(dealerHand == 6){

            if(playerHand >= 13){
                printf("STAND\n");
            }

    }else if(dealerHand == 7){

            if(playerHand >= 17){
                printf("STAND\n");
            }

    }else if(dealerHand == 8){

            if(playerHand >= 17){
                printf("STAND\n");
            }

    }else if(dealerHand == 9){

            if(playerHand >= 17){
                printf("STAND\n");
            }

    }else if(dealerHand == 10){

            if(playerHand >= 17){
                printf("STAND\n");
            }

    }else if(dealerHand == 11){

            if(playerHand >= 17){
                printf("STAND\n");
            }

    }


    return 0;
}
