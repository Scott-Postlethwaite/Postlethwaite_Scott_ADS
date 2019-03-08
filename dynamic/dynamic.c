#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define CTRL_KEYPRESS(k) ((k)  & 0x1f)

int num;

void drawBoard(char **board)
{
    int rows, columns;
    for ( rows = 0 ; rows < num ; rows++ )
        {
            for ( columns = 0 ; columns < num ; columns++ )
            {
                if((board[rows])[columns]){
                    printf( "|%c", board[rows][columns] );
                }else{
                    printf("| ");                         
                }
            }
            printf("|\n");
        }
}


bool isLegal(int row, int column, char **game)
{
	
	if(row >= num || column >= num)
	{
		return false;
	}
	else if(row < 0 || column < 0)
	{

		return false;
	}
	else if((game[row])[column] != ' ')
	{
		printf("You can't go there!\n");
		return false;
	}
	else{
		return true;
	}
	
}



bool hasWon(char player, char **game, char** moves)
{
	int diagonal = 0;
	for(int i=0; i<num;i++)
	{
		int vertical =0;
		int horizontal=0;
		if((game[i])[i] ==player)
		{
			diagonal++;
		}
		for(int j=0; j<num;j++)
		{	
			if((game[i])[j] ==player)
			{
				horizontal++;
			}
			if((game[j])[i] ==player)
			{
				vertical++;
			}
			if(vertical == num)
			{
				char Y;
				char gameName;
				printf("%c Wins!\n",player);
				printf("Would you like to save the game?\n");
				scanf("%c",&Y);
				getchar();
				if(Y == 'Y' || Y == 'y')
				{
					printf("Enter a name for the game\n");
					gameName = getchar();
					printf("declaring the file is the problem");
					FILE* stream;
					printf("strcat is the problem");
					char fName = strcat("games/",gameName, ".txt");
					printf("%c", fName);
					stream = fopen(fName, "w");
					for (int i=0; i< sizeof(moves); i++)
					{
						fprintf(stream,"%s\n", moves[i]);
					}
					fclose(stream); 
				}
				else{
					exit(0);
				}
			}
			if(horizontal == num)
			{
				char Y;
				char gameName;
				printf("%c Wins!\n",player);
				printf("Would you like to save the game?\n");
				scanf("%c",&Y);
				getchar();
				if(Y == 'Y' || Y == 'y')
				{
					printf("Enter a name for the game\n");
					scanf("%c",&gameName);
					getchar();
					printf("declaring the file is the problem");
					FILE* stream;
					printf("strcat is the problem");
					char fName = strcat("games/",gameName, ".txt");
					printf("%c", fName);
					stream = fopen(fName, "w");
					for (int i=0; i< sizeof(moves); i++)
					{
						fprintf(stream,"%s\n", moves[i]);
					}
					fclose(stream); 
				}
				else{
					exit(0);
				}
			}
		}
	}
	if(diagonal == num)
	{
		char Y;
				char gameName;
				printf("%c Wins!\n",player);
				printf("Would you like to save the game?\n");
				scanf("%c",&Y);
				getchar();
				if(Y == 'Y' || Y == 'y')
				{
					printf("Enter a name for the game\n");
					scanf("%c",&gameName);
					getchar();
					char fName = strcat(gameName, ".txt");
					FILE* stream = fopen(fName, "w");
					for (int i=0; i< sizeof(moves); i++)
					{
						fprintf(stream,"%s\n", moves[i]);
					}
					fclose(stream); 
				}
				else{
					exit(0);
				}
	}
	
return false;
}




int main()
{
	num =1;
	char a;
	char **moves =  (char **)malloc(num * num * sizeof(char*));
	while(num <=1){
		printf("How big do you want your board? ");
		scanf("%d",&num);
		getchar();
		
		for (int i=0; i<num*num; i++)
			{
				moves[i] = (char*)malloc(sizeof(char));
			}
	 }
	
  
    char** game =  (char **)malloc(num * sizeof(char*));
    for (int i=0; i<num; i++)
	{
		game[i] = (char*)malloc(sizeof(char));
		for(int j = 0; j < num; j++){
			(game[i])[j] = ' ';
		}
	}
    int totalEntry =1,row,column;
	char player = 'X';


    while(totalEntry<= num * num && !hasWon(player,game,moves)){
		if(player == 'X')
		 {
			 player='O';
		 }
		 else
		 {
			 player='X';
		 }
		row = -1;
		column = -1;
		printf("%c to play\n", player);
		while(!isLegal(row, column, game))
		{
			printf("Enter row number: ");
			scanf("%d",&row);
			char c = getchar();
			printf("Enter Column number: ");
			scanf("%d",&column);
			char d = getchar();
			if(c ==CTRL_KEYPRESS('u') || d == CTRL_KEYPRESS('u')){
				game = moves[totalEntry-1];
				printf("Move undone\n");
				drawBoard(game);
				if(player == 'X')
				 {
					 player='O';
				 }
				 else
				 {
					 player='X';
				 }
				 printf("%c to play\n", player);
			}
		}
	
		(game[row])[column] = player;
		drawBoard(game);
		moves[totalEntry]=game;
		totalEntry++;
	}  	

    return 0;
}