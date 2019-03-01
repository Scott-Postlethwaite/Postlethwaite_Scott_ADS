#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

int main()
{
	num =1;
	char a;
	while(num <=1){
		printf("How big do you want your board? ");
		scanf("%d",&num);
		getchar();
	 }
	
  //  char game = new int[][num];
  
    char** game =  (char **)malloc(num * sizeof(char*));
    for (int i=0; i<num; i++)
	{
		game[i] = (char*)malloc(sizeof(char));
		for(int j = 0; j < num; j++){
			//**game[i]=(char *)malloc(num * sizeof(chars));
			//*(game + i*num + j) = ' ';
			(game[i])[j] = ' ';
		}
	}
    int totalEntry =1,row,column;
	char player = 'O';


    while(totalEntry<= num * num){
		row = -1;
		column = -1;
		printf("%c to play\n", player);
		while(!isLegal(row, column, game))
		{
			printf("Enter row number: ");
			scanf("%d",&row);
			getchar();
			printf("Enter Column number: ");
			scanf("%d",&column);
			getchar();
		}
			(game[row])[column] = player;
			drawBoard(game);
			if(player == 'X')
			 {
				 player='O';
			 }
			 else
			 {
				 player='X';
			 }
			 			
			 totalEntry++;
		 
}  	

    return 0;
}