rook_moves(int rank1,char file1,int rank2,char file2,char type)
{
 int index1=(rank1-1)*8 + (file1-96) -1;//ascii of a is 97
int index2=(rank2-1)*8 + (file2-96) -1;
u64 a=pieces[index1];
u64 b=pieces[index2];
int test;
//u64 a;
u64 c=a; 
	switch(type)
	{
		case 'w':
		case 'W':


//Piece Illegal Move
if(file2!=file1) && (rank1!=rank2)
{
cout<<"Invalid Move"<<endl;
test=1; 
}
			
		
			
if(test==0)
{
	if (file1==file2)
	{
		if(rank2>rank1)
		while(a!=b)
		{
			a=a>>8;
			 if(a&tboard==0)
			{
			cout<<"Invalid move"<<endl;
			break;
			}
	else {
		c=a>>8*(rank2-rank1);
		WRooks=WRooks|c;
		remove2(WRooks,a);  //Basically removing elements of a from the bitboard		
	}


			
		}
	else if(rank2<rank1)
	while(a!=b)
	{
	a=a<<8;
 	if(a&tboard==0)
	{
	cout<<"Invalid move"<<endl;
	break;
	}

else {
		c=c<<8*abs((rank2-rank1));
		WRooks=WRooks|c;
		remove2(WRooks,a);
	
}
		
	}

	
	}
		}
	}
}


if(rank1==rank2)
{
if(file1>file2) 
{
a=a<<(file1-file2); 
if(a&tboard==0)
{
cout<<"Invalid move"<<endl;
break;
}
	else	{
		c=c<<abs((file1-file2));
		WRooks=WRooks|c;
		remove2(WRooks,a);	
	}
	
	
}
else if(file2>file1)
 {
a=a>>(file2-file1); 
if(a&tboard==0)
{
cout<<"Invalid move"<<endl;
break;
} 
	else	{
		c=c>>abs((file1-file2));
		WRooks=WRooks|c;
		remove2(WRooks,a);
	}
	
	
}
}


		case 'B': 
		case 'b':
			









}


