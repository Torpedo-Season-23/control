#ifndef OLD_ALG_ADAPT_H
#define OLD_ALG_ADAPT_H
#include "Thrusters.h"
#include "OldAlgorithm.h"
class OldAlgorithmAdaptor : public Thrusters
{
private:
    OldAlgorithm oldAlgorithm;
public:
    /**
     * @todo return the updated frame
     */
    int *get_thruster_frame();
    /**
     * @brief Set the h forces object
     * @todo 
     * Deduce the direction to which the ROV will move.
     * Update the thrusters frame by calling oldAlgorithm field.
     * @param array Array containing [Fx,Fy,Mz]
     */
    void set_h_forces(int *array);
    /**
     * @brief Set the v forces object
     * @todo same Idea as above
     */
    void set_v_forces(int *array);
};
#endif