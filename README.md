# Chess-Engine
A Standard Chess-Lib that uses arrays, U64 arrays (8x8 chess board) called bitboards, which consumes around 2*64=128 bytes.

A bitboard is a 64 Bit Integer where each bit represents the position and type of a chess piece. To represent a complete chess board, 12 bitboards are required (6 different white pieces + 6 different black pieces), which comes upto a size of 12*8=96 bytes.

This engine uses bitwise operations on bitboards to perform moves, check for illegal moves as well. After the chess engine has been designed with implementation of rules (checkmate,castling,En-Passant etc), a machine learning algorithm(Specifically, Reinforced Learning) will be designed so that the A.I. can decide which moves have better chances of winning and will learn it by playing with itself multiple number of times.
