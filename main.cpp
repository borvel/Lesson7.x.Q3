#include "io.h"
#include "numbers.h"

int main()
{
    print_welcome();
    bool running{ true };
   

    while (running)
    {
        int winning_num{ Random::get(1,100) };
        bool lost{ false };
        for (int iii{ 1 }; iii < 8; ++iii)
        {
            int guessed_number = input_guess(iii);
            switch (compare(guessed_number, winning_num))
            {
            case 2:
                print_end_game(true, winning_num);
                if (play_again())
                {
                    iii = 0;
                    winning_num = Random::get(1, 100);
                    break;
                }
                else
                {
                    running = false;
                    iii = 8;
                    break;
                }
            case 1: 
                print_higher();
                break;
            case 0: 
                print_lower();
                break;
            }

            if (iii == 7 && guessed_number != winning_num)
            {
                print_end_game(false, winning_num);
                if (play_again())
                {
                    iii = 0;
                    winning_num = Random::get(1, 100);
                }
                else running = false;
            }
        }
    }
}
