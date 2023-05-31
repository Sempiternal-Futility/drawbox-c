#include <stdio.h>
#include <stdlib.h>


void bkgd_color( char color[] ); // Sets the background color of the terminal
void bkgd_color_box( char color[] ); // Sets the background color of the box
void move_cur( int posY, int posX ); // Moves the cursor to the given position
void draw_box( int lines, int length ); // Draws the box
void exit_program(); // Cleans all the mess before returning the user back to the shell


int main( int argc, char *argv[] )
{

   if( argc < 6 )
   {
      fprintf( stderr, "THE AMOUNT OF ARGUMENTS SUPPLIED WAS NOT VALID!\n" );
      return 1;
   }

   else
   {

      int posY, posX, lines, length;

      posY = atoi( argv[3] );
      posX = atoi( argv[4] );
      lines = atoi( argv[5] );
      length = atoi( argv[6] );

      bkgd_color( argv[1] );
      bkgd_color_box( argv[2] );
      move_cur( posY, posX );
      draw_box( lines, length );

      getchar();
      exit_program();
      return 0;

   }

}


void bkgd_color( char color[] )
{

   if( color[0] == 'b'  &&  color[1] == 'l'  &&  color[2] == 'a'  &&  color[3] == 'c'  &&  color[4] == 'k'  &&  color[5] == '\0' )
      printf( "\033[40m" ); // Black

   else if( color[0] == 'r'  &&  color[1] == 'e'  &&  color[2] == 'd'  &&  color[3] == '\0' )
      printf( "\033[41m" ); // Red

   else if( color[0] == 'g'  &&  color[1] == 'r'  &&  color[2] == 'e'  &&  color[3] == 'e'  &&  color[4] == 'n'  &&  color[5] == '\0' )
      printf( "\033[42m" ); // Green

   else if( color[0] == 'y'  &&  color[1] == 'e'  &&  color[2] == 'l'  &&  color[3] == 'l'  &&  color[4] == 'o'  &&  color[5] == 'w'  &&  color[6] == '\0' )
      printf( "\033[43m" ); // Yellow

   else if( color[0] == 'b'  &&  color[1] == 'l'  &&  color[2] == 'u'  &&  color[3] == 'e'  &&  color[4] == '\0' )
      printf( "\033[44m" ); // Blue

   else if( color[0] == 'm'  &&  color[1] == 'a'  &&  color[2] == 'g'  &&  color[3] == 'e'  &&  color[4] == 'n'  &&  color[5] == 't'  &&  color[6] == 'a'  &&  color[7] == '\0' )
      printf( "\033[45m" ); // Magenta

   else if( color[0] == 'c'  &&  color[1] == 'y'  &&  color[2] == 'a'  &&  color[3] == 'n'  &&  color[4] == '\0' )
      printf( "\033[46m" ); // Cyan

   else if( color[0] == 'w'  &&  color[1] == 'h'  &&  color[2] == 'i'  &&  color[3] == 't'  &&  color[4] == 'e'  &&  color[5] == '\0' )
      printf( "\033[47m" ); // White

   else if( color[0] == 'b'  &&  color[1] == 'b'  &&  color[2] == 'l'  &&  color[3] == 'a'  &&  color[4] == 'c'  &&  color[5] == 'k'  &&  color[6] == '\0' )
      printf( "\033[100m" ); // Bright black

   else if( color[0] == 'b'  &&  color[1] == 'r'  &&  color[2] == 'e'  &&  color[3] == 'd'  &&  color[4] == '\0' )
      printf( "\033[101m" ); // Bright red

   else if( color[0] == 'b'  &&  color[1] == 'g'  &&  color[2] == 'r'  &&  color[3] == 'e'  &&  color[4] == 'e'  &&  color[5] == 'n'  &&  color[6] == '\0' )
      printf( "\033[102m" ); // Bright green

   else if( color[0] == 'b'  &&  color[1] == 'y'  &&  color[2] == 'e'  &&  color[3] == 'l'  &&  color[4] == 'l'  &&  color[5] == 'o'  &&  color[6] == 'w'  &&  color[7] == '\0' )
      printf( "\033[103m" ); // Bright yellow

   else if( color[0] == 'b' &&  color[1] == 'b'  &&  color[2] == 'l'  &&  color[3] == 'u'  &&  color[4] == 'e'  &&  color[5] == '\0' )
      printf( "\033[104m" ); // Bright blue

   else if( color[0] == 'b'  &&  color[1] == 'm'  &&  color[2] == 'a'  &&  color[3] == 'g'  &&  color[4] == 'e'  &&  color[5] == 'n'  &&  color[6] == 't'  &&  color[7] == 'a'  &&  color[8] == '\0' )
      printf( "\033[105m" ); // Bright magenta

   else if( color[0] == 'b'  &&  color[1] == 'c'  &&  color[2] == 'y'  &&  color[3] == 'a'  &&  color[4] == 'n'  &&  color[5] == '\0' )
      printf( "\033[106m" ); // Bright cyan

   else if( color[0] == 'b'  &&  color[1] == 'w'  &&  color[2] == 'h'  &&  color[3] == 'i'  &&  color[4] == 't'  &&  color[5] == 'e'  &&  color[6] == '\0' )
      printf( "\033[107m" ); // Bright white


   printf( "\033[2J" );

}


void bkgd_color_box( char color[] )
{

   if( color[0] == 'b'  &&  color[1] == 'l'  &&  color[2] == 'a'  &&  color[3] == 'c'  &&  color[4] == 'k'  &&  color[5] == '\0' )
      printf( "\033[40m" );

   else if( color[0] == 'r'  &&  color[1] == 'e'  &&  color[2] == 'd'  &&  color[3] == '\0' )
      printf( "\033[41m" );

   else if( color[0] == 'g'  &&  color[1] == 'r'  &&  color[2] == 'e'  &&  color[3] == 'e'  &&  color[4] == 'n'  &&  color[5] == '\0' )
      printf( "\033[42m" );

   else if( color[0] == 'y'  &&  color[1] == 'e'  &&  color[2] == 'l'  &&  color[3] == 'l'  &&  color[4] == 'o'  &&  color[5] == 'w'  &&  color[6] == '\0' )
      printf( "\033[43m" );

   else if( color[0] == 'b'  &&  color[1] == 'l'  &&  color[2] == 'u'  &&  color[3] == 'e'  &&  color[4] == '\0' )
      printf( "\033[44m" );

   else if( color[0] == 'm'  &&  color[1] == 'a'  &&  color[2] == 'g'  &&  color[3] == 'e'  &&  color[4] == 'n'  &&  color[5] == 't'  &&  color[6] == 'a'  &&  color[7] == '\0' )
      printf( "\033[45m" );

   else if( color[0] == 'c'  &&  color[1] == 'y'  &&  color[2] == 'a'  &&  color[3] == 'n'  &&  color[4] == '\0' )
      printf( "\033[46m" );

   else if( color[0] == 'w'  &&  color[1] == 'h'  &&  color[2] == 'i'  &&  color[3] == 't'  &&  color[4] == 'e'  &&  color[5] == '\0' )
      printf( "\033[47m" );

   else if( color[0] == 'b'  &&  color[1] == 'b'  &&  color[2] == 'l'  &&  color[3] == 'a'  &&  color[4] == 'c'  &&  color[5] == 'k'  &&  color[6] == '\0' )
      printf( "\033[100m" );

   else if( color[0] == 'b'  &&  color[1] == 'r'  &&  color[2] == 'e'  &&  color[3] == 'd'  &&  color[4] == '\0' )
      printf( "\033[101m" );

   else if( color[0] == 'b'  &&  color[1] == 'g'  &&  color[2] == 'r'  &&  color[3] == 'e'  &&  color[4] == 'e'  &&  color[5] == 'n'  &&  color[6] == '\0' )
      printf( "\033[102m" );

   else if( color[0] == 'b'  &&  color[1] == 'y'  &&  color[2] == 'e'  &&  color[3] == 'l'  &&  color[4] == 'l'  &&  color[5] == 'o'  &&  color[6] == 'w'  &&  color[7] == '\0' )
      printf( "\033[103m" );

   else if( color[0] == 'b' &&  color[1] == 'b'  &&  color[2] == 'l'  &&  color[3] == 'u'  &&  color[4] == 'e'  &&  color[5] == '\0' )
      printf( "\033[104m" );

   else if( color[0] == 'b'  &&  color[1] == 'm'  &&  color[2] == 'a'  &&  color[3] == 'g'  &&  color[4] == 'e'  &&  color[5] == 'n'  &&  color[6] == 't'  &&  color[7] == 'a'  &&  color[8] == '\0' )
      printf( "\033[105m" );

   else if( color[0] == 'b'  &&  color[1] == 'c'  &&  color[2] == 'y'  &&  color[3] == 'a'  &&  color[4] == 'n'  &&  color[5] == '\0' )
      printf( "\033[106m" );

   else if( color[0] == 'b'  &&  color[1] == 'w'  &&  color[2] == 'h'  &&  color[3] == 'i'  &&  color[4] == 't'  &&  color[5] == 'e'  &&  color[6] == '\0' )
      printf( "\033[107m" );

}


void move_cur( int posY, int posX )
{

   char num_one[4];
   char num_two[4];

   sprintf( num_one, "%d", posY );
   sprintf( num_two, "%d", posX );
   printf( "%s%s%s%s%s", "\033[", num_one, ";", num_two, "f" );

}


void draw_box( int lines, int length )
{

   printf("\e[?25l");
    
   for( short i = 0; i < lines; i++ )
   {

      for( short j = 0; j < length; j++ )
         printf( " " );


      char length_str[5];
      sprintf( length_str, "%d", length ); 

      printf( "%s%s%s", "\033[", length_str, "D");
      printf( "\033[1B" );

   }

}


void exit_program()
{

   putchar( '\n' );
   printf( "\033[39m "); printf( "\033[49m ");
   printf( "\033[2J " );
   printf( "\033[0;0f" );
   printf( "\e[?25h" );

}
