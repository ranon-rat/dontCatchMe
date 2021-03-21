#include "beings.h"

//  =================================== father class  ===================================
being::being()
{
    //this add stuff to the neural network
    neural_network.generate_neural_network(2, sizes, 2);
    // this only change the weight of the nodes from the neural network

    neural_network.randomize_weights();
}
void being::move(std::vector<float> enemy_position, sf::RenderWindow *window)
{
    // input nodes from position of the enemy
    neural_network.input_nodes(enemy_position);
    neural_network.summation();
    // this is for get the outputs for move
    float up_or_down = neural_network.get_last()->nodes.at(0).input_node,
          left_or_right = neural_network.get_last()->nodes.at(1).input_node;
    // this is for move the being depending of the output
    ((fmod(up_or_down, 0.5)) // reduce the output
         ? pos_y++
         : pos_y--);
    ((fmod(left_or_right, 0.5))
         ? pos_x++
         : pos_x--);

    neural_network.clear_all_nodes();
    // SFML rendering stuff
    being_visualize.setPosition(sf::Vector2f(pos_x, pos_y));
    being_visualize.setFillColor(sf::Color::Blue);
    window->draw(being_visualize);
    window->display();
}
//  ===================================catcher stuff ===================================
float the_catcher::evaluate(float dam_pos_x, float dam_pos_y)
{
    float difference_between_members = 0;
    // if the difference is more little the being is much better
    ((dam_pos_x > pos_x)
         ? (difference_between_members += dam_pos_x - pos_x)
         : (difference_between_members += pos_x - dam_pos_x));
    ((dam_pos_y > pos_y)
         ? (difference_between_members += dam_pos_y - pos_y)
         : (difference_between_members += pos_y - dam_pos_y));
    return difference_between_members;
}
// ===================================dam stuff============================================
void dam::check_if_die(float catcher_pos_x, float catcher_pos_y)
{
    die = catcher_pos_x - 10 <= pos_x &&
          catcher_pos_x + 10 >= pos_x &&
          catcher_pos_y - 10 <= pos_y &&
          catcher_pos_y + 10 >= pos_y;
    /**
         * _________
         * |    |   |
         * |----*---|
         * |    |   |
         * ----------
         * */
    time(&end);
}
float dam::evaluate(time_t start)
{
    return float(end - start); // if the output is much bigger  the being is going to be much better
}
void generate(std::vector<the_catcher> *catchers, std::vector<dam> *dams)
{
    while (catchers->size() < 10 || dams->size() < 10)
    {

        catchers->push_back(the_catcher());
        dams->push_back(dam());
    }
}