//Final Project
//Student: Wenjin Li
//Instructor: Hoenigman

#include "FinalProject.h"
#include <iostream>
#include <sstream>
#include <fstream>


FinalProject::FinalProject()
{
    root = NULL;//ctor
    root_rank = NULL;
    return;
}

FinalProject::~FinalProject()
{
    //dtor
}

void FinalProject::addMovieNode(int ranking, string title, int releaseYear, int quantity,string director){
    MovieNode *newNode=new MovieNode(); //set new pointer
    newNode->ranking = ranking; //put data from file into those four subjects
    newNode->title = title;
    newNode->year = releaseYear;
    newNode->quantity = quantity;
    newNode->director = director;
    newNode->leftChild = newNode->rightChild = NULL; //initialize left node and right node to NULL

    MovieNode *temp;
    MovieNode *temp2;
    temp = root; //set temp equal root
    temp2 = NULL; //set temp2 is a empty pointer

    //while loop to help loop through a binary search tree and insert nodes into bst by alpha order
    while(temp !=NULL) //while root already initialized
    {
        temp2 = temp; //temp2 become root
        if(newNode->title < temp->title) //compare two movie title and if newNode title is larger than temp title, then put it left
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }
    if(temp2 ==NULL) //if temp2 is empty, initialize first newNode to be root
        root = newNode;
    else //otherwise we will arrange the order
    {
        if(newNode->title < temp2->title)
            temp2->leftChild = newNode;
        else
            temp2->rightChild = newNode;
    }
//------------------------------------------------------------------------------------------------
    MovieNode_ranking *newNode_rank=new MovieNode_ranking(); //set new pointer
    newNode_rank->ranking = ranking; //put data from file into those four subjects
    newNode_rank->title = title;
    newNode_rank->year = releaseYear;
    newNode_rank->quantity = quantity;
    newNode_rank->director = director;
    newNode_rank->leftChild = newNode_rank->rightChild = NULL; //initialize left node and right node to NULL

    MovieNode_ranking *temp_rank;
    MovieNode_ranking *temp2_rank;
    temp_rank = root_rank; //set temp equal root
    temp2_rank = NULL; //set temp2 is a empty pointer

    //while loop to help loop through a binary search tree and insert nodes into bst by alpha order
    while(temp_rank !=NULL) //while root already initialized
    {
        temp2_rank = temp_rank; //temp2 become root
        if(newNode_rank->ranking < temp_rank->ranking) //compare two movie title and if newNode title is larger than temp title, then put it left
            temp_rank = temp_rank->leftChild;
        else
            temp_rank = temp_rank->rightChild;
    }
    if(temp2_rank ==NULL) //if temp2 is empty, initialize first newNode to be root
        root_rank = newNode_rank;
    else //otherwise we will arrange the order
    {
        if(newNode_rank->ranking < temp2_rank->ranking)
            temp2_rank->leftChild = newNode_rank;
        else
            temp2_rank->rightChild = newNode_rank;
    }
//-----------------------------------------------------------------------------------
}

void FinalProject::printMovieInventory(){
    printMovieInventory(root); //display all movies in bst
}

void FinalProject::printMovieInventory(MovieNode *node){
    if(node !=NULL){ //check node is empty or not, if is not empty, then
        if(node->leftChild) //node to left, and put into printMovieInventory function
            printMovieInventory(node->leftChild);
        cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
        if(node->rightChild) //node to right, and put into printMovieInventory function
            printMovieInventory(node->rightChild);
    }
}

void FinalProject::rentMovie(string title){
    MovieNode *temp; //same build in findMovie function
    temp = root;
    while((temp!=NULL) && (temp->title != title))
    {
        if(title < temp->title)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }
    if(temp == NULL)
        cout<<"Movie not found."<<endl;
    else
        if(temp->quantity != 0){ //if movie found, and quantity is not 0
            temp->quantity = temp->quantity-1; // then new quantity equal old quantity minus 1,
            cout<<"Movie has been rented."<<endl; //and display all info
            cout<<"Movie Info:"<<endl;
            cout<<"===========" <<endl;
            cout<<"Ranking:"<<temp->ranking<<endl;
            cout<<"Title:"<<temp->title<<endl;
            cout<<"Year:"<<temp->year<<endl;
            cout<<"Quantity:"<<temp->quantity<<endl;
            cout<<"Director:"<<temp->director<<endl;
        }
        else
            cout<<"Movie out of stock." <<endl; //if quantity is 0, then display out of stock
}

void FinalProject::returnMovie(string title){
    MovieNode *temp; //same build in findMovie function
    temp = root;
    while((temp!=NULL) && (temp->title != title))
    {
        if(title < temp->title)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }
    if(temp == NULL)
        cout<<"Movie not found."<<endl;
    else
        if(temp->quantity != 0){ //if movie found, and quantity is not 0
            temp->quantity = temp->quantity+1; // then new quantity equal old quantity minus 1,
            cout<<"Movie has been rented."<<endl; //and display all info
            cout<<"Movie Info:"<<endl;
            cout<<"===========" <<endl;
            cout<<"Ranking:"<<temp->ranking<<endl;
            cout<<"Title:"<<temp->title<<endl;
            cout<<"Year:"<<temp->year<<endl;
            cout<<"Quantity:"<<temp->quantity<<endl;
            cout<<"Director:"<<temp->director<<endl;
        }
        else
            cout<<"Movie out of stock." <<endl; //if quantity is 0, then display out of stock
}


void FinalProject::deleteMovie(string title){
    MovieNode *temp; //new pointer equal root
    temp = root;
    MovieNode *track = NULL; //new pointer to track the nodes
    while((temp!=NULL) &&(title != temp->title))  //while loop to help find user input movie
    {
        track = temp;
        if(title < temp->title)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }
    if(temp ==NULL)
    {
        cout<<"Movie not found."<<endl;
    }
    else{
        if(temp->rightChild ==NULL) //deleting node with case no child or one child
        {
            if(temp == root)  //if its root, deleting root
            {
                root = temp->leftChild;
                delete temp;
            }
            else{ //if it is not root, then use if statement to find which one it is and delete the node
                if(track->leftChild == temp){
                    track->leftChild = temp->leftChild;
                }
                else{
                    track->rightChild = temp->leftChild;
                    delete temp;
                }

            }
        }
        else //This case is one child or two child.
        {
            if(temp->leftChild == NULL) //1 right child
            {
                if(temp == root) //if its root, deleting root
                {
                   root = temp->rightChild;
                   delete temp;
                }
                else //same as the previous code to find the node by using two pointers
                {
                    if(track->leftChild == temp){
                        track->leftChild = temp->rightChild;
                    }
                    else{
                        track->rightChild = temp->rightChild;
                    }
                }
            }
            else //deleting two children node
            {
                MovieNode *tempNode; //we need a new variable pointer to help us delete in two child case
                tempNode = temp;
                temp = tempNode->rightChild;
                track = tempNode;
                while(temp->rightChild != NULL)
                {
                    track = temp;
                    temp = temp->rightChild;
                }
                //put the replacement into the node we deleted
                tempNode->title = temp->title;
                tempNode->quantity = temp->quantity;
                tempNode->ranking = temp->ranking;
                tempNode->year = temp->year;
                tempNode->director = temp->director;
                if(track != tempNode) //delete the node
                    track->leftChild = temp->leftChild;
                else
                    track->rightChild = temp->leftChild;
                delete temp;
            }
        }
    }
}


int FinalProject::countMovieInventory(MovieNode *node){
    if(node == NULL){ //if the tree is empty return 0
        return 0;
    }
    else { //if not, then set integer equal1 and track each node by increase 1. Put next leftchild and rightchild into the function until the end
        int count = 1;
        count += countMovieInventory(node->leftChild);
        count += countMovieInventory(node->rightChild);
        return count; //return the total
    }
}

int FinalProject::countMovieInventory(){
    countMovieInventory(root);
}

void FinalProject::findMovieByranking(int ranking){
    MovieNode_ranking *temp = root_rank; //set a temp pointer and initialize it to root
    while((temp!=NULL) && (temp->ranking != ranking)) //Use while loop to search user input movie title
    {
        if(ranking < temp->ranking) //if user move title is smaller than movie title in bst
            temp = temp->leftChild; // then go left
        else
            temp = temp->rightChild; // otherwise go right
    }
    if(temp == NULL){
        cout<<"Movie not found."<<endl;
    }
    else{
        cout<<"Movie Info:"<<endl;
        cout<<"===========" <<endl;
        cout<<"Ranking:"<<temp->ranking<<endl;
        cout<<"Title:"<<temp->title<<endl;
        cout<<"Year:"<<temp->year<<endl;
        cout<<"Quantity:"<<temp->quantity<<endl;
        cout<<"Director:"<<temp->director<<endl;
    }

}

void FinalProject::findMovie(string title){
    MovieNode *temp = root; //set a temp pointer and initialize it to root
    while((temp!=NULL) && (temp->title != title)) //Use while loop to search user input movie title
    {
        if(title < temp->title) //if user move title is smaller than movie title in bst
            temp = temp->leftChild; // then go left
        else
            temp = temp->rightChild; // otherwise go right
    }
    if(temp == NULL){
        cout<<"Movie not found."<<endl;
    }
    else{
        cout<<"Movie Info:"<<endl;
        cout<<"===========" <<endl;
        cout<<"Ranking:"<<temp->ranking<<endl;
        cout<<"Title:"<<temp->title<<endl;
        cout<<"Year:"<<temp->year<<endl;
        cout<<"Quantity:"<<temp->quantity<<endl;
        cout<<"Director:"<<temp->director<<endl;
    }
}

void FinalProject::printMovieDirector(){
    printMovieInventory(root); //display all movies in bst
}

void FinalProject::printMovieDirector(MovieNode *node){
    if(node !=NULL){ //check node is empty or not, if is not empty, then
        if(node->leftChild) //node to left, and put into printMovieInventory function
            printMovieInventory(node->leftChild);
        cout<<"Movie: "<<node->director<<endl;
        if(node->rightChild) //node to right, and put into printMovieInventory function
            printMovieInventory(node->rightChild);
    }
}

