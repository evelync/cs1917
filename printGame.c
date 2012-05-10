#include <stdio.h>
#include <stdlib.h>

#define BOARD_HEIGHT 40
#define BOARD_WIDTH 80

#define RED 31 //BPS
#define GREEN 32 //MTV
#define YELLOW 33 //MJ
#define BLUE 34 //THD
#define MAGENTA 35 //MMON
#define CYAN 36 //BQN
#define DEFAULT 39

#define COLUMN_1 3
#define COLUMN_2 7
#define COLUMN_3 12
#define COLUMN_4 16
#define COLUMN_5 19

#define COLUMN_SIZE 9
#define FIRST_COLUMN 6
#define ROW_SIZE 3
#define FIRST_ROW 4
#define LENGTH_OF_HORIZONTAL 5

typedef char bufferType[BOARD_HEIGHT][BOARD_WIDTH];
typedef int colourBufferType[BOARD_HEIGHT][BOARD_WIDTH];

static void printStats(bufferType buffer, int colourBuffer[][BOARD_WIDTH]/* also Game g, or something */);
static void printTile(bufferType buffer, int num);
static void makeColours (colourBufferType colourBuffer , int y, int xLeft, int xRight, int colour);
static int tileToX (int num);
static int tileToY (int num);


int main (int argc, char *argv[]) {
   bufferType buffer;
   colourBufferType colourBuffer;
   int i, k;
   
   for (i = 0; i < BOARD_HEIGHT; i++) {
      for (k = 0; k < BOARD_WIDTH; k++) {
         buffer[i][k] = ' ';
      }
   }
   
   for (i = 0; i < BOARD_HEIGHT; i++) {
      for (k = 0; k < BOARD_WIDTH; k++) {
         colourBuffer[i][k] = DEFAULT;
      }
   }

   for (i = 0; i <= 18; i++) {
      printTile(buffer, i);
   }
   
   printStats(buffer, colourBuffer);
   
   for (i = 0; i < BOARD_HEIGHT; i++) {
      for (k = 0; k < BOARD_WIDTH; k++) {
         printf("\x1B[%dm", colourBuffer[i][k]);
         printf("%c", buffer[i][k]);
      }
      printf("\n");
   }

   return EXIT_SUCCESS;
}


static void printTile(bufferType buffer, int num) {
   // Convert num to (x,y) coords of centre(?) of the tile
   // Print ascii art!! ^^
   
   // TODO: real coord calcs
   int i;
   int x = tileToX (num);
   int y = tileToY (num);
   
   char tempString[5];
   sprintf(tempString, "%d", num);
   if (tempString[0] != '\0') {
      buffer[y][x] = tempString[0];
   }
   if (tempString[1] != '\0') {
      buffer[y][x+1] = tempString[1];
   }

   buffer[y][x-6] = buffer[y][x+6] = '#';
   buffer[y-3][x-3] = buffer[y-3][x+3] = '#';
   buffer[y+3][x-3] = buffer[y+3][x+3] = '#';
   buffer[y-2][x-4] = buffer[y-1][x-5] = buffer[y+1][x+5]  = buffer[y+2][x+4]  = '/';
   buffer[y-2][x+4] = buffer[y-1][x+5] = buffer[y+1][x-5]  = buffer[y+2][x-4]  = '\\';
   
   for (i=0; i<LENGTH_OF_HORIZONTAL; i++) {
      buffer[y-3][x-2+i] = buffer[y+3][x-2+i] = '-';
   }
}


static void printStats (bufferType buffer, colourBufferType colourBuffer/* also Game g, or something */) {
   sprintf(&buffer[3][54], "UNI        A    B    C");
   makeColours(colourBuffer, 3, 64, 66, RED);
   makeColours(colourBuffer, 3, 69, 71, GREEN);
   makeColours(colourBuffer, 3, 74, 76, BLUE);
   sprintf(&buffer[4][54], "-----------------------");   
   sprintf(&buffer[5][54], "KPIs      %3d  %3d  %3d", 0, 123, 3);

   sprintf(&buffer[7][54], "Campuses  %3d  %3d  %3d", 456, 123, 3);
   sprintf(&buffer[8][54], "GO8s      %3d  %3d  %3d", 0, 123, 3);
   sprintf(&buffer[9][54], "ARCs      %3d  %3d  %3d", 0, 123, 3);
   sprintf(&buffer[10][54], "Patents   %3d  %3d  %3d", 0, 123, 3);
   sprintf(&buffer[11][54], "Papers    %3d  %3d  %3d", 0, 123, 3);
   
   sprintf(&buffer[13][54], "THDs      %3d  %3d  %3d", 0, 123, 3);
   makeColours(colourBuffer, 13, 54, 62, BLUE);
   sprintf(&buffer[14][54], "BPSs      %3d  %3d  %3d", 0, 123, 3);
   makeColours(colourBuffer, 14, 54, 62, RED);
   sprintf(&buffer[15][54], "BQNs      %3d  %3d  %3d", 0, 123, 3);
   makeColours(colourBuffer, 15, 54, 62, CYAN);
   sprintf(&buffer[16][54], "MJs       %3d  %3d  %3d", 0, 123, 3);
   makeColours(colourBuffer, 16, 54, 62, YELLOW);
   sprintf(&buffer[17][54], "MTVs      %3d  %3d  %3d", 0, 123, 3);
   makeColours(colourBuffer, 17, 54, 62, GREEN);
   sprintf(&buffer[18][54], "MMONEYs   %3d  %3d  %3d", 0, 123, 3);
   makeColours(colourBuffer, 18, 54, 62, MAGENTA);
   
   
   sprintf(&buffer[22][54], "Turn Number: %d", 12);
   sprintf(&buffer[23][54], "-----------------------");
   sprintf(&buffer[24][54], "%s", "Uni A trolled a 13");
}


static void makeColours (colourBufferType colourBuffer, int y, int xLeft, int xRight, int colour) {
   int x;
   for (x = xLeft; x <= xRight; x++) {
         colourBuffer[y][x] = colour;
   }
   
}


static int tileToX (int num) {
   int X;

   if (num < COLUMN_1) {
      X = 0*COLUMN_SIZE + FIRST_COLUMN;
   } else if (num < COLUMN_2) {
      X = 1*COLUMN_SIZE + FIRST_COLUMN;
   } else if (num < COLUMN_3) {
      X = 2*COLUMN_SIZE + FIRST_COLUMN;
   } else if (num < COLUMN_4) {
      X = 3*COLUMN_SIZE + FIRST_COLUMN;
   } else if (num < COLUMN_5){
      X = 4*COLUMN_SIZE + FIRST_COLUMN;
   }
   
   return X;
}


static int tileToY (int num) {
   int Y;
   
   if (num == 7) {
      Y = 0*ROW_SIZE + FIRST_ROW;
   } else if (num == 3 || num == 12) {
      Y = 1*ROW_SIZE + FIRST_ROW;
   } else if (num == 0 || num == 8 || num == 16) {
      Y = 2*ROW_SIZE + FIRST_ROW;
   } else if (num == 4 || num == 13) {
      Y = 3*ROW_SIZE + FIRST_ROW;
   } else if (num == 1 || num == 9 || num == 17) {
      Y = 4*ROW_SIZE + FIRST_ROW;
   } else if (num == 5 || num == 14) {
      Y = 5*ROW_SIZE + FIRST_ROW;
   } else if (num == 2 || num == 10 || num == 18) {
      Y = 6*ROW_SIZE + FIRST_ROW;
   } else if (num == 6 || num == 15) {
      Y = 7*ROW_SIZE + FIRST_ROW;
   } else if (num == 11) {
      Y = 8*ROW_SIZE + FIRST_ROW;
   }
   
   return Y;
}

