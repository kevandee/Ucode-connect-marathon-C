#include "header.h"

int main(int argc, char *argv[]) {
    if (argc > 2) {
        mx_printerr("usage: ./matrix_rain [-s] [-b] [-c] [-u] [-j]\n");
        exit(-1);
    }

    if (argc == 1) {
        mx_screen();
        mx_rain();
    }
    else if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'b') {
            mx_binary_rain();
        }
        if (argv[1][0] == '-' && argv[1][1] == 's') {
            mx_rain();
        }
        if (argv[1][0] == '-' && argv[1][1] == 'c') {
            mx_rain_colors();
        }
        if (argv[1][0] == '-' && argv[1][1] == 'u') {
            setlocale(LC_ALL, "uk_UA.UTF-8");
            mx_rain_ukr();
        }
        if (argv[1][0] == '-' && argv[1][1] == 'j') {
            setlocale(LC_ALL, "ja_JP.UTF-8");
            mx_rain_jap();
        }
        else {
            mx_printerr("usage: ./matrix_rain [-s] [-b] [-c]\n");
            exit(-1);
        }
    }

}
