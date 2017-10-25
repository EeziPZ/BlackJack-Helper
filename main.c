#include <stdio.h>
#include <stdlib.h>

//Notes.
//When the program tells you to hit, ask the user what card they got after.

int main()
{
    char card1[3];
    char card2[3];
    int playerHand;
    char dealerHand[3];
    printf("Enter your hand:\n");
    scanf(" %s", &card1);
    scanf(" %s", &card2);
    printf("Please enter the dealers card.\n");
    scanf(" %s", &dealerHand);

    //---------------------Double Hand Below-------------------------

    if (card1[0] == card2[0]){
        printf("Its a pair of %c%c's\n", card1[0], card1[1]);

        if(dealerHand == 2){
            printf("Worked");
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

            if(card1 >= 13){
                printf("STAND\n");
            }else if(card1 > 8 && card1 < 12){
                printf("Double\n");
            }else if (card1 > 4){
                printf("Hit");
            }

        }else if(dealerHand == 4){

            if(card1 >= 12){
                printf("STAND\n");
            }else if(card1 > 8 && card1 < 12){
                printf("Double\n");
            }else if (card1 > 4){
                printf("Hit");
            }

        }else if(dealerHand == 5){

            if(card1 >= 12){
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

    //---------------------Soft Hand Below----------------------------

    if ((card1 == 'A') || (card2 == 'A')){
        printf("Its 1 or 11\n");
    }

    if (card1 == 'A'){

    }


    playerHand = (int)(card1 - '0') + (int)(card2 - '0');

    printf("Your hand is %d\n", playerHand);





    //---------------------Hard Hand Below----------------------------


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
