// TicTacToe.cpp
// Simple console Tic-Tac-Toe with 1-player (Minimax AI) and 2-player mode.
// Should compile in Dev-C++ (use default C++ compiler settings).

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3];

void initBoard() {
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            board[r][c] = ' ';
}

void printBoard() {
    system("cls"); // clears console on Windows (Dev-C++)
    cout << "\n  Tic-Tac-Toe\n\n";
    cout << "     1   2   3\n";
    for (int r = 0; r < 3; ++r) {
        cout << "   -------------\n";
        cout << " " << r+1 << " |";
        for (int c = 0; c < 3; ++c) {
            cout << " " << board[r][c] << " |";
        }
        cout << "\n";
    }
    cout << "   -------------\n\n";
}

bool isMovesLeft() {
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            if (board[r][c] == ' ')
                return true;
    return false;
}

int evaluate() {
    // Rows
    for (int r = 0; r < 3; ++r) {
        if (board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
            if (board[r][0] == 'O') return +10;
            else if (board[r][0] == 'X') return -10;
        }
    }
    // Columns
    for (int c = 0; c < 3; ++c) {
        if (board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
            if (board[0][c] == 'O') return +10;
            else if (board[0][c] == 'X') return -10;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O') return +10;
        else if (board[0][0] == 'X') return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'O') return +10;
        else if (board[0][2] == 'X') return -10;
    }
    return 0;
}

int minimax(int depth, bool isMax) {
    int score = evaluate();

    if (score == 10) return score - depth; // prefer faster wins
    if (score == -10) return score + depth; // prefer slower losses
    if (!isMovesLeft()) return 0;

    if (isMax) {
        int best = std::numeric_limits<int>::min();
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board[r][c] == ' ') {
                    board[r][c] = 'O';
                    best = max(best, minimax(depth + 1, false));
                    board[r][c] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = std::numeric_limits<int>::max();
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board[r][c] == ' ') {
                    board[r][c] = 'X';
                    best = min(best, minimax(depth + 1, true));
                    board[r][c] = ' ';
                }
            }
        }
        return best;
    }
}

pair<int,int> findBestMove() {
    int bestVal = std::numeric_limits<int>::min();
    pair<int,int> bestMove = {-1, -1};

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board[r][c] == ' ') {
                board[r][c] = 'O';
                int moveVal = minimax(0, false);
                board[r][c] = ' ';
                if (moveVal > bestVal) {
                    bestMove = {r, c};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

bool checkWin(char &winner) {
    int score = evaluate();
    if (score == 10) { winner = 'O'; return true; }
    if (score == -10) { winner = 'X'; return true; }
    if (!isMovesLeft()) { winner = ' '; return true; } // draw
    return false;
}

void playerMove(char player) {
    int r, c;
    while (true) {
        cout << "Player " << player << " move (row col): ";
        if (!(cin >> r >> c)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter two numbers like: 1 3\n";
            continue;
        }
        if (r < 1 || r > 3 || c < 1 || c > 3) {
            cout << "Rows and columns must be between 1 and 3.\n";
            continue;
        }
        if (board[r-1][c-1] != ' ') {
            cout << "That cell is already taken. Choose another.\n";
            continue;
        }
        board[r-1][c-1] = player;
        break;
    }
}

int main() {
    srand((unsigned)time(0));
    initBoard();

    cout << "Tic-Tac-Toe for Dev-C++\n";
    cout << "1 - Single player (you vs computer)\n";
    cout << "2 - Two player\n";
    cout << "Choose mode (1 or 2): ";
    int mode;
    while (!(cin >> mode) || (mode != 1 && mode != 2)) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter 1 or 2: ";
    }

    char winner = ' ';
    // X is human, O is computer (if single player)
    bool humanTurn = true; // X starts
    while (true) {
        printBoard();
        if (mode == 2) {
            // Two-player
            char current = humanTurn ? 'X' : 'O';
            cout << "Turn: Player " << current << "\n";
            playerMove(current);
        } else {
            // Single-player
            if (humanTurn) {
                cout << "Your turn (X).\n";
                playerMove('X');
            } else {
                cout << "Computer is thinking...\n";
                pair<int,int> mv = findBestMove();
                // If findBestMove returns -1 (shouldn't happen), pick random
                if (mv.first == -1) {
                    vector<pair<int,int>> moves;
                    for (int r = 0; r < 3; ++r)
                        for (int c = 0; c < 3; ++c)
                            if (board[r][c] == ' ') moves.push_back({r,c});
                    if (!moves.empty()) mv = moves[rand() % moves.size()];
                }
                board[mv.first][mv.second] = 'O';
            }
        }

        if (checkWin(winner)) {
            printBoard();
            if (winner == 'X') cout << "Player X wins!\n";
            else if (winner == 'O') cout << (mode==1 ? "Computer wins!\n" : "Player O wins!\n");
            else cout << "It's a draw!\n";
            break;
        }

        humanTurn = !humanTurn;
    }

    cout << "Game over. Press Enter to exit.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}
