
queen_moves(char file1,int rank1,char file2,int rank2,char type)
{
  switch(type)
  {
    case 'w' :
    case 'W' :
  if(abs(rank1-rank2)==int(abs(file1-file2)))
    bishop_moves(file1,rank1,file2,rank2,'q');
      else if((rank1-rank2)*(file1-file2)==0)
        rook_moves(file1,rank1,file2,rank2,'q');
      else
      cout<<"Invalid move"<<endl;
      break;
    case 'b' :
    case 'B' :
     if(abs(rank1-rank2)==int(abs(file1-file2)))
    bishop_moves(file1,rank1,file2,rank2,'Q');
      else if((rank1-rank2)*(file1-file2)==0)
        rook_moves(file1,rank1,file2,rank2,'Q');
      else
      cout<<"Invalid move"<<endl;
      break;
      default : cout<<"Invalid color"<<endl;
  }
}
