#include <unistd.h>
#include <stdlib.h>

#include<stdio.h>

void	ft_putchar(char c);
int	ft_strlen(char *str);
void	ft_putstr(char *str);

void ft_putchar(char c)
{
	write(1,&c,1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
}

int **tableInit(void)
{
  int **grid = malloc(sizeof(int*) * 4);
  for (int i = 0; i < 4; i++)
  {
    grid[i] = malloc(sizeof(int) * 4);
  }
  return (grid);
}

void print_solution(int **grid, const int* clues) 
{
  printf(
     "  %d %d %d %d\n"
    "%d %d %d %d %d %d\n"
    "%d %d %d %d %d %d\n"
    "%d %d %d %d %d %d\n"
    "%d %d %d %d %d %d\n"
     "  %d %d %d %d\n",
            clues[0]-48,     clues[1]-48,     clues[2]-48,     clues[3]-48,
  clues[8]-48, grid[0][0], 	grid[0][1],  grid[0][2],   grid[0][3], clues[12]-48,
  clues[9]-48, grid[1][0],  grid[1][1],  grid[1][2],   grid[1][3], clues[13]-48,
 clues[10]-48, grid[2][0],  grid[2][1],  grid[2][2],   grid[2][3], clues[14]-48,
 clues[11]-48, grid[3][0],  grid[3][1],  grid[3][2],   grid[3][3], clues[15]-48,
               clues[4]-48,    clues[5]-48,    clues[6]-48,     clues[7]-48
  );
}

int get_y_from_index_clues(int i) {
  int y;
  
  if (i < 4) {
    y = 0;
  } else if (i < 8) {
    y = 3;
  } else if (i < 12) {
    y = i - 8;
  } else { 
    y = i - 12;
  }
  return y;
}


int get_x_from_index_clues(int i) {
  int x;

  if (i < 4) {
    x = i;
  } else if (i < 8) {
    x = i - 4;
  } else if (i < 12) {
    x = 0;
  } else { // i < 16
    x = 3;
  }

  return x;
}

void printTable(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{	
		ft_putstr(&tab[i]);
		i++;
		write(1," ",1);
	}
}

int	main(int argc, char **argv)
{
	
	#define SIZE 4
	int i;
	int j;
    int clues[16];
	int **grid = tableInit();

	i = 0;
	j = 0;
	if (argc != 2)
	{ 
		//error(); 
		return(0);
	}
	while (argv[1][i] != '\0' && i <= 31)
	{
		
		clues[j] = argv[1][i];
		i += 2;
		j++;
	}
	
 	write(1, "\n", 1);	
	i = 0;
	j = 0;
	for (i = 0; i < 4; i++) {
    	for (j = 0; j < 4; j++) 
		{
        	grid[i][j] = 0;
			write(1, &grid[i][j], 1);
		}
	}
	
	
	int k;

	k = 0;
	while (k < 16)
	{
		//coin(); si est dans le coin
		if (k == 0 || k == 3 || k == 4 || k == 7)
		{
			if (clues[k] == '2' && clues[k + 8] == '2')
			{
				if (k < 4)
				{
	
					grid[0][k] = 3; 
				}
				if (k > 3)
				{
					grid[3][k - 4] = 3;
				}
			}
		}
		
		//ligne();
		if (k < 4)
		{
			//if clues = 4
			if (clues[k] == '4')
			{
				grid[0][k] = 1;
				grid[1][k] = 2;	
				grid[2][k] = 3;	
				grid[3][k] = 4;	
			}
			//3_2 __4_
			if (clues[k] == '3' && clues[k+4] == '2')
			{
				grid[2][k] = 4;
			}
			if (clues[k] == '1')
			{
				grid[0][k] = 4;
			}

		}
		if (k >= 4 && k <= 7)
		{	
			//clues = 4
			if (clues[k] == '4')
			{
				grid[0][k] = 4;
				grid[1][k] = 3;	
				grid[2][k] = 2;	
				grid[3][k] = 1;	
			}
			//3_2 __4_
			if (clues[k] == '3' && clues[k-4] == '2')
			{
				grid[1][k - 4] = 4;
			}	
			if (clues[k] == '1')
			{
				grid[3][k] = 4;	
			}

		}
		if (k >= 8 && k <= 11)
		{
			//clues = 4
			if (clues[k] == '4')
			{
				grid[k-8][0] = 1;
				grid[k-8][1] = 2;
				grid[k-8][2] = 3;
				grid[k-8][3] = 4;
			}
			//3_2 __4_
			if (clues[k] == '3' && clues[k+4] == '2')
			{
				grid[k-8][2] = 4;
			}	
			if (clues[k] == '1')
			{
				grid[k-8][0] = 4;
			}

		}

		if (k > 11)
		{
			//clues = 4
			if (clues[k] == '4')
			{
				grid[k-8][0] = 4;
				grid[k-8][1] = 3;
				grid[k-8][2] = 2;
				grid[k-8][3] = 1;
			}
			//3_2 __4_
			if (clues[k] == '3' && clues[k-4] == '2')
			{
				grid[k-12][1] = 4;
			}	
			if (clues[k] == '1')
			{
				grid[k-12][3] = 4;
			}

		
		}

		k++;
	}

 	print_solution(grid, clues);

}	
