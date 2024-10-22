//Madeline Boss
//COP 3330
//Programming Assignment 4
//Driver file

#include "recipe4.h"

int main()
{
    RecipeBook book;
    book = RecipeBook();
    cout << book;

    //create function
    book.Create("Brownies", "Fudgy, Delicious Brownies!", 0);
    book.Create("Cupcakes", "Banana Foster's Cupcakes", 1);
    book.Create("Rice", "Garlic Parm Rice", 2);
    book.Create("Chicken", "Crispy Chicken Cutlets", 3);

    book.Read();

    cout << endl;
    cout << "Deleting" << endl;
    book.Delete(3);
    book.Update("Really Good Rice", "Garlic Parm rice that is super good", 2);
    cout << "Updating" << endl;

    book.Read();

    cout << endl;
    cout << endl;


    book.getRecipe(0).CreateStep(0, "Get Ingredients", "Please get the box mix, one egg, and oil");
    book.getRecipe(0).CreateStep(1, "Mix!", "Mix all of the ingredients together");
    book.getRecipe(0).CreateStep(2, "Bake", "Bake the brownies at 350 degrees for 20 minutes");
    book.getRecipe(0).CreateStep(3, "Enjoy!" , "Let the brownies cool and enjoy!");

    book.getRecipe(1).CreateStep(0,"Bananas", "Find perfect bananas");
    book.getRecipe(1).CreateStep(1, "Mash", "Mash the banaas");
    book.getRecipe(1).CreateStep(2, "Mix", "Fold the banana mush into the cupcake batter");
    book.getRecipe(1).CreateStep(3, "Bake", "Bake the cupcakes at 375 for 10 minutes");
    book.getRecipe(1).CreateStep(4, "Frosting", "Let the cupcakes cool and add frsoting");

    book.getRecipe(2).CreateStep(0, "Rice", "Cook the rice");
    book.getRecipe(2).CreateStep(1, "Garlic", "Mince three cloves of garlic");
    book.getRecipe(2).CreateStep(2, "Cheese", "Grate three cups of fresh parmesan");
    book.getRecipe(2).CreateStep(3, "Combine", "Combine the rice, garlic, and cheese for some delicious rice!");

    cout << "Reading" << endl;
    book.getRecipe(1).ReadStep();
    book.getRecipe(1).DeleteStep(1);
    cout << "Deleting"<< endl;
    book.getRecipe(1).ReadStep();
    book.getRecipe(1).UpdateStep(1, "Mix and Mash", "Mash the bananas and mix with other ingredients");
    cout << "Updating" << endl;
    book.getRecipe(1).ReadStep();

    return 0;
}