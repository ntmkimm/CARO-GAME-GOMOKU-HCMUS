#include "Ai.h"

int demnuocbot(_POINT A[BOARD_SIZE][BOARD_SIZE]) {
    int dem = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1) dem++;
        }
    }
    return dem;
}

int POINT2 = 0;
int evaluate(_POINT A[BOARD_SIZE][BOARD_SIZE]) {
    int POINT2 = INT_MIN;

    //Nuoc khoi dau
    if (demnuocbot(A) < 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (A[i][j].c == -1) {
                    if (A[i - 1][j - 1].c == 0 || A[i - 1][j + 1].c == 0 || A[i + 1][j - 1].c == 0 || A[i + 1][j + 1].c == 0) {
                        if (A[i - 1][j - 1].c == 1 || A[i - 1][j + 1].c == 1 || A[i + 1][j - 1].c == 1 || A[i + 1][j + 1].c == 1) {
                            POINT2 += 1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (A[i][j].c == 1) {
                    if (A[i - 1][j].c == 0 || A[i][j + 1].c == 0 || A[i][j - 1].c == 0 || A[i + 1][j].c == 0) {
                        if (A[i - 1][j].c == 1 || A[i][j + 1].c == 1 || A[i][j - 1].c == 1 || A[i + 1][j].c == 1) {
                            POINT2 += 1;
                        }
                    }
                }
            }
        }
    }

    // Check js for winner 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i + 3][j].c == A[i][j].c && A[i][j].c == A[i + 4][j].c) {
                if (A[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // Check iumns for winner
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && A[i][j].c == A[i][j + 4].c) {
                if (A[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // Check djagonals for winner
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && A[i][j].c == A[i + 4][j + 4].c) {
                if (A[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // check cheo win
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && A[i][j].c == A[i - 4][j + 4].c) {
                if (A[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }



    //DEFENSE

    //hang ngang xxxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c) {
                if (A[i - 1][j].c == 1 && A[i + 4][j].c == 1) POINT2 += 150;
            }
        }
    }
    //hang doc xxxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j - 1].c == 1 && A[i][j + 4].c == 1) POINT2 += 150;
            }
        }
    }
    // hang cheo1 xxxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c) {
                if (A[i - 1][j - 1].c == 1 && A[i + 4][j + 4].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hang cheo2 xxxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i + 1][j - 1].c == 1 && A[i - 4][j + 4].c == 1)
                    POINT2 += 150;
            }
        }
    }

    //hang ngang xxx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 4][j].c) {
                if (A[i][j + 3].c == 1) POINT2 += 150;
            }
        }
    }
    //hang doc xxx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j + 2].c == A[i][j].c && A[i][j].c == A[i][j + 4].c) {
                if (A[i][j + 3].c == 1) POINT2 += 150;
            }
        }
    }
    // hang cheo1 xxx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 4][j + 4].c) {
                if (A[i - 3][j + 3].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hang cheo2 xxx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 4][j + 4].c) {
                if (A[i + 3][j + 3].c == 1)
                    POINT2 += 150;
            }
        }
    }

    //hang ngang xx_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 4][j].c && A[i][j].c == A[i + 3][j].c) {
                if (A[i + 2][j].c == 1) POINT2 += 150;
            }
        }
    }
    //hang doc xx_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 2].c == 1) POINT2 += 150;
            }
        }
    }
    // hang cheo1 xx_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 4][j + 4].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i - 2][j + 2].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hang cheo2 xx_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 4][j + 4].c && A[i][j].c == A[i + 3][j + 3].c) {
                if (A[i + 2][j + 2].c == 1)
                    POINT2 += 150;
            }
        }
    }

    //hang ngang x_xxx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 1].c == 1) POINT2 += 150;
            }
        }
    }
    //hang doc x_xxx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 1].c == 1) POINT2 += 150;
            }
        }
    }
    // hang cheo1 x_xxx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 4][j + 4].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i - 1][j + 1].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hang cheo2 x_xxx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 4][j + 4].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c) {
                if (A[i + 1][j + 1].c == 1)
                    POINT2 += 150;
            }
        }
    }


    //hang ngang xxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c) {
                if (A[i - 1][j].c == 1 || A[i + 3][j].c == 1) POINT2 += 65;
            }
        }
    }
    //hang doc xxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c) {
                if (A[i][j - 1].c == 1 || A[i][j + 3].c == 1) POINT2 += 65;
            }
        }
    }
    // hang cheo1 xxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c) {
                if (A[i + 1][j - 1].c == 1 || A[i - 3][j + 3].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hang cheo2 xxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c) {
                if (A[i - 1][j - 1].c == 1 || A[i + 3][j + 3].c == 1)
                    POINT2 += 65;
            }
        }
    }

    //hang ngang xx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 3][j].c) {
                if (A[i + 2][j].c == 1) POINT2 += 65;
            }
        }
    }
    //hang doc xx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 2].c == 1) POINT2 += 65;
            }
        }
    }
    // hang cheo1 xx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i - 2][j + 2].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hang cheo2 xx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 3][j + 3].c) {
                if (A[i + 2][j + 2].c == 1)
                    POINT2 += 65;
            }
        }
    }

    //hang ngang x_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 3][j].c && A[i][j].c == A[i + 2][j].c) {
                if (A[i + 1][j].c == 1) POINT2 += 65;
            }
        }
    }
    //hang doc x_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 1].c == 1) POINT2 += 65;
            }
        }
    }
    // hang cheo1 x_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i - 1][j + 1].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hang cheo2 x_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 3][j + 3].c && A[i][j].c == A[i + 2][j + 2].c) {
                if (A[i + 1][j + 1].c == 1)
                    POINT2 += 65;
            }
        }
    }

    //ATTACK
    //hang ngang oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c && A[i][j].c == 1 && (A[i + 4][j].c == 0 || A[i - 1][j].c == 0)) {
                POINT2 += 75;
            }
        }
    }
    //hang doc oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && (A[i][j + 4].c == 0 || A[i][j - 1].c == 0)) {
                POINT2 += 75;
            }
        }
    }
    // hang cheo1 oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && (A[i - 4][j + 4].c == 0 || A[i + 1][j - 1].c == 0)) {
                POINT2 += 75;
            }
        }
    }
    //hang cheo2 oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && (A[i + 4][j + 4].c == 0 || A[i - 1][j - 1].c == 0)) {
                POINT2 += 75;
            }
        }
    }

    //hang ngang oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c && A[i][j].c == 1 && (A[i + 4][j].c == 0 && A[i - 1][j].c == 0)) {
                POINT2 += 70;
            }
        }
    }
    //hang doc oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && (A[i][j + 4].c == 0 && A[i][j - 1].c == 0)) {
                POINT2 += 70;
            }
        }
    }
    // hang cheo1 oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && (A[i - 4][j + 4].c == 0 && A[i + 1][j - 1].c == 0)) {
                POINT2 += 70;
            }
        }
    }
    //hang cheo2 oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && (A[i + 4][j + 4].c == 0 && A[i - 1][j - 1].c == 0)) {
                POINT2 += 70;
            }
        }
    }

    //hang ngang ooo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 4][j].c && A[i + 3][j].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang doc ooo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 4].c && A[i][j + 3].c == 0) {
                POINT2 += 73;
            }
        }
    }
    // hang cheo1 ooo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 4][j + 4].c && A[i - 3][j + 3].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang cheo2 ooo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 4][j + 4].c && A[i + 3][j + 3].c == 0) {
                POINT2 += 73;
            }
        }
    }

    //hang ngang oo_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 4][j].c && A[i][j].c == A[i + 3][j].c && A[i + 2][j].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang doc oo_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 3].c && A[i][j + 2].c == 0) {
                POINT2 += 73;
            }
        }
    }
    // hang cheo1 oo_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 4][j + 4].c && A[i][j].c == A[i - 3][j + 3].c && A[i - 2][j + 2].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang cheo2 oo_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 4][j + 4].c && A[i][j].c == A[i + 3][j + 3].c && A[i + 2][j + 2].c == 0) {
                POINT2 += 73;
            }
        }
    }

    //hang ngang o_ooo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 4][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c && A[i + 1][j].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang doc o_ooo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && A[i][j + 1].c == 0) {
                POINT2 += 73;
            }
        }
    }
    // hang cheo1 o_ooo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 4][j + 4].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && A[i - 1][j + 1].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang cheo2 o_ooo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 4][j + 4].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && A[i + 1][j + 1].c == 0) {
                POINT2 += 73;
            }
        }
    }

    //hang ngang ooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == 1 && (A[i + 3][j].c == 0 && A[i - 1][j].c == 0)) {
                POINT2 += 60;
            }
        }
    }
    //hang doc ooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && (A[i][j + 3].c == 0 && A[i][j - 1].c == 0)) {
                POINT2 += 60;
            }
        }
    }
    // hang cheo1 ooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && (A[i - 3][j + 3].c == 0 && A[i + 1][j - 1].c == 0)) {
                POINT2 += 60;
            }
        }
    }
    //hang cheo2 ooo_ 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && (A[i + 3][j + 3].c == 0 && A[i - 1][j - 1].c == 0)) {
                POINT2 += 60;
            }
        }
    }

    //hang ngang oo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 3][j].c && A[i][j].c == 1 && (A[i + 2][j].c == 0 && A[i - 1][j].c == 0 && A[i + 4][j].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    //hang doc oo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 3].c && (A[i][j + 2].c == 0 && A[i][j - 1].c == 0 && A[i][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    // hang cheo1 oo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 3][j + 3].c && (A[i - 2][j + 2].c == 0 && A[i + 1][j - 1].c == 0 && A[i - 4][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    //hang cheo2 oo_o 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 3][j + 3].c && (A[i + 2][j + 2].c == 0 && A[i - 1][j - 1].c == 0 && A[i + 4][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }

    //hang ngang o_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c && A[i][j].c == 1 && (A[i + 1][j].c == 0 && A[i - 1][j].c == 0 && A[i + 4][j].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    //hang doc o_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && (A[i][j + 1].c == 0 && A[i][j - 1].c == 0 && A[i][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    // hang cheo1 o_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && (A[i - 1][j + 1].c == 0 && A[i + 1][j - 1].c == 0 && A[i - 4][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    //hang cheo2 o_oo 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && (A[i + 1][j + 1].c == 0 && A[i - 1][j - 1].c == 0 && A[i + 4][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }

    return POINT2;
}

int evaluate1(_POINT A[BOARD_SIZE][BOARD_SIZE]) {
    int POINT2 = INT_MIN;

    //Nuoc khoi dau
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1) {
                if (A[i - 1][j - 1].c == 0 || A[i - 1][j + 1].c == 0 || A[i + 1][j - 1].c == 0 || A[i + 1][j + 1].c == 0) {
                    if (A[i - 1][j - 1].c == 1 || A[i - 1][j + 1].c == 1 || A[i + 1][j - 1].c == 1 || A[i + 1][j + 1].c == 1) {
                        POINT2 += 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1) {
                if (A[i - 1][j].c == 0 || A[i][j + 1].c == 0 || A[i][j - 1].c == 0 || A[i + 1][j].c == 0) {
                    if (A[i - 1][j].c == 1 || A[i][j + 1].c == 1 || A[i][j - 1].c == 1 || A[i + 1][j].c == 1) {
                        POINT2 += 1;
                    }
                }
            }
        }
    }


    // Check js for winner 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i + 3][j].c == A[i][j].c && A[i][j].c == A[i + 4][j].c) {
                if (A[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // Check iumns for winner
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && A[i][j].c == A[i][j + 4].c) {
                if (A[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // Check djagonals for winner
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && A[i][j].c == A[i + 4][j + 4].c) {
                if (A[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // check cheo win
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && A[i][j].c == A[i - 4][j + 4].c) {
                if (A[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }



    //DEFENSE

    //hang ngang xxxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c) {
                if (A[i - 1][j].c == 1 && A[i + 4][j].c == 1) POINT2 += 150;
            }
        }
    }
    //hang doc xxxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j - 1].c == 1 && A[i][j + 4].c == 1) POINT2 += 150;
            }
        }
    }
    // hang cheo1 xxxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c) {
                if (A[i - 1][j - 1].c == 1 && A[i + 4][j + 4].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hang cheo2 xxxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i + 1][j - 1].c == 1 && A[i - 4][j + 4].c == 1)
                    POINT2 += 150;
            }
        }
    }

    //hang ngang xxx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 4][j].c) {
                if (A[i][j + 3].c == 1) POINT2 += 150;
            }
        }
    }
    //hang doc xxx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j + 2].c == A[i][j].c && A[i][j].c == A[i][j + 4].c) {
                if (A[i][j + 3].c == 1) POINT2 += 150;
            }
        }
    }
    // hang cheo1 xxx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 4][j + 4].c) {
                if (A[i - 3][j + 3].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hang cheo2 xxx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 4][j + 4].c) {
                if (A[i + 3][j + 3].c == 1)
                    POINT2 += 150;
            }
        }
    }

    //hang ngang xx_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 4][j].c && A[i][j].c == A[i + 3][j].c) {
                if (A[i + 2][j].c == 1) POINT2 += 150;
            }
        }
    }
    //hang doc xx_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 2].c == 1) POINT2 += 150;
            }
        }
    }
    // hang cheo1 xx_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 4][j + 4].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i - 2][j + 2].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hang cheo2 xx_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 4][j + 4].c && A[i][j].c == A[i + 3][j + 3].c) {
                if (A[i + 2][j + 2].c == 1)
                    POINT2 += 150;
            }
        }
    }

    //hang ngang x_xxx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 1].c == 1) POINT2 += 150;
            }
        }
    }
    //hang doc x_xxx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 1].c == 1) POINT2 += 150;
            }
        }
    }
    // hang cheo1 x_xxx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 4][j + 4].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i - 1][j + 1].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hang cheo2 x_xxx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 4][j + 4].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c) {
                if (A[i + 1][j + 1].c == 1)
                    POINT2 += 150;
            }
        }
    }


    //hang ngang xxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c) {
                if (A[i - 1][j].c == 1 || A[i + 3][j].c == 1) POINT2 += 65;
            }
        }
    }
    //hang doc xxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c) {
                if (A[i][j - 1].c == 1 || A[i][j + 3].c == 1) POINT2 += 65;
            }
        }
    }
    // hang cheo1 xxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c) {
                if (A[i + 1][j - 1].c == 1 || A[i - 3][j + 3].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hang cheo2 xxx_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c) {
                if (A[i - 1][j - 1].c == 1 || A[i + 3][j + 3].c == 1)
                    POINT2 += 65;
            }
        }
    }

    //hang ngang xx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 3][j].c) {
                if (A[i + 2][j].c == 1) POINT2 += 65;
            }
        }
    }
    //hang doc xx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 2].c == 1) POINT2 += 65;
            }
        }
    }
    // hang cheo1 xx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i - 2][j + 2].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hang cheo2 xx_x
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 3][j + 3].c) {
                if (A[i + 2][j + 2].c == 1)
                    POINT2 += 65;
            }
        }
    }

    //hang ngang x_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 3][j].c && A[i][j].c == A[i + 2][j].c) {
                if (A[i + 1][j].c == 1) POINT2 += 65;
            }
        }
    }
    //hang doc x_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c) {
                if (A[i][j + 1].c == 1) POINT2 += 65;
            }
        }
    }
    // hang cheo1 x_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c) {
                if (A[i - 1][j + 1].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hang cheo2 x_xx
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 3][j + 3].c && A[i][j].c == A[i + 2][j + 2].c) {
                if (A[i + 1][j + 1].c == 1)
                    POINT2 += 65;
            }
        }
    }

    //ATTACK
    //hang ngang oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c && A[i][j].c == 1 && (A[i + 4][j].c == 0 || A[i - 1][j].c == 0)) {
                POINT2 += 75;
            }
        }
    }
    //hang doc oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && (A[i][j + 4].c == 0 || A[i][j - 1].c == 0)) {
                POINT2 += 75;
            }
        }
    }
    // hang cheo1 oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && (A[i - 4][j + 4].c == 0 || A[i + 1][j - 1].c == 0)) {
                POINT2 += 75;
            }
        }
    }
    //hang cheo2 oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && (A[i + 4][j + 4].c == 0 || A[i - 1][j - 1].c == 0)) {
                POINT2 += 75;
            }
        }
    }

    //hang ngang oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c && A[i][j].c == 1 && (A[i + 4][j].c == 0 && A[i - 1][j].c == 0)) {
                POINT2 += 70;
            }
        }
    }
    //hang doc oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && (A[i][j + 4].c == 0 && A[i][j - 1].c == 0)) {
                POINT2 += 70;
            }
        }
    }
    // hang cheo1 oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && (A[i - 4][j + 4].c == 0 && A[i + 1][j - 1].c == 0)) {
                POINT2 += 70;
            }
        }
    }
    //hang cheo2 oooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && (A[i + 4][j + 4].c == 0 && A[i - 1][j - 1].c == 0)) {
                POINT2 += 70;
            }
        }
    }

    //hang ngang ooo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 4][j].c && A[i + 3][j].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang doc ooo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 4].c && A[i][j + 3].c == 0) {
                POINT2 += 73;
            }
        }
    }
    // hang cheo1 ooo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 4][j + 4].c && A[i - 3][j + 3].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang cheo2 ooo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 4][j + 4].c && A[i + 3][j + 3].c == 0) {
                POINT2 += 73;
            }
        }
    }

    //hang ngang oo_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 4][j].c && A[i][j].c == A[i + 3][j].c && A[i + 2][j].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang doc oo_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 3].c && A[i][j + 2].c == 0) {
                POINT2 += 73;
            }
        }
    }
    // hang cheo1 oo_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 4][j + 4].c && A[i][j].c == A[i - 3][j + 3].c && A[i - 2][j + 2].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang cheo2 oo_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 4][j + 4].c && A[i][j].c == A[i + 3][j + 3].c && A[i + 2][j + 2].c == 0) {
                POINT2 += 73;
            }
        }
    }

    //hang ngang o_ooo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i + 4][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c && A[i + 1][j].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang doc o_ooo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == -1 && A[i][j].c == A[i][j + 4].c && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && A[i][j + 1].c == 0) {
                POINT2 += 73;
            }
        }
    }
    // hang cheo1 o_ooo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 4][j + 4].c && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && A[i - 1][j + 1].c == 0) {
                POINT2 += 73;
            }
        }
    }
    //hang cheo2 o_ooo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 4][j + 4].c && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && A[i + 1][j + 1].c == 0) {
                POINT2 += 73;
            }
        }
    }

    //hang ngang ooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 2][j].c && A[i][j].c == 1 && (A[i + 3][j].c == 0 && A[i - 1][j].c == 0)) {
                POINT2 += 60;
            }
        }
    }
    //hang doc ooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 2].c && (A[i][j + 3].c == 0 && A[i][j - 1].c == 0)) {
                POINT2 += 60;
            }
        }
    }
    // hang cheo1 ooo_
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 2][j + 2].c && (A[i - 3][j + 3].c == 0 && A[i + 1][j - 1].c == 0)) {
                POINT2 += 60;
            }
        }
    }
    //hang cheo2 ooo_ 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 2][j + 2].c && (A[i + 3][j + 3].c == 0 && A[i - 1][j - 1].c == 0)) {
                POINT2 += 60;
            }
        }
    }

    //hang ngang oo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 1][j].c && A[i][j].c == A[i + 3][j].c && A[i][j].c == 1 && (A[i + 2][j].c == 0 && A[i - 1][j].c == 0 && A[i + 4][j].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    //hang doc oo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 1].c && A[i][j].c == A[i][j + 3].c && (A[i][j + 2].c == 0 && A[i][j - 1].c == 0 && A[i][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    // hang cheo1 oo_o
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 1][j + 1].c && A[i][j].c == A[i - 3][j + 3].c && (A[i - 2][j + 2].c == 0 && A[i + 1][j - 1].c == 0 && A[i - 4][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    //hang cheo2 oo_o 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 1][j + 1].c && A[i][j].c == A[i + 3][j + 3].c && (A[i + 2][j + 2].c == 0 && A[i - 1][j - 1].c == 0 && A[i + 4][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }

    //hang ngang o_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == A[i + 2][j].c && A[i][j].c == A[i + 3][j].c && A[i][j].c == 1 && (A[i + 1][j].c == 0 && A[i - 1][j].c == 0 && A[i + 4][j].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    //hang doc o_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i][j + 2].c && A[i][j].c == A[i][j + 3].c && (A[i][j + 1].c == 0 && A[i][j - 1].c == 0 && A[i][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    // hang cheo1 o_oo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i - 2][j + 2].c && A[i][j].c == A[i - 3][j + 3].c && (A[i - 1][j + 1].c == 0 && A[i + 1][j - 1].c == 0 && A[i - 4][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }
    //hang cheo2 o_oo 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 1 && A[i][j].c == A[i + 2][j + 2].c && A[i][j].c == A[i + 3][j + 3].c && (A[i + 1][j + 1].c == 0 && A[i - 1][j - 1].c == 0 && A[i + 4][j + 4].c == 0)) {
                POINT2 += 56;
            }
        }
    }

    return POINT2;
}

Move findfirstBestmove(_POINT A[BOARD_SIZE][BOARD_SIZE]) {
    int Bestscorefornextmove = INT_MIN;
    Move Nextmove;
    Nextmove.x = -1;
    Nextmove.y = -1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j].c == 0) {
                A[i][j].c = 1;
                int currentscore = evaluate(A);
                A[i][j].c = 0;
                if (currentscore > Bestscorefornextmove) {
                    Bestscorefornextmove = currentscore;
                    Nextmove.x = i;
                    Nextmove.y = j;
                }
            }
        }
    }
    if (Nextmove.x == -1 && Nextmove.y == -1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (A[i][j].c == 0) {
                    A[i][j].c = 1;
                    int currentscore = evaluate1(A);
                    A[i][j].c = 0;
                    if (currentscore > Bestscorefornextmove) {
                        Bestscorefornextmove = currentscore;
                        Nextmove.x = i;
                        Nextmove.y = j;
                    }
                }
            }
        }
    }
    return Nextmove;
}
