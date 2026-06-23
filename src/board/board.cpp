#include "board.h"

// Constructor
Board::Board() {
}

// Methods
void Board::placePiece(ST_PIECE_AT_SQR _pas) {
    bitboard[static_cast<int>(_pas.color)][static_cast<int>(_pas.piece)] |= (1ULL << static_cast<int>(_pas.square));
}

void Board::placePiece(E_COLOR _color, E_PIECE _piece, E_SQUARE _square) {
    bitboard[static_cast<int>(_color)][static_cast<int>(_piece)] |= (1ULL << static_cast<int>(_square));
}

void Board::removePiece(ST_PIECE_AT_SQR _pas) {
    bitboard[static_cast<int>(_pas.color)][static_cast<int>(_pas.piece)] &= ~(1ULL << static_cast<int>(_pas.square));
}

void Board::removePiece(E_COLOR _color, E_PIECE _piece, E_SQUARE _square) {
    bitboard[static_cast<int>(_color)][static_cast<int>(_piece)] &= ~(1ULL << static_cast<int>(_square));
}

void Board::removePiece(E_SQUARE _square) {
    for (int c = 0; c < COLOR_NB; c++) {
        for (int p = 0; p < PIECE_NB; p++) {
            bitboard[c][p] &= ~(1ULL << static_cast<int>(_square));
        }
    }
}

void Board::clearBoard() {
    for (int c = 0; c < COLOR_NB; c++) {
        for (int p = 0; p < PIECE_NB; p++) {
            bitboard[c][p] = 0ULL;
        }
    }
}

E_PIECE Board::pieceAtSquare(E_SQUARE _square) {
    for (int c = 0; c < COLOR_NB; c++) {
        for (int p = 0; p < PIECE_NB; p++) {
            if (bitboard[c][p] & (1ULL << static_cast<int>(_square))) {
                return static_cast<E_PIECE>(p);
            }
        }
    }
    return E_PIECE::PIECE_NB; // return PIECE_NB if no piece is found at the square
}

void Board::_flipTurn() {
    white_to_move = !white_to_move;
    if (white_to_move) {
        player_color = WHITE;
        opponent_color = BLACK;
    } else {
        player_color = BLACK;
        opponent_color = WHITE;
    }
}

void Board::makeMove(Move _move) {
    _move.moved_piece    = pieceAtSquare(_move.from_square);
    _move.captured_piece = pieceAtSquare(_move.to_square);
    
    removePiece(player_color, _move.moved_piece, _move.from_square);
    removePiece(_move.to_square);
    placePiece(player_color, _move.moved_piece, _move.to_square);

    _flipTurn();
}

void Board::setupStartingPosition() {
    clearBoard();

    // Place white pieces
    placePiece({WHITE, ROOK, A1});
    placePiece({WHITE, KNIGHT, B1});
    placePiece({WHITE, BISHOP, C1});
    placePiece({WHITE, QUEEN, D1});
    placePiece({WHITE, KING, E1});
    placePiece({WHITE, BISHOP, F1});
    placePiece({WHITE, KNIGHT, G1});
    placePiece({WHITE, ROOK, H1});
    for (int file = 0; file < 8; file++) {
        placePiece({WHITE, PAWN, static_cast<E_SQUARE>(A2 + file)});
    }

    // Place black pieces
    placePiece({BLACK, ROOK, A8});
    placePiece({BLACK, KNIGHT, B8});
    placePiece({BLACK, BISHOP, C8});
    placePiece({BLACK, QUEEN, D8});
    placePiece({BLACK, KING, E8});
    placePiece({BLACK, BISHOP, F8});
    placePiece({BLACK, KNIGHT, G8});
    placePiece({BLACK, ROOK, H8});
    for (int file = 0; file < 8; file++) {
        placePiece({BLACK, PAWN, static_cast<E_SQUARE>(A7 + file)});
    }

    white_to_move = true;

    move_log.clear();
}

// void Board::undoMove() {
//     int move_count = move_log.getMoveCount();
//     if (move_count == 0) {
//         return; // No moves to undo
//     }

//     Move last_move = move_log.list.back();
//     move_log.undoMove();

//     _flipTurn();

//     removePiece(opponent_color, last_move.moved_piece, last_move.to_square);
//     if (last_move.captured_piece != E_PIECE::PIECE_NB) {
//         placePiece(opponent_color, last_move.captured_piece, last_move.to_square);
//     }
//     placePiece(player_color, last_move.moved_piece, last_move.from_square);
// }