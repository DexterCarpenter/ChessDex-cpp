#include "common.h"

const char* pieceSan(E_PIECE p) {
    return PIECE_SAN_LETTER[static_cast<int>(p)];
}

const char* pieceSymbol(E_COLOR c, E_PIECE p) {
    return PIECE_SYMBOL[static_cast<int>(c)][static_cast<int>(p)];
}

const char* squareSymbol(E_COLOR c) {
    return SQUARE_SYMBOL[static_cast<int>(c)];
}