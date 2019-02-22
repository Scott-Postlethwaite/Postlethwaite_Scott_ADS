#include <stdio.h>
#include <string.h>

void drawBoard(char board[][3])
{
    int rows, columns;
    for ( rows = 0 ; rows < 3 ; rows++ )
        {
            for ( columns = 0 ; columns < 3 ; columns++ )
            {
                if(board[rows][columns]){
                    printf( "|%c", board[rows][columns] );
                }else{
                    printf("| ");                         
                }
            }
            printf("|\n");
        }
}


int main()
{
    char game[3][3]={{0}};
    int totalEntry =0,row,column;
	char player = 'O';

    while(totalEntry<=9){
		 printf("%c to play\n", player);
         printf("Enter row number: ");
         scanf("%d",&row);        
         getchar();
         printf("Enter Column number: ");
         scanf("%d",&column);
         getchar();
		 if(game[row][column] == 'X')
		 {
 			printf("Enter row number: ");
			scanf("%d",&row);        
			getchar();
			printf("Enter Column number: ");
			scanf("%d",&column);
			getchar();
		 }
		else if (game[row][column] == 'O')
		{
 			printf("Enter row number: ");
			scanf("%d",&row);        
			getchar();
			printf("Enter Column number: ");
			scanf("%d",&column);
			getchar();
		}
		else{
			game[row][column] = player;
			drawBoard(game);
			
			if(game[0][column] == player && game[1][column] == player && game[2][column] == player)
			{
				printf("%c Wins!", player);
				exit(0);
			}
			else if(game[row][0] == player && game[row][1] == player && game[row][2] == player)
			{
				printf("%c Wins!", player);
				exit(0);
			}
			else if(game[0][0] == player && game[1][1] == player && game[2][2] == player)
			{
				printf("%c Wins!", player);
				exit(0);
			}
			else if(game[2][0] == player && game[1][1] == player && game[0][2] == player)
			{
				printf("%c Wins!", player);
				exit(0);
			}
			
			
			if(player == 'X')
			 {
				 player='O';
			 }
			 else
			 {
				 player='X';
			 }
		 }
		
		
		 
    }          

    return 0;
}