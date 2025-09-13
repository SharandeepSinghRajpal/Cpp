#include <iostream>
#include <ctime>

char GetUserChoice();
char GetComputerChoice();
void ShowChoice(char choice);
void chooseWinner(char player,char computer);

int main(){
    srand(time(0));
    char player;
    char computer;
    char PlayAgain;
do{
    player = GetUserChoice();
    std::cout<<"Your Choice: ";
    ShowChoice(player);
    std::cout<<std::endl;

    computer = GetComputerChoice();
    std::cout<<"Computer's Choice: ";
    ShowChoice(computer);
    std::cout<<std::endl;

    chooseWinner(player,computer);

    std::cout<<"Play again (y/n)? \n";
    std::cin>>PlayAgain;

}while(PlayAgain=='y' || PlayAgain=='Y');

    return 0;
}

char GetUserChoice(){
    char player;
    std::cout<<"**************************** \n";
    std::cout<<"**Rock Paper Scissors game** \n";
    std::cout<<"**************************** \n\n";

    do{
    std::cout<<"Choose one of the following:\n";
    std::cout<<"r for rock \n";
    std::cout<<"p for paper \n";
    std::cout<<"s for scissors \n";


    std::cin>> player;
    }while(player !='r' && player !='p' && player !='s');

    return player;

}

char GetComputerChoice(){
    int num = rand()% 3 + 1 ;

    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 0;
}

void ShowChoice(char choice){

    switch(choice){
        case 'r': std::cout<<"Rock";
            break;
        case 'p': std::cout<<"Paper";
            break;
        case 's': std::cout<<"Scissors";
        break;
    }
}

void chooseWinner(char player,char computer){ 
        if (player == computer) {
        std::cout << "It's a Tie!";
    }
    else if ((player == 'r' && computer == 's') ||
             (player == 'p' && computer == 'r') ||
             (player == 's' && computer == 'p')) {
        std::cout << "You Win!!!";
    }
    else {
        std::cout << "Computer Wins!!!";
    }
    

}