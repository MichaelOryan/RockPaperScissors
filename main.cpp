#include <iostream>
#include <string>
#include <random>

void updateWins(const Player p1, unsigned int &p1Score, const Player p2, unsigned int &p2Score, Player winner);
void playRound(unsigned int &playerWins, unsigned int &computerWins);
void printSummary(unsigned int playerWins, unsigned int computerWins);
void print(Text text);
Choice getComputerChoice();
Choice convertToChoice(int n);
Choice getPlayerChoice();

const unsigned int NUMBER_OF_CHOICES = 3;
enum Choice = {ROCK = 1, PAPER = 2, SCISSORS = 3};
enum Player = {HUMAN, COMPUTER};
enum Text = {GREETINGS, CHOICES, UNKNOWNCHOICE};

int main()
{
    unsigned int playerWins = 0, computerWins = 0;

    print(GREETINGS);

    do{
        playRound(playerWins, computerWins);
    } while(playAgain());
    
    printSummary(playerWins, computerWins);
    
    return 0;
}

void playRound(unsigned int &playerWins, unsigned int &computerWins)
{
    Player winner = calcWinner(HUMAN, getPlayerChoice(), COMPUTER, getComputerChoice());
    printResult(winner);
    updateWins(HUMAN, playerWins, COMPUTER, computerWins, winner);
}

void updateWins(const Player p1, unsigned int &p1Score, const Player p2, unsigned int &p2Score, Player winner)
{
    if(p1 == winner)
        ++p1Score;
    if(p2 == winner)
        ++p2Score;
}

void printSummary(unsigned int playerWins, unsigned int computerWins)
{
    std::cout << "You scored: " << playerWins "\nComputer Scored: " << computerWins << std::endl;
    if(playerWins > computerWins)
        std::cout << "You Won!"<< std::endl;
    else if (computerWins > playerWins)
        std::cout << "Computer Won!"<< std::endl;
    else
        std::cout << "It was a draw!"<< std::endl;
}

Choice getPlayerChoice()
{
    string playerMove;
    print(CHOICES);
    getline(std::cin, playerMove);

    while(!(playerMove == std::itoa(ROCK) || playerMove == std::itoa(PAPER) || playerMove == std::itoa(SCISSORS)))
    {
        print(UNKNOWNCHOICE);
        print(CHOICES);
        getline(std::cin, playerMove);
    }
    
    return convertToChoice(std::stoi(playerMove))
}

void print(Text text)
{
    string output;
    switch(text)
    {
        case GREETINGS: output = "Welcome to Rock, Paper, Scissors!"; break;
        case CHOICES: output = "Enter " << std::itoa(ROCK) << " to play Rock, " << std::itoa(PAPER) << " to play Paper, and " << std::itoa(SCISSORS) << " to play Scissors!:"; break;
        case UNKNOWNCHOICE: output = "Unknown command! Please try that again..."; break;
        default
    }
}

Choice convertToChoice(int n)
{
    Choice playerChoice;
    
    switch(n)
    {
        case ROCK: playerChoice == ROCK; break;
        case SCISSORS: playerChoice == SCISSORS; break;
        case PAPER: playerChoice == PAPER; break;
        default: playerChoice == ROCK; break;
    }
    
    return playerChoice;
}

Choice getComputerChoice()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, NUMBER_OF_CHOICES);
    
    return convertToChoice(distr(eng));
}
