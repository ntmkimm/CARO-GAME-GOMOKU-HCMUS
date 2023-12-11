#include "Ai.h"



int demnuocbot(_POINT B[22][22]) {
    int dem = 0;
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1) dem++;
        }
    }
    return dem;
}
bool defense(_POINT B[22][22]) {
    //hBng ngBng xxxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c) {
                if (B[i - 1][j].c == 0 || B[i + 4][j].c == 0) return 0;
            }
        }
    }
    //hBng doc xxxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j - 1].c == 0 || B[i][j + 4].c == 0) return 0;
            }
        }
    }
    // hBng cheo1 xxxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c) {
                if (B[i - 1][j - 1].c == 0 || B[i + 4][j + 4].c == 0)
                    return 0;
            }
        }
    }
    //hBng cheo2 xxxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i + 1][j - 1].c == 0 || B[i - 4][j + 4].c == 0)
                    return 0;
            }
        }
    }

    //hBng ngBng xxx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 4][j].c) {
                if (B[i + 3][j].c == 0) return 0;
            }
        }
    }
    //hBng doc xxx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j + 2].c == B[i][j].c && B[i][j].c == B[i][j + 4].c) {
                if (B[i][j + 3].c == 0) return 0;
            }
        }
    }
    // hBng cheo1 xxx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 4][j + 4].c) {
                if (B[i - 3][j + 3].c == 0)
                    return 0;
            }
        }
    }
    //hBng cheo2 xxx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 4][j + 4].c) {
                if (B[i + 3][j + 3].c == 0)
                    return 0;
            }
        }
    }

    //hBng ngBng xx_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 4][j].c && B[i][j].c == B[i + 3][j].c) {
                if (B[i + 2][j].c == 0) return 0;
            }
        }
    }
    //hBng doc xx_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 4].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j + 2].c == 0) return 0;
            }
        }
    }
    // hBng cheo1 xx_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 4][j + 4].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i - 2][j + 2].c == 0)
                    return 0;
            }
        }
    }
    //hBng cheo2 xx_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 4][j + 4].c && B[i][j].c == B[i + 3][j + 3].c) {
                if (B[i + 2][j + 2].c == 0)
                    return 0;
            }
        }
    }

    //hBng ngBng x_xxx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 4][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c) {
                if (B[i + 1][j].c == 0) return 0;
            }
        }
    }
    //hBng doc x_xxx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 4].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j + 1].c == 0) return 0;
            }
        }
    }
    // hBng cheo1 x_xxx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 4][j + 4].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i - 1][j + 1].c == 0)
                    return 0;
            }
        }
    }
    //hBng cheo2 x_xxx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 4][j + 4].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c) {
                if (B[i + 1][j + 1].c == 0)
                    return 0;
            }
        }
    }
    return 1;
}
bool attack(_POINT B[22][22]) {
    //hBng ngBng oooo_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c && B[i][j].c == 1 && (B[i + 4][j].c == 0 || B[i - 1][j].c == 0)) {
                return 1;
            }
        }
    }
    //hBng doc oooo_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c && (B[i][j + 4].c == 0 || B[i][j - 1].c == 0)) {
                return 1;
            }
        }
    }
    // hBng cheo1 oooo_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c && (B[i - 4][j + 4].c == 0 || B[i + 1][j - 1].c == 0)) {
                return 1;
            }
        }
    }
    //hBng cheo2 oooo_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c && (B[i + 4][j + 4].c == 0 || B[i - 1][j - 1].c == 0)) {
                return 1;
            }
        }
    }

    //hBng ngBng ooo_o
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 4][j].c && B[i + 3][j].c == 0) {
                return 1;
            }
        }
    }
    //hBng doc ooo_o
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 4].c && B[i][j + 3].c == 0) {
                return 1;
            }
        }
    }
    // hBng cheo1 ooo_o
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 4][j + 4].c && B[i - 3][j + 3].c == 0) {
                return 1;
            }
        }
    }
    //hBng cheo2 ooo_o
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 4][j + 4].c && B[i + 3][j + 3].c == 0) {
                return 1;
            }
        }
    }

    //hBng ngBng oo_oo
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 4][j].c && B[i][j].c == B[i + 3][j].c && B[i + 2][j].c == 0) {
                return 1;
            }
        }
    }
    //hBng doc oo_oo
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 4].c && B[i][j].c == B[i][j + 3].c && B[i][j + 2].c == 0) {
                return 1;
            }
        }
    }
    // hBng cheo1 oo_oo
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 4][j + 4].c && B[i][j].c == B[i - 3][j + 3].c && B[i - 2][j + 2].c == 0) {
                return 1;
            }
        }
    }
    //hBng cheo2 oo_oo
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 4][j + 4].c && B[i][j].c == B[i + 3][j + 3].c && B[i + 2][j + 2].c == 0) {
                return 1;
            }
        }
    }

    //hBng ngBng o_ooo
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i + 4][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c && B[i + 1][j].c == 0) {
                return 1;
            }
        }
    }
    //hBng doc o_ooo
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i][j + 4].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c && B[i][j + 1].c == 0) {
                return 1;
            }
        }
    }
    // hBng cheo1 o_ooo
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i - 4][j + 4].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c && B[i - 1][j + 1].c == 0) {
                return 1;
            }
        }
    }
    //hBng cheo2 o_ooo
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1 && B[i][j].c == B[i + 4][j + 4].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c && B[i + 1][j + 1].c == 0) {
                return 1;
            }
        }
    }
    return 0;
}
bool pre_defense(_POINT B[22][22]) {
    //hBng ngBng xxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c) {
                if (B[i - 1][j].c == 0 && B[i + 3][j].c == 0) return 0;
            }
        }
    }
    //hBng doc xxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c) {
                if (B[i][j - 1].c == 0 && B[i][j + 3].c == 0) return 0;
            }
        }
    }
    // hBng cheo1 xxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c) {
                if (B[i + 1][j - 1].c == 0 && B[i - 3][j + 3].c == 0)
                    return 0;
            }
        }
    }
    //hBng cheo2 xxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c) {
                if (B[i - 1][j - 1].c == 0 && B[i + 3][j + 3].c == 0)
                    return 0;
            }
        }
    }

    //hBng ngBng xx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 3][j].c) {
                if (B[i + 2][j].c == 0) return 0;
            }
        }
    }
    //hBng doc xx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j + 2].c == 0) return 0;
            }
        }
    }
    // hBng cheo1 xx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i - 2][j + 2].c == 0)
                    return 0;
            }
        }
    }
    //hBng cheo2 xx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 3][j + 3].c) {
                if (B[i + 2][j + 2].c == 0)
                    return 0;
            }
        }
    }

    //hBng ngBng x_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 3][j].c && B[i][j].c == B[i + 2][j].c) {
                if (B[i + 1][j].c == 0) return 0;
            }
        }
    }
    //hBng doc x_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j + 1].c == 0) return 0;
            }
        }
    }
    // hBng cheo1 x_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i - 1][j + 1].c == 0)
                    return 0;
            }
        }
    }
    //hBng cheo2 x_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 3][j + 3].c && B[i][j].c == B[i + 2][j + 2].c) {
                if (B[i + 1][j + 1].c == 0)
                    return 0;
            }
        }
    }
    return 1;
}
int POINT2 = 0;
int evaluate(_POINT B[22][22]) {
    int POINT2 = INT_MIN;
    bool def = defense(B);
    bool pre_def = pre_defense(B);
    bool atk = attack(B);
    //Nuoc khoi dBu
    if (demnuocbot(B) < 4) {
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == -1) {
                    if (B[i - 1][j - 1].c == 1 || B[i - 1][j + 1].c == 1 || B[i + 1][j - 1].c == 1 || B[i + 1][j + 1].c == 1) {
                        POINT2 += 1;
                    }
                }
            }
        }
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1) {
                    if (B[i - 1][j].c == 1 || B[i][j + 1].c == 1 || B[i][j - 1].c == 1 || B[i + 1][j].c == 1) {
                        POINT2 += 1;
                    }
                }
            }
        }
    }

    // Check js for winner 
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i + 3][j].c == B[i][j].c && B[i][j].c == B[i + 4][j].c) {
                if (B[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // Check iumns for winner
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c && B[i][j].c == B[i][j + 4].c) {
                if (B[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // Check djBgonBls for winner
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c && B[i][j].c == B[i + 4][j + 4].c) {
                if (B[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }
    // check cheo win
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c && B[i][j].c == B[i - 4][j + 4].c) {
                if (B[i][j].c == 1)
                    return INT_MAX;
            }
        }
    }



    //DEFENSE

    //hBng ngBng xxxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c) {
                if ((B[i - 1][j].c == 1 || B[i - 1][j].c == -2) && (B[i + 4][j].c == 1 || B[i + 4][j].c == -2)) POINT2 += 150;
            }
        }
    }
    //hBng doc xxxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c) {
                if ((B[i][j - 1].c == 1 || B[i][j - 1].c == -2) && (B[i][j + 4].c == 1 || B[i][j + 4].c == -2)) POINT2 += 150;
            }
        }
    }
    // hBng cheo1 xxxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c) {
                if ((B[i - 1][j - 1].c == 1 || B[i - 1][j - 1].c == -2) && (B[i + 4][j + 4].c == 1 || B[i + 4][j + 4].c == -2))
                    POINT2 += 150;
            }
        }
    }
    //hBng cheo2 xxxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c) {
                if ((B[i + 1][j - 1].c == 1 || B[i + 1][j - 1].c == -2) && (B[i - 4][j + 4].c == 1 || B[i - 4][j + 4].c == -2))
                    POINT2 += 150;
            }
        }
    }

    //hBng ngBng xxx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 4][j].c) {
                if (B[i + 3][j].c == 1) POINT2 += 150;
            }
        }
    }
    //hBng doc xxx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j + 2].c == B[i][j].c && B[i][j].c == B[i][j + 4].c) {
                if (B[i][j + 3].c == 1) POINT2 += 150;
            }
        }
    }
    // hBng cheo1 xxx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 4][j + 4].c) {
                if (B[i - 3][j + 3].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hBng cheo2 xxx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 4][j + 4].c) {
                if (B[i + 3][j + 3].c == 1)
                    POINT2 += 150;
            }
        }
    }

    //hBng ngBng xx_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 4][j].c && B[i][j].c == B[i + 3][j].c) {
                if (B[i + 2][j].c == 1) POINT2 += 150;
            }
        }
    }
    //hBng doc xx_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 4].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j + 2].c == 1) POINT2 += 150;
            }
        }
    }
    // hBng cheo1 xx_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 4][j + 4].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i - 2][j + 2].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hBng cheo2 xx_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 4][j + 4].c && B[i][j].c == B[i + 3][j + 3].c) {
                if (B[i + 2][j + 2].c == 1)
                    POINT2 += 150;
            }
        }
    }

    //hBng ngBng x_xxx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 4][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c) {
                if (B[i + 1][j].c == 1) POINT2 += 150;
            }
        }
    }
    //hBng doc x_xxx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 4].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j + 1].c == 1) POINT2 += 150;
            }
        }
    }
    // hBng cheo1 x_xxx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 4][j + 4].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i - 1][j + 1].c == 1)
                    POINT2 += 150;
            }
        }
    }
    //hBng cheo2 x_xxx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 4][j + 4].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c) {
                if (B[i + 1][j + 1].c == 1)
                    POINT2 += 150;
            }
        }
    }


    //hBng ngBng xxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c) {
                if (B[i - 1][j].c == 1 || B[i + 3][j].c == 1 || B[i - 1][j].c == -2 || B[i + 3][j].c == -2) POINT2 += 65;
            }
        }
    }
    //hBng doc xxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c) {
                if (B[i][j - 1].c == 1 || B[i][j + 3].c == 1 || B[i][j - 1].c == -2 || B[i][j + 3].c == -2) POINT2 += 65;
            }
        }
    }
    // hBng cheo1 xxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c) {
                if (B[i + 1][j - 1].c == 1 || B[i - 3][j + 3].c == 1 || B[i + 1][j - 1].c == -2 || B[i - 3][j + 3].c == -2)
                    POINT2 += 65;
            }
        }
    }
    //hBng cheo2 xxx_
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c) {
                if (B[i - 1][j - 1].c == 1 || B[i + 3][j + 3].c == 1 || B[i - 1][j - 1].c == -2 || B[i + 3][j + 3].c == -2)
                    POINT2 += 65;
            }
        }
    }

    //hBng ngBng xx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 3][j].c) {
                if (B[i + 2][j].c == 1) POINT2 += 65;
            }
        }
    }
    //hBng doc xx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j + 2].c == 1) POINT2 += 65;
            }
        }
    }
    // hBng cheo1 xx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i - 2][j + 2].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hBng cheo2 xx_x
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 3][j + 3].c) {
                if (B[i + 2][j + 2].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hBng ngBng x_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 3][j].c && B[i][j].c == B[i + 2][j].c) {
                if (B[i + 1][j].c == 1) POINT2 += 65;
            }
        }
    }
    //hBng doc x_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c) {
                if (B[i][j + 1].c == 1) POINT2 += 65;
            }
        }
    }
    // hBng cheo1 x_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c) {
                if (B[i - 1][j + 1].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //hBng cheo2 x_xx
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1 && B[i][j].c == B[i + 3][j + 3].c && B[i][j].c == B[i + 2][j + 2].c) {
                if (B[i + 1][j + 1].c == 1)
                    POINT2 += 65;
            }
        }
    }
    //BTTBCK
     //check for defense
    if (def == 1) {
        //hBng ngBng oooo_
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c && B[i][j].c == 1 && (B[i + 4][j].c == 0 || B[i - 1][j].c == 0)) {
                    POINT2 += 300;
                }
            }
        }

        //hBng doc oooo_
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c && (B[i][j + 4].c == 0 || B[i][j - 1].c == 0)) {
                    POINT2 += 300;
                }
            }
        }

        // hBng cheo1 oooo_
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c && (B[i - 4][j + 4].c == 0 || B[i + 1][j - 1].c == 0)) {
                    POINT2 += 300;
                }
            }
        }

        //hBng cheo2 oooo_
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c && (B[i + 4][j + 4].c == 0 || B[i - 1][j - 1].c == 0)) {
                    POINT2 += 300;
                }
            }
        }

        //hBng ngBng ooo_o
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 4][j].c && B[i + 3][j].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        //hBng doc ooo_o
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 4].c && B[i][j + 3].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        // hBng cheo1 ooo_o
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 4][j + 4].c && B[i - 3][j + 3].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        //hBng cheo2 ooo_o
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 4][j + 4].c && B[i + 3][j + 3].c == 0) {
                    POINT2 += 73;
                }
            }
        }

        //hBng ngBng oo_oo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 4][j].c && B[i][j].c == B[i + 3][j].c && B[i + 2][j].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        //hBng doc oo_oo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 4].c && B[i][j].c == B[i][j + 3].c && B[i][j + 2].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        // hBng cheo1 oo_oo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 4][j + 4].c && B[i][j].c == B[i - 3][j + 3].c && B[i - 2][j + 2].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        //hBng cheo2 oo_oo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 4][j + 4].c && B[i][j].c == B[i + 3][j + 3].c && B[i + 2][j + 2].c == 0) {
                    POINT2 += 73;
                }
            }
        }

        //hBng ngBng o_ooo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 4][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c && B[i + 1][j].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        //hBng doc o_ooo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i][j + 4].c && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c && B[i][j + 1].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        // hBng cheo1 o_ooo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i - 4][j + 4].c && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c && B[i - 1][j + 1].c == 0) {
                    POINT2 += 73;
                }
            }
        }
        //hBng cheo2 o_ooo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 4][j + 4].c && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c && B[i + 1][j + 1].c == 0) {
                    POINT2 += 73;
                }
            }
        }
    }

    if ((def == 1 && pre_def == 1) || (def == 1 && atk == 1)) {
        //hBng ngBng ooo_
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 2][j].c && B[i][j].c == 1 && (B[i + 3][j].c == 0 && B[i - 1][j].c == 0)) {
                    POINT2 += 60;
                }
            }
        }
        //hBng doc ooo_
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 2].c && (B[i][j + 3].c == 0 && B[i][j - 1].c == 0)) {
                    POINT2 += 60;
                }
            }
        }
        // hBng cheo1 ooo_
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 2][j + 2].c && (B[i - 3][j + 3].c == 0 && B[i + 1][j - 1].c == 0)) {
                    POINT2 += 60;
                }
            }
        }
        //hBng cheo2 ooo_ 
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 2][j + 2].c && (B[i + 3][j + 3].c == 0 && B[i - 1][j - 1].c == 0)) {
                    POINT2 += 60;
                }
            }
        }

        //hBng ngBng oo_o
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == B[i + 1][j].c && B[i][j].c == B[i + 3][j].c && B[i][j].c == 1 && (B[i + 2][j].c == 0 && B[i - 1][j].c == 0 && B[i + 4][j].c == 0)) {
                    POINT2 += 56;
                }
            }
        }
        //hBng doc oo_o
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i][j + 1].c && B[i][j].c == B[i][j + 3].c && (B[i][j + 2].c == 0 && B[i][j - 1].c == 0 && B[i][j + 4].c == 0)) {
                    POINT2 += 56;
                }
            }
        }
        // hBng cheo1 oo_o
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i - 1][j + 1].c && B[i][j].c == B[i - 3][j + 3].c && (B[i - 2][j + 2].c == 0 && B[i + 1][j - 1].c == 0 && B[i - 4][j + 4].c == 0)) {
                    POINT2 += 56;
                }
            }
        }
        //hBng cheo2 oo_o 
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 1][j + 1].c && B[i][j].c == B[i + 3][j + 3].c && (B[i + 2][j + 2].c == 0 && B[i - 1][j - 1].c == 0 && B[i + 4][j + 4].c == 0)) {
                    POINT2 += 56;
                }
            }
        }

        //hBng ngBng o_oo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == B[i + 2][j].c && B[i][j].c == B[i + 3][j].c && B[i][j].c == 1 && (B[i + 1][j].c == 0 && B[i - 1][j].c == 0 && B[i + 4][j].c == 0)) {
                    POINT2 += 56;
                }
            }
        }
        //hBng doc o_oo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i][j + 2].c && B[i][j].c == B[i][j + 3].c && (B[i][j + 1].c == 0 && B[i][j - 1].c == 0 && B[i][j + 4].c == 0)) {
                    POINT2 += 56;
                }
            }
        }
        // hBng cheo1 o_oo
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i - 2][j + 2].c && B[i][j].c == B[i - 3][j + 3].c && (B[i - 1][j + 1].c == 0 && B[i + 1][j - 1].c == 0 && B[i - 4][j + 4].c == 0)) {
                    POINT2 += 56;
                }
            }
        }
        //hBng cheo2 o_oo 
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 1 && B[i][j].c == B[i + 2][j + 2].c && B[i][j].c == B[i + 3][j + 3].c && (B[i + 1][j + 1].c == 0 && B[i - 1][j - 1].c == 0 && B[i + 4][j + 4].c == 0)) {
                    POINT2 += 56;
                }
            }
        }
    }
    return POINT2;
}
int evaluate1(_POINT B[22][22]) {
    int POINT2 = INT_MIN;
    bool def = defense(B);
    bool pre_def = pre_defense(B);
    bool atk = attack(B);
    //Nuoc khoi dau
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == -1) {
                if (B[i - 1][j - 1].c == 1 || B[i - 1][j + 1].c == 1 || B[i + 1][j - 1].c == 1 || B[i + 1][j + 1].c == 1) {
                    POINT2 += 1;
                }
            }
        }
    }
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 1) {
                if (B[i - 1][j].c == 1 || B[i][j + 1].c == 1 || B[i][j - 1].c == 1 || B[i + 1][j].c == 1) {
                    POINT2 += 1;
                }
            }
        }
    }
    return POINT2;
}
Move findfirstBestmove(_POINT B[22][22]) {
    int Bestscorefornextmove = INT_MIN;
    Move Nextmove;
    Nextmove.x = -1;
    Nextmove.y = -1;
    for (int i = 5; i < SIZE + 5; i++) {
        for (int j = 5; j < SIZE + 5; j++) {
            if (B[i][j].c == 0) {
                B[i][j].c = 1;
                int currentscore = evaluate(B);
                B[i][j].c = 0;
                if (currentscore > Bestscorefornextmove) {
                    Bestscorefornextmove = currentscore;
                    Nextmove.x = i;
                    Nextmove.y = j;
                }
            }
        }
    }
    if (Nextmove.x == -1 && Nextmove.y == -1) {
        for (int i = 5; i < SIZE + 5; i++) {
            for (int j = 5; j < SIZE + 5; j++) {
                if (B[i][j].c == 0) {
                    B[i][j].c = 1;
                    int currentscore = evaluate1(B);
                    B[i][j].c = 0;
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