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
				char g2[10];
				printf("%c Wins!\n",player);
				printf("Would you like to save the game?\n");
				scanf("%c",&Y);
				getchar();
				if(Y == 'Y' || Y == 'y')
				{
					printf("Enter a name for the game\n");
					scanf("%c",&g2);
					getchar();
					FILE* stream;
					char txt = ".txt";
					strcat(g2,".txt");
					printf("%c", g2);
					printf("We will now save the game\n");
					stream = fopen(g2, "w");
					for (int i=0; i< sizeof(moves); i++)
					{
						fprintf(stream,"%s\n", moves[i]);
					}
					fclose(stream); 
					exit(0);
				}
				else{
					exit(0);
				}
			}
			if(horizontal == num)
			{
				char Y;
				char gameName;
				char g2[10];
				printf("%c Wins!\n",player);
				printf("Would you like to save the game?\n");
				scanf("%c",&Y);
				getchar();
				if(Y == 'Y' || Y == 'y')
				{
					printf("Enter a name for the game\n");
					scanf("%s",&g2);
					getchar();
					FILE* stream;
					char txt = ".txt";
					strcat(g2,".txt");
					printf("%c", g2);
					printf("We will now save the game\n");
					stream = fopen(g2, "w");
					for (int i=0; i< sizeof(moves); i++)
					{
						fprintf(stream,"%s\n", moves[i]);
					}
					fclose(stream); 
					exit(0);
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
				char g2[10];
				printf("%c Wins!\n",player);
				printf("Would you like to save the game?\n");
				scanf("%c",&Y);
				getchar();
				if(Y == 'Y' || Y == 'y')
				{
					printf("Enter a name for the game\n");
					scanf("%c",&g2);
					getchar();
					FILE* stream;
					char txt = ".txt";
					strcat(g2,".txt");
					printf("%c", g2);
					printf("We will now save the game\n");
					stream = fopen(g2, "w");
					for (int i=0; i< sizeof(moves); i++)
					{
						fprintf(stream,"%s\n", moves[i]);
					}
					fclose(stream); 
					exit(0);
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
	char ***moves =  (char ***)malloc(num * num * num * num * sizeof(char));
	while(num <=1){
		printf("How big do you want your board? ");
		scanf("%d",&num);
		getchar();
		
		
	 }
	 printf("before moves are allocated\n");
	for (int i=0; i<num*num; i++)
	{
		moves[i] = (char**)malloc(sizeof(char) *num *num);
		for (int j=0; j<num; j++)
	{
		moves[i][j] = (char*)malloc(num * sizeof(char));
		for(int l = 0; l < num; l++){
			moves[i][j][l] = (char*)malloc(num * sizeof(char));
		}
	}
	}
	printf("before game is allocated\n");
    char** game =  (char **)malloc(num * sizeof(char*));
    for (int i=0; i<num; i++)
	{
		game[i] = (char*)malloc(num * sizeof(char));
		for(int j = 0; j < num; j++){
			(game[i])[j] = ' ';
		}
	}
	printf("Before moves is set to an empty board\n");
	for (int j=0; j<num; j++)
		{
			
			for(int l = 0; l < num; l++){
				(moves[0])[j][l] = game[j][l];
			}
		}
		printf("after board is set to an empty board\n");
		drawBoard(moves[0]);
    int totalEntry =1;
	int row;
	int column;
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
				totalEntry--;
				
				for (int i=0; i<num; i++)
				{	
					for(int j = 0; j< num; j++){
						game[i][j] = moves[totalEntry-1][i][j];
					}
				}
				
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
			
			if(c ==CTRL_KEYPRESS('y') || d == CTRL_KEYPRESS('y')){
				
				for (int i=0; i<num; i++)
				{	
					for(int j = 0; j< num; j++){
						game[i][j] = moves[totalEntry][i][j];
					}
				}
				totalEntry++;
				printf("Move redone\n");
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
		for (int j=0; j<num; j++)
		{
			
			for(int l = 0; l < num; l++){
				(moves[totalEntry])[j][l] = game[j][l];
			}
		}
		drawBoard(moves[totalEntry-1]);
		totalEntry++;
	}  	

    return 0;
}