# Chess-Engine [WIP]
Standard chess engines use array , int arrays of size 64 (8x8 chess board) size consume arounds 2*64=128 bytes.
A bitboard is an 64 bit integer where each bit represents the position of the chess piece and to represent a chess board 12 bitboards are required (6 different white pieces + 6 different black pieces) which comes upto a size of 12*8=96 bytes.
This engine uses bit wise operations on bitboard to perform moves and check for illegal moves as well. After the chess engine has been designed with implementation of rules (checkmate etc), a machine learning algorithm will be designed so that the ai can decide which moves have better chances of winning and will learn it by playing with itself multiple number of times.
