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
		int ID;
		string header;
		string description;
		
		
	public:
		RecipeStep();	//default constructor
		RecipeStep(int sequenceNumber, string header, string description);	//parameterized constructor
			
		int getSeqNumber() const;
		string getHeader() const;
		string getDesc() const;
		int getStepID() const;
		
		void setSeqNumber(int sequenceNumber);
		void setHeader(string header);
		void setDesc(string description);
		void setStepID(int ID);
		
	
};

class Recipe
{
	friend ostream& operator<<(ostream& o, const Recipe& r);
	private: 
		int size;
		int capacity;
		int recStep;
		int ID;
		string title;
		string description;
		RecipeStep* steps;
		
	public:
		Recipe();	//default constructor
		Recipe(string title, string description);	//param constructor
		~Recipe();	//destructor
		Recipe(const Recipe& r);	//copy constructor
		Recipe& operator=(const Recipe& r);		//deep copy assignment
				
		string getTitle() const;
		string getDescription() const;
		int getRecipeStep() const;
		int getRecipeID() const;
		RecipeStep& getRecStep(int i);
		
		void setTitle(string title);
		void setDescription(string description);
		void setRecipeStep(int recStep);
		void setRecipeID(int ID);
		
		void CreateStep(int sequenceNumber, string header, string description);
		void ReadStep();
		void UpdateStep(int sequenceNumber, string header, string description);
		RecipeStep DeleteStep(int i);

};

class RecipeBook
{
	friend ostream& operator<<(ostream& o, const RecipeBook& r);
	private: 
		int size;
		int capacity;
		int recNum;
		string title;
		Recipe* recipes;
		
	public:
		RecipeBook();	//default constructor
		RecipeBook(string title);	//parameterized constructor
		~RecipeBook();	//destructor
		RecipeBook(const RecipeBook& r);	//copy constructor
		RecipeBook& operator=(const RecipeBook& r);	//deep copy assignment
		
		int getRecNum() const;
		string getTitle();
		Recipe& getRecipe(int i);	//return recipe[i]
		
		
		void setRecNum(int recNum);
		void setTitle(string title);
		
		void Create(string title, string description); //Create(string title, string description)
		void Read();
		void Update(string title, string description, int i);
		Recipe Delete(int i);
};
