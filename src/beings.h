#include "./neuralDecisionsCpp/src/neural.h"
#include "SFML/Graphics.hpp"
#include "vector"

class being
{
private:
    std::vector<int> sizes = {8, 8, 8, 8};

public:
    layer neural_network;
    std::vector<float> action = {0, 0};
    float pos_x = 0, pos_y = 0;
    being()
    {
        neural_network.generate_neural_network(2, sizes, 2);
        neural_network.randomize_weights();
    }
    void move(std::vector<float> enemy_position)
    {
        neural_network.input_nodes(enemy_position);
        neural_network.summation();
        node up_or_down = neural_network.get_last()->nodes.at(0), left_or_right = neural_network.get_last()->nodes.at(1);
        ((up_or_down.input_node % 1 - 0.5 > 0 && up_or_down.input_node % 1 - 0.5) ? pos_y++ : pos_y--);
        ((left_or_right.input_node % 1 - 0.5 > 0 && left_or_right.input_node % 1 - 0.5 > 0) ? pos_x++ : pos_x--);
    }
};