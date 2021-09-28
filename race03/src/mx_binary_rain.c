#include "../inc/header.h"

void mx_binary_rain() {
        initscr();
        curs_set(0);

        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK); 
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK); 
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);

        int sizes_str[COLS];
	int str_x[COLS];
	int str_dx[COLS];

	for (int i = 0; i < COLS; i++) {
		str_x[i] =  -1 * (rand() % 80);
		str_dx[i] = str_x[i];
		sizes_str[i] = rand() % (LINES - 5) + 5;
	}

	int choise_color = 1;
	int speed = 100;

        while (1) {
                for (int i = 0; i < COLS; i += 2) {
                        attron(COLOR_PAIR(7));
                        mvprintw(str_dx[i] + 1, i, "%i", rand() % 2);
                        attroff(COLOR_PAIR(7));

                        attron(COLOR_PAIR(choise_color));
                        mvprintw(str_dx[i], i, "%i", rand() % 2);
                        attroff(COLOR_PAIR(choise_color));

                        attron(COLOR_PAIR(7));
                        mvaddch(str_dx[i] - sizes_str[i], i, ' ');
                        attroff(COLOR_PAIR(7));

                        if (str_dx[i] - sizes_str[i] > LINES) {
                                str_dx[i] = str_x[i];
                        }

                        str_dx[i]++;
                }
                usleep(1000 * speed);
                nodelay(stdscr,TRUE);
                noecho();

                char ch = getch();
                if (ch == 'q') {
                        clear();
                        break;
                }


                if (mx_isdigit(ch)) {
                        choise_color = ch - 48;
                }

                if (ch == '+') {
                        if (speed > 1) {
                                if (speed <= 11)
                                        speed--;
                                else
                                        speed -= 5;

                        }
                }

                if (ch == '-') {
                        if (speed < 300) {
                                if (speed <= 10)
                                        speed++;
                                else
                                        speed += 5;
                        }
                }

                refresh();
        }

        endwin();
}

