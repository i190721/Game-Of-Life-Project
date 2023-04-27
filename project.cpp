// i190721
// SUMEN JAMIL
// FINAL PROJECT

#include <iostream>
#include <fstream>
using namespace std ;

// Function for Writing
int Writing ( int Secondary_Array_x [ 100 ] , int Secondary_Array_y [ 100 ] , int generations , int &Sec_Size )    
{

	ofstream projectfile ( "Output.txt" ) ;
	projectfile << generations << endl;
	projectfile << Sec_Size << endl;
	for ( int  i = 0 ; i < Sec_Size ; i ++ )
	{
		projectfile << Secondary_Array_x [ i ] << " " ;
		projectfile << Secondary_Array_y [ i ] << " " << endl;
	}
	projectfile.close();

}

// Function to Reset the Count
void Count_Update ( int Secondary_Count [ 100 ] , int Neighbour_Count [ 300 ] )   
{	
	int i = 0 ;
	while ( i < 100 )
	{
		
		Secondary_Count [ i ] = 0 ;
		i++ ;
		
	}
	i = 0 ;
	while (i < 100 )
	{
	 	
	 	Neighbour_Count [ i ] = 0 ;
	 	i++ ; 
	 	
	}
	 
}
	
// Function to Reset the Grid
void Grid_Reset ( int grid [ ] [ 20 ] ) 
{

	int i = 0 ;
	while ( i < 20 )
	{
		
		int j = 0 ;
		while ( j < 20 ) 
		{
			grid [ i ] [ j ] = 0 ; 
			j++ ;
		}
		i++ ;
	}

}

// Function to reset neighbour array
void Neighbour_Reset ( int Neighbour_Array_x [ 300 ] , int Neighbour_Array_y [ 300 ] , int &Neigh_Size ) 
{
	int i = 0 ;
	while ( i <= Neigh_Size )
	{
		Neighbour_Array_x [ i ] = 0 ;
		Neighbour_Array_y [ i ] = 0 ;
		i++ ;
	}
	Neigh_Size = -1 ;
	
	
}

// Function to combine count of neigh array with secondary array
void Combining_Sec_Neigh ( int Secondary_Array_x [ 100 ] , int Secondary_Array_y [ 100 ] , int &Sec_Size , int Neighbour_Array_x [ 300 ] , int Neighbour_Array_y [ 300 ] , int &Neigh_Size , int Count_Neighbour [ 300 ] ) 
{
	int i = 0 ; 
	
	while ( i < Neigh_Size )
	{
	
		if ( Count_Neighbour [ i ] == 3 )
		{
			Secondary_Array_x [ Sec_Size ] = Neighbour_Array_x [ i ];
			Secondary_Array_y [ Sec_Size ] = Neighbour_Array_y [ i ];
			Sec_Size ++ ;
		}
		
	i++ ;	
	}
	
}

// Function to update secondary
void Update_Secondary ( int Secondary_Array_x [ 100 ] , int Secondary_Array_y [ 100 ] , int &Sec_Size , int Count_Secondary [ 100 ] ) 
 
{
	int i = 0 ;
	
	while ( i < Sec_Size )
	{
	
		if ( Count_Secondary [ i ] < 2 || Count_Secondary [ i ] > 3 )
		{
			int j = i ;
		
			while ( j < Sec_Size )
			{
				Secondary_Array_x [ j ] = Secondary_Array_x[j + 1] ;
				Secondary_Array_y [ j ] = Secondary_Array_y[j + 1] ;
				Count_Secondary [ j ] = Count_Secondary[j + 1] ;
				j++;	
			}
			
			Sec_Size = Sec_Size - 1 ;
			i = i - 1 ;
		}
	i++ ; 
			
	}
}

//Function For Neighbour Count
void Neighbour_Count ( int Neighbour_Array_x [ 300 ] , int Neighbour_Array_y [ 300 ] , int Neigh_Size , int Count_Neighbour [ 300 ],int grid[20][20] ) 
{
	int i = 0 ;
	
	while ( i < Neigh_Size )
	{
		int x ;
		int y ;
		x = Neighbour_Array_x [ i ] ;
		y = Neighbour_Array_y [ i ] ;
		
		if ( grid[x - 1][y - 1] == 1 )
		{
			Count_Neighbour [ i ] += 1 ;
		}
		
		if ( grid[x][y - 1] == 1 )
		{
			Count_Neighbour [ i ] += 1 ;
		}
		
		if ( grid[x + 1][y - 1] == 1 )
		{
			Count_Neighbour [ i ] += 1 ;
		} 
		
		if ( grid[x - 1][y] == 1 )
		{
			Count_Neighbour [ i ] += 1 ;
		} 
		
		if ( grid[x + 1][y] == 1 )
		{
			Count_Neighbour [ i ] += 1 ;
		} 
		
		if ( grid[x - 1][y + 1] == 1 )
		{
			Count_Neighbour [ i ] += 1 ;
		} 
		
		if ( grid[x][y + 1] == 1 )
		{
			Count_Neighbour [ i ] += 1 ;
		} 
		
		if ( grid[x + 1][y + 1] == 1 )
		{
			Count_Neighbour [ i ] += 1 ;
		} 
		
		i++ ;
	}
		
}
	
// Function for Secondary Count
void Secondary_Count ( int Secondary_Array_x [ 100 ] , int Secondary_Array_y [ 100 ] , int Sec_Size , int Count_Secondary [ 100 ], int grid[20][20] )

{
	int i = 0 ;
	
	while ( i < Sec_Size )
	{
		int x ;
		int y ;
		x = Secondary_Array_x [ i ] ;
		y = Secondary_Array_y [ i ] ;
		
		if ( grid[x - 1][y - 1] == 1 )
		{
			Count_Secondary [ i ] += 1 ;
		}
		
		if ( grid[x][y - 1] == 1 )
		{
			Count_Secondary [ i ] += 1 ;
		}
		
		if ( grid[x + 1][y - 1] == 1 )
		{
			Count_Secondary [ i ] += 1 ;
		} 
		
		if ( grid[x - 1][y] == 1 )
		{
			Count_Secondary [ i ] += 1 ;
		} 
		
		if ( grid[x + 1][y] == 1 )
		{
			Count_Secondary [ i ] += 1 ;
		} 
		
		if ( grid[x - 1][y + 1]== 1 )
		{
			Count_Secondary [ i ] += 1 ;
		} 
		
		if ( grid[x][y + 1] == 1 )
		{
			Count_Secondary [ i ] += 1 ;
		} 
		
		if ( grid[x + 1][y + 1] == 1 )
		{
			Count_Secondary [ i ] += 1 ;
		} 
		
		i++ ;
	}
		
}

// Function of neighbours around live cells 
void Neighbour_Input ( int grid [ 20 ] [ 20 ] , int Neighbour_Array_x [ 300 ] , int Neighbour_Array_y [ 300 ] , int &Neigh_Size , int Secondary_Array_x [ 100 ], int Secondary_Array_y [ 100 ] , int Sec_Size ) 
{
	int x ;
	int y ;
	int i = 0 ;
	int j = 0 ;
	bool sec_found = false ;
	bool neigh_found = false ;
	while ( i < Sec_Size )
	{
		x = Secondary_Array_x [ i ] ;
		y = Secondary_Array_y [ i ] ;
		int a = 0 ;
		
		// Part of code which check the repeatition of neighbour cell around active or live cell
		while ( a < Sec_Size )
		{
		
			if ( Secondary_Array_x [ a ] == x - 1 &&  Secondary_Array_y [ a ] == y - 1 )
			{
				sec_found = true ;
				break ;
			}
			
			 a++ ;
		}
		
		a = 0 ;
		while ( a < Neigh_Size )
		{
		
			if ( Neighbour_Array_x [ a ] == x - 1 &&  Neighbour_Array_y [ a ] == y - 1 )
			{
				neigh_found = true ;
				break ;
			}
			
			a++ ;
		}
			
			if ( sec_found == false && neigh_found == false )
			{
				Neighbour_Array_x [ j ] = x - 1 ;
				Neighbour_Array_y [ j ] = y - 1 ;
				Neigh_Size++ ;
				j++ ;
			}
		
		sec_found = false ;
		neigh_found = false ;
		a = 0 ;
		
		while ( a < Sec_Size ) 
		{
		
			if ( Secondary_Array_x [ a ] == x &&  Secondary_Array_y [ a ] == y - 1 )
			{
				sec_found = true ;
				break ;
			}
			
			a++ ;
		}
		
		a = 0 ;
		while ( a < Neigh_Size )
		{
		
			if ( Neighbour_Array_x [ a ] == x &&  Neighbour_Array_y [ a ] == y - 1 )
			{
				neigh_found = true ;
				break ;
			}
			
			a++ ;
		}
			
			if ( sec_found == false && neigh_found == false )
			{
		
				Neighbour_Array_x [ j ] = x ;
				Neighbour_Array_y [ j ] = y - 1 ;
				Neigh_Size++ ;
				j++ ;
			}
			
		sec_found = false ;
		neigh_found = false ;
		a = 0 ;
		
		while ( a < Sec_Size ) 
		{
		
			if ( Secondary_Array_x [ a ] == x + 1 &&  Secondary_Array_y [ a ] == y - 1 )
			{
				sec_found = true ;
				break ;
			}
			
			a++ ;
		}
		
		a = 0 ;
		while ( a < Neigh_Size )
		{
		
			if ( Neighbour_Array_x [ a ] == x + 1 &&  Neighbour_Array_y [ a ] == y - 1 )
			{
				neigh_found = true ;
				break ;
			}
			
			a++ ;
		}
			if ( sec_found == false && neigh_found == false )
			{
		
				Neighbour_Array_x [ j ] = x + 1 ;
				Neighbour_Array_y [ j ] = y - 1 ;
				Neigh_Size++ ;
				j++ ;
			}
			
		sec_found = false ;
		neigh_found = false ;
		a = 0 ;
		
		while ( a < Sec_Size ) 
		{
		
			if ( Secondary_Array_x [ a ] == x - 1 &&  Secondary_Array_y [ a ] == y )
			{
				sec_found = true ;
				break ;
			}
			
			a++ ;
			
		}
		
		a = 0 ;
		
		while ( a < Neigh_Size )
		{
		
			if ( Neighbour_Array_x [ a ] == x - 1 &&  Neighbour_Array_y [ a ] == y )
			{
				neigh_found = true ;
				break ;
			}
			
			a++ ;
		}
			if ( sec_found == false && neigh_found == false )
			{
			
				Neighbour_Array_x [ j ] = x - 1 ;
				Neighbour_Array_y [ j ] = y ;
				Neigh_Size++ ;
				j++ ;
			}
			
		sec_found = false ;
		neigh_found = false ;
		a = 0 ;
		
		while ( a < Sec_Size ) 
		{
			if ( Secondary_Array_x [ a ] == x + 1 &&  Secondary_Array_y [ a ] == y )
			{
				sec_found = true ;
				break ;
			}
			a++ ;
			
		}
		
		a = 0 ;
		while ( a < Neigh_Size )
		{
		
			if ( Neighbour_Array_x [ a ] == x + 1 &&  Neighbour_Array_y [ a ] == y )
			{
				neigh_found = true ;
				break ;
			}
			
			a++ ;
		}
		
			if ( sec_found == false && neigh_found == false )
			{
		
				Neighbour_Array_x [ j ] = x + 1 ;
				Neighbour_Array_y [ j ] = y ;
				Neigh_Size++ ;
				j++ ;
			}
			
		sec_found = false ;
		neigh_found = false ;
		a = 0 ;
		
		while ( a < Sec_Size ) 
		{
		
			if ( Secondary_Array_x [ a ] == x - 1 &&  Secondary_Array_y [ a ] == y + 1 )
			{
				sec_found = true ;
				break ;
			}
			a++ ;
			
		}
		
		a = 0 ;
		
		while ( a < Neigh_Size )
		{
		
			if ( Neighbour_Array_x [ a ] == x - 1 &&  Neighbour_Array_y [ a ] == y + 1 )
			{
				neigh_found = true ;
				break ;
			}
			
			a++ ;
		}
			if ( sec_found == false && neigh_found == false )
			{
			
				Neighbour_Array_x [ j ] = x - 1 ;
				Neighbour_Array_y [ j ] = y + 1 ;
				Neigh_Size++ ;
				j++ ;
			}
		
		sec_found = false ;
		neigh_found = false ;
		a = 0 ;
		
		while ( a < Sec_Size ) 
		{
		
			if ( Secondary_Array_x [ a ] == x &&  Secondary_Array_y [ a ] == y + 1 )
			{
				sec_found = true ;
				break ;
			}
			a++ ;
		
		}
		
		a = 0 ;
		
		while ( a < Neigh_Size )
		{
		
			if ( Neighbour_Array_x [ a ] == x &&  Neighbour_Array_y [ a ] == y + 1 )
			{
				neigh_found = true ;
				break ;
			}
			
			a++ ;
		}
		
			if ( sec_found == false && neigh_found == false )
			{
				Neighbour_Array_x [ j ] = x ;
				Neighbour_Array_y [ j ] = y + 1 ;
				Neigh_Size++ ;
				j++ ;
			}
			
		sec_found = false ;
		neigh_found = false ;
		a = 0 ;
		
		while ( a < Sec_Size ) 
		{
		
			if ( Secondary_Array_x [ a ] == x + 1 &&  Secondary_Array_y [ a ] == y + 1 )
			{
				sec_found = true ;
				break ;
			}
			a++ ;
			
		}
		
		a = 0 ;
		while ( a < Neigh_Size )
		{
		
			if ( Neighbour_Array_x [ a ] == x + 1 &&  Neighbour_Array_y [ a ] == y + 1 )
			{
				neigh_found = true ;
				break ;
			}
			
			a++ ;
		}
		
			if ( sec_found == false && neigh_found == false )
			{
			
				Neighbour_Array_x [ j ] = x + 1 ;
				Neighbour_Array_y [ j ] = y + 1 ;
				Neigh_Size++ ;
				j++ ;
					
			}
			i++ ;	
			
	}
}

// Displaying the Grid
void Grid_Output ( int grid [ 20 ] [ 20 ] ) 
{
	for ( int i = 0 ; i < 20 ; i++ )
	{
	
		for ( int j = 0 ; j < 20 ; j ++ ) 
		{
			cout << grid [ i ] [ j ] ;
			cout << "  ";
		}
		cout << endl;
	}
	
	
}

// Function for Alive Cells 
void Grid_Input ( int grid [ 20 ] [ 20 ] , int Secondary_Array_x [ 100 ] , int Secondary_Array_y [ 100 ] , int Size ) 
{
	int x ;
	int y ;
	int i = 0 ;
	while ( i < Size )
	{
		x = Secondary_Array_x [ i ] ;
		y = Secondary_Array_y [ i ] ;
		grid [x][y] = 1 ;
		i++ ;
	}
		  	
}

// function for file Reading 
void File_Reading ( int Secondary_Array_x [ 100 ] , int Secondary_Array_y [ 100 ] , int &generations , int &last ) 
{
	
	string Projectfile ;
	cout << "Please enter the text file to read the input data = " ;
	cin >> Projectfile ;
	cout << endl ;
	ifstream projectfile ( Projectfile ) ;
	string file ;
	if ( projectfile )
	{
	
		projectfile >> generations ;
		cout << "Generation are = " << generations << endl ;
		projectfile >> last ;
		cout << "last is = " << last << endl ;
		for ( int  a = 0 ; a < last ; a ++ )
		{
			projectfile >> Secondary_Array_x [ a ] ;
			projectfile >> Secondary_Array_y [ a ] ;
		}

		
	}
	else 
	{ 
		cout << "Sorry No Such File is Found" << endl ;
	} 
	projectfile.close () ;
}	
	
// Function to start the program
int start ( ) 
{
	cout << "===========================================================" << endl ;
	cout << "                   GAME OF LIFE " << endl ;
	cout << "                LET'S START THE GAME" << endl ;
	cout << "===========================================================" << endl ;       
	int Generations ;
	int Secondary_size ;
	int Neighbour_size = 0 ;
	int Sec_Array_x [ 100 ] = { } ;
	int Sec_Array_y [ 100 ] = { } ;
	int Neigh_Array_x [ 300 ] = { } ; 
	int Neigh_Array_y [ 300 ] = { } ;
	int Count_Second [ 100 ] = { } ;
	int Count_Neigh [ 300 ] = { } ;
	int Grid [ 20 ] [ 20 ] = { } ;
	File_Reading ( Sec_Array_x , Sec_Array_y , Generations  , Secondary_size ) ;
	Grid_Input ( Grid , Sec_Array_x , Sec_Array_y , Secondary_size ) ;
	Grid_Output ( Grid ) ;
	int i = 0 ;
	while ( i < Generations )
	{
		Neighbour_Input ( Grid , Neigh_Array_x , Neigh_Array_y , Neighbour_size , Sec_Array_x , Sec_Array_y , Secondary_size ) ;
		Secondary_Count ( Sec_Array_x , Sec_Array_y , Secondary_size , Count_Second, Grid ) ;
		Neighbour_Count ( Neigh_Array_x , Neigh_Array_y , Neighbour_size , Count_Neigh, Grid ) ;
		Update_Secondary ( Sec_Array_x , Sec_Array_y , Secondary_size , Count_Second ) ;
		Combining_Sec_Neigh ( Sec_Array_x , Sec_Array_y , Secondary_size, Neigh_Array_x, Neigh_Array_y, Neighbour_size,Count_Neigh ) ;
		Neighbour_Reset ( Neigh_Array_x , Neigh_Array_y , Neighbour_size ) ;
		Grid_Reset ( Grid ) ;
		Grid_Input ( Grid , Sec_Array_x , Sec_Array_y , Secondary_size ) ;
		Count_Update ( Count_Second , Count_Neigh ) ;
		cout << "==========================================================="<< endl ;
		Grid_Output ( Grid ) ;
		i++ ;
	}
	Writing ( Sec_Array_x , Sec_Array_y , Generations ,  Secondary_size ) ;
	cout << "==========================================================="<< endl ;
	cout << "                         END " << endl ;
	cout << "==========================================================="<< endl ;
}

int main ()
{
	start () ; 
	return  0 ; 
}
	

