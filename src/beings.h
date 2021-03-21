#include "./neuralDecisionsCpp/src/neural.h"

#include <SFML/Graphics.hpp>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <math.h>

class being
{
public:
    std::vector<int> sizes = {8, 8, 8, 8};
    sf::RectangleShape being_visualize(sf::Vector2f(20, 20));
    layer neural_network;
    std::vector<float> action = {0, 0};
    float pos_x = 0, pos_y = 0;

public:
    // constructor
    being();
    // this only move the being
    void move(std::vector<float>, sf::RenderWindow *);
};
class the_catcher : public being
{
public:
    float evaluate(float, float);
};
class dam : public being
{
public:
    float time_surviving;
    bool die;
    time_t end;

public:
    void check_if_die(float, float);
    float evaluate(time_t);
};
void generate(std::vector<the_catcher> *, std::vector<dam> *);