//
// Created by Honza Fojtík on 10.10.2023.
//

#include "../Include/Camera.h"
#include "../Include/Shader.h"
#include "../Include/Application.h"

Camera::Camera(Shader* shader) {
    this->shader = shader;
    attach(shader);

    this->position = glm::vec3(0.f, 0.f, 10.f);
    this->target = glm::vec3(0.f, 0.f, 0.f);
    this->cameraUp = glm::vec3(0.f, 1.f, 0.f);
    this->cameraFront = glm::vec3(0.f, 0.f, -1.f);

    this->lastX = Application::get().getWidth() / 2.f;
    this->lastY = Application::get().getHeight() / 2.f;
}

Camera::~Camera() {
    delete shader;
}

glm::mat4 Camera::getCamera() {
    return glm::lookAt(this->position, this->position + this->cameraFront, this->cameraUp);
}

glm::mat4 Camera::getPerspective() {
    return glm::perspective(glm::radians(this->fov), (float)Application::get().getWidth() / (float)Application::get().getHeight(), 0.1f, 100.f);
}

void Camera::moveForward(float speed) {
    this->position += this->cameraFront * speed;
    notify();
}

void Camera::moveBackward(float speed) {
    this->position -= this->cameraFront * speed;
    notify();
}

void Camera::moveLeft(float speed) {
    this->position -= glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
    notify();
}

void Camera::moveRight(float speed) {
    this->position += glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
    notify();
}