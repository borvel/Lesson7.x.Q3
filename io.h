#ifndef IO_H
#define IO_H

int input_guess(const int guess_number);
void print_end_game(bool result, int winning_num);
bool play_again();
void print_lower();
void print_higher();
void print_welcome();
void ignore_line();

#endif