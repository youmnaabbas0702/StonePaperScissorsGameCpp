#include <iostream>
using namespace std;

enum enChoice{Stone = 1, Paper, Scissors};

enum enWinner{Player = 1, Computer, Draw};

int AskUserForRounds()
{
    int Rounds = 0;
    do 
    {
        cout << "How Many rounds you want to play? :";
        cin >> Rounds;
        cout << endl;

    } while (Rounds <= 0);
    
    return Rounds;
}

enChoice ReadUserChoice()
{
    enChoice choice;
    unsigned short intChoice;
    bool Stop = false;

    cout << "Enter your choice: [1]Stone. [2]Paper. [3]Scissors. :";
    cin >> intChoice;

    do
    {
        switch (intChoice)
        {
        case 1:
            choice = enChoice::Stone;
            Stop = true;
            break;
        case 2:
            choice = enChoice::Paper;
            Stop = true;
            break;
        case 3:
            choice = enChoice::Scissors;
            Stop = true;
            break;
        default:
            Stop = false;
        }

    } while (Stop = false);

    return choice;
}

enChoice GenerateComputerChoice()
{
    unsigned short choice = 0;

    choice = (rand() % 3) + 1;

    return (enChoice)choice;
}

enWinner WhoIsTheWinner(enChoice PlayerChoice, enChoice ComputerChoice)
{
    if (PlayerChoice == ComputerChoice)
        return enWinner::Draw;

    switch (PlayerChoice)
    {
    case Stone:
        if (ComputerChoice == enChoice::Paper)
            return enWinner::Computer;
        break;
    case Paper:
        if (ComputerChoice == enChoice::Scissors)
            return enWinner::Computer;
        break;
    case Scissors:
        if (ComputerChoice == enChoice::Stone)
            return enWinner::Computer;
        break;
    default:
        break;
    }

    return enWinner::Player;
}

void PrintRoundResults(enChoice PlayerChoice, enChoice ComputerChoice, enWinner Winner, int Round)
{
    cout << "\n________________Round [" << Round << "]________________\n";
    
    cout << "Player Choice : ";
    switch (PlayerChoice)
    {
    case Stone:
        cout << "Stone\n";
        break;
    case Paper:
        cout << "Paper\n";
        break;
    case Scissors:
        cout << "Scissors\n";
        break;
    }

    cout << "Computer Choice : ";
    switch (ComputerChoice)
    {
    case Stone:
        cout << "Stone\n";
        break;
    case Paper:
        cout << "Paper\n";
        break;
    case Scissors:
        cout << "Scissors\n";
        break;
    }
    
    cout << "Round Winner : ";
    switch (Winner)
    {
    case Computer:
        cout << "\a";
        cout << "[Computer]\n";
        system("color 4F");
        break;
    case Player:
        cout << "[Player]\n";
        system("color 2F");
        break;
    case Draw:
        cout << "[No winner]\n";
        system("color 6F");
        break;
    }
    cout << "\n________________________________________________________\n";
}

void CountWinner(enWinner Winner, int& PlayerCount, int& ComputerCount, int& DrawCount)
{
    switch (Winner)
    {
    case Player:
        PlayerCount++;
        break;
    case Computer:
        ComputerCount++;
        break;
    case Draw:
        DrawCount++;
        break;
    }
}

void GenerateGameRound(int Round, int& PlayerCount, int& ComputerCount, int& DrawCount)
{
    enChoice UserChoice = ReadUserChoice();

    enChoice ComputerChoice = GenerateComputerChoice();

    enWinner Winner = WhoIsTheWinner(UserChoice, ComputerChoice);

    CountWinner(Winner, PlayerCount, ComputerCount, DrawCount);

    PrintRoundResults(UserChoice, ComputerChoice, Winner, Round);
}

void GenerateRounds(int Rounds, int& PlayerCount, int& ComputerCount, int& DrawCount)
{
    for (int i = 1; i <= Rounds; i++)
    {
        cout << "Round [" << i << "] Begins: \n\n";
        GenerateGameRound(i, PlayerCount, ComputerCount, DrawCount);
    }
}

void EndGame(int Rounds, int& PlayerCount, int& ComputerCount, int& DrawCount)
{
    cout << "\t\t\t_________________________________________\n\n";
    cout << "\t\t\t+++ G a m e  O v e r +++\n\n";
    cout << "Game Rounds : " << Rounds << endl;
    cout << "Player Win times : " << PlayerCount << endl;
    cout << "Computer Win times : " << ComputerCount << endl;
    cout << "Draw times : " << DrawCount << endl;
    cout << "Final Winner is : ";
    if (PlayerCount > ComputerCount)
        cout << "You\n";
    else if (ComputerCount > PlayerCount)
        cout << "Computer\n";
    else
        cout << "No winner\n";
}

void GenerateGame()
{
    char C;
    bool PlayAgain;

    do
    {

        int Rounds = AskUserForRounds();
        int PlayerCount = 0, ComputerCount = 0, DrawCount = 0;

        GenerateRounds(Rounds, PlayerCount, ComputerCount, DrawCount);

        EndGame(Rounds, PlayerCount, ComputerCount, DrawCount);

        cout << "Do you want to playe again? Y/N : ";
        cin >> C;

        switch (C)
        {
        case 'Y':
        case 'y':
            PlayAgain = true;
            system("color 0F");
            system("cls");
            PlayerCount = 0;
            ComputerCount = 0;
            DrawCount = 0;
            break;
        default:
            PlayAgain = false;
        }
    } while (PlayAgain);
}

int main()
{
    srand((unsigned)time(NULL));
    GenerateGame();
}