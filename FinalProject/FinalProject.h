//Final Project
//Student: Wenjin Li
//Instructor: Hoenigman


#ifndef FINALPROJECT_H
#define FINALPROJECT_H
#include <iostream>


using namespace std;

struct MovieNode{
    int ranking;
    std::string title;
    int year;
    int quantity;
    std::string director;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity,std::string in_director)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        director = in_director;
    }

};


struct MovieNode_ranking{
    int ranking;
    std::string title;
    int year;
    int quantity;
    std::string director;
    MovieNode_ranking *parent;
    MovieNode_ranking *leftChild;
    MovieNode_ranking *rightChild;

    MovieNode_ranking(){};

    MovieNode_ranking(int in_ranking, std::string in_title, int in_year, int in_quantity,std::string in_director)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        director = in_director;
    }

};

class FinalProject
{
    public:
        FinalProject();
        virtual ~FinalProject();
        void printMovieInventory();
        void addMovieNode(int ranking, std::string title, int releaseYear, int quantity,std::string director);
        void findMovie(std::string title);
        void rentMovie(std::string title);
        void returnMovie(std::string title);
        void deleteMovie(std::string title);
        void findMovieBytimerange(int Year_start, int Year_end);
        void findMovieByranking(int ranking);
        void printMovieDirector();
        int countMovieInventory();
	void printMoviesInYearRange(int startYear, int endYear);


    protected:
    private:
	void printMoviesInYearRange(int startYear, int endYear, MovieNode * node);
        void printMovieInventory(MovieNode * node);
        void printMovieDirector(MovieNode *node);
        int countMovieInventory(MovieNode *node);
        MovieNode* search(std::string title);
        MovieNode *root;
        MovieNode_ranking *root_rank;
};

#endif // FINALPROJECT_H
