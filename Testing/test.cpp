#include <cassert>
#include <iostream>
#include <cstring>

#include "../src/board/board.h"

int main() {
    /* ========== COMMON TESTS ========== */
    assert(SQ_NB == 64);
    assert(FILE_OF[A1] == 'a');
    assert(FILE_OF[D6] == 'd');
    assert(RANK_OF[A1] == '1');
    assert(RANK_OF[E3] == '3');
    assert(isLightSquare(A1) == false);
    assert(isLightSquare(B7) == true);
    assert(strcmp(PIECE_SYMBOL[WHITE][PAWN],  "♙") == 0);
    assert(strcmp(PIECE_SYMBOL[BLACK][QUEEN], "♛") == 0);
    assert(strcmp(SQUARE_SYMBOL[WHITE],       "◻") == 0);
    assert(strcmp(SQUARE_SYMBOL[BLACK],       "◼") == 0);

    /* ========== PIECE TESTS ========== */
    Piece white_pawn(WHITE, PAWN);
    assert(white_pawn.getColor() == WHITE);
    assert(white_pawn.getPiece() == PAWN);
    Piece black_king(BLACK, KING);
    assert(black_king.getColor() == BLACK);
    assert(black_king.getPiece() == KING);

    /* ========== MOVE TESTS ========== */
    Move move1(A2, A4);
    assert(move1.from_square == A2);
    assert(move1.to_square == A4);
    assert(move1.promotion_piece == PIECE_NB);

    /* ========== BOARD TESTS ========== */








    return 0;
}