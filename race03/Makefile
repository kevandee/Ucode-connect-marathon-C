flags := -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses
name := matrix_rain

all: MINILIBMX

MINILIBMX:
	clang $(flags) -Iinc -o $(name) src/*.c

clean:
	rm -f $(name)

uninstall:
	rm -f $(name)

reinstall:
	make uninstall
	make
