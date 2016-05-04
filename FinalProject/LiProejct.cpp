//Final Project
//Student: Wenjin Li
//Instructor: Hoenigman

#include <iostream>
#include <sstream>
#include <fstream>
#include "FinalProject.h"



using namespace std;


int main(int argc, char* argv[])
{
    FinalProject t; //
    ifstream infile;
    string line;
    string tmpranking;
    string tmptitle;
    string tmpyear;
    string tmpquantity;
    string movie;
    string tmpdirector;
    string director;
    string title;
    int startYear;
    int endYear;
    int int_ranking;
    int int_year;
    int int_quantity;
    int releaseYear;
    int ranking;
    int quantity;

    infile.open(argv[1]); //open file by using command line
    while(getline(infile,line)){
        istringstream ss(line); // convert all lines in file into string
        getline(ss,tmpranking,','); //read file separate by comma
        stringstream convert(tmpranking);   // convert ranking be a integer therefore we can take it into movie node
        convert>>int_ranking;

        getline(ss,tmptitle,',');

        getline(ss,tmpyear,',');
        stringstream convertt(tmpyear);   // convert year be a integer therefore we can take it into movie node
        convertt>>int_year;

        getline(ss,tmpquantity,',');
        stringstream converttt(tmpquantity);  // convert quantity be a integer therefore we can take it into movie node
        converttt>>int_quantity;

        getline(ss,tmpdirector,',');

        t.addMovieNode(int_ranking,tmptitle,int_year,int_quantity,tmpdirector); //put data from file into the void function in another cpp file

    }

    int choice;
    bool gameOn = true; //use boolean to keep running main menu until hit No4.
    while (gameOn != false){ //display those five options
        cout << "======Main Menu======\n";
        cout << "1. Searching tool: Movie name\n";
        cout << "2. Searching tool: Movie Ranking\n";
        cout << "3. Display total amount of movies\n";
        cout << "4. Display movie directors\n";
        cout << "5. Display the movie list\n";
        cout << "6. Remove a movie from the list\n";
        cout << "7. Rent a movie\n";
        cout << "8. Return a movie\n";
        cout << "9. Store a new movie\n";
	cout << "10. Display movies in a range of years\n";
        cout << "11. Delete all movies in the list and quit\n";

        cin >> choice; //get input to choose the option
	if(cin.good()){
        switch (choice)
        {
            case 1:
                cout<<"Enter title:"<<endl;
                cin.ignore(); //get user input and call findMovie function
                getline(cin,movie);
                t.findMovie(movie);
                break;

            case 2:
                cout<<"Enter ranking:"<<endl;
                cin.ignore(); //get user input and call findMovie function
                cin>>ranking;
                t.findMovieByranking(ranking);
                break;

            case 3:
                cout<<"List have: " <<t.countMovieInventory()<< " movies" <<endl;
                break;


            case 4:
                t.printMovieDirector();
                break;


            case 5:
                t.printMovieInventory(); //call printMovieInventory function
                break;

            case 6:
                cout<<"Enter title:"<<endl;
                cin.ignore();
                getline(cin,movie);
                t.deleteMovie(movie);
                break;

            case 7:
                cout<<"Enter title:"<<endl;
                cin.ignore();  //get user input and call rentMovie function
                getline(cin,movie);
                t.rentMovie(movie);
                break;


            case 8:
                cout<<"Enter title:"<<endl;
                cin.ignore();  //get user input and call rentMovie function
                getline(cin,movie);
                t.returnMovie(movie);
                break;

            case 9:
                cout<<"Enter title:"<<endl;
                cin.ignore(); //get user input and call findMovie function
                getline(cin,title);

                cout<<"Who is the director:"<<endl;
                getline(cin,director);

                cout<<"Enter ranking:"<<endl;
                cin>>ranking;
                cout<<"Enter release year:"<<endl;
                cin>>releaseYear;
                cout<<"How many in stock:"<<endl;
                cin>>quantity;

                t.addMovieNode(ranking,title,releaseYear,quantity,director);
                break;
	    
	    case 10:
		cout << "Enter year to begin with: " << endl;
		
		cin >> startYear;
		cout << "Enter year to end with: " << endl;
		cin >> endYear;
		t.printMoviesInYearRange(startYear, endYear);
		break;

            case 11: cout<<"Goodbye!"<<endl; //output good bye and exit the main menu

            gameOn = false;
            break;
            default:
            cout << "Not a Valid Choice. \n";
            cout << "Choose again.\n";
            cin >> choice;
            break;
        }
	}
	else{
	    cout << "Not a valid choice." << endl;
	    cin.clear();
	    cin.ignore(9999, '\n');
	    continue;	
	}
    }
    return 0;
}
