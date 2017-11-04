README

CIS*3250 Software Design III | Section 2, Group 3

The purpose of this program is to simulate a game of boggle, where the user is 
prompted to find a word that is made of of adjacent letters in a sequence. If
the user is correct, the score is updated and the length of the inputted word is
displayed.

There are four source files each with their corresponding header files that
handle the gameplay functionality behind-the-scenes. There is also another
source file that contains the main method of the program. Below, a brief
description of each source file's purpose is available.

boardGenerator.c  -  The source file containing the mutator functions necessary for generating a boggle board (using virtually randomized “dice" rolls), as well as accessor functions that visualize this board.

dictionary.c  -  The source file that generates hash values for dictionary words (using the data in "EnglishWords.txt" file) and also contains functions to search (starting at an appropriate location given a hash value), copy strings, and free memory for dictionary-related components.

scoreboard.c  -  The source file containing the accessor and mutator functions that find and retrieve users based on name and index, validate users exist in the singly-linked list of users, verify the amount of user's in the list of users, and display scoreboard and free memory for scoreboard components.

wordChecker.c  -  The source file containing the accessor functions to validate that the attempted inputted word by the user is on the boggle board and abides by the rules of boggle. The functions do not change values of any components, they simply access the given values.

boggle.c  -  The source file containing the main method of the program. This file handles file I/O, and calls upon the accessor and mutator functions in the other files (above) to simulate a boggle game.

Instructions:
Ensure you are in the directory the files are contained in. Once in said directory, type "make".
This will compile the program and create an executable called "program" in the
root directory. You can access this executable by entering "./program" to run
the executable. To remove the executable (if it exists), enter "make clean".
