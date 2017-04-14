// This function removes elements of the second bitboard from the first bitboard. Used in Rook

void (u64 *a, u64 *b)
{
u64 temp=a&b;
temp=~temp;
a=temp;


return;

}
