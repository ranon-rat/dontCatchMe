#include "./neuralDecisionsCpp/src/neural.h"
#include <SFML/Graphics.hpp>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <math.h>

class being
{
private:
    std::vector<int> sizes = {8, 8, 8, 8};

public:
    layer neural_network;
    std::vector<float> action = {0, 0};
    float pos_x = 0, pos_y = 0;
    sf::RectangleShape being_visualize(sf::Vector2f(20.0, 20.0));
    being()
    {
        neural_network.generate_neural_network(2, sizes, 2);
        neural_network.randomize_weights();
    }
    void move(std::vector<float> enemy_position)
    {
        neural_network.input_nodes(enemy_position);
        neural_network.summation();
        float up_or_down = neural_network.get_last()->nodes.at(0).input_node, left_or_right = neural_network.get_last()->nodes.at(1).input_node;

        ((fmod(up_or_down, 0.5))
             ? pos_y++
             : pos_y--);
        ((fmod(left_or_right, 0.5))
             ? pos_x++
             : pos_x--);
    }
};
class the_catcher : public being
{
public:
    float evaluate(float dam_pos_x, float dam_pos_y)
    {
        float difference_between_members = 0;
        ((dam_pos_x > pos_x) ? (difference_between_members += dam_pos_x - pos_x) : (difference_between_members += pos_x - dam_pos_x));
        ((dam_pos_y > pos_y) ? (difference_between_members += dam_pos_y - pos_y) : (difference_between_members += pos_y - dam_pos_y));
    }
};
class dam : public being
{
public:
    float time_surviving;
    bool die;
    time_t end;

    void check_if_die(float catcher_pos_x, float catcher_pos_y)
    {
        die = (catcher_pos_x - 10 <= pos_x &&
               catcher_pos_x + 10 >= pos_x &&
               catcher_pos_y - 10 <= pos_y &&
               catcher_pos_y + 10 >= pos_y);
        time(&end);
    }
    float evaluate(time_t start)
    {
        return float(end - start) * 1e6;
    }
};
void generate(std::vector<the_catcher> *catchers, std::vector<dam> *dams)
{
    while (catchers->size() < 10 || dams->size() < 10)
    {

        catchers->push_back(the_catcher);
        dams->push_back(dam);
    }
}