#include "piece.h"

/* ========== CONSTRUCTOR ========== */
Piece::Piece(E_COLOR _color, E_PIECE _piece) : color(_color), piece(_piece) {
}

/* ========== PROPERTIES ========== */
E_COLOR Piece::getColor() const {
    return color;
}

E_PIECE Piece::getPiece() const {
    return piece;
}