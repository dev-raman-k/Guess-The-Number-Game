#include <stdio.h>  // used for Taking input form user and show output
#include <stdlib.h> // used for srand and rand funcions
#include <time.h>   // used for time funcion

int Game();
int main()
{
    time_t begin, end; // it will calculate time spend by player on the game
    time(&begin);

    system("color 90"); // for giving background color and text color
    printf("\t \t \t \t **Welcome to My Guess the Number Game**\v\v");

    int final_score = 0, score_of_this_round, play_again, number_of_rounds = 1, collection_of_scores[100], i , streak=0;
    char s;
    score_of_this_round = Game(number_of_rounds);
    collection_of_scores[0] = score_of_this_round;
    final_score += score_of_this_round;
    
    if(score_of_this_round > 0)
    streak++;
    else
    streak=0;

    printf("\nPress Enter to check your score\n\n");
    system("PAUSE");
    printf("Score of this round is : %d\n\n", score_of_this_round);
    system("PAUSE");

    while (1)
    {
        system("cls");
        printf("\n Do You want to play again? \n [ENTER Y OR y TO say Yes] \n [ENTER any other character to say No] ");
        scanf(" %c", &s);
        if (s == 'y' || s == 'Y')
            play_again = 1;
        else
            play_again = 0;
        if (play_again == 1)
        {
            number_of_rounds++;
            score_of_this_round = Game(number_of_rounds);
            collection_of_scores[number_of_rounds - 1] = score_of_this_round;
            final_score += score_of_this_round;
            
            if(score_of_this_round > 0)
            streak++;
            else
            streak=0;
            if(streak==5)
            {
            	printf("\n\n #Congrats, You have won 5 consecutive matches !!\n You Got 10 Extra Points ");
            	final_score +=10;
            	streak=0;
			}
            printf("\nPress Enter to check your score\n\n");
            system("PAUSE");
            printf("Score of this round is : %d\n\n", score_of_this_round);
            system("PAUSE");
        }

        else
            break;
    }

    if (number_of_rounds == 1)
        printf(" You Played %d round \n", number_of_rounds);
    else
        printf(" You Played %d rounds\n", number_of_rounds);

    printf(" Your Score in every Round are displayed as following :\n");

    for (i = 0; i < number_of_rounds; i++)
        printf(" Score in Round number %d are %d\n", i + 1, collection_of_scores[i]);

    printf("\n Your Final score : %d\n\n", final_score);
    system("PAUSE");

    time(&end);
    time_t elapsed = end - begin;
    printf("\n\n time u stayed on my game : %ld seconds \n\n", elapsed);
    system("PAUSE");
    return 0;
}

int Game(int number_of_rounds)
{
    srand(time(0));
    
    int i, type, num, user, score, life;

    printf(" Enter Mode of Game:\n");
    printf("  Press 1 for Easy\n  Press 2 for Medium\n  Press 3 for Hard\n  Press 4 for Extemely Hard\n");
    printf("((NOTE :- Entering any other number will start easy mode))\n");

    scanf("%d", &type);
    if (type <= 1 || type > 4)
    {
        num = rand() % 25 + 1;
        printf("\n You Chose EASY mode \n The Number Lies Between 1 and 25 \n You have 25 Turns to give correct answer \n\n ");
        printf("Score Distribution for This Level is :- \n 5 Points on guessing in single attempt \n 4 points on guessing in 2 to 6 Turns");
        printf("\n 3 Points on guessing in 7 to 13 Turns \n 2 Points on guessing in 14 to 20 Turns\n 1 Point  on guessing in 21 to 25");
        printf("\n 2 Points will be deducted if u lose \n 10 Points will be awarded on 5 consecutive Wins \n\n Now, GUESS THE NUMBER\n\n");
        system("PAUSE");
        printf("\n\n");    
    }

    else if (type == 2)
    {
        num = rand() % 50 + 1;
        printf("\n You Chose MEDIUM mode \n The Number Lies Between 1 and 50 \n You have 10 Turns to give correct answer \n\n ");
        printf("Score Distribution for This Level is :- \n 5 Points on guessing in single attempt \n 4 points on guessing in 2 to 4 Turns");
        printf("\n 3 Points on guessing in 5 to 6 Turns \n 2 Points on guessing in 7 to 9 Turns\n 1 Point  on guessing in 10th Turn");
        printf("\n 2 Points will be deducted if u lose \n 10 Points will be awarded on 5 consecutive Wins \n\n Now, GUESS THE NUMBER\n\n");
        system("PAUSE");
        printf("\n\n");
	}

    else if (type == 3)
    {
        num = rand() % 100 + 1;
        printf("\n You Chose HARD mode \n The Number Lies Between 1 and 100 \n You have 8 Turns to give correct answer \n\n ");
        printf("Score Distribution for This Level is :- \n 5 Points on guessing in single attempt \n 4 points on guessing in 2 to 3 Turns");
        printf("\n 3 Points on guessing in 4 to 5 Turns \n 2 Points on guessing in 6 to 7 Turns \n 1 Point  on guessing in 8th Turn");
        printf("\n 2 Points will be deducted if u lose \n 10 Points will be awarded on 5 consecutive Wins \n\n Now, GUESS THE NUMBER\n\n");
        system("PAUSE");
        printf("\n\n");
	}
    else if (type == 4)
    {
        num = rand() % 1000 + 1;
        printf("\n You Chose EXTREMELY HARD mode \n The Number Lies Between 1 and 1000 \n You have 5 Turns to give correct answer \n\n ");
        printf("Score Distribution for This Level is :- \n 5 Points on guessing in single attempt \n 4 points on guessing in 2 Turns");
        printf("\n 3 Points on guessing in 3 Turns \n 2 Points on guessing in 4 Turns \n 1 Point  on guessing in 5 Turns");
        printf("\n 2 Points will be deducted if u lose \n 10 Points will be awarded on 5 consecutive Wins \n\n Now, GUESS THE NUMBER\n\n");
        system("PAUSE");
        printf("\n\n");
	}
    printf("\nRound Number %d\n",number_of_rounds);

    printf("Turn Number 1\n");
    scanf("%d", &user);

    if (type <= 1 || type > 4)
    {
        for (i = 1; user != num; i++)
        {
            if (user > num && i < 25)
            {
                printf("\n .. That's incorrect \n Try With a Lower Number\n");
                printf("\n Turn Number %d\n", i + 1);
                scanf("%d", &user);
            }
            else if (user < num && i < 25)
            {
                printf("\n .. That's incorrect \n Try With a Higher Number\n");
                printf("\n Turn Number %d\n", i + 1);
                scanf("%d", &user);
            }
            if (i >= 25)
            {
                printf(" The limit of turns provided has ended \n Hence, You have Lost The game !!\n\n");
                printf("The Number Was : %d\n\n", num);
                score = score - 2;
                return score;
                break;
            }
        }
    }

    if (type == 2)
    {
        for (i = 1; user != num; i++)
        {
            if (user > num && i < 10)
            {
                printf("\n .. That's incorrect \n Try With a Lower Number\n");
                printf("\n Turn Number %d\n", i + 1);
                scanf("%d", &user);
            }
            else if (user < num && i < 10)
            {
                printf("\n .. That's incorrect \n Try With a Higher Number\n");
                printf("\n Turn Number %d\n", i + 1);
                scanf("%d", &user);
            }
            if (i >= 10)
            {
                printf(" The limit of turns provided has ended \n Hence, You have Lost The game !!\n\n");
                printf("The Number Was : %d\n\n", num);
                score = score - 2;
                return score;
                break;
            }
        }
    }

    if (type == 3)
    {
        for (i = 1; user != num; i++)
        {
            if (user > num && i < 8)
            {
                printf("\n .. That's incorrect \n Try With a Lower Number\n");
                printf("\n Turn Number %d\n", i + 1);
                scanf("%d", &user);
            }
            else if (user < num && i < 8)
            {
                printf("\n .. That's incorrect \n Try With a Higher Number\n");
                printf("\n Turn Number %d\n", i + 1);
                scanf("%d", &user);
            }
            if (i >= 8)
            {
                printf(" The limit of turns provided has ended \n Hence, You have Lost The game !!\n\n");
                printf("The Number Was : %d\n\n", num);
                score = -2;
                return score;
                break;
            }
        }
    }

    if (type == 4)
    {
        for (i = 1; user != num; i++)
        {
            if (user > num && i < 5)
            {
                printf("\n .. That's incorrect \n Try With a Lower Number\n");
                printf("\n Turn Number %d\n", i + 1);
                scanf("%d", &user);
            }
            else if (user < num && i < 5)
            {
                printf("\n .. That's incorrect \n Try With a Higher Number\n");
                printf("\n Turn Number %d\n", i + 1);
                scanf("%d", &user);
            }
            if (i == 5)
            {
                printf("\n .. That's incorrect \n\n");
                break;
            }
        }
    }

    if (type == 4 && i == 5 && user!=num)
    {
        printf("\n & Now, You have played Maximum Number of turns..\n Do You want 5 Extra Turns?\n");
        printf("Press 1 For Extra Turns\n Or\n Press any other number To end This Round\n");
        scanf(" %d", &life);
        if (life == 1)
        {
            for (i = 5; user != num; i++)
            {
                if (user > num && i < 10)
                {
                    if (i != 5)
                    printf("\n .. That's incorrect \n Try With a Lower Number\n");
                    printf("\n Turn Number %d\n", i + 1);

                    scanf("%d", &user);
                }
                else if (user < num && i < 10)
                {
                    if (i != 5)
                    printf("\n .. That's incorrect \n Try With a Higher Number\n");
                    printf("\n Turn Number %d\n", i + 1);
                    scanf("%d", &user);
                }
                if (i == 10)
                {
                    printf(" The limit of turns provided has ended \n Hence, You have Lost The game !!\n\n");
                    printf("The Number Was : %d\n\n", num);
                    score = -2;
                    return score;
                }
            }
        }
        if (life != 1)
        {
            printf(" The limit of turns provided has ended \n Hence, You have Lost The game !!\n\n");
            printf("The Number Was : %d\n\n", num);
            score = -2;
            return score;
        }
    }
    if (user == num)
    {
        if (i != 1)
        {
            printf("\a CONGRATULATIONS !! That's Correct Number \n You guessed in %d Turns\n", i);
            if (((type <= 1 || type > 4) && i <= 6 && i >= 2) || (type == 2 && i <= 4 && i >= 2) || (type == 3 && i <= 3 && i >= 2) || (type == 4 && i == 2))
            {
                score = 4;
                return score;
            }
            else if (((type <= 1 || type > 4) && i >= 7 && i <= 13) || (type == 2 && i >= 5 && i <= 6) || (type == 3 && i >= 3 && i <= 4) || (type == 4 && i == 3))
            {
                score = 3;
                return score;
            }
            else if (((type <= 1 || type > 4) && i >= 14 && i <= 20) || (type == 2 && i >= 7 && i <= 9) || (type == 3 && i >= 5 && i <= 7) || (type == 4 && i == 4))
            {
                score = 2;
                return score;
            }
            else if (((type <= 1 || type > 4) && i >= 21 && i <= 25) || (type == 2 && i == 10) || (type == 3 && i == 8) || (type == 4 && i >= 5 && i < 10))
            {
                score = 1;
                return score;
            }
        }
        else
        {
            printf("\a CONGRATULATIONS !! That's Correct Number \n You guessed in a Single Try\n");
            score = 5;
            return score;
        }
    }
}
