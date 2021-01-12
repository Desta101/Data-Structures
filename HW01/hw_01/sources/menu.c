#include <stdio.h>
#include <stdlib.h>

#include "../headers/menu.h"
#include "../headers/matrix.h"
#include "../headers/picture.h"
#include "../headers/puzzle.h"

void display_menu()
{
    char opn = '\0';
    printf("Welcome to the program\n");
    while (opn != 'e')
    {
        printf("Please choose one of the following options\n");
        printf("P/p - Picture Manipulation\n");
        printf("N/n - Number Game\n");
        printf("E/e - Quit\n");
        scanf("%c", &opn);
        switch (opn)
        {
            case 'p':
            case 'P':
                display_picture_manipulation_menu();
                break;
            case 'n':
            case 'N':
                play_puzzle_game();
                break;
            case 'e':
            case 'E':
                printf("Thank you for using the program, goodbye");
                exit(0);
            default:
                printf("Please choose a valid option\n");
                break;
        }
    }
}

void display_picture_manipulation_menu()
{
    int opn = 0;
    int rows = PICTURE_ROWS, cols = PICTURE_COLS;
    int picture[rows][cols];
    initialize_matrix_random_values((int*)picture, rows, cols, 1, 100);
    while (opn != -1)
    {
        printf("Please choose one of the following options\n");
        printf("1 - 90 degree clockwise\n");
        printf("2 - 90 degree counter clock wise\n");
        printf("3 - Flip Horizontal\n");
        printf("4 - Flip Vertical\n");
        printf("- 1 - Quit\n");
        scanf("%d", &opn);
        switch (opn)
        {
        case 1:
            printf("inputted matrix:\n");
            print_matrix((int*)picture, rows , cols);
            ninty_degree_clockwise((int*)picture, rows , cols);
            printf("\n--------------- Picture after manipulation ---------------\n\n");
            print_matrix((int*)picture, rows , cols);
            printf("\n");
            break;
        break;
        case 2:
            printf("inputted matrix:\n");
            print_matrix((int*)picture, rows , cols);
            ninty_degree_counter_clockwise((int*)picture, rows , cols);
            printf("\n--------------- Picture after manipulation ---------------\n\n");
            print_matrix((int*)picture, rows , cols);
            printf("\n");
            break;
        case 3:
            printf("inputted matrix:\n");
            print_matrix((int*)picture, rows , cols);
            flip_horizontally((int*)picture, rows , cols);
            printf("\n--------------- Picture after manipulation ---------------\n\n");
            print_matrix((int*)picture, rows , cols);
            printf("\n");
            break;
        case 4:
            printf("inputted matrix:\n");
            print_matrix((int*)picture, rows , cols);
            flip_vertically((int*)picture, rows, cols);
            printf("\n--------------- Picture after manipulation ---------------\n\n");
            print_matrix((int*)picture, rows , cols);
            printf("\n");
            break;
        case -1:
            printf("Thank you for using the program, goodbye");
            exit(0);
        default:
            printf("Please choose a valid option\n");
            break;
        }
    }
}

void play_puzzle_game()
{
    int puzzle[PUZZLE_ROWS][PUZZLE_COLS];
    play((int*)puzzle, PUZZLE_ROWS, PUZZLE_COLS);
}