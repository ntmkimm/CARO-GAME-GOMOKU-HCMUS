
#include "Ai.h"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>


using namespace std;


void set_game(_POINT board[][BOARD_SIZE + 2]) {
    for (int i = 0; i < BOARD_SIZE + 2; i++) {
        for (int j = 0; j < BOARD_SIZE + 2; j++) {
            if (i == 0 || i == BOARD_SIZE + 2 - 1 || j == 0 || j == BOARD_SIZE + 2 - 1) {
                board[i][j].c = 2;
            }
            else {
                board[i][j].c = 0;
            }
        }
    }
}


void make_move(_POINT board[][BOARD_SIZE + 2], int x, int y, bool turn) {
    board[x][y].c = turn ? 1 : -1;
}

int win_check(_POINT board[][BOARD_SIZE + 2]) {
    const int WINNING_LENGTH = 5;

    for (int i = 1; i < BOARD_SIZE + 2 - 1; i++) {
        for (int j = 1; j < BOARD_SIZE + 2 - WINNING_LENGTH + 1; j++) {
            if (board[i][j].c != 0 &&
                board[i][j].c == board[i][j + 1].c &&
                board[i][j].c == board[i][j + 2].c &&
                board[i][j].c == board[i][j + 3].c &&
                board[i][j].c == board[i][j + 4].c) {
                return board[i][j].c;
            }
        }
    }

    for (int i = 1; i < BOARD_SIZE + 2 - WINNING_LENGTH + 1; i++) {
        for (int j = 1; j < BOARD_SIZE + 2 - 1; j++) {
            if (board[i][j].c != 0 &&
                board[i][j].c == board[i + 1][j].c &&
                board[i][j].c == board[i + 2][j].c &&
                board[i][j].c == board[i + 3][j].c &&
                board[i][j].c == board[i + 4][j].c) {
                return board[i][j].c;
            }
        }
    }

    for (int i = 1; i < BOARD_SIZE + 2 - WINNING_LENGTH + 1; i++) {
        for (int j = 1; j < BOARD_SIZE + 2 - WINNING_LENGTH + 1; j++) {
            if (board[i][j].c != 0 &&
                board[i][j].c == board[i + 1][j + 1].c &&
                board[i][j].c == board[i + 2][j + 2].c &&
                board[i][j].c == board[i + 3][j + 3].c &&
                board[i][j].c == board[i + 4][j + 4].c) {
                return board[i][j].c;
            }
        }
    }

    for (int i = 4; i < BOARD_SIZE + 2 - 1; i++) {
        for (int j = 1; j < BOARD_SIZE + 2 - WINNING_LENGTH + 1; j++) {
            if (board[i][j].c != 0 &&
                board[i][j].c == board[i - 1][j + 1].c &&
                board[i][j].c == board[i - 2][j + 2].c &&
                board[i][j].c == board[i - 3][j + 3].c &&
                board[i][j].c == board[i - 4][j + 4].c) {
                return board[i][j].c;
            }
        }
    }
    return 0; // No winner
}


int evaluation(_POINT board[][BOARD_SIZE + 2]) {
    const int WINNING_LENGTH = 5;
    int score = 0;

    // Đánh giá cho các chuỗi 3 và 4 liên tiếp
    for (int i = 1; i < BOARD_SIZE + 2 - WINNING_LENGTH + 1; i++) {
        for (int j = 1; j < BOARD_SIZE + 2 - WINNING_LENGTH + 1; j++) {
            // Kiểm tra hàng ngang
            if (board[i][j].c != 0) {
                if (board[i][j].c == board[i][j + 1].c &&
                    board[i][j].c == board[i][j + 2].c) {
                    if (board[i][j + 3].c == board[i][j + 4].c) { // 4 liên tiếp
                        if (board[i][j - 1].c == 0 && board[i][j + 5].c == 0) {
                            score += (board[i][j].c == 1) ? 1000 : -1000;
                        }
                        else if (board[i][j - 1].c == 0 || board[i][j + 5].c == 0) {
                            score += (board[i][j].c == 1) ? 500 : -500;
                        }
                    }
                    else if (board[i][j + 3].c == 0 && board[i][j + 4].c == 0) { // 3 liên tiếp
                        score += (board[i][j].c == 1) ? 100 : -100;
                    }

                    //TEST CODE=================================================
                    else if (board[i][j + 3].c == 0 || board[i][j + 4].c == 0) { // 3 liên tiếp
                        score += (board[i][j].c == 1) ? 30 : -30;
                    }
                    //TEST CODE=================================================
                }

                // Kiểm tra hàng dọc
                if (board[i][j].c == board[i + 1][j].c &&
                    board[i][j].c == board[i + 2][j].c) {
                    if (board[i + 3][j].c == board[i + 4][j].c) { // 4 liên tiếp
                        if (board[i - 1][j].c == 0 && board[i + 5][j].c == 0) {
                            score += (board[i][j].c == 1) ? 1000 : -1000;
                        }
                        else if (board[i - 1][j].c == 0 || board[i + 5][j].c == 0) {
                            score += (board[i][j].c == 1) ? 500 : -500;
                        }
                    }
                    else if (board[i + 3][j].c == 0 && board[i + 4][j].c == 0) { // 3 liên tiếp
                        score += (board[i][j].c == 1) ? 100 : -100;
                    }

                    //TEST CODE=================================================
                    else if (board[i + 3][j].c == 0 || board[i + 4][j].c == 0) { // 3 liên tiếp
                        score += (board[i][j].c == 1) ? 30 : -30;
                    }
                    //TEST CODE=================================================
                }

                // Kiểm tra chéo chính
                if (board[i][j].c == board[i + 1][j + 1].c &&
                    board[i][j].c == board[i + 2][j + 2].c) {
                    if (board[i + 3][j + 3].c == board[i + 4][j + 4].c) { // 4 liên tiếp
                        if (board[i - 1][j - 1].c == 0 && board[i + 5][j + 5].c == 0) {
                            score += (board[i][j].c == 1) ? 1000 : -1000;
                        }
                        else if (board[i - 1][j - 1].c == 0 || board[i + 5][j + 5].c == 0) {
                            score += (board[i][j].c == 1) ? 500 : -500;
                        }
                    }
                    else if (board[i + 3][j + 3].c == 0 && board[i + 4][j + 4].c == 0) { // 3 liên tiếp
                        score += (board[i][j].c == 1) ? 100 : -100;
                    }

                    else if (board[i + 3][j + 3].c == 0 || board[i + 4][j + 4].c == 0) { // 3 liên tiếp
                        score += (board[i][j].c == 1) ? 30 : -30;
                    }
                }

                // Kiểm tra chéo phụ
                if (board[i][j].c == board[i - 1][j + 1].c &&
                    board[i][j].c == board[i - 2][j + 2].c) {
                    if (board[i - 3][j + 3].c == board[i - 4][j + 4].c) { // 4 liên tiếp
                        if (board[i + 1][j - 1].c == 0 && board[i - 5][j + 5].c == 0) {
                            score += (board[i][j].c == 1) ? 1000 : -1000;
                        }
                        else if (board[i + 1][j - 1].c == 0 || board[i - 5][j + 5].c == 0) {
                            score += (board[i][j].c == 1) ? 500 : -500;
                        }
                    }
                    else if (board[i - 3][j + 3].c == 0 && board[i - 4][j + 4].c == 0) { // 3 liên tiếp
                        score += (board[i][j].c == 1) ? 100 : -100;
                    }

                    else if (board[i - 3][j + 3].c == 0 || board[i - 4][j + 4].c == 0) { // 3 liên tiếp
                        score += (board[i][j].c == 1) ? 30 : -30;
                    }
                }
            }
        }
    }
    return score;
}



bool on_border_check(_POINT board[][BOARD_SIZE + 2], int x, int y) {
    int radius = 1;
    for (int i = x - radius; i <= x + radius; i++) {
        for (int j = y - radius; j <= y + radius; j++) {
            if (board[i][j].c == 1 || board[i][j].c == -1) return true;
        }
    }
    return false;
}

int minimax(_POINT board[][BOARD_SIZE + 2], bool turn, int depth, int alpha, int beta, int& count) {
    int score;
    int temp = win_check(board);
    if (temp != 0 || depth == 0) {
        if (temp == 1) return 100000000;
        if (temp == -1) return -100000000;
        return evaluation(board);
    }

    if (turn) {
        score = -INT_MAX;
        for (int i = 1; i < BOARD_SIZE + 2 - 1; i++) {
            for (int j = 1; j < BOARD_SIZE + 2 - 1; j++) {
                if (on_border_check(board, i, j) && board[i][j].c == 0) {
                    board[i][j].c = 1;
                    count++;
                    score = max(score, minimax(board, !turn, depth - 1, alpha, beta, count));
                    board[i][j].c = 0;
                    alpha = max(alpha, score);
                    if (beta <= alpha) return score;
                }
            }
        }
    }
    else {
        score = INT_MAX;
        for (int i = 1; i < BOARD_SIZE + 2 - 1; i++) {
            for (int j = 1; j < BOARD_SIZE + 2 - 1; j++) {
                if (on_border_check(board, i, j) && board[i][j].c == 0) {
                    board[i][j].c = -1;
                    count++;
                    score = min(score, minimax(board, !turn, depth - 1, alpha, beta, count));
                    board[i][j].c = 0;
                    beta = min(beta, score);
                    if (beta <= alpha) return score;
                }
            }
        }
    }
    return score;
}

MOVE next_move(_POINT board[][BOARD_SIZE + 2], bool turn, int& min_count) {
    int depth = 3;
    int score, best_score;
    MOVE move = { -1, -1 };


    best_score = turn ? -INT_MAX : INT_MAX;

    for (int i = 1; i < BOARD_SIZE + 2 - 1; i++) {
        for (int j = 1; j < BOARD_SIZE + 2 - 1; j++) {
            int count = 0;
            if (on_border_check(board, i, j) && board[i][j].c == 0) {
                make_move(board, i, j, turn);
                score = minimax(board, !turn, depth, -INT_MAX, INT_MAX, count);
                board[i][j].c = 0;
                if ((turn && score > best_score) || (!turn && score < best_score)) {
                    best_score = score;
                    min_count = count;
                    move.x = i;
                    move.y = j;
                }
                else if (score == best_score && count < min_count) {
                    min_count = count;
                    move.x = i;
                    move.y = j;
                }
            }
        }
    }
    return move;
}




