/**
 * @file Composite.h
 *
 * @brief Composite class
 *
 * @details Composite class for transformations
 *
 * @author Jan Fojtik
 *
 * @year 2023
 **/

#ifndef ZPGPROJECT_COMPOSITE_H
#define ZPGPROJECT_COMPOSITE_H

#include "Transformation.h"

class Composite : public Transformation {
private:
    std::vector<Transformation*> children;

public:
    glm::mat4 getMatrix() override;
    void tick(float deltaTime) override;
    void addChild(Transformation* child);

};


#endif //ZPGPROJECT_COMPOSITE_H
