
//individual module for the bishop move.
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
