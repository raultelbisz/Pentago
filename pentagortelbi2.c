// pentagortelbi2.c
//
// Pentago is a two player game where players alternate taking turns placing their pieces
// and then rotating a quadrant of the board. The winner is the first player to match up
// 5 of their same pieces in a row either horizontally, vertically or diagonally.
// 
// Author : Raul Telbisz
// Program: 3, Pentago
// TA: Moumita Samanta, Tues 11
// Feb 20, 2017
/*
A run-through of the program looks like this:

			Author: Raul Telbisz
			Program: #3, Pentago
			TA: Moumita Samanta, Tues 11
			Feb 5, 2017

			Play the two - player game of Pentago. Be the first to get 5 in a row.
			Pentago is played on a 6 by 6 board, divided into four 3 by 3
			quadrants.  There are two players, X and O, who alternate turns.
			The goal of each player is to get five of their pieces in a row,
			either horizontally, vertically, or diagonally.

			Players take turns placing one of their pieces into an empty
			space anywhere on the board, then choosing one of the four
			board quadrants to rotate 90 degrees left or right.

			If both players get five in a row at the same time, or the
			last move is played with no five in a row, the game is a tie.
			If a player makes five a row by placing a piece, there is no need
			to rotate a quadrant and the player wins immediately.

			Play online at:  https://perfect-pentago.net
			Purchase at:     www.mindtwisterusa.com

			For each move provide four inputs
			row (A-F), column (1-6), quadrant (1-4), rotation direction (L or R)
			For instance input of B32R places the next piece at B3 and then
			would rotate quadrant 3 (lower-left) to the right (clockwise).

			At any point enter 'x' to exit the program.


			1  1 2 3 4 5 6  2
			-----------
			A: . . . . . . :A
			B: . . . . . . :B
			C: . . . . . . :C
			D: . . . . . . :D
			E: . . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			1. Enter row, column, quadrant, direction for X:
			c31r

			1  1 2 3 4 5 6  2
			-----------
			A: . . . . . . :A
			B: . . . . . . :B
			C: X . . . . . :C
			D: . . . . . . :D
			E: . . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			2. Enter row, column, quadrant, direction for O:
			A5 3R

			1  1 2 3 4 5 6  2
			-----------
			A: . . . . O . :A
			B: . . . . . . :B
			C: X . . . . . :C
			D: . . . . . . :D
			E: . . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			3. Enter row, column, quadrant, direction for X:
			C2 1r

			1  1 2 3 4 5 6  2
			-----------
			A: X . . . O . :A
			B: X . . . . . :B
			C: . . . . . . :C
			D: . . . . . . :D
			E: . . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			4. Enter row, column, quadrant, direction for O:
			b 6 4 l

			1  1 2 3 4 5 6  2
			-----------
			A: X . . . O . :A
			B: X . . . . O :B
			C: . . . . . . :C
			D: . . . . . . :D
			E: . . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			5. Enter row, column, quadrant, direction for X:
			c 53l

			1  1 2 3 4 5 6  2
			-----------
			A: X . . . O . :A
			B: X . . . . O :B
			C: . . . . X . :C
			D: . . . . . . :D
			E: . . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			6. Enter row, column, quadrant, direction for O:
			d6 3r

			1  1 2 3 4 5 6  2
			-----------
			A: X . . . O . :A
			B: X . . . . O :B
			C: . . . . X . :C
			D: . . . . . O :D
			E: . . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			7. Enter row, column, quadrant, direction for X:
			c41r

			1  1 2 3 4 5 6  2
			-----------
			A: . X X . O . :A
			B: . . . . . O :B
			C: . . . X X . :C
			D: . . . . . O :D
			E: . . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			8. Enter row, column, quadrant, direction for O:
			e14l

			1  1 2 3 4 5 6  2
			-----------
			A: . X X . O . :A
			B: . . . . . O :B
			C: . . . X X . :C
			D: . . . O . . :D
			E: O . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			9. Enter row, column, quadrant, direction for X:
			c6 2r

			1  1 2 3 4 5 6  2
			-----------
			A: . X X X . . :A
			B: . . . X . O :B
			C: . . . X O . :C
			D: . . . O . . :D
			E: O . . . . . :E
			F: . . . . . . :F
			-----------
			3  1 2 3 4 5 6  4

			10. Enter row, column, quadrant, direction for O:
			f2 3l
			O has won the game!

			1  1 2 3 4 5 6  2
			-----------
			A: . X X X . . :A
			B: . . . X . O :B
			C: . . . X O . :C
			D: . . . O . . :D
			E: . . O . . . :E
			F: . O . . . . :F
			-----------
			3  1 2 3 4 5 6  4
			Thanks for playing. Exiting...
			Press any key to continue . . .


*/

#include <stdio.h>
#include <ctype.h>				// ctype header needed for toupper() function
#include <string.h>				
#include <stdlib.h>
#pragma warning(disable:4996)	// disables the scanf warning
#define boardSize 37			// defining the BoardSize as 37 allocating enough room for the '\0' at the end


//-----------------------------------------------------------------------
void programInformation()
{
	printf("Author: Raul Telbisz\n");
	printf("Program: #3, Pentago\n");
	printf("TA: Moumita Samanta, Tues 11\n");
	printf("Feb 5, 2017\n");
	printf("\n");
}// end of programInformation()


//-----------------------------------------------------------------------
void programInstructions()
{
	printf("Play the two - player game of Pentago. Be the first to get 5 in a row.\n");
	printf("Pentago is played on a 6 by 6 board, divided into four 3 by 3\n");
	printf("quadrants.  There are two players, X and O, who alternate turns.\n");
	printf("The goal of each player is to get five of their pieces in a row,\n");
	printf("either horizontally, vertically, or diagonally.\n");
	printf("\n");

	printf("Players take turns placing one of their pieces into an empty\n");
	printf("space anywhere on the board, then choosing one of the four\n");
	printf("board quadrants to rotate 90 degrees left or right.\n");
	printf("\n");

	printf("If both players get five in a row at the same time, or the\n");
	printf("last move is played with no five in a row, the game is a tie.\n");
	printf("If a player makes five a row by placing a piece, there is no need\n");
	printf("to rotate a quadrant and the player wins immediately.\n");
	printf("\n");

	printf("Play online at:  https://perfect-pentago.net\n");
	printf("Purchase at:     www.mindtwisterusa.com\n");
	printf("\n");

	printf("For each move provide four inputs\n");
	printf(" row (A-F), column (1-6), quadrant (1-4), rotation direction (L or R)\n");
	printf("For instance input of B32R places the next piece at B3 and then\n");
	printf("would rotate quadrant 3 (lower-left) to the right (clockwise).\n");
	printf("\n");

	printf("At any point enter 'x' to exit the program.\n");
	printf("\n");
} // end of programInstructions()


//-----------------------------------------------------------------------
// Displays the updated board
void displayBoard(char gameBoard[])  // gameBoard[] is the array which holds all the pieces of the game as it progresses.
{
	char boardCharacter = 'A';  // This is letter to indicate the start of the row when we print the board.
								// The letter gets updated with each row for a total of 6 letters (A-F)
	int row    = 0; // Row looping variable
	int column = 0; // Column looping variable


	printf("\n");

	// Loop to populate the board with .'s
	for (row = 0; row < boardSize; row++) {
		if (gameBoard[row] == 'X') {         // If there is an X piece already in place on the board this statement 
			continue;						 // will cause the loop to skip past that spot
		}
		else if (gameBoard[row] == 'O') {	 // If there is an O piece already in place on the board this statement
			continue;						 // will cause the loop to skip past that spot
		}
		else {
			gameBoard[row] = '.';            // Rest of the board gets .
		}
	}

	gameBoard[36] = '\0'; // After the board is populated with their respective chars
						  // We end the string of characters with this NULL character to indicate the end of the array.


	printf("1  1 2 3 4 5 6  2\n"); // Prints the top half of the board.
	printf("   -----------   \n"); 

	// This loop prints out the up-to-date board beginning with the first row
	for (row = 0; row < 6; row++) {

		printf("%c: ", boardCharacter); // Prints the letter that begins each row
										// A: . . . .
										// B: . . . .
										// C: . . . .
										// and so on...

		// This loop populates the columns of the board	
		for (column = 0; column < 6; column++) {
			if (row == 0) {
				printf("%c ", gameBoard[column]);
			}
			else if (row == 1) {
				printf("%c ", gameBoard[column + 6]);
			}
			else if (row == 2) {
				printf("%c ", gameBoard[column + 12]);
			}
			else if (row == 3) {
				printf("%c ", gameBoard[column + 18]);
			}
			else if (row == 4) {
				printf("%c ", gameBoard[column + 24]);
			}
			else if (row == 5) {
				printf("%c ", gameBoard[column + 30]);
			}


		}// end of column loop


		printf(":%c ", boardCharacter);  // Prints the letter at the end of each row
		boardCharacter++;                // And then increments that letter for ever loop of the row
		printf("\n");                    // . . . . :A
										 // . . . . :B
										 // and so on...

		if (boardCharacter == 'G') { // This statement prevents 
			break;                   // the letters from passing 'F'
		}
	}// end of the row loop

	printf("   -----------   \n"); // Prints out the bottom of the board
	printf("3  1 2 3 4 5 6  4\n"); // along with quadrant numbers and column numbers.
} // end of displayBoard()


//-----------------------------------------------------------------------
//Rotates all pieces in the board based on the input of the user
//The argument directionRotation decides which direction the board will rotate
//The argument quadrantNumber indicates which quadrant of the board will be rotated
void rotateBoard(int quadrantNumber, char directionRotation, char gameBoard[])
{
	if ((quadrantNumber == 1) && (directionRotation == 'L')) { // 'L' direction indicates the board will rotate counter-clockwise
															   // quadrantNumber 1 indicates the first quadrant will rotate

		// As the board is rotated, temporary pieces are assigned to specific temporary variables
		 // Which hold whatever piece (X, O, or .) was initially in that place before the board is rotated. 
		char tempPiece1 = gameBoard[1];  // Temporary piece holder for the char value that was in gameboard[1]
		char tempPiece0 = gameBoard[0];  // Temporary piece holder for the char value that was in gameboard[0]
		char tempPiece6 = gameBoard[6];  // And so on..
		char tempPiece12 = gameBoard[12];

		gameBoard[0] = gameBoard[2];     // These assignments perform the
		gameBoard[1] = gameBoard[8];     // counter-clockwise rotation of the board
		gameBoard[2] = gameBoard[14];    // by assigning and reassigning values of the board
		gameBoard[6] = tempPiece1;       
		gameBoard[8] = gameBoard[13];	 
		gameBoard[12] = tempPiece0;		 
		gameBoard[13] = tempPiece6;      
		gameBoard[14] = tempPiece12;     
	}
	else if ((quadrantNumber == 1) && (directionRotation == 'R')) { // 'R' direction indicates the board will rotate clockwise

		// Necessary temp variables to hold initial game pieces prior to rotation
		char tempPiece0 = gameBoard[0];
		char tempPiece1 = gameBoard[1];
		char tempPiece2 = gameBoard[2];
		char tempPiece8 = gameBoard[8];

		// Rotation assignments and/or operations
		gameBoard[0] = gameBoard[12];
		gameBoard[1] = gameBoard[6];
		gameBoard[2] = tempPiece0;
		gameBoard[6] = gameBoard[13];
		gameBoard[8] = tempPiece1;
		gameBoard[12] = gameBoard[14];
		gameBoard[13] = tempPiece8;
		gameBoard[14] = tempPiece2;
	}
	else if ((quadrantNumber == 2) && (directionRotation == 'L')) { // Here the second quadrant is being rotated counter-clockwise


		char tempPiece3 = gameBoard[3];
		char tempPiece4 = gameBoard[4];
		char tempPiece9 = gameBoard[9];
		char tempPiece15 = gameBoard[15];

		gameBoard[3] = gameBoard[5];
		gameBoard[4] = gameBoard[11];
		gameBoard[5] = gameBoard[17];
		gameBoard[9] = tempPiece4;
		gameBoard[11] = gameBoard[16];
		gameBoard[15] = tempPiece3;
		gameBoard[16] = tempPiece9;
		gameBoard[17] = tempPiece15;
	}
	else if ((quadrantNumber == 2) && (directionRotation == 'R')) { // Second quadrant rotating clockwise

		char tempPiece3 = gameBoard[3];
		char tempPiece4 = gameBoard[4];
		char tempPiece5 = gameBoard[5];
		char tempPiece11 = gameBoard[11];

		gameBoard[3] = gameBoard[15];
		gameBoard[4] = gameBoard[9];
		gameBoard[5] = tempPiece3;
		gameBoard[9] = gameBoard[16];
		gameBoard[11] = tempPiece4;
		gameBoard[15] = gameBoard[17];
		gameBoard[16] = tempPiece11;
		gameBoard[17] = tempPiece5;
	}
	else if ((quadrantNumber == 3) && (directionRotation == 'L')) { // Third quadrant rotating counter-clockwise

		char tempPiece18 = gameBoard[18];
		char tempPiece19 = gameBoard[19];
		char tempPiece24 = gameBoard[24];
		char tempPiece30 = gameBoard[30];

		gameBoard[18] = gameBoard[20];
		gameBoard[19] = gameBoard[26];
		gameBoard[20] = gameBoard[32];
		gameBoard[24] = tempPiece19;
		gameBoard[26] = gameBoard[31];
		gameBoard[30] = tempPiece18;
		gameBoard[31] = tempPiece24;
		gameBoard[32] = tempPiece30;
	}
	else if ((quadrantNumber == 3) && (directionRotation == 'R')) { // Third quadrant rotation clockwise

		char tempPiece18 = gameBoard[18];
		char tempPiece19 = gameBoard[19];
		char tempPiece20 = gameBoard[20];
		char tempPiece26 = gameBoard[26];

		gameBoard[18] = gameBoard[30];
		gameBoard[19] = gameBoard[24];
		gameBoard[20] = tempPiece18;
		gameBoard[24] = gameBoard[31];
		gameBoard[26] = tempPiece19;
		gameBoard[30] = gameBoard[32];
		gameBoard[31] = tempPiece26;
		gameBoard[32] = tempPiece20;
	}
	else if ((quadrantNumber == 4) && (directionRotation == 'L')) { // Fourth quadrant. Counter-clockwise rotation

		char tempPiece21 = gameBoard[21];
		char tempPiece22 = gameBoard[22];
		char tempPiece27 = gameBoard[27];
		char tempPiece33 = gameBoard[33];

		gameBoard[21] = gameBoard[23];
		gameBoard[22] = gameBoard[29];
		gameBoard[23] = gameBoard[35];
		gameBoard[27] = tempPiece22;
		gameBoard[29] = gameBoard[34];
		gameBoard[30] = tempPiece21;
		gameBoard[31] = tempPiece27;
		gameBoard[32] = tempPiece33;
	}
	else if ((quadrantNumber == 4) && (directionRotation == 'R')) { // Fourth quadrant. Clockwise rotation

		char tempPiece21 = gameBoard[21];
		char tempPiece22 = gameBoard[22];
		char tempPiece23 = gameBoard[23];
		char tempPiece29 = gameBoard[29];

		gameBoard[21] = gameBoard[33];
		gameBoard[22] = gameBoard[27];
		gameBoard[23] = tempPiece21;
		gameBoard[27] = gameBoard[34];
		gameBoard[29] = tempPiece22;
		gameBoard[33] = gameBoard[35];
		gameBoard[34] = tempPiece29;
		gameBoard[35] = tempPiece23;
	}
} // end of rotateBoard()


//-----------------------------------------------------------------------
// Places pieces on the board. X or O. The piece which will be placed is indicated
// by the argument char pieceToPlace
void placePiece(char rowLetter, int columnNumber, char pieceToPlace, char gameBoard[])
{
	// Finds the location on the board based on the rowLetter (A-F)
	// And the columnNumber (1-6). Once the location is found
	// The piece is inserted in place of the '.'

	int column = 0; // Column variable to be looped
	int row    = 0; // Row variable to be looped
	int columnNumberCounter = 1; // Beginning column Number to be used in the loop to match user's destination
	char rowLetterCounter = 'A'; // Beginning row Letter to be used in the loop to match user's destination

	// Loops through every piece on the board beginning with the first row and first column
	// If the column does not match the user's column, the columnNumberCounter increments
	// If the row does not match the user's row, the rowLetterCounter increments
	// It keeps incrementing until a match is found
	for (column = 0; column < 36; column++) {
		if ((rowLetter == rowLetterCounter)) {
			if ((columnNumber == columnNumberCounter)) {
				gameBoard[row] = pieceToPlace;
			}
			else if ((columnNumber != columnNumberCounter)) {
				columnNumberCounter++;
				row++;
			}

		}
		else if ((rowLetter != rowLetterCounter)) {
			rowLetterCounter++;
			row += 6;
		}
	}

}// end of placePiece()


//-----------------------------------------------------------------------
// Verifies that a user's input is within the valid range of rows, columns, quadrants, and direction rotations
// If any of the inputs is invalid, the function prints an error message and returns a 0 invoking a reprompt
// for input from the user in main()
int verifyUserInput(char rowLetter, int columnNumber, int quadrantNumber, char directionRotation, char gameBoard[])
{
	int existingPieceReprompt = 5; // This is used later to determine whether or not the user is trying to place over an existing piece.

	existingPieceReprompt = checkForExistingPiece(rowLetter, columnNumber, gameBoard); // checkForExistingPiece is a function call that
																					   // assigns 0 to the variable existingPieceReprompt
																					   // if and only if the user tries to place a piece
																					   // over an exising piece

	if ((rowLetter < 'A') || (rowLetter > 'F')) { // Checks if the row accesed is out of bounds
		printf("*** Invalid move row.  Please retry.\n");
		return 0;
	}
	else if ((columnNumber < 1) || (columnNumber > 6)) { // Checks if the column accessed is out of bounds
		printf("*** Invalid move column.  Please retry.\n");
		return 0;
	}
	else if ((quadrantNumber < 1) || (quadrantNumber > 4)) { // Checks if the quadrant chosen is a valid one
		printf("*** Selected quadrant is invalid.  Please retry.\n");
		return 0;
	}
	else if ((directionRotation != 'L') && (directionRotation != 'R')) {		// Checks if the direction of the rotation is left or right
		printf("*** Quadrant rotation direction is invalid.  Please retry.\n"); // i.e. clockwise or counterclockwise.
		return 0;
	}
	else if (existingPieceReprompt == 0) { // Checks if there is an existing piece already in the specified location
		printf("*** Must move where there is an empty spot.\n");
		return 0;
	}

	return 1; // If none of the above criteria has been violated the function returns a 1 signaling
			  // that the user has chosen a valid destination for his piece.

}// end of verifyUserInput()



//-----------------------------------------------------------------------
// Scans the entire game board to find if there are five piecess in a row
// If a condition for a win, the integer 1 is returned. Otherwise if no win conditions for the piece are met, 0 is returned
int checkForWinner(char gameBoard[], char playerPiece)
{

	int row = 0;
	int column = 0;
	int pieceCounter = 0; // Counts number of consecutive pieces on the board

	// Checks all the horizontal positions on the board for five pieces in a row. 
	// Beginning with the left side and working its way right
	// The process works by "matching" the current piece with the previous horizontal piece. 
	// If it finds that the two pieces match
	// The counter is incremented by + 1
	for (row = 0; row < 36; row += 6) {
		for (column = 0; column < 6; column++) {
			if ((gameBoard[column + row] == gameBoard[column + row - 1]) && (gameBoard[column + row] == playerPiece)) {
				pieceCounter++;
				if (pieceCounter > 4) {
					return 1;
				}

			}
			else if (gameBoard[column + row] == playerPiece) {
				pieceCounter = 1;
			}
		}

		pieceCounter = 0;
	}

	// Checks all vertical positions on the board for five pieces in a row. Beginning with the top working its way down
	// The process works by "matching" the current piece with the previous vertical piece. If it finds that the two pieces match
	// The counter is incremented by + 1
	for (row = 0; row < 6; row++) {
		for (column = 0; column < 36; column += 6) {
			if ((gameBoard[row + column] == gameBoard[column + row - 6]) && (gameBoard[column + row] == playerPiece)) {
				pieceCounter++;
				if (pieceCounter > 4) {
					return 1;
				}

			}
			else if (gameBoard[column + row] == playerPiece) {
				pieceCounter = 1;
			}
		}

		pieceCounter = 0;
	}

	// Checks the diagonal locations beginning with the top left corner and working its way to the bottom right corner
	// The process works by "matching" the current piece with the left diagonal piece. If it finds that the two pieces match
	// The counter is incremented by + 1
	for (row = 0; row < 8; row++) {
		for (column = 0; column < 36; column += 7) {
			if ((gameBoard[row + column] == gameBoard[column + row - 7]) && (gameBoard[column + row] == playerPiece)) {
				pieceCounter++;
				if (pieceCounter > 4) {
					return 1;
				}

			}

			else if (gameBoard[column + row] == playerPiece) {
				pieceCounter = 1;
			}
		}

		pieceCounter = 0;
	}

	// Checks the diagonal locations beginning with the top right corner and working its way to the bottom left corner
	// The process works by "matching" the current piece with the previous right diagonal piece. If it finds that the two pieces match
	// The counter is incremented by + 1
	for (row = 4; row < 12; row++) {
		for (column = 0; column < 31; column += 5) {
			if ((gameBoard[row + column] == gameBoard[column + row - 5]) && (gameBoard[column + row] == playerPiece)) {
				pieceCounter++;
				if (pieceCounter > 4) {
					return 1;
				}
			}
			else if (gameBoard[column + row] == playerPiece) {
				pieceCounter = 1;
			}
		}

		pieceCounter = 0;

	}

	return 0; // Zero is returned if there are no 5 pieces in a row

}// end of checkForWinner()


 //-----------------------------------------------------------------------
 // Checks if there is an existing piece already in place of the user's desired destination
 // If a piece already is in place of the destination, the function prints an error message
 // and returns 0 to the main function, which causes a reprompt from the user for a valid input
int checkForExistingPiece(char rowLetter, int columnNumber, char gameBoard[])
{
	// rowLetter and columnNumber together can be though of as desired destination
	// Variable declarations for the 'for loop'
	int column = 0;
	int row    = 0;
	int columnNumberCounter = 1; // Initial column number for the board
	char rowLetterCounter = 'A'; // Beginning letter for the board to loop through as it finds the desired
								 // location for the user.

	// The following loop "loops" through each spot on the board searching for the destination the user specified.
	// if there is no empty spot or '.' char in the desired destination location, 
	// the function returns 0 to main, prompting new valid input from the user.
	for (column = 0; column < 36; column++) {
		if ((rowLetter == rowLetterCounter)) {
			if ((columnNumber == columnNumberCounter)) {
				if (gameBoard[row] != '.') {
					return 0;
				}
			}
			else if ((columnNumber != columnNumberCounter)) {
				columnNumberCounter++;
				row++;
			}

		}
		else if ((rowLetter != rowLetterCounter)) {
			rowLetterCounter++;
			row += 6;
		}
	}

	return 1; // If no violation has been committed, the function returns 1 for true

} // end of checkForExistingPiece()


//-----------------------------------------------------------------------
int main()
{
	char gameBoard[boardSize];      // Char Array of the size 37 for the playing board (plus a null character)
	char boardCharacter = 'A';		// Character at the beginning of each new row. Used as an indicator for the board.

	int row    = 0; // Row looping variable
	int column = 0; // Column looping variable

	char rowLetter;         // The letter for the row which the user wishes to place his/her piece
	int columnNumber   = 0; // The number for the column in which the user wishes to place his/her piece
	int quadrantNumber = 0; // The quadrant which the user wishes to rotate
	char directionRotation; // The direction in which the user wishes to rotate the specified quadrant

	int moveCounter         = 1;	// Counts the number of moves as the game progresses
	int continueOrTerminate = 0;    // Variable used in the do-while loop to determine if the user has chosen an invalid destination
	int isXaWinner          = 0;    // Variable that determines whether X is a winner or not
	int isOaWinner          = 0;    // Variable that determines whether O is a winner or not

						   // If isXaWinner returns a 1 and isOaWinner returns a 0, then x is declared the winner
						   // If isXaWinner returns a 0 and isOaWwinner returns a 1, then o is declared the winner
						   // If both isXaWinner and isOaWinner return 1, then
						   // the game is declared as a tie.

	programInformation();  // Displays program information
	programInstructions(); // Displays program instructions

	// This is the initial populating of the empty board array with .'s
	for (row = 0; row < boardSize; row++) {
		gameBoard[row] = '.';

	}

	// Null character is assigned at the end to indicate an end to the string. Without this, the board acts wrongly.
	gameBoard[36] = '\0';

	printf("\n");


	// Print the top half the board
	printf("1  1 2 3 4 5 6  2\n");
	printf("   -----------   \n");

	// Loop through each row, "stretching" the board array to look like an actual game board
	for (row = 0; row < 6; row++) {

		// Print the preceding row letter character                   // 1  1 2 3 4 5 6 2
		printf("%c: ", boardCharacter);                               //    -----------
																	  // A: . . . . . . :A      This is the result of the loops        
		// Loop through each column indicator creating columns		  // B: . . . . . . :B
		for (column = 0; column < 6; column++) {                      // C: . . . . . . :C
			printf("%c ", gameBoard[column]);                         // D: . . . . . . :D
		}                                                             // E: . . . . . . :E 
																	  // F: . . . . . . :F
		printf(":%c ", boardCharacter);								  //    -----------
																	  // 3  1 2 3 4 5 6 4
		boardCharacter++;
		printf("\n");
	}

	printf("   -----------   \n"); // Print the bottom of the board
	printf("3  1 2 3 4 5 6  4\n");

	// Do loop that continues to execute all program functions until 
	// 1. The user inputs 'x' which means quit the game OR
	// 2. A win condition is met                                         
	do {

		// Do loop that continues to prompt the user for a valid move until a valid move is made for X
		do {
			printf("\n");
			printf("%d. Enter row, column, quadrant, direction for X: \n", moveCounter);

			// Scanf statements that records each and every input by the user and stores it into assigned variables
			scanf(" %c", &rowLetter);
			scanf("%1d", &columnNumber);
			scanf("%1d", &quadrantNumber);
			scanf(" %c", &directionRotation);

			// Converts all cases of letter to uppercase to make the program run more smoothly
			rowLetter = toupper(rowLetter);
			directionRotation = toupper(directionRotation);

			// Check statement after every input to see if the first letter entered by the user is x for exit.
			if (rowLetter == 'X') {
				printf("User entered X. Exiting game!\n");
				exit(0);
			}

			// Function call to determine if the user entered valid input. If the input is invalid, continueOrTerminate
			// is assigned the value 0, which in turn reprompts the whole loop over and over again.
			continueOrTerminate = verifyUserInput(rowLetter, columnNumber, quadrantNumber, directionRotation, gameBoard);

		} while (continueOrTerminate == 0);

		// Once a valid move is verified, the placePiece function places the X piece of the user into the desired location
		placePiece(rowLetter, columnNumber, 'X', gameBoard);
		isXaWinner = checkForWinner(gameBoard, 'X'); // Statement checks after every input to determine if X is a winner
		isOaWinner = checkForWinner(gameBoard, 'O'); // Statement checks after every input to determine if O is a winner

		if ((isXaWinner + isOaWinner) == 2) { // If both isXaWinner and isOaWinner functions return 1, the game is a a tie
			printf("It's a tie game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}

		else if ((isXaWinner == 1) && (isOaWinner == 0)) { // If only isXaWinner returns 1, then X is declared the winner.
			printf("X has won the game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}
		else if ((isXaWinner == 0) && (isOaWinner == 1)) { // If only isOaWinner returns 1, then O is declared the winner.
			printf("O has won the game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}

		rotateBoard(quadrantNumber, directionRotation, gameBoard); // Rotates the board based on quadrant and direction
		isXaWinner = checkForWinner(gameBoard, 'X'); // Check if X is a winner after rotation
		isOaWinner = checkForWinner(gameBoard, 'O'); // Check if O is a winner after rotation

		if ((isXaWinner + isOaWinner) == 2) { // If both isXaWinner and isOaWinner functions return 1, the game is a a tie
			printf("It's a tie game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}

		else if ((isXaWinner == 1) && (isOaWinner == 0)) { // If only isXaWinner returns 1, then X is declared the winner.
			printf("X has won the game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}
		else if ((isXaWinner == 0) && (isOaWinner == 1)) { // If only isOaWinner returns 1, then O is declared the winner.
			printf("O has won the game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}

		// Display the board in preparation for the O's turn to move
		displayBoard(gameBoard);
		printf("\n");
		moveCounter++; // moveCounter is updated to keep track of how many rounds have passed

		// Do loop that continues to prompt the user for a valid move until a valid move is made for O
		do {
			printf("%d. Enter row, column, quadrant, direction for O: \n", moveCounter);

			// Scanf statements that records each and every input by the user and stores it into assigned variables
			scanf(" %c", &rowLetter);
			scanf("%1d", &columnNumber);
			scanf("%1d", &quadrantNumber);
			scanf(" %c", &directionRotation);

			rowLetter = toupper(rowLetter);                 // Convert all letters to uppercase to make
			directionRotation = toupper(directionRotation); // the program run more smoothly

			// Check statement after every input to see if the first letter entered by the user is x for exit.
			if (rowLetter == 'X') {
				printf("User has entered x! Exiting the game!\n");
				exit(0);
			}

			// Function call to determine if the user entered valid input. If the input is invalid, continueOrTerminate
			// is assigned the value 0, which in turn reprompts the whole loop over and over again.
			continueOrTerminate = verifyUserInput(rowLetter, columnNumber, quadrantNumber, directionRotation, gameBoard);

		} while (continueOrTerminate == 0);

		// Once a valid move is verified, the placePiece function places the O piece of the user into the desired location
		placePiece(rowLetter, columnNumber, 'O', gameBoard);
		isXaWinner = checkForWinner(gameBoard, 'X'); // Checks if X is a winner
		isOaWinner = checkForWinner(gameBoard, 'O'); // Checks if O is a winner

		if ((isXaWinner + isOaWinner) == 2) { // Checks if both X and O are winners resulting in a tie
			printf("It's a tie game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}

		else if ((isXaWinner == 1) && (isOaWinner == 0)) { // Checks if only X is a winner
			printf("X has won the game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}
		else if ((isXaWinner == 0) && (isOaWinner == 1)) { // Checks if only O is a winner
			printf("O has won the game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}

		// Rotates the board based on quadrant and direction
		rotateBoard(quadrantNumber, directionRotation, gameBoard);
		isXaWinner = checkForWinner(gameBoard, 'X'); // Checks if X is a winner after rotation
		isOaWinner = checkForWinner(gameBoard, 'O'); // Checks if O is a winner after rotation

		if ((isXaWinner + isOaWinner) == 2) { // Checks if the game is a tie after rotation
			printf("It's a tie game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}

		else if ((isXaWinner == 1) && (isOaWinner == 0)) { // Checks if X is a winner after rotation
			printf("X has won the game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}
		else if ((isXaWinner == 0) && (isOaWinner == 1)) { //Checks if O is a winner after rotation
			printf("O has won the game!\n");
			displayBoard(gameBoard);
			printf("Thanks for playing. Exiting...\n");
			exit(0);
		}

		// Displays the board in its current status
		displayBoard(gameBoard);
		moveCounter++; // Updates the number of moves that have passed

	} while (rowLetter != 'X');
	//end of outer do-while loop


	return 0;
}// end of main()

