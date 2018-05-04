#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
using namespace std;


void gotoxy(int x,int y)
{
}

void view()
{
	cout<<"\n\n\t\t\tHELLO! MUSICIANS ";
	cout<<"\n\n\t\tWELCOME TO DELHI MUSIC STORE";
	cout<<"\n\n\t\t A  place  for  all music lovers";
	cout<<"\n\t\t The world  of music  is awaiting your arival to share ";
	cout<<"\n\t\t your musical knowledge  and  ideas  with  us.";
	cout<<"\n \t\tPlease  note  that playing with feeling  is  the  main  keyword";
	cout<<"\n\n\t\tFind  us  globaly: www.delhimusical523.com";
	cout<<"\n\n\tPhone: +919593436327, +919641867814";
	cout<<"\n\n\tMADE BY:-";
	cout<<"\n\tMAMIK DAS";
	cout<<"\n\tMCA 2ND SEMESTER";
	getch();
}
class music
{
	private:
		char itemname[50],category[50],manufacturer[30];
		int slno;
	public:
		void getdata()
		{
		    system("cls");
			cout<<"\n\n\tEnter Following Details:-";
			cout<<"\n\nSerial no.: ";
			cin>>slno;
			fflush(stdin);
			cout<<"\nItem name: ";
			gets(itemname);
			cout<<"\nCategory: ";
			gets(category);
			cout<<"\nManufacturer: ";
			gets(manufacturer);

		}
		void showdata()
		{
			cout<<"\n\nSerial no.: "<<slno;
			cout<<"\nItem name: "<<itemname;
			cout<<"\nCategory: ";
			puts(category);
			cout<<"\nManufacturer: "<<manufacturer;
		}
		int in()
		{
			return slno;
		}
};
fstream file;
ofstream fo;
music cassetes,instruments,accesories,amplifiers;

void addcassetes()
{
    system("cls");
	cout<<"\n\n\t\tMUSIC CASSETES";
	cassetes.getdata();
	file.open("cas.dat",ios::out|ios::app);
	file.write((char*)&cassetes,sizeof(music));
	file.close();
}

void showcassetes()
{
    system("cls");
	cout<<"MUSIC CASSETES";
	file.open("cas.dat",ios::in);
	while(file.read((char*)&cassetes,sizeof(music)))
	{
		cassetes.showdata();
	}
	file.close();
	getch();
}

void delcassetes()
{
	int n,found=0;
	system("cls");
	cout<<"\n\n\t\tMUSIC CASSETES";
	cout<<"\n\n\tEnter serial no. for Record Deletion: ";
	cin>>n;
	file.open("cas.dat",ios::binary|ios::in);
	fo.open("temp.dat",ios::binary|ios::out);
	while(!file.eof())
	{
		file.read((char*)&cassetes,sizeof(music));
		if(cassetes.in()!=n)

			fo.write((char*)&cassetes,sizeof(music));

			else
				found=1;
	}
	file.close();
	fo.close();
	remove("cas.dat");
	rename("temp.dat","cas.dat");
	if(found==1)
	{
	    system("cls");
		cout<<"\n\tRecord deleted successfully";
	}
	else
	{
	    system("cls");
		cout<<"\n\nRecord not found!!";
	}
	getch();
}
void modcassetes()
{
	int n;
	system("cls");
	cout<<"/n/n/tMUSIC CASSETES";
	cout<<"/n/n/tEnter Serial no. for Record Modification: ";
	cin>>n;
	file.open("cas.dat",ios::binary|ios::in);
	fo.open("second.dat",ios::binary|ios::out);

	while(!file.eof())
	{
		file.read((char*)&cassetes,sizeof(music));
		if(n!=cassetes.in())
			fo.write((char*)&cassetes,sizeof(music));
		else
		{
			cassetes.getdata();
			fo.write((char*)&cassetes,sizeof(music));
		}
	}
	file.close();
	fo.close();
	remove("cas.dat");
	rename("second.dat","cas.dat");
	getch();
}
void searchcassetes()
{
	int r;
	system("cls");
	cout<<"\n\n\t\tMUSIC CASSETES";
	cout<<"\n\nEnter index no. to find a record: ";
	cin>>r;
	file.open("cas.dat",ios::binary|ios::in);
	file.seekg((r-1)*sizeof(music),ios::beg);
	file.read((char*)&cassetes,sizeof(music));
	cassetes.showdata();
	file.close();
	getch();
}


void musiccassetes()
{
	int n;
	system("cls");
	cout<<"\n\n\t\tMUSIC CASSETES";
	cout<<"\n\n\t1) Add New Cassete Records";
	cout<<"\n\t2) Find a particular Cassete Record";
	cout<<"\n\t3) Modify Cassete Records";
	cout<<"\n\t4) Delete Existing Cassete Records";
	cout<<"\n\t5) View Cassetes";
	cout<<"\n\t6) Return to previous Menu";
	cout<<"\n\nEnter Choice(1-6):";
	cin>>n;
	switch(n)
	{
		case 1:
		    addcassetes();
		    break;

		case 2:
		    searchcassetes();
		    break;

		case 3:
		    modcassetes();
		    break;

		case 4:
		    delcassetes();
		    break;

		case 5:
		    showcassetes();
		    break;

		case 6:
		    return;

        default:
            cout<<"\n WRONG CHOICE!!!";
            exit(1);
	}
}         // --------------------------------------------------

void addinstruments()
{
    system("cls");
	cout<<"\n\n\t\tMUSICAL INSTRUMENTS";
	instruments.getdata();
	file.open("ins.dat",ios::out|ios::app);
	file.write((char*)&instruments,sizeof(music));
	file.close();
	getch();
}
void showinstruments()
{
    system("cls");
	cout<<"\n\n\t\tMUSICAL INSTRUMENTS";
	file.open("ins.dat",ios::in);
	while(file.read((char*)&instruments,sizeof(music)))
	{
		instruments.showdata();
	}
	file.close();
	getch();
}
void delinstruments()
{
	int n,found=0;
	system("cls");
	cout<<"\n\n\t\tMUSICAL INSTRUMENTS";
	cout<<"\n\n\tEnter index no. for Record Deletion: ";
	cin>>n;
	file.open("ins.dat",ios::binary|ios::in);
	fo.open("temp.dat",ios::binary|ios::out);
	while(!file.eof())
	{
		file.read((char*)&instruments,sizeof(music));
		if(instruments.in()!=n)

			fo.write((char*)&instruments,sizeof(music));

			else
				found=1;
	}
	file.close();
	fo.close();
	remove("ins.dat");
	rename("temp.dat","ins.dat");
	if(found==1)
	{
	    system("cls");
		cout<<"\n\n\tRecord deleted successfully";
		getch();
	}
	else
	{
	    system("cls");
		cout<<"\n\n\tRecord not found!!";
		getch();
	}
	getch();
}

void modinstruments()
{
	int n;
	system("cls");
	cout<<"\n\n\t\tMUSICAL INSTRUMENTS";
	cout<<"\n\n\tEnter serial no. for Record Modification: ";
	cin>>n;
	file.open("ins.dat",ios::binary|ios::in);
	fo.open("second.dat",ios::binary|ios::out);

	while(!file.eof())
	{
		file.read((char*)&instruments,sizeof(music));
		if(n!=instruments.in())
			fo.write((char*)&instruments,sizeof(music));
		else
		{
			instruments.getdata();
			fo.write((char*)&instruments,sizeof(music));
		}
	}
	file.close();
	fo.close();
	remove("ins.dat");
	rename("second.dat","ins.dat");
	getch();
}

void searchinstruments()
{
	int r;
	system("cls");
	cout<<"\n\n\t\tMUSICAL INSTRUMENTS";
	cout<<"\n\n\tEnter serial no. to find an instrument:";
	cin>>r;
	file.open("ins.dat",ios::binary|ios::in);
	file.seekg((r-1)*sizeof(music),ios::beg);
	file.read((char*)&instruments,sizeof(music));
	instruments.showdata();
	file.close();
	getch();
}


void musicinstruments()
{
	int n;
	system("cls");
	cout<<"\n\n\t\tMUSICAL INSTRUMENTS";
	cout<<"\n\n\t1) Add New Instrument Records";
	cout<<"\n\t2) Find a particular Instrument Record";
	cout<<"\n\t3) Modify Instruments Records";
	cout<<"\n\t4) Delete Existing Instruments Records";
	cout<<"\n\t5) View Instruments";
	cout<<"\n\t6) Return to previous Menu";
	cout<<"\n\n\tEnter Choice(1-6):";
	cin>>n;
	switch(n)
	{

		case 1:
		    addinstruments();
            break;

		case 2:
		    searchinstruments();
            break;

		case 3:
		    modinstruments();
            break;

		case 4:
		    delinstruments();
            break;

		case 5:
		    showinstruments();
		    break;

		case 6:
		    exit(1);
	}
}         // --------------------------------------------------

void addaccesories()
{
	system("cls");
	cout<<"\n\n\t\tACCESORIES";
	accesories.getdata();
	file.open("acc.dat",ios::out|ios::app);
	file.write((char*)&accesories,sizeof(music));
	file.close();
	getch();
}

void showaccesories()
{
	system("cls");
	cout<<"\n\n\t\tACCESSORIES";
	file.open("acc.dat",ios::in);
	while(file.read((char*)&accesories,sizeof(music)))
	{
		accesories.showdata();
	}
	file.close();
	getch();
}

void delaccesories()
{
	int n,found=0;
	system("cls");
	cout<<"\n\n\t\tACCESSORIES";
	cout<<"\n\n\tEnter serial no. for Record Deletion: ";
	cin>>n;
	file.open("acc.dat",ios::binary|ios::in);
	fo.open("temp.dat",ios::binary|ios::out);
	while(!file.eof())
	{
		file.read((char*)&accesories,sizeof(music));
		if(accesories.in()!=n)

			fo.write((char*)&accesories,sizeof(music));

			else
				found=1;
	}
	file.close();
	fo.close();
	remove("acc.dat");
	rename("temp.dat","acc.dat");
	if(found==1)
	{
		cout<<"\n\n\tRecord deleted successfully";
	}
	else
	{
		cout<<"\n\n\tRecord not found!!";
	}
	getch();
}

void modaccesories()
{
	int n;
	system("cls");
	cout<<"\n\n\t\tACCESSORIES";
	cout<<"\n\n\tEnter serial no. for Record Modification: ";
	cin>>n;
	file.open("acc.dat",ios::binary|ios::in);
	fo.open("second.dat",ios::binary|ios::out);

	while(!file.eof())
	{
		file.read((char*)&accesories,sizeof(music));
		if(n!=accesories.in())
			fo.write((char*)&accesories,sizeof(music));
		else
		{
			accesories.getdata();
			fo.write((char*)&accesories,sizeof(music));
		}
	}
	file.close();
	fo.close();
	remove("acc.dat");
	rename("second.dat","acc.dat");
	getch();
}

void searchaccesories()
{
	int r;
	system("cls");
	cout<<"\n\n\t\tACCESSORIES";
	//gotoxy(25,10);
	cout<<"\n\n\tEnter serial no. to find a accessory ";
	cin>>r;
	file.open("acc.dat",ios::binary|ios::in);
	file.seekg((r-1)*sizeof(music),ios::beg);
	file.read((char*)&accesories,sizeof(music));
	accesories.showdata();
	file.close();
	getch();
}

void musicaccesories()
{
    system("cls");
    int n;
	//clrscr();
	gotoxy(30,5);
	cout<<"\n\n\t\tACCESSORIES";
	//gotoxy(25,10);
	cout<<"\n\n\t1) Add New Accessory Records";
	//gotoxy(25,12);
	cout<<"\n\t2) Find a particular Accessory Record";
	//gotoxy(25,14);
	cout<<"\n\t3) Modify Accessory Records";
	//gotoxy(25,16);
	cout<<"\n\t4) Delete Existing Accessory Records";
	//gotoxy(25,18);
	cout<<"\n\t5) View Accessories";
	//gotoxy(25,20);
	cout<<"\n\t6) Return to previous Menu";
	//gotoxy(25,22);
	cout<<"\n\n\tEnter Choice(1-6):";
	cin>>n;
	switch(n)
	{

		case 1:
		    addaccesories();
		    break;

		case 2:
		    searchaccesories();
		    break;

		case 3:
		    modaccesories();
		    break;

		case 4:
		    delaccesories();
		    break;

		case 5:
		    showaccesories();
		    break;

		case 6:
		    return;
	}
}         // --------------------------------------------------

void addamplifiers()
{
	system("cls");
	cout<<"\n\n\t\tAMPLIFICATION";
	amplifiers.getdata();
	file.open("amp.dat",ios::out|ios::app);
	file.write((char*)&amplifiers,sizeof(amplifiers));
	file.close();
	getch();
}
void showamplifiers()
{
	system("cls");
	cout<<"\n\n\t\tAMPLIFICATION";
	file.open("amp.dat",ios::in);
	while(file.read((char*)&amplifiers,sizeof(music)))
	{
		amplifiers.showdata();
	}
	file.close();
	getch();
}


void delamplifiers()
{
	int n,found=0;
	system("cls");
	cout<<"\n\n\t\tAMPLIFICATION";
	//gotoxy(25,10);
	cout<<"\n\n\tEnter serial no. for Record Deletion: ";
	cin>>n;
	file.open("amp.dat",ios::binary|ios::in);
	fo.open("temp.dat",ios::binary|ios::out);
	while(!file.eof())
	{
		file.read((char*)&amplifiers,sizeof(music));
		if(amplifiers.in()!=n)

			fo.write((char*)&amplifiers,sizeof(music));

			else
				found=1;
	}
	file.close();
	fo.close();
	remove("amp.dat");
	rename("temp.dat","amp.dat");
	if(found==1)
	{
		system("cls");
		cout<<"\n\n\tRecord deleted successfully";
	}
	else
	{
		//gotoxy(25,12);
		cout<<"\n\n\tRecord not found!!";
	}
	getch();
}
void modamplifiers()
{
	int n;
	system("cls");
	cout<<"\n\n\t\tAMPLIFICATION";
	//gotoxy(25,10);
	cout<<"\n\n\tEnter serial no. for Record Modification: ";
	cin>>n;
	file.open("amp.dat",ios::binary|ios::in);
	fo.open("second.dat",ios::binary|ios::out);

	while(!file.eof())
	{
		file.read((char*)&amplifiers,sizeof(music));
		if(n!=amplifiers.in())
			fo.write((char*)&amplifiers,sizeof(music));
		else
		{
			amplifiers.getdata();
			fo.write((char*)&amplifiers,sizeof(music));
		}
	}
	file.close();
	fo.close();
	remove("amp.dat");
	rename("second.dat","amp.dat");
	getch();
}
void searchamplifiers()
{
	int r;
	system("cls");
	cout<<"\n\n\t\tAMPLIFICATION";
	//gotoxy(25,10);
	cout<<"\n\n\tEnter serial no. to find a amplifier ";
	cin>>r;
	file.open("amp.dat",ios::binary|ios::in);
	file.seekg((r-1)*sizeof(music),ios::beg);
	file.read((char*)&amplifiers,sizeof(music));
	amplifiers.showdata();
	file.close();
	getch();
}
void musicamplifiers()
{
	int n;
	system("cls");
	cout<<"\n\n\t\tAMPLIFICATION";
	//gotoxy(25,10);
	cout<<"\n\n\t1) Add New Amplifier Records";
	//gotoxy(25,12);
	cout<<"\n\t2) Find a particular Amplifier Record";
	//gotoxy(25,14);
	cout<<"\n\t3) Modify Amplifier Records";
	//gotoxy(25,16);
	cout<<"\n\t4) Delete Existing Amplifier Records";
	//gotoxy(25,18);
	cout<<"\n\t5) View Amplifier";
	//gotoxy(25,20);
	cout<<"\n\t6) Return to previous Menu";
	//gotoxy(25,22);
	cout<<"\n\n\tEnter Choice(1-6):";
	cin>>n;
	switch(n)
	{

		case 1:
		    addamplifiers();
		    break;

		case 2:
		    searchamplifiers();
		    break;

		case 3:
		    modamplifiers();
		    break;

		case 4:
		    delamplifiers();
		    break;

		case 5:
		    showamplifiers();
		    break;

		case 6:
		    exit(1);
	}
}
int main()
{
	int n;
	view();
	do
	{
		system("cls");
		cout<<"\n\n-----------------------MUSIC SHOP SYSTEM---------------------------";
		//gotoxy(30,8);
		cout<<"\n\n\t\tSelect Category:-";
		//gotoxy(28,11);
		cout<<"\n\n1) Cassetes";
		//gotoxy(28,13);
		cout<<"\n2) Musical Instruments";
		//gotoxy(28,15);
		cout<<"\n3) Accessories";
		//gotoxy(28,17);
		cout<<"\n4) Amplifiers";
		//gotoxy(28,19);
		cout<<"\n5) Exit";
		//gotoxy(28,23);
		cout<<"\n\nEnter Choice(1-5):";
		cin>>n;
		switch(n)
		{
			case 1:
			    musiccassetes();
			    break;

			case 2:
			    musicinstruments();
			    break;

			case 3:
			    musicaccesories();
			    break;

			case 4:
			    musicamplifiers();
			    break;

			case 5:
			    exit(0);

			default:
			    exit(1);
		}
	}while(n!=5);
	return 0;
}
