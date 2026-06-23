#pragma once

#include <array>
#include <vector>

#include "../common.h"
#include "piece.h"

enum E_MOVE_TYPE {
    MORNAL,
    CASTLE,
    EnPASSANT,
    PROMOTION
};

class Move {
    // object defining a single player's move
    public:
        // Constructor
        Move(E_SQUARE _from_square, E_SQUARE _to_square, E_PIECE _promotion_piece = E_PIECE::PIECE_NB);

        // Properties
        E_SQUARE  from_square; // original square
        E_SQUARE  to_square; // destination square
        E_PIECE   promotion_piece; // desired promotion piece

        E_MOVE_TYPE type; // states if move is a special move (see E_MOVE_TYPE)

        E_PIECE moved_piece; // the piece being moved
        E_PIECE captured_piece; // the piece being captured

        bool    is_legal; // TRUE if this is a legal move
};

class MoveLog {
    private:
        // Properties
        std::vector<Move>   list; // dynamic list of the moves
        std::array<bool, 2> castling_rights; // 2 bools to remember if each side still has the right to castle
        E_SQUARE            ep_square = E_SQUARE::SQ_NB; // the square that can be captured en passant, if any
        int                 move_count; // number of moves (plies, half-moves) made in the game

    public:
        // Constructor
        MoveLog();

        // Methods
        void logMove(Move _move); // appends a move to the log
        void undoMove(); // undos the last move made
        void clear(); // removes all moves from log
        int  getMoveCount(); // returns the number of moves made in the game
};