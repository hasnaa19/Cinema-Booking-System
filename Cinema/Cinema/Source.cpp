#include <fstream>
#include <string>
#include<sstream>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

struct theatref {
	string ID[2];
	int CAPACITY;
	int reservedseats;
};

struct timef {
	int hours;
	int min[2];
};
struct screeninginfo {
	int screan[2];
	timef TIME[6];
	theatref id;

}hp, bs, split, tangled, fa, hepta;

struct movie {
	string title1, title2;
	string director1, director2;
	string actor1, actor2;
	float rate;
	screeninginfo s;
}HP, BS, SPLIT, TANGLED, FA, HEPTA;
movie list[6];
screeninginfo si[6];
time_t curr_time;

void TIMES(time_t) {
	curr_time = time(NULL);

	tm* tm_local = localtime(&curr_time);
	//cout << "Current local time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
}
tm* tm_local = localtime(&curr_time);
struct tim {
	int h, m;
};
struct screen {
	string movie;
	tim T[6];
};
struct theatre {
	string name;
	screen s[4];
};
struct REQUIRED {
	int HOURS, MINS;
};
struct seat_num
{
	char row;
	int column;
};
struct seat_info
{
	seat_num seatN;
	bool seat_availability;
}available_Seats[5][60];

seat_num wanted_seatsARR[60];
seat_num wanted_seatV;
theatre TH[2];
REQUIRED Rtime;
string Reqtheatre;
int num = 0, m = 0;
int f = 0;
bool Valid = false;

void Display_Atheatre(string a) {
	Valid = false;
	cout << a << " is available at: " << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (a == TH[i].s[j].movie) {
				m++;
				cout << TH[i].name << endl;
			}
		}
	}

	if (m == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (a == TH[i].s[j].movie) {

					Reqtheatre = TH[i].name;

				}
			}
		}
	}
	else if (m == 2) {
		cout << "Choose desired theatre:";

		while (Valid == false) {


			cin >> Reqtheatre;
			transform(Reqtheatre.begin(), Reqtheatre.end(), Reqtheatre.begin(), toupper);
			for (int i = 0; i < 2; i++) {
				if (Reqtheatre != TH[i].name) {
					f++;
				}
			}
			if (f == 2) {
				Valid = false;
				cout << "Invalid entry .....Please retype your desired theatre: ";
			}
			else {
				Valid = true;
			}
			f = 0;

		}

	}
	m = 0;

}
void Display_Atime(string a, string b, int& num) {
	for (int i = 0; i < 2; i++) {
		if (b == TH[i].name) {
			for (int j = 0; j < 4; j++) {
				if (a == TH[i].s[j].movie) {
					for (int k = 0; k < 6; k++) {
						if (((tm_local->tm_hour) == TH[i].s[j].T[k].h && (tm_local->tm_min) > TH[i].s[j].T[k].m) || ((tm_local->tm_hour) > TH[i].s[j].T[k].h) || ((tm_local->tm_hour) == TH[i].s[j].T[k].h && (tm_local->tm_min) == TH[i].s[j].T[k].m)) {

							num++;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		if (b == TH[i].name) {

			for (int j = 0; j < 4; j++) {
				if (a == TH[i].s[j].movie) {
					for (int k = 0; k < 6; k++) {
						if (((tm_local->tm_hour) == TH[i].s[j].T[k].h && (tm_local->tm_min) > TH[i].s[j].T[k].m) || ((tm_local->tm_hour) > TH[i].s[j].T[k].h)) {

							switch (num)
							{
							case 1:
								cout << "YOU'RE TOO LATE FOR:[" << TH[i].s[j].T[0].h << ":" << TH[i].s[j].T[0].m << "0]" << endl;
								break;
							case 2:
								cout << "YOU'RE TOO LATE FOR:[" << TH[i].s[j].T[1].h << ":" << TH[i].s[j].T[1].m << "]" << endl;
								break;
							case 3:
								cout << "YOU'RE TOO LATE FOR:[" << TH[i].s[j].T[2].h << ":" << TH[i].s[j].T[2].m << "0]" << endl;
								break;
							case 4:
								cout << "YOU'RE TOO LATE FOR:[" << TH[i].s[j].T[3].h << ":" << TH[i].s[j].T[3].m << "]" << endl;
								break;
							case 5:
								cout << "YOU'RE TOO LATE FOR:[" << TH[i].s[j].T[4].h << ":" << TH[i].s[j].T[4].m << "0]" << endl;
								break;
							case 6:
								cout << "YOU'RE TOO LATE FOR:[" << TH[i].s[j].T[5].h << ":" << TH[i].s[j].T[5].m << "]" << endl;
								cout << "There isn't any other available times....";
								break;
							default:
								break;
							}
							break;
						}

					}
				}
			}
		}
	}
	if (num != 6) {
		for (int i = 0; i < 2; i++) {
			if (b == TH[i].name) {
				cout << a << " is screened at " << TH[i].name << " at:" << endl;
				for (int j = 0; j < 4; j++) {
					if (a == TH[i].s[j].movie) {
						for (int k = 0; k < 6; k++) {
							if (((tm_local->tm_hour) == TH[i].s[j].T[k].h && (tm_local->tm_min) < TH[i].s[j].T[k].m) || ((tm_local->tm_hour) < TH[i].s[j].T[k].h)) {

								cout << TH[i].s[j].T[k].h << ":" << TH[i].s[j].T[k].m;
								if (TH[i].s[j].T[k].m == 0) {
									cout << "0";
								}
								cout << endl;
							}
						}
					}
				}
			}
		}
	}
}
//FATMA'S FUNCTIONS
int check(int a, int determiner, int End_Of_Counter)
{
	int Returned_Value;
	int count = 0;
	char choice;
	char choice2;
	for (int i = 0; i < End_Of_Counter; i++)
	{
		if (available_Seats[determiner][i].seat_availability == true)
			count++;

	}
	if (count >= a)
	{
		Returned_Value = 1;//(1)lw fy space kfaya w zyada

	}
	else if (count == 0)
	{
		cout << "UNFORTUNATELY it's Fully booked...would you like to choose another MOVIE/TIME??" << endl;
		cout << endl << endl;
		cout << "NOTE: if yes choose (y) and if no choose (n) : " << endl;

		while (true)
		{
			cin >> choice; cin.ignore();
			cout << endl << endl;
			if (choice == 'y' || choice == 'Y') {
				Returned_Value = 2; break; //(2)lw hy5tar time tani 3mtn swa2 fully booked 2w not enough space
			}
			else if (choice == 'n' || choice == 'N') {
				Returned_Value = 4; break; //(4)exit
			}
			else if (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y') {
				cout << "INVALID ENTRY PLEASE ENTER(Y/N)....." << endl << endl; continue;
				//nothing will be returned until he enters a valid choice
			}
		}



	}
	else if (count < a)
	{
		cout << "Only " << count << " SEATS ARE AVAILABLE,,," << endl << endl;
		cout << "Do you want to choose another MOVIE/TIME(click'T') ?" << endl;
		cout << "OR Do you want to choose from available seats(click'S')?" << endl;
		cout << "OR do you want to exit(click 'N')?" << endl;
		cout << endl;

		while (true)
		{
			cin >> choice;
			cin.ignore();

			if (choice == 't' || choice == 'T')
			{
				Returned_Value = 2;//(2)lw hy5tar time tani 3mtn swa2 fully booked 2w not enough space
				break;
			}

			else if (choice == 's' || choice == 'S')
			{
				Returned_Value = 3;//(3) lw 3dd al seats not enough bs hwa hy5tar mnhom
				break;
			}

			else if (choice == 'n' || choice == 'N')
			{
				Returned_Value = 4;//(4) exit
				break;
			}
			else if (choice != 't' && choice != 'T' && choice != 's' && choice != 'S' && choice != 'n' && choice != 'N')
			{
				cout << "INVALID ENTRY,,PLEASE ENTER(T/S/N)....." << endl;
				continue;

			}

		}
	}
	return Returned_Value;
}
//HASNAA'S FUNCTIONS

int book_seats(int numofseats, int determiner, int End_Of_Counter)
{
	bool isFound = false;
	int COUNTER = 0;
	int done = 0;

	//DISPLAYING THE AVAILABLE SEATS........

	cout << "those are the available seats: " << endl;
	int counter = 0;
	for (int i = 0; i < End_Of_Counter; i++)
	{
		if (counter == 10) { cout << endl; counter = 0; }
		if (available_Seats[determiner][i].seat_availability == true)
		{
			cout << available_Seats[determiner][i].seatN.row << available_Seats[determiner][i].seatN.column << "   ";
			counter++;
		}
	}

	//ENTERING THE DESIRED SEATS..................
	cout << endl;
	cout << "Do you want to choose from these seats ? (click 'Y' ) " << endl;
	cout << "OR do you want to choose another MOVIE/TIME ? (click 'N') " << endl;
	cout << "OR do you want to exit ?(click 'E') " << endl;
	while (true)
	{


		char answer; cin >> answer; cin.ignore();
		if (answer == 'Y')
		{
			cout << "enter the seats you want to book ..." << endl;
			while (true)
			{
				if (COUNTER == numofseats) break;
				for (COUNTER = 0; COUNTER < numofseats;)
				{
					isFound = false;
					cin >> wanted_seatV.row >> wanted_seatV.column;
					for (int i = 0; i < End_Of_Counter; i++)
					{
						if (wanted_seatV.row == available_Seats[determiner][i].seatN.row && wanted_seatV.column == available_Seats[determiner][i].seatN.column)
						{
							if (available_Seats[determiner][i].seat_availability == true)
							{
								available_Seats[determiner][i].seat_availability = false;
								wanted_seatsARR[COUNTER].row = wanted_seatV.row; wanted_seatsARR[COUNTER].column = wanted_seatV.column;
								isFound = true;
							}

						}
					}

					if (isFound == false) cout << " invalid seat number , PLEASE enter a valid seat number...";
					else if (isFound == true) COUNTER++;
					if (COUNTER == numofseats) break;
				}
			}

			done = 1;
			break;
		}
		else if (answer == 'N') { done = 2; break; }
		else if (answer == 'E') { done = 3; break; }
		else cout << "invalid entery , PLEASE ENTER ' Y ' OR ' N ' OR 'E' .... " << endl;
	}
	return done;
};


//MAINNNNN

int main() {
	ifstream myfile;
	myfile.open("Text.txt");
	if (!myfile.is_open()) { cout << "failed to open file" << endl; }

	else

		for (int i = 0; i < 2; i++) {

			myfile >> list[i].title1; myfile >> list[i].title2;
			myfile >> list[i].director1; myfile >> list[i].director2;
			myfile >> list[i].actor1; myfile >> list[i].actor2;
			myfile >> list[i].rate;
		}
	for (int i = 2; i < 6; i++) {
		myfile >> list[i].title1;
		myfile >> list[i].director1; myfile >> list[i].director2;
		myfile >> list[i].actor1; myfile >> list[i].actor2;
		myfile >> list[i].rate;
	}
	myfile.close();



	ifstream timefile;
	timefile.open("time.txt");

	if (!timefile.is_open()) { cout << "failed to open file" << endl; }
	else

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 6; j++) {
				timefile >> si[i].TIME[j].hours >> si[i].TIME[j].min[0] >> si[i].TIME[j].min[1];

			}

			timefile >> si[i].screan[0] >> si[i].screan[1];
			timefile >> si[i].id.ID[0] >> si[i].id.ID[1];

		}

	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 6; j++) {

			timefile >> si[i].TIME[j].hours >> si[i].TIME[j].min[0] >> si[i].TIME[j].min[1];


		}
		timefile >> si[i].screan[0];

		timefile >> si[i].id.ID[0];

	}
	timefile.close();

	char menu = 'y';
	string userchoice;
	while (menu == 'y' || menu == 'Y') {

		cout << "1.MOVIES " << endl
			<< "-----------------------------------------------" << endl
			<< "2.BOOK NOW " << endl
			<< "-----------------------------------------------" << endl
			<< "PLEASE TYPE YOUR CHOICE!" << endl;
		cin >> userchoice;
		transform(userchoice.begin(), userchoice.end(), userchoice.begin(), tolower);
		cout << "*******************" << endl;

		if (userchoice == "movies")
		{
			cout << "1.List all movies" << endl
				<< "-----------------------------------------------" << endl
				<< "2.List all movies with certain theatre " << endl
				<< "-----------------------------------------------" << endl
				<< "3.Search for movies by genre " << endl
				<< "-----------------------------------------------" << endl
				<< "4.Search for movie by certain time" << endl
				<< "-----------------------------------------------" << endl
				<< "5.Coming soon movies " << endl
				<< "-----------------------------------------------" << endl;
			int u;
			cout << "PLEASE TYPE YOUR CHOICE! (AS A NUMBER)" << endl;
			cin >> u; cout << "*******************" << endl;
			if (u == 1) {

				for (int i = 0; i < 2; i++)
				{
					cout << i + 1 << ".Movie: " << list[i].title1 << " " << list[i].title2 << endl
						<< "Director: " << list[i].director1 << " " << list[i].director2 << endl;
					cout << "Main Actor: " << list[i].actor1 << " " << list[i].actor2 << endl << "Rate: " << list[i].rate << endl;

					for (int j = 0; j < 6; j++) {
						cout << "Time: " << si[i].TIME[j].hours << ":" << si[i].TIME[j].min[0] << si[i].TIME[j].min[1] << "AM" << endl;
					}

					cout << "Theatre: " << si[i].id.ID[0] << " at Screen: " << si[i].screan[0] << endl;
					cout << "  and at Theatre:  " << si[i].id.ID[1] << "at Screen:" << si[i].screan[1] << endl;
					cout << "_______________________________________________" << endl;

				}

				for (int i = 2; i < 6; i++)
				{
					cout << i + 1 << ".Movie: " << list[i].title1 << endl
						<< "Director: " << list[i].director1 << " " << list[i].director2 << endl;
					cout << "Main Actor: " << list[i].actor1 << " " << list[i].actor2 << endl << "Rate:" << list[i].rate << endl;

					for (int j = 0; j < 6; j++) {
						cout << "Time: " << si[i].TIME[j].hours << ":" << si[i].TIME[j].min[0] << si[i].TIME[j].min[1] << "PM" << endl;
					}

					cout << "Theatre: " << si[i].id.ID[0];
					cout << " at screen: " << si[i].screan[0] << endl;
					cout << "_______________________________________________" << endl;
				}
				cout << "Back to Main Menu?? if yes TYPE Y" << endl; cin >> menu; cout << "*******************" << endl;
			}

			else if (u == 2) {
				struct all_theatres {
					string filmName;
					string theatreName[2];

				}SI[6];
				struct theatre {
					timef theatreTime[6];
				}TH;
				ifstream THEATRE;
				THEATRE.open("theatre.txt");
				if (!THEATRE.is_open()) {
					cout << "failed to open file" << endl;
				}
				else {
					for (int i = 0; i < 2; i++) {
						THEATRE >> SI[i].filmName;
						for (int k = 0; k < 2; k++) {
							THEATRE >> SI[i].theatreName[k];
						}
						for (int j = 0; j < 6; j++) {

							THEATRE >> TH.theatreTime[j].hours;
							THEATRE >> TH.theatreTime[j].min[0];
							THEATRE >> TH.theatreTime[j].min[1];

						}
					}

				}
				for (int i = 2; i < 6; i++) {
					THEATRE >> SI[i].filmName;

					THEATRE >> SI[i].theatreName[0];
					for (int j = 0; j < 6; j++) {

						THEATRE >> TH.theatreTime[j].hours;
						THEATRE >> TH.theatreTime[j].min[0];
						THEATRE >> TH.theatreTime[j].min[1];

					}

				}
				THEATRE.close();


				for (int i = 0; i < 2; i++) {
					cout << i + 1 << ".Movie: " << SI[i].filmName << endl << "theatres: " << SI[i].theatreName[i] << endl;
					for (int j = 0; j < 6; j++) {


						cout << "time: " << TH.theatreTime[j].hours << ":" << TH.theatreTime[j].min[0] << TH.theatreTime[j].min[1] << "AM" << endl;
					}
				}
				for (int i = 2; i < 6; i++) {
					cout << i + 1 << ".Movie: " << SI[i].filmName << endl << "theatres: " << SI[i].theatreName[0] << SI[i].theatreName[1] << endl;
					for (int j = 0; j < 6; j++) {

						cout << "time: " << TH.theatreTime[j].hours << ":" << TH.theatreTime[j].min[0] << TH.theatreTime[j].min[1] << "PM" << endl;
					}
				}
				cout << "Back to Main Menu?? if yes TYPE Y" << endl; cin >> menu;
				cout << "*******************" << endl;
			}
			else if (u == 3) {

				//SEARCH WITH MOVIE GENRE
				HP = list[0]; BS = list[1]; SPLIT = list[2]; FA = list[4]; TANGLED = list[3]; HEPTA = list[5];
				hp = si[0]; bs = si[1]; split = si[2]; fa = si[4]; tangled = si[3]; hepta = si[5];
				string genre;
				string newgenre = "yes";
				while (newgenre == "yes") {

					cout << "Choose Movie Genre:" << endl;
					cin >> genre;
					transform(genre.begin(), genre.end(), genre.begin(), tolower);
					cout << "*******************" << endl;
					if (genre == "fantasy") {

						cout << genre << ":" << endl << "1. " << "Movie: " << HP.title1 << " " << HP.title2 << endl
							<< "Director: " << HP.director1 << " " << HP.director2 << endl
							<< "Main Actor: " << HP.actor1 << " " << HP.actor2 << endl << "Rate: " << HP.rate << endl;

						for (int j = 0; j < 6; j++) {
							cout << "Time:" << hp.TIME[j].hours << ":" << hp.TIME[j].min[0]
								<< hp.TIME[j].min[1] << endl;
						}

						cout << "Theatre: " << hp.id.ID[0] << " at Screen : " << hp.screan[0] << endl;
						cout << " and at Theatre:  " << hp.id.ID[1] << " at Screen:" << hp.screan[1] << endl
							<< "_______________________________________________" << endl;

						cout << "2. " << "Movie: " << TANGLED.title1 << endl
							<< "Director: " << TANGLED.director1 << " " << TANGLED.director2 << endl
							<< "Main Actor: " << TANGLED.actor1 << " " << TANGLED.actor2 << endl << "Rate: " << TANGLED.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time:" << tangled.TIME[j].hours << ":" << tangled.TIME[j].min[0] <<
								tangled.TIME[j].min[1] << endl;
						}

						cout << " Theatre: " << tangled.id.ID[0] << " at Screen: " << tangled.screan[0] << endl
							<< "_______________________________________________" << endl;


					}
					else if (genre == "animation")
					{
						cout << genre << ":" << endl << "1. " << "Movie : " << TANGLED.title1 << endl
							<< "Director : " << TANGLED.director1 << " " << TANGLED.director2 << endl
							<< "Main Actor : " << TANGLED.actor1 << " " << TANGLED.actor2 << endl << "Rate : " << TANGLED.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time :" << tangled.TIME[j].hours << ":" << tangled.TIME[j].min[0] <<
								tangled.TIME[j].min[1] << endl;
						}
						cout << " Theatre : " << tangled.id.ID[0] << " at Screen : " << tangled.screan[0] << endl
							<< "_______________________________________________" << endl;
					}


					else if (genre == "psychological" || genre == "thriller" || genre == "horror") {

						cout << genre << ":" << endl << "1. " << "Movie : " << BS.title1 << " " << BS.title2 << endl
							<< "Director: " << BS.director1 << " " << BS.director2 << endl
							<< "Main Actor :" << BS.actor1 << " " << BS.actor2 << endl << "Rate :" << BS.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time :" << bs.TIME[j].hours << ":" << bs.TIME[j].min[0] <<
								bs.TIME[j].min[1] << endl;
						}

						cout << " Theatre : " << bs.id.ID[0] << " at Screen : " << bs.screan[0] << endl;
						cout << " and at Theatre:  " << bs.id.ID[1] << " at Screen :" << bs.screan[1] << endl
							<< "_______________________________________________" << endl;

						cout << "2. " << " Movie : " << SPLIT.title1 << endl
							<< " Director : " << SPLIT.director1 << " " << SPLIT.director2 << endl
							<< "Main Actor : " << SPLIT.actor1 << " " << SPLIT.actor2 << endl << "Rate : " << SPLIT.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time :" << split.TIME[j].hours << ":" << split.TIME[j].min[0] <<
								split.TIME[j].min[1] << endl;
						}

						cout << " Theatre : " << split.id.ID[0] << " at Screen : " << split.screan[0] << endl
							<< "_______________________________________________" << endl;
					}
					else if (genre == "drama") {
						cout << genre << ":" << endl << "1. " << "Movie : " << BS.title1 << " " << BS.title2 << endl
							<< "Director : " << BS.director1 << " " << BS.director2 << endl
							<< "Main Actor : " << BS.actor1 << " " << BS.actor2 << endl << "Rate : " << BS.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time :" << bs.TIME[j].hours << ":" << bs.TIME[j].min[0] <<
								bs.TIME[j].min[1] << endl;
						}

						cout << "Theatre : " << bs.id.ID[0] << "at Screen : " << bs.screan[0] << endl;
						cout << " and at Theatre:  " << bs.id.ID[1] << " at Screen : " << bs.screan[1] << endl
							<< "_______________________________________________" << endl;

						cout << "2. " << "Movie : " << HEPTA.title1 << endl
							<< "Director : " << HEPTA.director1 << " " << HEPTA.director2
							<< endl
							<< "Main Actor :" << HEPTA.actor1 << " " << HEPTA.actor2 << endl << "Rate : " << HEPTA.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time :" << hepta.TIME[j].hours << ":" << hepta.TIME[j].min[0] <<
								hepta.TIME[j].min[1] << endl;
						}

						cout << " Theatre : " << hepta.id.ID[0] << " at Screen : " << hepta.screan[0] << endl
							<< "_______________________________________________" << endl;

						cout << "3. " << " Movie : " << FA.title1 << endl
							<< "Director : " << FA.director1 << " " << FA.director2 << endl
							<< "Main Actor : " << FA.actor1 << " " << FA.actor2 << endl << "Rate : " << FA.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time :" << fa.TIME[j].hours << ":" << fa.TIME[j].min[0] <<
								fa.TIME[j].min[1] << endl;
						}

						cout << "Theatre : " << fa.id.ID[0] << " at Screen : " << fa.screan[0] << endl
							<< "_______________________________________________" << endl;
					}

					else if (genre == "romance") {
						cout << genre << ":" << endl << "Movie : " << HEPTA.title1 << endl
							<< "Director: " << HEPTA.director1 << " " << HEPTA.director2 << endl

							<< "Main Actor : " << HEPTA.actor1 << " " << HEPTA.actor2 << endl << "Rate: " << HEPTA.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time :" << hepta.TIME[j].hours << ":" << hepta.TIME[j].min[0] <<
								hepta.TIME[j].min[1] <<
								endl;
						}

						cout << " Theatre : " << hepta.id.ID[0] << " at Screen : " << hepta.screan[0] << endl
							<< "_______________________________________________" << endl;
					}

					else if (genre == "crime" || genre == "sci-ficition")

					{
						cout << genre << ":" << endl << "Movie : " << FA.title1 << endl
							<< "Director : " << FA.director1 << " " << FA.director2 << endl
							<< "Main Actor : " << FA.actor1 << " " << FA.actor2 << endl << "Rate : " << FA.rate << endl;
						for (int j = 0; j < 6; j++) {
							cout << "Time :" << fa.TIME[j].hours << ":" << fa.TIME[j].min[0] <<
								fa.TIME[j].min[1] << endl;
						}

						cout << "Theatre : " << fa.id.ID[0] << " at Screen : " << fa.screan[0] << endl
							<< "_______________________________________________" << endl;
					}
					else {
						cout << "NO AVAILABLE MOVIES NOW WITH THIS GENRE!" << endl
							<< "CHECK THE COMING SOON MOVIES!" << endl;
					}

					cout << "_______________________________________________" << endl
						<< "Do you want to enter another genre , IF YES PLEASE TYPE YES" << endl;

					cin >> newgenre;
					transform(newgenre.begin(), newgenre.end(), newgenre.begin(), tolower);
					cout << "*******************" << endl;

				}

				cout << "_______________________________________________" << endl
					<< "Back to Main Menu?? if yes TYPE Y" << endl; cin >> menu; cout << "*******************" << endl;

			}
			else if (u == 4) {
				string hour;
				char enterNewTime = 'y';
				while (enterNewTime == 'Y' || enterNewTime == 'y') {

					cout << "enter time hours:minutes\n Note:\n Time must be written as following times: \n 8:00\n 10:30\n 13:00\n 15:30\n 18:00\n 20:30\n  " << endl;
					cin >> hour; cout << "*******************" << endl;
					if (hour == "8:00") {
						cout << "availble films at that time are: \n" << "Harry potter\n Black swan\n Split\n Tangled\n Alfeel alazraq\n Hepta\n" << endl;
					}
					else if (hour == "10:30") {
						cout << "availble films at that time are: \n" << "Harry potter\n Black swan\n Split\n Tangled\n Alfeel alazraq\n Hepta\n" << endl;
					}
					else if (hour == "13:00") {
						cout << "availble films at that time are: \n" << "Harry potter\n Black swan\n Split\n Tangled\n Alfeel alazraq\n Hepta\n" << endl;
					}
					else if (hour == "15:30") {
						cout << "availble films at that time are: \n" << "Harry potter\n Black swan\n Split\n Tangled\n Alfeel alazraq\n Hepta\n" << endl;
					}
					else if (hour == "18:00") {
						cout << "availble films at that time are: \n" << "Harry potter\n Black swan\n Split\n Tangled\n Alfeel alazraq\n Hepta\n" << endl;
					}
					else if (hour == "20:30") {
						cout << "availble films at that time are: \n" << "Harry potter\n Black swan\n Split\n Tangled\n Alfeel alazraq\n Hepta\n" << endl;
					}
					else {
						cout << "No availble movies at that time" << endl;
					}
					cout << "Do you want to enter another time (y/n)" << endl;
					cin >> enterNewTime; cout << "*******************" << endl;
				}
				cout << "_______________________________________________" << endl
					<< "Back to Main Menu?? if yes TYPE Y" << endl; cin >> menu; cout << "*******************" << endl;
			}

			else if (u == 5) {
				struct comingSoon {
					string filmName;
					string director;
					string actors;
					float rate;
				};
				comingSoon list[3];

				ifstream CS;
				CS.open("comingsoon.txt");
				if (!CS.is_open()) {
					cout << "failed to open file" << endl;
				}
				else {
					for (int i = 0; i < 3; i++) {
						CS >> list[i].filmName;
						CS >> list[i].director;
						CS >> list[i].actors;
						CS >> list[i].rate;
					}

				}
				CS.close();
				cout << "coming soon movies are: \n" << endl;
				for (int i = 0; i < 3; i++) {
					cout << i + 1 << ".Movie: " << list[i].filmName << endl << "director: " << list[i].director << endl << "Main actor: " << list[i].actors << endl << "rate: " << list[i].rate << endl;
					cout << "________________________________________________" << endl;
				}
				cout << "_______________________________________________" << endl
					<< "Back to Main Menu?? if yes TYPE Y" << endl; cin >> menu; cout << "*******************" << endl;
			}


			else {
				cout << "INVALID CHOICE" << endl;
				cout << "_______________________________________________" << endl <<
					"Back to Main Menu?? if yes TYPE Y" << endl; cin >> menu; cout << "*******************" << endl;
			}
		}


		else if (userchoice == "book") {
			TIMES(curr_time);
			ifstream bookingfile;
			bookingfile.open("booking.txt");
			if (!bookingfile.is_open()) { cout << "FAILED TO OPEN FILE" << endl; }
			else
				for (int k = 0; k < 2; k++) {
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 6; j++) {
							bookingfile >> TH[k].s[i].T[j].h;
							bookingfile >> TH[k].s[i].T[j].m;
						}
					}
				}

			for (int i = 0; i < 2; i++) {
				bookingfile >> TH[i].name;
			}
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 4; j++)
					bookingfile >> TH[i].s[j].movie;
			}

			bookingfile.close();

			string choice;
			while (true)
			{

				cout << "THOSE ARE THE AVAILABLE MOVIES..... " << endl;
				cout << "1. HARRY POTTER \t 2. SPLIT \t 3. BLACK SWAN  " << endl;
				cout << "4.TANGLED \t 5. AlFyl Alazrak \t 6.HEPTA " << endl;
				cout << endl;
				cout << "please enter THE NAME of the movie you want : ";
				Valid = false;
				while (Valid == false) {


					getline(cin, choice);
					transform(choice.begin(), choice.end(), choice.begin(), tolower);
					for (int i = 0; i < choice.length(); i++)
						if (choice[i] == ' ') choice.erase(i, 1);

					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 4; j++) {
							if (choice != TH[i].s[j].movie) {
								f++;
							}
						}
					}
					if (f == 8) {
						Valid = false;
						cout << "Invalid entry .....Please retype your desired movie: ";
					}
					else
						Valid = true;
					f = 0;
				}

				Display_Atheatre(choice);
				f = 0;
				num = 0;
				Display_Atime(choice, Reqtheatre, num);

				if (num == 6) {
					cout << endl;
					break;
				}
				cout << "Choose desired time:";

				string Time;

				Valid = false;
				while (Valid == false) {
					f = 0;

					cin >> Time;
					string a, b;
					string::size_type sz;
					switch (Time.size())
					{
					case 4:
						a = Time.substr(0, 2);
						b = Time.substr(3, 3);
						break;
					case 5:
						a = Time.substr(0, 2);
						b = Time.substr(3, 4);
						break;
					default:
						break;
					}

					Rtime.HOURS = stoi(a, &sz);
					Rtime.MINS = stoi(b, &sz);
					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 4; j++) {
							for (int k = 0; k < 6; k++) {
								if ((Rtime.HOURS < (tm_local->tm_hour)) || (Rtime.HOURS == (tm_local->tm_hour) && Rtime.MINS < (tm_local->tm_min)) || (Rtime.HOURS != TH[i].s[j].T[k].h) || ((Rtime.HOURS == TH[i].s[j].T[k].h) && (Rtime.MINS != TH[i].s[j].T[k].m))) {
									f++;

								}
							}
						}
					}
					if (f == 48) {
						Valid = false;
						cout << "Invalid entry .....Please retype your desired time: ";
					}
					else {
						Valid = true;
					}
				}
				f = 0;

				/*cout << Rtime.HOURS << ":" << Rtime.MINS;
				if (Rtime.MINS == 0){
				cout << "0";
				}
				cout << endl;

				*/


				//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				// Hasnaa's part

				int numofseats, determiner, End_Of_Counter;


				if (Rtime.HOURS == 8)
				{
					ifstream in("available1.txt");
					if (in.fail())
					{
						cerr << "Error in opening that file" << endl;
						exit(1);
					}
					for (int i = 0; i < 60; i++)
					{
						in >> available_Seats[0][i].seatN.row >> available_Seats[0][i].seatN.column;
						available_Seats[0][i].seat_availability = true;
					}
					in.close();
					determiner = 0; End_Of_Counter = 60;
				}
				else if (Rtime.HOURS == 10)
				{
					ifstream in("available2.txt");
					if (in.fail())
					{
						cerr << "Error in opening that file" << endl;
						exit(1);
					}
					for (int i = 0; i < 30; i++)
					{
						in >> available_Seats[1][i].seatN.row >> available_Seats[1][i].seatN.column;
						available_Seats[1][i].seat_availability = true;
					}
					in.close();
					determiner = 1; End_Of_Counter = 30;
				}

				else if (Rtime.HOURS == 13)
				{
					ifstream in("available3.txt");
					if (in.fail())
					{
						cerr << "Error in opening that file" << endl;
						exit(1);
					}
					for (int i = 0; i < 20; i++)
					{
						in >> available_Seats[2][i].seatN.row >> available_Seats[2][i].seatN.column;
						available_Seats[2][i].seat_availability = true;
					}
					in.close();
					determiner = 2; End_Of_Counter = 20;
				}

				else if (Rtime.HOURS == 15)
				{
					ifstream in("available4.txt");
					if (in.fail())
					{
						cerr << "Error in opening that file" << endl;
						exit(1);
					}
					for (int i = 0; i < 15; i++)
					{
						in >> available_Seats[3][i].seatN.row >> available_Seats[3][i].seatN.column;
						available_Seats[3][i].seat_availability = true;
					}
					in.close();
					determiner = 3; End_Of_Counter = 15;
				}

				else if (Rtime.HOURS == 18)
				{
					ifstream in("available5.txt");
					if (in.fail())
					{
						cerr << "Error in opening that file" << endl;
						exit(1);
					}
					for (int i = 0; i < 10; i++)
					{
						in >> available_Seats[4][i].seatN.row >> available_Seats[4][i].seatN.column;
						available_Seats[4][i].seat_availability = true;
					}
					in.close();
					determiner = 4; End_Of_Counter = 10;
				}
				else if (Rtime.HOURS == 20)
				{
					ifstream in("available6.txt");
					if (in.fail())
					{
						cerr << "Error in opening that file" << endl;
						exit(1);
					}
					for (int i = 0; i < 1; i++)
					{
						in >> available_Seats[4][i].seatN.row >> available_Seats[4][i].seatN.column;
						available_Seats[4][i].seat_availability = false;
					}
					in.close();
					determiner = 5; End_Of_Counter = 1;
				}
				//_//





				//FATMA's PART_____

				cout << "PLEASE ENTER the the number of SEATS you want : " << endl;
				cin >> numofseats;
				cout << endl;
				cout << endl;
				cout << " ===============================================================================" << endl;
				int result = check(numofseats, determiner, End_Of_Counter);//determiner w end of counter already hyb2a 3arfhom mnk
				if (result == 1) {
					//call hasnaa
				}
				else if (result == 2) { continue; }
				else if (result == 3)
				{
					cout << "Enter number of seats you want to choose from those available seats" << endl;
					cin >> numofseats;
					//call hasnaa
				}
				else if (result == 4)
				{
					cout << "Exit/Thank you" << endl;
					break;
				}

				//____-

				int Booking_isDone = book_seats(numofseats, determiner, End_Of_Counter);
				if (Booking_isDone == 1)
				{
					cout << "booking is done successfully " << endl;
					cout << "you booked the following seats : ";
					for (int j = 0; j < numofseats; j++)
					{
						cout << wanted_seatsARR[j].row << wanted_seatsARR[j].column << " \t ";
					}cout << endl; break;
				}
				else if (Booking_isDone == 2)
				{
					cout << endl;
					continue;
				}
				else if (Booking_isDone == 3)
				{
					cout << endl << endl;
					cout << "..............THANK YOU.............." << endl;
					break;
				}
			}
			cout << "_______________________________________________" << endl
				<< "Back to Main Menu?? if yes TYPE Y" << endl; cin >> menu; cout << "********************" << endl;
		}
	}
	system("pause");
	return 0;
}