#include <iostream>
#include <string.h>
#include <fstream> 
#include<iomanip>                    
using namespace std;
fstream file,f1;
class A
{
	char name[30];
	int quant;
	int cost;
	public:
	void adding();
	void displaying();
	void searching();
	void updating();
	void deleting();
	void buying();
}s;
void A::adding()
{
	int n,i;
	cout<<"How many items you want to add"<<endl;
	cin>>n;
file.open("shopping.dat",ios::binary|ios::app);
for(i=1;i<=n;i++)

{
	cout<<"Input item name, quantity and cost of item"<<endl;
	cin>>name>>quant>>cost;
	file.write((char *)&s,sizeof(s));
	
}
file.close();
}
void A::displaying()
{
	cout<<"Item Name \t \t  Quantity \t     Cost"<<endl;
file.open("shopping.dat",ios::binary|ios::in|ios::out);
while(!file.eof())
{
	file.read((char *)&s,sizeof(s));
	if(!file.eof())
	{
		if(file.tellg()<=0)
		break;
		else
	
	cout<<setw(10)<<name<<"\t\t  "<<quant<<"\t\t  "<<cost<<endl;
}
}
file.close();


}
void A::updating()
{
	char n[20];
	int q;
	cout<<"Enter the item to be updated"<<endl;
	cin>>n;
	cout<<"Enter the Quantity to update"<<endl;
	cin>>q;
	file.open("shopping.dat",ios::binary|ios::ate);
	while(!file.eof())
{
	file.read((char *)&s,sizeof(s));
	{
		
		int p=file.tellp();
		if(strcmp(n,name)==0)
		{
			
			quant=quant+q;
			file.seekp(p);
			file.write((char*)&s,sizeof(s));
			break;
		}
	}
	file.close();
}


}
	void A::deleting()
	{
		int i=0;
     char x[30];
     cout<<"\n\nEnter the name of the product to delete:";
     cin>>x;
     f1.open("SHOP.dat",ios::binary|ios::out);
     file.open("shopping.dat",ios::binary|ios::in);
     while(file)
     {
	  file.read((char*)&s,sizeof(s));
	    if(strcmp(x,name)!=0)
	    {
		
	    f1.write((char*)&s,sizeof(s));
	    i++;
	}
     }
     file.close();
     f1.close();
    // if(i==0)
       //cout<<"\n\n!!Record not found!!";
     //f.close();
     //f1.close();
     remove("shopping.dat");
     rename("SHOP.dat","shopping.dat");

	
	
	


	

file.close();
}
void A::buying()
{
	char n1[100];int q1;
	int j=0;
	long p1=0;
	//display();
	cout<<"\n\nEnter the product to buy \n"<<endl;
	cin>>n1;
	cout<<"\n\nEnter no.of products \n"<<endl;
	cin>>q1;
	file.open("shopping.dat",ios::binary|ios::ate|ios::in);
     while(file)
     {
	    p1=file.tellp();
	    file.read((char*)&s,sizeof(s));
	    if(strcmp(n1,name)==0)
	    {
		  if(quant>=q1)
		  {
		  	quant=quant-q1;
		  	cout<<"Total bill is:"<<cost*q1<<endl;
		  file.seekg(p1);
		  file.write((char*)&s,sizeof(s));
		  j++;
		  
	    }
     }
     file.close();
     
    
     if(j!=1)
       cout<<"\n\n!!Record not found!!";
     //f.close();
	 //disp(); 
	
}}
void A::searching()
{
	char prd[30];
	cout<<"\t\t\t Enter the product you want to search"<<endl;	
	cin>>prd;
	file.open("shopping.dat",ios::in|ios::out);
		while(file)
		{
			file.read((char*)&s,sizeof(s));
			if(strcmp(prd,name)==0)
			{
			
			displaying();
			break;
		}
			else
			{
			 
			cout<<"Product not available!";
			break;
		}
		}
		file.close();
}

main()
{
	char p[30];
	int ch;
	cout<<"WELCOME TO SHOPPING"<<endl;
	A:
		
		
	cout<<"Enter the password"<<endl;
	cin>>p;
	if(strcmp(p,"harsha")==0)
	cout<<"Access Granted!!"<<endl;
	else
	{
		cout<<"Incorrect password"<<endl;
	goto A;
	
	}
	
	
	B:
		cout<<"1.Add items"<<endl;
		cout<<"2.Display the items"<<endl;
		cout<<"3.Search"<<endl;
		cout<<"4.Update"<<endl;
		cout<<"5.Delete"<<endl;
		cout<<"6.Buy"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					s.adding();
					goto B;
					break;
				}
				case 2:
					{
						s.displaying();
						goto B;
						break;
					}
					case 3:
						{
							s.searching();
							goto B;
							break;
						}
						case 4:
					{
						s.updating();
						goto B;
						break;
					}
					case 5:
					{
						s.deleting();
						goto B;
						break;
					}
					case 6:
					{
						s.buying();
						goto B;
						break;
					}
					case 7:
						{
							exit(0);
						}
		}
	
}



	

	
	
	
	
	
	
	

