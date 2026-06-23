#include "move.h"

/* ========== Move ========== */
Move::Move(E_SQUARE _from_square, E_SQUARE _to_square, E_PIECE _promotion_piece)
    : from_square(_from_square), to_square(_to_square)
{
    promotion_piece = _promotion_piece;
    if (promotion_piece != E_PIECE::PIECE_NB) {
        type = E_MOVE_TYPE::PROMOTION;
    }
}
  




/* ========== MoveLog ========== */
MoveLog::MoveLog() : castling_rights{true, true}, ep_square(E_SQUARE::SQ_NB) {
}

void MoveLog::logMove(Move _move) {
    list.push_back(_move);
}

void MoveLog::undoMove() {
    list.pop_back();
}

void MoveLog::clear() {
    list.clear();
}

int MoveLog::getMoveCount() {
    move_count = static_cast<int>(list.size());
    return move_count;
}