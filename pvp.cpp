#include<iostream>
#include<math.h>
#include<conio.h>
#include<process.h>
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
  		WRooks    =9295429630892703744U;//1000000100000000000000000000000000000000000000000000000000000000
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
	check_piece(u64 a , char type,int p)
	{
		switch(type)
		{
			case 'w' :
			case 'W' : 
			           switch(p)
				   {
					   case 0 :
						   if(a&WPawns==0)
					   	    {
						     cout<<"Given piece doesnt belong to pawn"<<endl;
						     getch();
						     exit(0);
					   	    }
						   break;
					   case 1 :
						   if(a&WKnights==0)
					   	    {
						      cout<<"Given piece doesnt belong to knight"<<endl;
					              getch();
					              exit(0);
						   }
						   break;
					   case 2 :
						   if(a&WBishops==0)
						   {
						       cout<<"Given piece doesnt belong to bishop"<<endl;
						       getch();
						       exit(0);
						   }
						   break;
					   case 3 :
						   if(a&WRooks==0)
						   {
						       cout<<"Given piece doesnt belong to rook"<<endl;
						       getch();
						       exit(0);
						   }
						   break;
					   case 4 :
						   if(a&WQueen==0)
						   {
						       cout<<"Given piece isnt a queen"<<endl;
						       getch();
						       exit(0);
						   }
						   break;
					   case 5 :
						   if(a&WKing==0)
						   {
						       cout<<"Given piece isnt a king"<<endl;
						       getch();
						       exit(0);
						   }
						   break;
				        default : cout<<"Invalid entry value"<<endl
				   }
				break;
			case 'b' :
			case 'B' :
				  switch(p)
				   {
					   case 0 :
						   if(a&BPawns==0)
					   	    {
						     cout<<"Given piece doesnt belong to pawn"<<endl;
						     getch();
						     exit(0);
					   	    }
						   break;
					   case 1 :
						   if(a&BKnights==0)
					   	    {
						      cout<<"Given piece doesnt belong to knight"<<endl;
					              getch();
					              exit(0);
						   }
						   break;
					   case 2 :
						   if(a&BBishops==0)
						   {
						       cout<<"Given piece doesnt belong to bishop"<<endl;
						       getch();
						       exit(0);
						   }
						   break;
					   case 3 :
						   if(a&BRooks==0)
						   {
						       cout<<"Given piece doesnt belong to rook"<<endl;
						       getch();
						       exit(0);
						   }
						   break;
					   case 4 :
						   if(a&BQueen==0)
						   {
						       cout<<"Given piece isnt a queen"<<endl;
						       getch();
						       exit(0);
						   }
						   break;
					   case 5 :
						   if(a&BKing==0)
						   {
						       cout<<"Given piece isnt a king"<<endl;
						       getch();
						       exit(0);
						   }
						   break;
				        default : cout<<"Invalid entry value"<<endl
				   }
				break;
				default : cout<<"Invalid entry"<<endl;
		}
	}
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
	      case 1 :
		       if(a&BPawns!=0)
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
	 pawn_moves(char file1,int rank1,char file2,int rank2,char type)
	  {
	   //Number of shifting positions will vary with the pawn taken 
                int index1=(rank1-1)*8 + (file1-96) -1;//ascii of a is 97
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 a=pieces[index1];
		u64 b=pieces[index2];
		 check_piece(a,type,0);
		 if(type=='w' || type=='W')
		 {	if((rank1==2 && rank2 >4 && rank2-rank1 > 1 )||((file1-file2!=0)&&b|bboard==0))
			{ 	
			   cout<<"Invalid move"<<endl;
		   	   return 0;
			}
		       else
		       {
	           		WPawns= WPawns^a;
		   		WPawns= WPawns|b;
				 if(b&bboard!=0)       //If a black piece is removed this block removes that piece from the bitboard
				 {
		          	    remove(b,1);
				 	
			 	}
			       total_board();
		 	}
		 }
		 else if(type=='b' || type=='B')
		 { 
			 if((rank1=7 && rank2<5 && rank1-rank2 >1 ) && ((file1-file2!=0)&&b|wboard==0))
		   		{	 cout<<"Invalid move"<<endl;
	                		  return 0;
		   		}
		     	else 
		 		{
	        	   		BPawns=BPawns^a;
	        	   		BPawns=BPawns|b;
	      	   			if(b&wboard!=0)            // Similar block for removing white piece
			 		{
		          	         remove(b,0);
				 	
			 		}
				total_board();
		               }
	       	}
		 else
		 { cout<<"Invalid type "<<endl;
		   
		 }
		
	} 
       
    knight_moves(char file1,int rank1,char file2,int rank2,char type)
    {
	        int index1=(rank1-1)*8 + (file1-96) -1;
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 a=pieces[index1];
		u64 b=pieces[index2];
	    check_piece(a,type,1);
	switch(type)
	{
		case 'w' :
		case 'W' :  	if((abs(rank1-rank2)!=1 && abs(file1-file2)!=2 ) || (abs(rank1-rank2)!=2 && abs(file1-file2)!=1) ||wboard|b==0)
	           		cout<<"Invalid move"<<endl;
	         	 	else 
	         	 	 {
	           			WKnights=WKnights^a;
	           			WKnights=WKnights|b;
	           			if(b&bboard!=0)
					{
	           			remove(b,1);
	           			
					}
					total_board();
			  	 }
		      		 break;
	      case 'b' :
	      case 'B' :	        if((abs(rank1-rank2)!=1 && abs(file1-file2)!=2 ) || (abs(rank1-rank2)!=2 && abs(file1-file2)!=1) ||bboard|b==0)
	           	        cout<<"Invalid move"<<endl;
	         	        else 
	          	         {
	           			BKnights=BKnights^a;
	           			BKnights=BKnights|b;
	           			if(b&wboard==1)
					{	
					remove(b,0);
	           			
					}
					total_board();
		       		 }
		     		 break;
	    default : cout<<"Invalid Type "<<endl;
		      cout<<"Try again "<<endl;
	}
}  
 bishop_moves( int rank1,char file1,int rank2,char file2,char type)
{
int index1=(rank1-1)*8 + (file1-96) -1;
int index2=(rank2-1)*8 + (file2-96) -1;
u64 a=pieces[index1];
u64 b=pieces[index2];
u64 c=a;
    if(abs(rank1-rank2)==abs(file1-file2))
    switch(type)
    {
    case 'w':
    case 'W':  
		   if(file1<file2)
		     {
			if(rank1<rank2)
			  {
			    while(a!=b)
			     {
			      a=a>>9;
		              if(a&tboard!=0)
				 {
			           cout<<"Invalid move"<<endl;
			     	   break;
			         }
			     }
			    if(a==b)
			     {
				WBishops=WBishops^c;
				WBishops=WBishops|a;
				    if(a&bboard!=0)
				    {
					    remove(a,1);
				    }
			        total_board();
			     }
			  }
				else if(rank1>rank2)
				  {
				     while(a!=b)
					 { 
					  a=a<<7;
					  if(a&tboard!=0)
					    {
						 cout<<"Invalid move"<<endl;
						 break;
					    }
					 }
					if(a==b)
					{
						WBishops=WBishops^c;
						WBishops=WBishops|a;
						if(a&bboard!=0)
						{
							remove(a,1);
						}
					}
			           }
				else
				{
				cout<<"Invalid move"<<endl;
				}
			  }
	      		else if(file1>file2)
			{
				if(rank1>rank2)
				{
				 while(a!=b)
				 {
				   a=a>>7  ;
				  if(a&tboard!=0)
				   {
				    cout<<"Invalid move"<<endl;
				    break;
			       	   }
				 }
					if(a==b)
			    		 {
						WBishops=WBishops^c;
						WBishops=WBishops|a;
				  		  if(a&bboard!=0)
				   		 {
					   	 remove(a,1);
				  	 	 }
			      		 	 total_board();
					 }
				}
				 else if(rank1<rank2)
 		        	 {
	          		   while(a!=b)
				   {
					   a=a<<9  ;
					   if(a&tboard!=0)
					   {
					     cout<<"Invalid move"<<endl;
				             break;
					   }
				   }
					 if(a==b)
			    		 {
						WBishops=WBishops^c;
						WBishops=WBishops|a;
				  		  if(a&bboard!=0)
				   		 {
					   	 remove(a,1);
				  	 	 }
			      		 	 total_board();
					 }
				 }
				else 
			   	{
		          	 cout<<"Invalid move"<<endl;
				}
			}
		    else
		    {
			    cout<<"Invalid move"<<endl;
		    }
                break;
		 
   case 'b' :
   case 'B' :
		        if(file1<file2)
		     {
			if(rank1<rank2)
			  {
			    while(a!=b)
			     {
			      a=a>>9;
		              if(a&tboard!=0)
				 {
			           cout<<"Invalid move"<<endl;
			     	   break;
			         }
			     }
			    if(a==b)
			     {
				BBishops=BBishops^c;
				BBishops=BBishops|a;
				    if(a&wboard!=0)
				    {
					    remove(a,0);
				    }
			        total_board();
			     }
			  }
				else if(rank1>rank2)
				  {
				     while(a!=b)
					 { 
					  a=a<<7;
					  if(a&tboard!=0)
					    {
						 cout<<"Invalid move"<<endl;
						 break;
					    }
					 }
					if(a==b)
					{
						BBishops=BBishops^c;
						BBishops=BBishops|a;
						if(a&wboard!=0)
						{
							remove(a,0);
						}
				  }
				}
				else
				{
				cout<<"Invalid move"<<endl;
				}
			  }
	      		else if(file1>file2)
			{
				if(rank1>rank2)
				{
				 while(a!=b)
				 {
				   a=a>>7  ;
				  if(a&tboard!=0)
				   {
				    cout<<"Invalid move"<<endl;
				    break;
			       	   }
				 }
					if(a==b)
					{
						BBishops=BBishops^c;
						BBishops=BBishops|a;
						if(a&wboard!=0)
						{
							remove(a,0);
						}
					}
				}
				 else if(rank1<rank2)
 		        	 {
	          		   while(a!=b)
				   {
					   a=a<<9  ;
					   if(a&tboard!=0)
					   {
					     cout<<"Invalid move"<<endl;
				             break;
					   }
				   }
					 if(a==b)
					{
						BBishops=BBishops^c;
						BBishops=BBishops|a;
						if(a&wboard!=0)
						{
							remove(a,0);
						}
				  	}
				 }
				else 
			   	{
		          	 cout<<"Invalid move"<<endl;
				}
			}
	case 'q' :
				if(file1<file2)
		    	 	{
				if(rank1<rank2)
			 	 {
			  	  while(a!=b)
			    	 {
			     	 a=a>>9;
		           	   if(a&tboard!=0)
				 	{
			           	cout<<"Invalid move"<<endl;
			     	   	break;
			        	 }
			     	 }
			   	 	if(a==b)
			    		 {
						WQueen=WQueen^c;
						WQueen=WQueen|a;
				  		  if(a&bboard!=0)
				   		 {
					   	 remove(a,1);
				  	 	 }
			      		 	 total_board();
					 }
			 	 }
				else if(rank1>rank2)
				  {
				     while(a!=b)
					 { 
					  a=a<<7;
					  if(a&tboard!=0)
					    {
						 cout<<"Invalid move"<<endl;
						 break;
					    }
					 }
					if(a==b)
					{
						WQueen=WQueen^c;
						WQueen=WQueen|a;
						if(a&bboard!=0)
						{
							remove(a,1);
						}
					}
			           }
				else
				{
				cout<<"Invalid move"<<endl;
				}
			  }
	      		else if(file1>file2)
			{
				if(rank1>rank2)
				{
				 while(a!=b)
				 {
				   a=a>>7  ;
				  if(a&tboard!=0)
				   {
				    cout<<"Invalid move"<<endl;
				    break;
			       	   }
				 }
					if(a==b)
			    		 {
						WQueen=WQueen^c;
						WQueen=WQueen|a;
				  		  if(a&bboard!=0)
				   		 {
					   	 remove(a,1);
				  	 	 }
			      		 	 total_board();
					 	}
					 }
				 else if(rank1<rank2)
 		        	 {
	          		   while(a!=b)
				   {
					   a=a<<9  ;
					   if(a&tboard!=0)
					   {
					     cout<<"Invalid move"<<endl;
				             break;
					   }
				   }
					 if(a==b)
			    		 {
						WQueen=WQueen^c;
						WQueen=WQueen|a;
				  		  if(a&bboard!=0)
				   		 {
					   	 remove(a,1);
				  	 	 }
			      		 	 total_board();
					 	}
				 }
			
				else 
			   	{
		          	 cout<<"Invalid move"<<endl;
				}
			}
		
		    else
		    {
			    cout<<"Invalid move"<<endl;
		    }
               	    break;
         case 'Q' :
				if(file1<file2)
		    	 	{
				if(rank1<rank2)
			 	 {
			  	  while(a!=b)
			    	 {
			     	 a=a>>9;
		           	   if(a&tboard!=0)
				 	{
			           	cout<<"Invalid move"<<endl;
			     	   	break;
			        	 }
			     	 }
			   	 	if(a==b)
			    		 {
						BQueen=BQueen^c;
						BQueen=BQueen|a;
				  		  if(a&wboard!=0)
				   		 {
					   	 remove(a,0);
				  	 	 }
			      		 	 total_board();
					 }
			 	 }
				else if(rank1>rank2)
				  {
				     while(a!=b)
					 { 
					  a=a<<7;
					  if(a&tboard!=0)
					    {
						 cout<<"Invalid move"<<endl;
						 break;
					    }
					 }
					if(a==b)
			    		 {
						BQueen=BQueen^c;
						BQueen=BQueen|a;
				  		  if(a&wboard!=0)
				   		 {
					   	 remove(a,0);
				  	 	 }
			      		 	 total_board();
					 }
			           }
				else
				{
				cout<<"Invalid move"<<endl;
				}
			  }
	      		else if(file1>file2)
				{
				if(rank1>rank2)
				{
				 while(a!=b)
				 {
				   a=a>>7  ;
				  if(a&tboard!=0)
				   {
				    cout<<"Invalid move"<<endl;
				    break;
			       	   }
				 }
			
					if(a==b)
			    		 {
						BQueen=BQueen^c;
						BQueen=BQueen|a;
				  		  if(a&wboard!=0)
				   		 {
					   	 remove(a,0);
				  	 	 }
			      		 	 total_board();
					 	}
					 }
				 else if(rank1<rank2)
 		        	 {
	          		   while(a!=b)
				   {
					   a=a<<9  ;
					   if(a&tboard!=0)
					   {
					     cout<<"Invalid move"<<endl;
				             break;
					   }
				   }
					 if(a==b)
			    		 {
						BQueen=BQueen^c;
						BQueen=BQueen|a;
				  		  if(a&wboard!=0)
				   		 {
					   	 remove(a,0);
				  	 	 }
			      		 	 total_board();
					 }
				 }
				else 
			   	{
		          	 cout<<"Invalid move"<<endl;
				}
			}
		    else
		    {
			    cout<<"Invalid move"<<endl;
		    }
               	   break;
		   

				default: cout<<"Invalid color"<<endl;
			}                                								
	}
	u64 rook_moves(char file1,int rank1,char file2,int rank2,char type)
{
 int index1=(rank1-1)*8 + (file1-96) -1;//ascii of a is 97
int index2=(rank2-1)*8 + (file2-96) -1;
u64 a=pieces[index1];
u64 b=pieces[index2];
int test=0;
//u64 a;
u64 c=a; 
	switch(type)
	{
		case 'w':
		case 'W':
//Piece Illegal Move
if((file2!=file1) && (rank1!=rank2))
{
cout<<"Invalid Move"<<endl;
test=1; 
}
if(test==0)
{
	if (file1==file2)
	{
		if(rank2>rank1)
		{
		
		while(a!=b)
		{
			a=a>>8;
			 if(a&tboard==0)
			{
			cout<<"Invalid move"<<endl;  // this is for checking if pieces are in between
			break;
			}
		}
		if(a==b)
		{
		                                  
		WRooks=WRooks^c;
		WRooks=WRooks|a;                       
		if(a&bboard!=0)                         //only remove piece if u find a black piece there      
		remove(a,1);
		}
		}
		else if(rank1>rank2)
		{
			while(a!=b)
			{
			a=a<<8;
			if(a&tboard==0)
			{
				cout<<"Invalid move"<<endl;
				break;
			}
			}
			if(a==b)
			{
				WRooks=WRooks^c;
				WRooks=WRooks|a;
				if(a&bboard!=0)
				remove(a,1);
			}
		}
	}
	else if(rank1==rank2)
	 {
	 	if(file1>file2)
	 	{
	 		while(a!=b)
	 		{
	 			a=a>>1;
	 			if(a&tboard==0)
	 			{
	 				cout<<"Invalid move"<<endl;
	 				break;
				 }
			}
			if(a==b)
			{
				WRooks=WRooks^c;
				WRooks=WRooks|a;
				if(a&bboard!=0)
				remove(a,1);
			}
			}
			else if(file1<file2)
			{
				while(a!=b)
				{
					a=a<<1;
					if(a&tboard==0)
					{
						cout<<"Invalid move"<<endl;
						break;
					}
				}
				if(a==b)
				{
					WRooks=WRooks^c;
					WRooks=WRooks|a;
					if(a&bboard!=0)
					remove(a,1);
					
				}
			}
			 }
		 }
	 }
}


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
};
int main()
{

return 0;

}
