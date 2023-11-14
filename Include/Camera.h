/**
 * @file Camera.h
 *
 * @brief Camera class
 *
 * @details Camera class for 3D scene
 *
 * @author Jan Fojtik
 *
 * @year 2023
 **/

#ifndef ZPGPROJECT_CAMERA_H
#define ZPGPROJECT_CAMERA_H

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include "Observer.h"
#include "Subject.h"

class Shader;

class Camera : public Subject, public Observer {
private:
    Shader* shader;

    glm::vec3 position;
    glm::vec3 cameraUp;
    glm::vec3 cameraFront;
    float fov = 45.f;

    float yaw = -90.f;
    float pitch = 0.f;

    //cursor initial coords
    bool firstMouse = true;
    float lastX;
    float lastY;
public:
    Camera();
    explicit Camera(Shader* s);
    ~Camera();

    void setShader(Shader* s);
    void update(Event event) override;

    glm::vec3 getPosition() const { return this->position; }
    glm::vec3 getDirection() const { return this->cameraFront; }

    glm::mat4 getCamera();
    glm::mat4 getPerspective();

    void moveForward(float speed);
    void moveBackward(float speed);
    void moveLeft(float speed);
    void moveRight(float speed);
    void move(bool forward, bool backward, bool left, bool right);

    void scrollAction(float yoffset);
    void mouseAction(float x, float y);

    void setCameraFront(glm::vec3 front) { this->cameraFront = front; }

    float getFov() const { return this->fov; }
    float getYaw() const { return this->yaw; }
    float getPitch() const { return this->pitch; }
    void setFov(float f) { this->fov = f; }
    void setYaw(float y) { this->yaw = y; }
    void setPitch(float p) { this->pitch = p; }

    bool getFirstMouse() const { return this->firstMouse; }
    float getLastX() const { return this->lastX; }
    float getLastY() const { return this->lastY; }
    void setFirstMouse(bool fm) { this->firstMouse = fm; }
    void setLastX(float x) { this->lastX = x; }
    void setLastY(float y) { this->lastY = y; }

    void enableDebugInterface();
};


#endif //ZPGPROJECT_CAMERA_H
