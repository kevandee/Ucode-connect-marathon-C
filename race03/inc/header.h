#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include <locale.h>

void mx_screen();
void mx_rain();
void mx_binary_rain();
void mx_rain_colors();
void mx_rain_ukr();
void mx_rain_jap();
bool mx_isdigit(int);
void mx_printerr(const char *);
int mx_strlen(const char *);

#endif
