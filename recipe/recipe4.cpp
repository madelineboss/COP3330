//Madeline Boss
//COP 3330
//Programming Assignment 4
//Definition file

#include "recipe4.h"

//=====RecipeStep Class=====//

//operator overload
ostream& operator<<(ostream& o, const RecipeStep& r)
{
    o << "Step: " << r.sequenceNumber << endl;
    o << "Header: " << r.header << endl;
    o << "Descripiton: " << r.description << endl;

    return o;
}

//default constructor
RecipeStep::RecipeStep()
{
    sequenceNumber = 0;
    header = "h";
    description = "h";
}

//Parameterized constructor
RecipeStep::RecipeStep(int sequenceNumber, string header, string description)
{
    this -> sequenceNumber = sequenceNumber;
    this -> header = header;
    this -> description = description;
}

//getters

int RecipeStep::getSeqNumber() const
{
    return sequenceNumber;
}

string RecipeStep::getHeader() const
{
    return header;
}

string RecipeStep::getDesc() const
{
    return description;
}

//setters
void RecipeStep::setSeqNumber(int sequenceNumber)
{
    this -> sequenceNumber = sequenceNumber;
}

void RecipeStep::setHeader(string header)
{
    this -> header = header;
}

void RecipeStep::setDesc(string description)
{
    this -> description = description;
}

//=====Recipe Class===//

//operator overload
ostream& operator<<(ostream& o, const Recipe& r)
{
    o << "Title: " << r.title << endl;
    o << "Description: " << r.description << endl;

    return o;
}

//deafult constructor
Recipe::Recipe()
{
    size = 0;
    capacity = 3;
    title = " ";
    description = " ";

    steps = new RecipeStep[capacity];

}

//param constructor
Recipe::Recipe(string title, string description)
{
    this -> title = title;
    this -> description = description;
    size = 0;
    capacity = 3;

    steps = new RecipeStep[capacity];
}

//destructor
Recipe::~Recipe()
{
    delete[] steps;
}

//copy constructor
Recipe::Recipe(const Recipe& r)
{
    size = r.size;
    capacity = r.capacity;

    steps = new RecipeStep[capacity];
    for(int i = 0; i < size; i++)
    {
        steps[i] = r.steps[i];
    }
}

//deep copy assignment
Recipe& Recipe::operator=(const Recipe& r)
{
    if(this != &r)
    {
        size = r.size;
        capacity = r.size;
        title = r.title;
        description = r.description;

        delete[] steps;
        steps = new RecipeStep[capacity];

        for (int i = 0; i < size; i++) {
            steps[i] = r.steps[i];
        }
    }

    return *this;
}

//getters
string Recipe::getTitle() const
{
    return title;
}

string Recipe::getDescription() const
{
    return description;
}

//setters
void Recipe::setTitle(string title)
{
    this -> title = title;
}

void Recipe::setDescription(string description)
{
    this -> description = description;
}

//create function
void Recipe::CreateStep(int sequenceNumber, string header, string description)
{
    if(size >= capacity)
    {
        RecipeStep* tmp = new RecipeStep[capacity + 1];
        for(int i = 0; i < size; i++)
        {
            tmp[i] = steps[i];
        }

        delete[] steps;
        steps = tmp;
        capacity = capacity + 1;
    }
    steps[size] = RecipeStep(sequenceNumber, header, description);
    size++;
}

//read function
void Recipe::ReadStep()
{
    for(int i = 0; i < size; i++)
    {
        cout << steps[i] << endl;
    }
}

//update function
void Recipe::UpdateStep(int sequenceNumber, string header, string description)
{
    steps[sequenceNumber] = RecipeStep(sequenceNumber, header, description);
}

//delete function
void Recipe::DeleteStep(int i)  //made the return type void if this doesn't work go back to normal
{
    for(int b = i; b < size - 1;b++ )
    {
        steps[b] = steps[b + 1];
        steps[b].setSeqNumber(b);
    }
    size--;
}

//=====RecipeBook=====//

//operator overload
ostream& operator<<(ostream& o, const RecipeBook& r)
{
    o << r.title << endl;
    o << "Recipes: " << endl;
    for(int i = 0; i < r.size; i++)
    {
        o << r.recipes[i] << endl;
    }

    return o;
}

//deafult constructor
RecipeBook::RecipeBook()
{
    size = 0;
    capacity = 1;
    title = "Madeline's Fantastic Cook Book";

    recipes = new Recipe[capacity];
}

//destructor
RecipeBook::~RecipeBook()
{
    delete[] recipes;
}
//copy constructor
RecipeBook::RecipeBook(const RecipeBook& r)
{
    this -> title = r.title;
    this -> size = r.size;
    this -> capacity = r.capacity;

    recipes = new Recipe[capacity];
    for(int i = 0; i < size; i++)
    {
        recipes[i] = r.recipes[i];
    }
}

//deep copy assignment
RecipeBook &RecipeBook::operator=(const RecipeBook& g)
{
        size = g.size;
        capacity = g.capacity;
        title = g.title;

        delete[] recipes;
        recipes = new Recipe[capacity];
        for (int i = 0; i < size; i++)
        {
            recipes[i] = g.recipes[i];
        }

        return *this;
}

//getters
string RecipeBook::getTitle() const
{
  return title;
}
Recipe& RecipeBook::getRecipe(int i)
{
  return recipes[i];
}

//setter
void RecipeBook::setTitle(string title)
{
  this -> title = title;
}

void RecipeBook::Create(string title, string description, int i)
{
    if(size >= capacity)
    {
        Recipe* tmp = new Recipe[capacity + 1];

        for(int i = 0; i < size; i++)
        {
            tmp[i] = recipes[i];
        }

        delete[] recipes;
        recipes = tmp;
        capacity = capacity + 1;
    }

    recipes[i] = Recipe(title, description);
    size++;
}


//read function
void RecipeBook::Read()
{
  for(int i = 0; i < size; i++)
  {
    cout << recipes[i] << endl;
  }
}

//update function
void RecipeBook::Update(string title, string description, int i)
{
    recipes[i] = Recipe(title, description);
}

//delete function
void RecipeBook::Delete(int i)
{
    for(int b = i; b < size - 1; b++)
    {
        recipes[b] = recipes[b + 1];
    }

    size--;
}

