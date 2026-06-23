#pragma once

#include <cstdint>

#include "../common.h"
#include "piece.h"
#include "move.h"

class Board {
    private:
        std::uint64_t   bitboard[COLOR_NB][PIECE_NB]; // bitboard representation of all pieces
        MoveLog         move_log; // keeps a record of the move history

        bool            white_to_move; // TRUE if white's turn to play
        E_COLOR         player_color; // color of the player to move
        E_COLOR         opponent_color; // color of the opponent
        
        // Private Methods
        void _flipTurn(); // flips the turn to the other player, updates player_color and opponent_color accordingly

    public:
        // Constructor
        Board();

        // Methods
        void    placePiece(ST_PIECE_AT_SQR _pas); // places a piece on the board
        void    placePiece(E_COLOR _color, E_PIECE _piece, E_SQUARE _square); // places a piece on the board
        void    removePiece(ST_PIECE_AT_SQR _pas); // removes a specific piece from the board
        void    removePiece(E_COLOR _color, E_PIECE _piece, E_SQUARE _square); // removes a specific piece from the board
        void    removePiece(E_SQUARE _square); // removes any piece from the given square, loops through all bitboards
        void    clearBoard(); // removes all pieces from the board
        E_PIECE pieceAtSquare(E_SQUARE _square); // returns the piece at a given square, or PIECE_NB if empty

        void    makeMove(Move _move); // makes a move on the board
        void    undoMove(); // undos the last move made on the board

        void    setupStartingPosition(); // sets up the board to the starting position

        // Move Generation
        std::vector<Move> getPawnMoves();   // generates all possible pawn moves for the current player
        std::vector<Move> getKnightMoves(); // generates all possible knight moves for the current player
        std::vector<Move> getBishopMoves(); // generates all possible bishop moves for the current player
        std::vector<Move> getRookMoves();   // generates all possible rook moves for the current player
        std::vector<Move> getQueenMoves();  // generates all possible queen moves for the current player
        std::vector<Move> getKingMoves();   // generates all possible king moves for the current player
        std::vector<Move> getAllMoves();    // generates all possible moves for the current player

        // Display
        void renderBoard(); // displays the board in the console

};