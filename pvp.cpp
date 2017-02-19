#include<iostream>
using namespace std;
typedef unsigned long long u64;
class cboard
{
  private :
  u64 WKnights;
  u64 WPawns ;
  u64 WRooks ;
  u64 WBishops;
  u64 WKing;
  u64 WQueen;
  u64 BKnights;
  u64 BPawns ;
  u64 BRooks ;
  u64 BBishops;
  u64 BKing;
  u64 BQueen;
  u64 wboard;
  u64 bboard;
  u64 tboard;
  u64 pieces[64];
  public :
  	cboard()
  	{            
  	
  	//NOTE: We could also create different values for every piece to make it simple while printing the board
  		WKnights  =4755801206503243776;//0100001000000000000000000000000000000000000000000000000000000000
                WPawns    =71776119061217280;  //0000000011111111000000000000000000000000000000000000000000000000
  		WRooks    =9295429630892703744;//1000000100000000000000000000000000000000000000000000000000000000
  		WBishops  =2594073385365405696;//0010010000000000000000000000000000000000000000000000000000000000
  		WKing     =576460752303423488; //0000100000000000000000000000000000000000000000000000000000000000
  		WQueen    =1152921504606846976;//0001000000000000000000000000000000000000000000000000000000000000
  		BKnights  =66;                 //0000000000000000000000000000000000000000000000000000000001000010
  		BPawns    =65280;              //0000000000000000000000000000000000000000000000001111111100000000
  		BRooks    =129;                //0000000000000000000000000000000000000000000000000000000010000001
  		BBishops  =36;                 //0000000000000000000000000000000000000000000000000000000000100100
  		BKing     =8;                  //0000000000000000000000000000000000000000000000000000000000001000
  		BQueen    =16;                 //0000000000000000000000000000000000000000000000000000000000010000
		int i ;
		u64 x;
		for(i=0;i<64;i++)
		{	
	        x=pow(2,i);
		pieces[63-i]=  x;  // Each index has a bitboard for piece (ie) a1 ,b1 , c1 and so on 
	        }
	}	
	 total_board()
	{
		
		wboard=WKnights|WPawns|WRooks|WBishops|WKing|WQueen;
		bboard=BKnights|BPawns|BRooks|BBishops|BKing|BQueen;
		tboard=wboard|bboard;
	}
	
	 pawn_moves(int rank1,char file1,int rank2,char file2,char type)
	{
	   //Number of shifting positions will vary with the pawn taken 
                int index1=(rank1-1)*8 + (file1-96) -1;//ascii of a is 97
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 oroperand=pieces[index1];
		u64 oropshift=pieces[index2];
		 if(type='w' || type='W')
		 {	if((rank1==2 && rank2 >4 || rank2-rank1 > 1 )&& ((file1-file2!=0)&&oropshift|bboard==0))
			{ 	
			   cout<<"Invalid move"<<endl;
		   	   return 0;
			}
		       else
		       {
	           		WPawns= WPawns^oroperand;
		   		WPawns= WPawns|oropshift;
				 if(WPawns|bboard!=0)       //If a black piece is removed this block removes that piece from the bitboard
				 {
		          		BPawns=BPawns^oropshift;
				 	total_board();
			 	}
		 	}
		 }
		 else if(type='b' || type='B')
		 { 
			 if((rank1=7 && rank2<5 || rank1-rank2 >1 ) && ((file1-file2!=0)&&oropshift|wboard==0))
		   		{	 cout<<"Invalid move"<<endl;
	                		  return 0;
		   		}
		     	else 
		 		{
	        	   		BPawns=BPawns^oroperand;
	        	   		BPawns=BPawns|oropshift;
	      	   			if(BPawns|wboard!=0)            // Similar block for removing white piece
			 		{
		          		WPawns=WPawns^oropshift;
				 	total_board();
			 		}
		               }
	       	}
		 else
		 { cout<<"Invalid type "<<endl;
		   return 1;
		 }
		
	} 
       
    knight_moves(int rank1,char file1,int rank2,char file2,char type)
    {
	        int index1=(rank1-1)*8 + (file1-96) -1;
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 oroperand=pieces[index1];
		u64 oropshift=pieces[index2];
	switch(type)
	{
		case 'w' :
		case 'W' :  	if((abs(rank1-rank2)!=1 && abs(file1-file2)!=2 ) || (abs(rank1-rank2)!=2 && abs(file1-file2)!=1) ||wboard|oropshift==0)
	           		cout<<"Invalid move"<<endl;
	         	 	else 
	         	 	 {
	           			WPawns=WPawns^oroperand;
	           			WPawns=WPawns|oropshift;
	           			if(oropshift|bboard!=0)
					{
	           			BPawns=BPawns^oropshift;
	           			total_board();
					}
			  	 }
		      		 break;
	      case 'b' :
	      case 'B' :	        if((abs(rank1-rank2)!=1 && abs(file1-file2)!=2 ) || (abs(rank1-rank2)!=2 && abs(file1-file2)!=1) ||bboard|oropshift==0)
	           	        cout<<"Invalid move"<<endl;
	         	        else 
	          	         {
	           			BPawns=BPawns^oroperand;
	           			BPawns=BPawns|oropshift;
	           			if(oropshift|wboard!=0)
					{	
					WPawns=WPawns^oropshift;
	           			total_board();
					}
		       		 }
		     		 break;
	    default : cout<<"Invalid Type "<<endl;
		      cout<<"Try again "<<endl;
	}
}  
   bishop_moves(int rank1,char file1,int rank2,char file2,char type)
   {
        	int index1=(rank1-1)*8 + (file1-96) -1;
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 oroperand=pieces[index1];
		u64 oropshift=pieces[index2];
	   		u64 bopar=0;  //Convert this. Keeping it in this format for now for understanding

	   switch(type)
	   {
		     case 'w' :
		   case 'W' :


if((file1-file2=0) || abs(rank1-rank2)!=abs(file1-file2))
{
cout<<"Invalid move"<<endl;
 return 0;
}
if(file2>file1 && rank2>rank1)
{
if(rank2-rank1=x)
{
bopar=bopar>>9*x; 
}
WBishops=WBishops|bopar;
} 	
if(file2>file1 && rank2<rank1)
{
if(abs(rank2-rank1=x))
{
bopar=bopar>>9*x; 
}
WBishops=WBishops|bopar;
}
if(file2<file1 && rank2>rank1)
{
if(abs(rank2-rank1=x))
{
bopar=bopar<<9*x; 
}
WBishops=WBishops|bopar;
} 	
else {
 if(abs(rank2-rank1=x))
{
bopar=bopar>>9*x; 
}
WBishops=WBishops|bopar;
}
total_board();	
break;

		   case 'b' :
		   case 'B' :

if((file1-file2=0) || abs(rank1-rank2)!=abs(file1-file2))
{
cout<<"Invalid move"<<endl;
 return 0;
}
if(file2>file1 && rank2>rank1)
{
if(rank2-rank1=x)
{
bopar=bopar>>9*x; 
}
BBishops=BBishops|bopar;
} 	
if(file2>file1 && rank2<rank1)
{
if(abs(rank2-rank1=x))
{
bopar=bopar>>9*x; 
}
BBishops=BBishops|bopar;
}
if(file2<file1 && rank2>rank1)
{
if(abs(rank2-rank1=x))
{
bopar=bopar<<9*x; 
}
BBishops=BBishops|bopar;
} 	
else {
 if(abs(rank2-rank1=x))
{
bopar=bopar>>9*x; 
}
BBishops=BBishops|bopar;
}	

total_board();
  break;
			   default : cout<<"Invalid type"<<endl;
}
	
	
	
	rook_moves(int rank1,char file1,int rank2,char file2,char type)
{

        int index1=(rank1-1)*8 + (file1-96) -1;
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 oroperand=pieces[index1];
		u64 oropshift=pieces[index2];
		u64 temp;
		u64 temp2;
		u64 x=abs(rank2-rank1);
		switch(type)
	{
		
		case w :
		case W : 
if(rank2>rank1 && file 1!=file2 || rank2<rank1 && file1!=file2)
{
cout<<"Invalid Move"<<endl; 
}

//Horizontal Moves: Bruteforce so super long
if(rank1==rank2)
{
if(file1==a && file2==b)
{
temp=WRooks>>1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==a && file2==c)
{
temp=WRooks>>2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==a && file2==d)
{
temp=WRooks>>3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==a && file2==e)
{
temp=WRooks>>4;
WRooks=WRooks^temp; 
total_board();
}
if(file1==a && file2==f)
{
temp=WRooks>>5;
WRooks=WRooks^temp; 
total_board();
}
if(file1==a && file2==g)
{
temp=WRooks>>6;
WRooks=WRooks^temp; 
total_board();
}
if(file1==a && file2==h)
{
temp=WRooks>>7;
WRooks=WRooks^temp; 
total_board();
}
if(file1==b && file2==a)
{
temp=WRooks<<1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==b && file2==c)
{
temp=WRooks>>1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==b && file2==d)
{
temp=WRooks>>2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==b && file2==e)
{
temp=WRooks>>3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==b && file2==f)
{
temp=WRooks>>4;
WRooks=WRooks^temp; 
total_board();
}
if(file1==b && file2==g)
{
temp=WRooks>>5;
WRooks=WRooks^temp; 
total_board();
}
if(file1==b && file2==h)
{
temp=WRooks>>6;
WRooks=WRooks^temp; 
total_board();
}



if(file1==c && file2==a)
{
temp=WRooks<<2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==c && file2==b)
{
temp=WRooks<<1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==c && file2==d)
{
temp=WRooks>>1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==c && file2==e)
{
temp=WRooks>>2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==c && file2==f)
{
temp=WRooks>>3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==c && file2==g)
{
temp=WRooks>>4;
WRooks=WRooks^temp; 
total_board();
}
if(file1==c && file2==h)
{
temp=WRooks>>5;
WRooks=WRooks^temp; 
total_board();
}


if(file1==d && file2==a)
{
temp=WRooks<<3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==d && file2==b)
{
temp=WRooks<<2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==d && file2==c)
{
temp=WRooks<<1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==d && file2==e)
{
temp=WRooks>>1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==d && file2==f)
{
temp=WRooks>>2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==d && file2==g)
{
temp=WRooks>>3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==d && file2==h)
{
temp=WRooks>>4;
WRooks=WRooks^temp; 
total_board();
}





if(file1==e && file2==a)
{
temp=WRooks<<4;
WRooks=WRooks^temp; 
total_board();
}
if(file1==e && file2==b)
{
temp=WRooks<<3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==e && file2==c)
{
temp=WRooks<<2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==3 && file2==d)
{
temp=WRooks<<1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==e && file2==f)
{
temp=WRooks>>1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==e && file2==g)
{
temp=WRooks>>2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==e && file2==h)
{
temp=WRooks>>3;
WRooks=WRooks^temp; 
total_board();
}


if(file1==f && file2==a)
{
temp=WRooks<<5;
WRooks=WRooks^temp; 
total_board();
}
if(file1==f && file2==b)
{
temp=WRooks<<4;
WRooks=WRooks^temp; 
total_board();
}
if(file1==f && file2==c)
{
temp=WRooks<<3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==f && file2==d)
{
temp=WRooks<<2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==f && file2==e)
{
temp=WRooks<<1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==f && file2==g)
{
temp=WRooks>>1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==f && file2==h)
{
temp=WRooks>>2;
WRooks=WRooks^temp; 
total_board();
}




if(file1==g && file2==a)
{
temp=WRooks<<6;
WRooks=WRooks^temp; 
total_board();
}
if(file1==g && file2==b)
{
temp=WRooks<<5;
WRooks=WRooks^temp; 
total_board();
}
if(file1==g && file2==c)
{
temp=WRooks<<4;
WRooks=WRooks^temp; 
total_board();
}
if(file1==g && file2==d)
{
temp=WRooks<<3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==g && file2==e)
{
temp=WRooks<<2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==g && file2==f)
{
temp=WRooks<<1;
WRooks=WRooks^temp; 
total_board();
}
if(file1==g && file2==h)
{
temp=WRooks>>1;
WRooks=WRooks^temp; 
total_board();
}

if(file1==h && file2==a)
{
temp=WRooks<<7;
WRooks=WRooks^temp; 
total_board();
}
if(file1==h && file2==b)
{
temp=WRooks<<6;
WRooks=WRooks^temp; 
total_board();
}
if(file1==h && file2==c)
{
temp=WRooks<<5;
WRooks=WRooks^temp; 
total_board();
}
if(file1==h && file2==d)
{
temp=WRooks<<4;
WRooks=WRooks^temp; 
total_board();
}
if(file1==h && file2==e)
{
temp=WRooks<<3;
WRooks=WRooks^temp; 
total_board();
}
if(file1==h && file2==f)
{
temp=WRooks<<2;
WRooks=WRooks^temp; 
total_board();
}
if(file1==h && file2==g)
{
temp=WRooks<<1;
WRooks=WRooks^temp; 
total_board();
}
}

//Vertical moves 
if(file1==file2)
{
if(rank2>rank1)
{
temp2=WRooks>>8*x;
WRooks=WRooks^temp2;
total_board();
}
if(rank1>rank2)
{
temp2=WRooks<<8*x;
WRooks=WRooks^temp2;
total_board();
}
}

		case 'b':
		case 'B': 
if(rank2>rank1 && file 1!=file2 || rank2<rank1 && file1!=file2)
{
cout<<"Invalid Move"<<endl;
}

//Horizontal Moves: Bruteforce, so super long
if(rank1==rank2)
{
if(file1==a && file2==b)
{
temp=BRooks>>1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==a && file2==c)
{
temp=BRooks>>2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==a && file2==d)
{
temp=BRooks>>3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==a && file2==e)
{
temp=BRooks>>4;
BRooks=BRooks^temp; 
total_board();
}
if(file1==a && file2==f)
{
temp=BRooks>>5;
BRooks=BRooks^temp; 
total_board();
}
if(file1==a && file2==g)
{
temp=BRooks>>6;
BRooks=BRooks^temp; 
total_board();
}
if(file1==a && file2==h)
{
temp=BRooks>>7;
BRooks=BRooks^temp; 
total_board();
}
if(file1==b && file2==a)
{
temp=BRooks<<1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==b && file2==c)
{
temp=BRooks>>1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==b && file2==d)
{
temp=BRooks>>2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==b && file2==e)
{
temp=BRooks>>3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==b && file2==f)
{
temp=BRooks>>4;
BRooks=BRooks^temp; 
total_board();
}
if(file1==b && file2==g)
{
temp=BRooks>>5;
BRooks=BRooks^temp; 
total_board();
}
if(file1==b && file2==h)
{
temp=BRooks>>6;
BRooks=BRooks^temp; 
total_board();
}



if(file1==c && file2==a)
{
temp=BRooks<<2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==c && file2==b)
{
temp=BRooks<<1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==c && file2==d)
{
temp=BRooks>>1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==c && file2==e)
{
temp=BRooks>>2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==c && file2==f)
{
temp=BRooks>>3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==c && file2==g)
{
temp=BRooks>>4;
BRooks=BRooks^temp; 
total_board();
}
if(file1==c && file2==h)
{
temp=BRooks>>5;
BRooks=BRooks^temp; 
total_board();
}


if(file1==d && file2==a)
{
temp=BRooks<<3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==d && file2==b)
{
temp=BRooks<<2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==d && file2==c)
{
temp=BRooks<<1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==d && file2==e)
{
temp=BRooks>>1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==d && file2==f)
{
temp=BRooks>>2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==d && file2==g)
{
temp=BRooks>>3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==d && file2==h)
{
temp=BRooks>>4;
BRooks=BRooks^temp; 
total_board();
}





if(file1==e && file2==a)
{
temp=BRooks<<4;
BRooks=BRooks^temp; 
total_board();
}
if(file1==e && file2==b)
{
temp=BRooks<<3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==e && file2==c)
{
temp=BRooks<<2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==3 && file2==d)
{
temp=BRooks<<1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==e && file2==f)
{
temp=BRooks>>1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==e && file2==g)
{
temp=BRooks>>2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==e && file2==h)
{
temp=BRooks>>3;
BRooks=BRooks^temp; 
total_board();
}


if(file1==f && file2==a)
{
temp=BRooks<<5;
BRooks=BRooks^temp; 
total_board();
}
if(file1==f && file2==b)
{
temp=BRooks<<4;
BRooks=BRooks^temp; 
total_board();
}
if(file1==f && file2==c)
{
temp=BRooks<<3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==f && file2==d)
{
temp=BRooks<<2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==f && file2==e)
{
temp=BRooks<<1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==f && file2==g)
{
temp=BRooks>>1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==f && file2==h)
{
temp=BRooks>>2;
BRooks=BRooks^temp; 
total_board();
}




if(file1==g && file2==a)
{
temp=BRooks<<6;
BRooks=BRooks^temp; 
total_board();
}
if(file1==g && file2==b)
{
temp=BRooks<<5;
BRooks=BRooks^temp; 
total_board();
}
if(file1==g && file2==c)
{
temp=BRooks<<4;
BRooks=BRooks^temp; 
total_board();
}
if(file1==g && file2==d)
{
temp=BRooks<<3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==g && file2==e)
{
temp=BRooks<<2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==g && file2==f)
{
temp=BRooks<<1;
BRooks=BRooks^temp; 
total_board();
}
if(file1==g && file2==h)
{
temp=BRooks>>1;
BRooks=BRooks^temp; 
total_board();
}

if(file1==h && file2==a)
{
temp=BRooks<<7;
BRooks=BRooks^temp; 
total_board();
}
if(file1==h && file2==b)
{
temp=BRooks<<6;
BRooks=BRooks^temp; 
total_board();
}
if(file1==h && file2==c)
{
temp=BRooks<<5;
BRooks=BRooks^temp; 
total_board();
}
if(file1==h && file2==d)
{
temp=BRooks<<4;
BRooks=BRooks^temp; 
total_board();
}
if(file1==h && file2==e)
{
temp=BRooks<<3;
BRooks=BRooks^temp; 
total_board();
}
if(file1==h && file2==f)
{
temp=BRooks<<2;
BRooks=BRooks^temp; 
total_board();
}
if(file1==h && file2==g)
{
temp=BRooks<<1;
BRooks=BRooks^temp; 
total_board();
}
}

//Vertical moves 
if(file1==file2)
{
if(rank2>rank1)
{
temp2=BRooks>>8*x;
BRooks=BRooks^temp2;
total_board();
}
if(rank1>rank2)
{
temp2=BRooks<<8*x;
BRooks=BRooks^temp2;
total_board();
}
}
}
}


};
int main()
{

return 0;

}
