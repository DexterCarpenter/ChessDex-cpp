#pragma once

#include <string>
#include <stdexcept>
#include <ostream>
#include <array>

/* ========== TYPES ========== */
using algebraic = const std::string&; // algebraic notation

/* ========== ENUMS ========== */
enum E_COLOR {
    WHITE,
    BLACK,
    COLOR_NB
};

enum E_PIECE {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    PIECE_NB
};

enum E_SQUARE {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    SQ_NB
};

/* ========== STRUCTS ========== */
struct ST_PIECE_AT_SQR {
    E_COLOR     color;
    E_PIECE     piece;
    E_SQUARE    square;
};

/* ========== CONSTANTS ========== */
constexpr char FILE_OF[SQ_NB] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'
};

constexpr char RANK_OF[SQ_NB] = {
    '1', '1', '1', '1', '1', '1', '1', '1',
    '2', '2', '2', '2', '2', '2', '2', '2',
    '3', '3', '3', '3', '3', '3', '3', '3',
    '4', '4', '4', '4', '4', '4', '4', '4',
    '5', '5', '5', '5', '5', '5', '5', '5',
    '6', '6', '6', '6', '6', '6', '6', '6',
    '7', '7', '7', '7', '7', '7', '7', '7',
    '8', '8', '8', '8', '8', '8', '8', '8'
};

constexpr bool isLightSquare(E_SQUARE sq)
{
    int file = static_cast<int>(sq) % 8;
    int rank = static_cast<int>(sq) / 8;

    return (file + rank) % 2 == 0;
}

constexpr std::array<const char*, 6> PIECE_SAN_LETTER = {
    "P",         // Pawn
    "N",         // Knight
    "B",         // Bishop
    "R",         // Rook
    "Q",         // Queen
    "K"          // King
};

constexpr std::array<std::array<const char*, 6>, 2> PIECE_SYMBOL = {{
    // White row
    { "♙", "♘", "♗", "♖", "♕", "♔" },
    // Black row
    { "♟", "♞", "♝", "♜", "♛", "♚" }
}};

constexpr std::array<const char*, 2> SQUARE_SYMBOL = {
    "◻",  // White
    "◼"   // Black
};