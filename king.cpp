king_moves( int rank1,char file1,int rank2,char file2,char type)
{
int index1=(rank1-1)*8 + (file1-96) -1;
int index2=(rank2-1)*8 + (file2-96) -1;
u64 a=pieces[index1];
u64 b=pieces[index2];

//invalid moves
if((abs(rank1-rank2)!=1) || (abs(file1-file2)!=1))
{
cout<<"Invalid move";
}
switch(type)
{


case 'w':
case 'W':
case 'b':
case 'B': 

if(file1>file2 && rank1==rank2)
{
//left
WKing=WKing<<1;
}
if(file1<file2 && rank1==rank2)
{
WKing=Wking>>1;
}
if(rank2>rank1 && file2>file1)
{
WKing=WKing>>9;
}
if(rank1>rank2 && file1<file2)
{
WKing=WKing<<9
}





