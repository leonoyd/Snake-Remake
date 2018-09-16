#include "top_score.h"
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <../project_settings.h>

top_score::top_score()
{
    //ctor
    load_top_score();
}

top_score::~top_score()
{
    //dtor
}

std::string get_sudstr_first(std::string& str)
{
    std::string tmpStr;
    std::string::size_type found = str.find(":");
    if(found!=std::string::npos)
    {
        tmpStr = str.substr(0,found);
    }

    return tmpStr;
}

std::string get_sudstr_last(std::string& str)
{
    std::string tmpStr;
    std::string::size_type found = str.find(":");
    if(found!=std::string::npos)
    {
        tmpStr = str.substr(found+1);
    }

    return tmpStr;
}

void top_score::load_top_score()
{
    std::ifstream ifile;
    std::string istr;

    ifile.open("top_score.cfg");

    if(ifile.is_open())
    {
        //leonoy douglas:450
        while(std::getline(ifile, istr))
        {
            tp_score tmp_score;
            tmp_score.name = get_sudstr_first(istr);
            tmp_score.score = get_sudstr_last(istr);
            top_score_table.push_back(tmp_score);
        }
    }
    else{

        std::ofstream tmp;
        tmp.open("top_score.cfg");
        tmp.close();
    }
    ifile.close();
}

void top_score::eventHandler(sf::Event& event)
{
    std::string str;
    sf::Text text;
    if (event.type == sf::Event::TextEntered)
    {
        // Handle ASCII characters only
        if (event.text.unicode < 128)
        {
            str += static_cast<char>(event.text.unicode);
            text.setString(str);
        }
    }

}
#if 0
top_score::getPlayerName()
{

}
top_score::addTopScore()
{

}
#endif

void top_score::saveTopScore()
{
    std::ofstream ofile;

    ofile.open("top_score.cfg");

    if(ofile.is_open())
    {
        for(auto& ts : top_score_table)
            ofile<<ts.name<<":"<<ts.score<<std::endl;
    }

    ofile.close();
}
void top_score::drawTitle(sf::RenderWindow& window)
{
    sf::Font font;
    sf::Text text;
    bool st = font.loadFromFile("BEBAS___.ttf");

    text.setFont(font);
    text.scale(sf::Vector2f(1.5,1.5));
    text.setColor(sf::Color::Red);
    text.setString("Top Score");
    text.setPosition((platform_w-(text.getGlobalBounds().width))/2,25);

    window.draw(text);
}


void top_score::draw(sf::RenderWindow& window)
{
    sf::Font font;
    sf::Text text;

    drawTitle(window);
    bool st = font.loadFromFile("BEBAS___.ttf");

    text.setFont(font);
    text.setColor(sf::Color::White);

    int line = 0;
    for(auto& ts : top_score_table )
    {

        text.setPosition(40,100+line*TOP_SCORE_LINE_SPACING);
        text.setString(ts.name);
        window.draw(text);

        text.setPosition(350,100+line*TOP_SCORE_LINE_SPACING);
        text.setString(ts.score);
        window.draw(text);
        line++;
    }


//text.setString(std::to_string(mScore));
    //window.draw(text);
}


