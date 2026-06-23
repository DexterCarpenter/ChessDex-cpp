#include <cassert>

#include "../src/board/piece.h"

void test_piece_constructor() {
    Piece white_pawn(WHITE, PAWN);
    assert(white_pawn.getColor() == WHITE);
    assert(white_pawn.getPiece() == PAWN);

    Piece black_king(BLACK, KING);
    assert(black_king.getColor() == BLACK);
    assert(black_king.getPiece() == KING);
}

int main() {
    test_piece_constructor();

    return 0;
}