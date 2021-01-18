
#include "stack.h"
#include <stdio.h>

const int MAX_X = 10;
const int MAX_Y = 16;

int main()
{
	//Initialize variables and the maze
	int posX = 1;
	int posY = 1;
	char maze[MAX_X][MAX_Y] = { "OOOOOOOOOOOOOOO",
							"O O O OOO O  OO",
							"O             O",
							"O O OOOOOOO O O",
							"O O   O   O   O",
							"O OOO  OO  OOOO",
							"O    O O      O",
							"OO O O O OOO OO",
							"OO   O   O    O",
							"OOOOOOOOOOOOOOO" };
	Stack player(MAX_X * MAX_Y);

	//Put the player in the initial position
	maze[posX][posY] = 'P';

	//Print initial maze pattern
	printf("Starting maze pattern:\n");
	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
	printf("Coordinates: (%d,%d)\n", posX, posY);

	//Begin the pathfinding loop!
	while (posX != 8 || posY != 13)
	{
		//Select a direction for the player to move
		if (maze[posX][posY + 1] == ' ')
		{
			//Set the current player position as a 'visited' spot
			maze[posX][posY] = '*';

			//go forward
			posY++;

			//Replace the space with the P for the new player position
			maze[posX][posY] = 'P';

			//Add the direction to the stack
			player.push(1);

		}
		else if (maze[posX + 1][posY] == ' ')
		{
			//Set the current player position as a 'visited' spot
			maze[posX][posY] = '*';

			//go down
			posX++;

			//Replace the space with the P for the new player position
			maze[posX][posY] = 'P';

			//Add the direction to the stack
			player.push(2);
		}
		else if (maze[posX][posY - 1] == ' ')
		{
			//Set the current player position as a 'visited' spot
			maze[posX][posY] = '*';

			//go backwards
			posY--;

			//Replace the space with the P for the new player position
			maze[posX][posY] = 'P';

			//Add the direction to the stack
			player.push(3);
		}
		else if (maze[posX - 1][posY] == ' ')
		{
			//Set the current player position as a 'visited' spot
			maze[posX][posY] = '*';

			//go up
			posX--;

			//Replace the space with the P for the new player position
			maze[posX][posY] = 'P';

			//Add the direction to the stack
			player.push(4);
		}
		else
		{
			//Set the current position as a 'deadend'
			maze[posX][posY] = 'D';

			//Get the previous direction by popping from the top of the stack
			try
			{
				int prevDirection = player.pop();

				//Backtrack using the previous direction

				if (prevDirection == 1)
				{
					//go backwards
					posY--;

					//Replace the space with the P for the new player position
					maze[posX][posY] = 'P';
				}
				else if (prevDirection == 2)
				{
					//go up
					posX--;

					//Replace the space with the P for the new player position
					maze[posX][posY] = 'P';
				}
				else if (prevDirection == 3)
				{
					//go forward
					posY++;

					//Replace the space with the P for the new player position
					maze[posX][posY] = 'P';
				}
				else if (prevDirection == 4)
				{
					//go down
					posX++;

					//Replace the space with the P for the new player position
					maze[posX][posY] = 'P';
				}
				else
				{
					throw "UH OH! prevDirection isn't from 1 to 4.";
				}
			}
			catch (...)
			{
				printf("The maze has no solution.");
				return 0;
			}
		}

		//print the iteration of the maze
		printf("\n");
		for (int i = 0; i < MAX_X; i++)
		{
			for (int j = 0; j < MAX_Y; j++)
			{
				printf("%c", maze[i][j]);
			}
			printf("\n");
		}
		printf("Coordinates: (%d,%d)\n", posX, posY);
	}

	//Maze solved!
	printf("The maze has been solved!");

	//Tell the computer all went fine!
	return 0;
}
