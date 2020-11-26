// Implementation for a technical interview with
// Ledger*

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// This is to demonstrate that C++ supports protocols through inheritance
class HasDescription {
    public:
        virtual std::string description(){
            return std::string("Please implement description() function in derrived class.");
        }
};

// Player object keeps track of scores and games
class Player : public HasDescription {
    public:
        explicit Player()
        :_score(0), _game(0){}
        explicit Player(const int& score, const int& game)
        : _score(score), _game(game){}
        std::string description(){
            return "\tScore: " + this->getScoreName() + "\n\tGames: " + std::to_string(_game);
        }
        void increment(){
            if (this->_score >= 3){ this->_score = 0; this->_game++;}
            else { this->_score++; }
        }
        std::string getScoreName(){
            return _scoreNames[_score];
        }
    private:
        int _score;
        int _game;
        std::vector<std::string> _scoreNames = {"Love", "15", "30", "40"};
};

std::vector<Player*> calculateScores(std::string scores, Player* p1, Player* p2){
    std::vector<Player*> players = {p1, p2};
    if (scores != ""){
        for (auto& s : scores){
            if (s == 'a' || s == 'A'){
                p1->increment();
            } else if (s == 'b' || s == 'B') {
                p2->increment();
            }
        }
    }
    return players;
}

int main(int argc, char ** argv){

    auto p1 = new Player();
    auto p2 = new Player();

    std::string scores = argv[1] ? argv[1] : "";

    auto players = calculateScores(scores, p1, p2);

    std::cout << "Player A: \n";
    std::cout << players[0]->description() << std::endl;

    std::cout << "Player B: \n";
    std::cout << players[1]->description() << std::endl;


    return 0;
}