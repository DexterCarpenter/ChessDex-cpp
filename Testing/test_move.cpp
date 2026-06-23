#include <cassert>

#include "../src/board/move.h"

void test_move_constructor() {
    Move move1(A2, A4);
    assert(move1.from_square == A2);
    assert(move1.to_square == A4);
    assert(move1.promotion_piece == PIECE_NB);
}

int main() {
    test_move_constructor();
    
    return 0;
}