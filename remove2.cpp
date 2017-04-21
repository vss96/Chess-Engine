// This function removes elements of the second bitboard from the first bitboard. Used in Rook

void remove2(u64 &a, u64 &b)
{
u64 temp=a&b;
temp=~temp;
a=temp;
tboard=tboard & a;

return;

}
