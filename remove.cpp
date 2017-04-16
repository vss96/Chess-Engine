remove(u64 a , int type)
{
switch(type)
{
case 0 :
        if(a&WPawns!=0)
        WPawns=WPawns^a;
        else if(a&WBishops!=0)
        WBishops=WBishops^a;
        else if(a&WKnights!=0)
        WKnights=WKnights^a;
        else if(a&WRooks!=0)
        WRooks=WRooks^a;
        else if(a&WQueen!=0)
        WQueen=WQueen^a;
        else
        {
        cout<<"Game over,Black Wins"<<endl;
         getch();
          exit(0);
          }
        break;
case 1 :if(a&BPawns!=0)
        BPawns=BPawns^a;
        else if(a&BBishops!=0)
        BBishops=BBishops^a;
        else if(a&BKnights!=0)
        BKnights=BKnights^a;
        else if(a&BRooks!=0)
        BRooks=BRooks^a;
        else if(a&BQueen!=0)
        BQueen=BQueen^a;
        else
        {  cout<<"Game over,White Wins"<<endl;
          getch();
          exit(0);
          }
          break;
          }
          total_board();
          }
