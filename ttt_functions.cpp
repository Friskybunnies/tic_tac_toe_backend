#include <iostream>
#include "ttt_functions.hpp"
#include <vector>
#include <string>

// -------- VARIABLES AND CONSTANTS --------

std::vector<std::string> gridHeader = {" ", "1", " ", " ", " ", "2", " ", " ", " ", "3"};
std::vector<std::string> gridRow1 = {"A", " ", " ", "|", " ", " ", " ", "|", " ", " "};
std::vector<std::string> gridRow2 = {" ", "_", " ", " ", " ", "_", " ", " ", " ", "_"};
std::vector<std::string> gridRow3 = {"B", " ", " ", "|", " ", " ", " ", "|", " ", " "};
std::vector<std::string> gridRow4 = {" ", "_", " ", " ", " ", "_", " ", " ", " ", "_"};
std::vector<std::string> gridRow5 = {"C", " ", " ", "|", " ", " ", " ", "|", " ", " "};
std::vector<std::string> moves = {"1A", "1B", "1C", "2A", "2B", "2C", "3A", "3B", "3C"}; 
std::vector<std::string> remaining_moves = {"1A", "1B", "1C", "2A", "2B", "2C", "3A", "3B", "3C"};
std::string player1;
std::string player2;
std::string player;
std::string player1_symbol;
std::string player2_symbol;
std::string player_symbol;
int turn = 0;
std::string winner;
std::string next_move;
bool is_unvalidated = true;

// -------- GAME LOGIC --------

void opening() {
    std::cout << "\n\n\nPlayer 1, please enter your name: ";
    std::cin >> player1;
    std::cout << "\n";
    std::cout << "Player 1, please enter your player symbol: ";
    std::cin >> player1_symbol;
    player1_symbol = player1_symbol[0];
    std::cout << "\n\n  >>  Thanks, " << player1 << "." << " Your symbol is: " << player1_symbol << "\n\n";
    std::cout << "\n";
    std::cout << "Player 2, please enter your name: ";
    std::cin >> player2;
    std::cout << "\n";
    std::cout << "Player 2, please enter your player symbol: ";
    std::cin >> player2_symbol;
    player2_symbol = player2_symbol[0];
    while (player2_symbol == player1_symbol) {
        std::cout << "That symbol is already taken. Please enter a different symbol: ";
        std::cin >> player2_symbol;
        player2_symbol = player2_symbol[0];
    }
    if (player2 == player1) {
        player2 = player2 + " #2";
    }
    std::cout << "\n\n  >>  Thanks, " << player2 << "." << " Your symbol is: " << player2_symbol << "\n\n";
    std::cout << "\n\n";
    player = player1;
    player_symbol = player1_symbol;
}

void print_grid() {
    std::cout << "\n";
    for (int i = 0; i < gridHeader.size(); i++) {
        std::cout << gridHeader[i];
    }
    std::cout << "\n";
        for (int i = 0; i < gridRow1.size(); i++) {
        std::cout << gridRow1[i];
    }
    std::cout << "\n";
        for (int i = 0; i < gridRow2.size(); i++) {
        std::cout << gridRow2[i];
    }
    std::cout << "\n";
        for (int i = 0; i < gridRow3.size(); i++) {
        std::cout << gridRow3[i];
    }
    std::cout << "\n";
        for (int i = 0; i < gridRow4.size(); i++) {
        std::cout << gridRow4[i];
    }
    std::cout << "\n";
        for (int i = 0; i < gridRow5.size(); i++) {
        std::cout << gridRow5[i];
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
}

void update_grid(std::string player_move) {
    if (player_move == "1A") {
        gridRow1[1] = player_symbol;
    } else if (player_move == "1B") {
        gridRow3[1] = player_symbol;
    } else if (player_move == "1C") {
        gridRow5[1] = player_symbol;
    } else if (player_move == "2A") {
        gridRow1[5] = player_symbol;
    } else if (player_move == "2B") {
        gridRow3[5] = player_symbol;
    } else if (player_move == "2C") {
        gridRow5[5] = player_symbol;
    } else if (player_move == "3A") {
        gridRow1[9] = player_symbol;
    } else if (player_move == "3B") {
        gridRow3[9] = player_symbol;
    } else {
        gridRow5[9] = player_symbol;
    }
}

int check_for_winner() {
    if (
        moves[0] == player1_symbol && moves[1] == player1_symbol && moves[2] == player1_symbol ||
        moves[3] == player1_symbol && moves[4] == player1_symbol && moves[5] == player1_symbol ||
        moves[6] == player1_symbol && moves[7] == player1_symbol && moves[8] == player1_symbol ||
        moves[0] == player1_symbol && moves[3] == player1_symbol && moves[6] == player1_symbol ||
        moves[1] == player1_symbol && moves[4] == player1_symbol && moves[7] == player1_symbol ||
        moves[2] == player1_symbol && moves[5] == player1_symbol && moves[8] == player1_symbol ||
        moves[0] == player1_symbol && moves[4] == player1_symbol && moves[8] == player1_symbol ||
        moves[2] == player1_symbol && moves[4] == player1_symbol && moves[6] == player1_symbol 
        ) {
            winner = player1;
            for (int i = 0; i < winner.size(); i++) {
                winner[i] = toupper(winner[i]);
            }
            std::cout << "\n\n\n\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            std::cout << "        " << winner << " HAS WON THE GAME!\n";
            std::cout << "        " << winner << " HAS WON THE GAME!\n";
            std::cout << "        " << winner << " HAS WON THE GAME!\n\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n\n";
            std::cout << "WINNING GRID:\n";
            std::cout << "-------------\n\n";
            print_grid();
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n\n\n\n\n\n\n\n";
            return 0;
    } else if (
        moves[0] == player2_symbol && moves[1] == player2_symbol && moves[2] == player2_symbol ||
        moves[3] == player2_symbol && moves[4] == player2_symbol && moves[5] == player2_symbol ||
        moves[6] == player2_symbol && moves[7] == player2_symbol && moves[8] == player2_symbol ||
        moves[0] == player2_symbol && moves[3] == player2_symbol && moves[6] == player2_symbol ||
        moves[1] == player2_symbol && moves[4] == player2_symbol && moves[7] == player2_symbol ||
        moves[2] == player2_symbol && moves[5] == player2_symbol && moves[8] == player2_symbol ||
        moves[0] == player2_symbol && moves[4] == player2_symbol && moves[8] == player2_symbol ||
        moves[2] == player2_symbol && moves[4] == player2_symbol && moves[6] == player2_symbol
        ) {
            winner = player2;
            for (int i = 0; i < winner.size(); i++) {
                winner[i] = toupper(winner[i]);
            }
            std::cout << "\n\n\n\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            std::cout << "        " << winner << " HAS WON THE GAME!\n";
            std::cout << "        " << winner << " HAS WON THE GAME!\n";
            std::cout << "        " << winner << " HAS WON THE GAME!\n\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n\n";
            std::cout << "WINNING GRID:\n";
            std::cout << "-------------\n\n";
            print_grid();
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n\n\n\n\n\n\n\n";
            return 0;
    } else {
        return 1;
    }
}  

int play_game() {

    // Player chooses where to move next

    while (winner != player1 || winner != player2) { 
        std::cout << player << " (" << player_symbol << "), it is your turn.\n\n";
        std::cout << "Please enter your next move from the remaining spaces:    ";
        for (int i = 0; i < remaining_moves.size(); i++) {
            std::cout << remaining_moves[i] << "   ";
        }
        std::cout << "\n";
        print_grid();
        std::cin >> next_move;
        
        // Validation that the entry is sensical

        while (is_unvalidated) {
            for (int i = 0; i < remaining_moves.size(); i++) {
                if (remaining_moves[i] == next_move) {
                    is_unvalidated = false;
                    break;
                }
            }
            if (is_unvalidated) {
                std::cout << "\n\nThat entry was incorrect. Please re-enter your next move.\n\n";
                std::cin >> next_move;
            }
        }
        is_unvalidated = true;
        
        // Keeping record of gameplay and possible options within vectors

        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == next_move) {
                moves[i] = player_symbol;
            }
        }
        for (int i = 0; i < remaining_moves.size(); i++) {
            if (remaining_moves[i] == next_move) {
                for (int j = i; j < remaining_moves.size(); j++) {
                    remaining_moves[j] = remaining_moves[j+1];
                }
            }
        }

        // If there is a tie, gameplay stops

        if (remaining_moves[0] == "") {
            std::cout << "\n\n\n\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            std::cout << "    THERE IS A TIE. THE GAME CANNOT BE WON\n";
            std::cout << "    THERE IS A TIE. THE GAME CANNOT BE WON\n";
            std::cout << "    THERE IS A TIE. THE GAME CANNOT BE WON\n\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n\n";
            std::cout << "FINAL GRID:\n";
            std::cout << "-------------\n\n";
            update_grid(next_move);
            print_grid();
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n";
            std::cout << "//////////////////////////////////////////\n\n\n\n\n\n\n\n";
            return 0;
        }

        // Wrapping up before next player's turn
        
        update_grid(next_move);
        if (check_for_winner() == 0) {
            return 0;
        }

        std::cout << "\n\nThanks " << player << ", your turn is ended.\n\n";
        std::cout << "==============================================\n\n";

        if (turn % 2 == 1) {
            player = player1;
            player_symbol = player1_symbol;
        } else {
            player = player2;
            player_symbol = player2_symbol;
        }
        turn++;

    }
    return 0;
}



