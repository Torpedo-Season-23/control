#ifndef OLD_ALG_H
#define OLD_ALG_H
#include <Arduino.h>
typedef enum Directions
{
    FORWARD,
    BACKWARD,
    LATERAL_LEFT,
    LATERAL_RIGHT,
    MOMENT_RIGHT,
    MOMENT_LEFT,
    UP,
    DOWN,
    STATIONARY
} Directions;
class OldAlgorithm
{
public:
    /**
     * @brief Set the speed  which will be applied to the thrusters
     */
    void setSpeed(uint16_t speed){};
    /**
     * @brief Set the horizontal movement object
     * Directions are forward, backward, left, right, moment_left, moment_right
     * @todo
     * You should implement this function and make it update the thruster frame with respect to direction specified.
     * If direction is stationary, then set all values to 1500.
     */
    void set_horizontal_movement(Directions dir, int *thrusterFrame){};
    /**
     * @brief Set the vertical movement object
     * @todo Same as the above function
     */
    void set_vertical_movement(Directions dir, int *thrustersFrame){};
}
#endif