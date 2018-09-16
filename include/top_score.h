#ifndef TOP_SCORE_H
#define TOP_SCORE_H

#include <SFML/Graphics.hpp>


struct tp_score
{
    std::string name;
    std::string score;
};
class top_score
{
    public:
        top_score();
        virtual ~top_score();
        void draw(sf::RenderWindow& window);
        void load_top_score();
        void saveTopScore();
        void drawTitle(sf::RenderWindow& window);
        void eventHandler(sf::Event& event);
        int lowestTopScore(){return stoi(top_score_table.back().score);}

    protected:

    private:
        std::map<int, std::string> mTopScore;
        std::vector<tp_score> top_score_table;
    public:

};

#endif // TOP_SCORE_H
