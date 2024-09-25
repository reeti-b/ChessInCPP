a.out: chess.o board.h move.h validMoves.h
	gcc -g -Wall -Werror -o a.out chess.o 

chess.o: chess.c board.c board.h move.c move.h validMoves.c validMoves.h
	gcc -g -Wall -Werror -c -o chess.o chess.c

board.o: board.c board.h
	gcc -g -Wall -Werror -c -o board.o board.c

move.o: move.c board.h move.h
	gcc -g -Wall -Werror -c -o move.o move.c

validMoves.o: validMoves.c board.h move.h validMoves.h
	gcc -g -Wall -Werror -c -o validMoves.o validMoves.c