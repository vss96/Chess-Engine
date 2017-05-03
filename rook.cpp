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
			cout<<"Invalid move"<<endl;  // this is for checking if pieces are in between
			break;
			}
		}
		if(a==b)
		{
		                                  //c=a>>8*(rank2-rank1); dont need this since a is already incremented in the previous while loop
		WRooks=WRooks^c;
		WRooks=WRooks|a;                       //see the change here 
		if(a&bboard!=0)                         //only remove piece if u find a black piece there      
		remove(a,1);
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


