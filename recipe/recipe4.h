//Madeline Boss
//COP 3330
//Programming Assignment 4
//Declaration file

#include <cstring>
#include <iostream>
using namespace std;

class RecipeStep
{
    friend ostream& operator<<(ostream& o, const RecipeStep& r);

private:
    int sequenceNumber;
    string header;
    string description;

public:
    RecipeStep();   //default constructor
    RecipeStep(int sequenceNumber, string header, string description);  //parameterized constructor

    int getSeqNumber() const;
    string getHeader() const;
    string getDesc() const;

    void setSeqNumber(int sequenceNumber);
    void setHeader(string header);
    void setDesc(string description);
};

class Recipe
{
    friend ostream& operator<<(ostream& o, const Recipe& r);

private:
    int size;
    int capacity;
    string title;
    string description;
    RecipeStep* steps;

public:
    Recipe();   //default constructor
    Recipe(string title, string description);
    ~Recipe();  //destructor
    Recipe(const Recipe& r);    //copy constructor
    Recipe& operator=(const Recipe& r); //deep copy assignment

    string getTitle() const;
    string getDescription() const;
    RecipeStep& getRecipeStep(int i);

    void setTitle(string title);
    void setDescription(string description);

    void CreateStep(int sequenceNumber, string header, string description);
    void ReadStep();
    void UpdateStep(int sequenceNumber, string header, string description);
    void DeleteStep(int i);
};

class RecipeBook
{
    friend ostream& operator<<(ostream& o, const RecipeBook& r);

private:
    int size;
    int capacity;
    string title;
    Recipe* recipes;

public:
    RecipeBook();   //default constructor
    ~RecipeBook();  //destructor
    RecipeBook(const RecipeBook& r);    //copy constructor
    RecipeBook& operator=(const RecipeBook& g); //deep copy assignment

    string getTitle() const;
    Recipe& getRecipe(int i);

    void setTitle(string title);

    void Create(string title, string description, int i);
    void Read();
    void Update(string title, string description, int i);
    void Delete(int i);

};
