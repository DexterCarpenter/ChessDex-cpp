#include <cassert>
#include <cstring>

#include "../src/common.h"

void test_common_square() {
    assert(SQ_NB == 64);
    assert(FILE_OF[A1] == 'a');
    assert(FILE_OF[D6] == 'd');
    assert(RANK_OF[A1] == '1');
    assert(RANK_OF[E3] == '3');
    assert(isLightSquare(A1) == false);
    assert(isLightSquare(B7) == true);
}

void test_common_piece() { 
    assert(strcmp(PIECE_SYMBOL[WHITE][PAWN],  "♙") == 0);
    assert(strcmp(PIECE_SYMBOL[BLACK][QUEEN], "♛") == 0);
    assert(strcmp(SQUARE_SYMBOL[WHITE],       "◻") == 0);
    assert(strcmp(SQUARE_SYMBOL[BLACK],       "◼") == 0);
}

int main() {
    test_common_square();
    test_common_piece();

    return 0;
}