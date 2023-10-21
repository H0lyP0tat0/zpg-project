/**
 * @file Light.h
 *
 * @brief Class for light source
 *
 * @details This class is used for light source. It contains position, color and intensity of the light.
 *
 * @author Jan Fojtik
 *
 * @year 2023
 **/

#ifndef ZPGPROJECT_LIGHT_H
#define ZPGPROJECT_LIGHT_H

#include <glm/vec3.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "imgui/imgui.h"

class Light {
private:
    glm::vec3 position;
    glm::vec3 color;
    float intensity = 1.f;

public:
    Light(glm::vec3 position, float intensity, glm::vec3 color);
    glm::vec3 getPosition() const { return this->position; }
    glm::vec3 getColor() const { return this->color; }
    float getIntensity() const { return this->intensity; }

    void enableDebugInterface();
};

#endif //ZPGPROJECT_LIGHT_H
