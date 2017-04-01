#include <iostream>
#include <string.h>
#include "TicTacToe.h"
#include "NewGame.h"

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string game = argv[1];
        if (game == "TicTacToe") {
            TicTacToe* g = new TicTacToe();
            g->startGame();
        }
        else if (game == "TicTacNo") {
            NewGame* g = new NewGame();
            g->startGame();
        }
        return 0;
    }
    std::cerr << "Please use 'TicTacToe' or 'TicTacNo' as an argument\n";
    exit(1);
}