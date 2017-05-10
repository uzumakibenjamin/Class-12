/*
	Define a class PHOTO in C++ with the following description.

		Private members:
			Pno (Photo number of type integer)
			Category (Photo Category of type string)
			Exhibit (Exhibition Gallery of type string)
			FixExhibit -A member function to assign Exhibition Gallery as per Category as shown in the following table.

						Category	Exhibit
						--------	-------
						Antique		Zaveri
						Modern		Johnsen
						Classic		Terenida

		Public members: 
			Register() -A function to allow user to enter values Pno, Category and call FixExhibit() function.
			ViewAll() -A function to display all the data members.

Develop a complete C++ program to enter details of 5 Photos and do the following.
	
	1.Display details of all the photos(void ViewAll())
	2.Search for a photo based on category(void Search()).

Author: Benjamin Jacob Reji
		(2017-2018)

*/

# include <iostream>
# include <string.h>
	using namespace std;
	
class PHOTO
	{
		int Pno;
		char Category[15], Exhibit[15];
		
		void FixExhibit ()
			{
				if(strcmpi(Category,"antique"))
					strcpy(Exhibit,"Zaveri");
				else if(strcmpi(Category,"modern"))
					strcpy(Exhibit,"Johnsen");
				else if(strcmpi(Category,"classic"))
					strcpy(Exhibit,"Terenida");
			}
		
		public:
		
		void Register()
			{
				cout<<"\nEnter the Picture_Number: ";
					cin>>Pno;
				cout<<"\nEnter the Picture_Category: ";
					cin>>Category;
				
				FixExhibit();
			}
		
		void ViewAll ()
			{
				cout<<"\nPicture_Number: "<<Pno<<"\t"<<"Picture_Category: "<<Category<<"\t"<<"Picture_Exhibit:"<<Exhibit<<endl;
				
			}
		
		friend void Search ();
					
	}p[5];
	
	void Search ()
		{
			int z=0;
			char temp[15];
			
			cout<<"\nEnter the Picture_Category: ";
				cin>>temp;
			
			for(int i=0;i<5;++i)
				{
					if(strcmpi(temp,p[i].Category)==0)
						{
							cout<<"\nPicture_Number: "<<p[i].Pno<<"\t";
							cout<<"Picture_Category: "<<p[i].Category<<"\t";
							cout<<"Picture_Exhibit:"<<p[i].Exhibit<<endl;
							
							z=1;
						}	
				}
			if(z==0)
				cout<<"Picture_Category Not Recognized. ";	
		}
		
		
	int main ()
		{
			cout<<"\nPicture Register Programme"<<endl;
			
			for(int i=0;i<5;++i)
				{
					p[i].Register();
				}
			
			int c;
			
			start:
			
			cout<<"\nMenu\n\n\t1.Display All Picture_Details\n\t2.Search For Picture Using Picture_Category\n\t3.Exit\n\nOption: ";
				cin>>c;
			
			switch (c)
				{
					case 1	:	for(int i=0;i<5;++i)
									{
										p[i].ViewAll();
									}
								break;
								
					case 2	:	Search();
								break;
								
					case 3	:	goto exit;
								break;			
								
					default	:	break;							
				}
			
			goto start;
			
			exit:
				
			cout<<"Thank You. Awaiting Your Delighted Presence.";	
			
			return 0;		
		}
