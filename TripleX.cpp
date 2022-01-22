#include <iostream> //PREPROCESSOR DIRECTIVE
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{ 
    cout << "\n\nThrawn: Eli, punch in the tri-digit coordinates for the Plasma cannon!\n" ;
    cout << "Difficulty: " << Difficulty;
}

bool PlayGame(int Difficulty) // void = returns no data
{
    PrintIntroduction(Difficulty);

    // DECLARE 
    const int CodeA = rand() % Difficulty + Difficulty; 
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // PRINT sum & product
    cout << "\n\n+ There are 3 numbers in the code";
    cout << "\n+ The codes add up to: " << CodeSum << ", and multiply to give: " << CodeProduct << "\n\n";

    // STORE Player's Guess
    int GuessA, GuessB, GuessC;
    cout << "Enter tri-digit coordinate: \n";
    cin >> GuessA >> GuessB >> GuessC; 

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\n=== Hit! ===";
        return true;
    }
    else 
    {
        cout << "\n*** Miss! Try Again! ***";
        return false;
    }
}


int main() // The MAIN function is the entry point of a C++ program
{
    srand(time(NULL)); //Creates new random sequence based on the time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
       
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); // Clears any errors
        cin.ignore(); // Discards the buffer

       if (bLevelComplete)
       {
           ++LevelDifficulty;
       }
       
    }

    cout<<"\n====Thrawn: Good job Commander, the frigate is destroyed.====";
    return 0;
}