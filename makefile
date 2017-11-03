CC = gcc
CFLAGS = -Wall -std=c99

program:
	$(CC) $(CFLAGS) boardGenerator.c boggle.c dictionary.c scoreboard.c wordChecker.c -o program

cls:
	clear

clean:
	$(RM) program
