#pragma once

#include "../common.h"

class Piece { 
    // Represents a chess piece in color and type
    private:
        E_COLOR color; // color of the piece
        E_PIECE piece; // type of piece
    public:
        // Constructor
        Piece(E_COLOR _color, E_PIECE _piece);

        // Getters
        E_COLOR getColor() const; // get color of piece
        E_PIECE getPiece() const; // get type of piece
};