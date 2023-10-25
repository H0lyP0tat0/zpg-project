﻿// Jan Fojtík
// FOJ0127

//Include the standard C++ headers
#include <stdlib.h>
#include <stdio.h>

// Include chrono for time measurement
#include <chrono>

#include "Include/Application.h"
#include "Include/Colors.h"
#include "Models/pyramid.h"
#include "Scenes/BallScene.h"
#include "Scenes/ForestScene.h"


int main(void)
{	
	// get start time
	auto start = std::chrono::high_resolution_clock::now();

    Application& app = Application::get();
    app.initialization(1280, 720);

    // Scene 1 automatically created
    app.addScene(new BallScene(2));  // Scene 2 - added from preset
    app.createScene();  // Scene 3
    app.createScene();  // Scene 4
    app.addScene(new ForestScene(5));
    // Scene # = press number to switch to desired scene

    auto floorTransform = new Composite();
    floorTransform->addChild(new Translation(glm::vec3(0.f, -1.f, 1.f)));
    floorTransform->addChild(new Scale(glm::vec3(3.f, 3.f, 3.f)));

    auto sc1Transform = new Composite();
    sc1Transform->addChild(new Rotation(180.f, glm::vec3(0.f, 0.f, 1.f)));
    sc1Transform->addChild(new Scale(glm::vec3(0.8f)));
    sc1Transform->addChild(new Translation(glm::vec3(2.f, 0.0f, 0.f)));
//    sc1Transform->addChild(new Rotation(0.f, glm::vec3(0.f, 1.f, 0.f), 50.f));

    auto sc1Transform2 = new Composite();
    sc1Transform2->addChild(new Rotation(180.f, glm::vec3(0.f, 0.f, 1.f)));
    sc1Transform2->addChild(new Scale(glm::vec3(1.8f)));
    sc1Transform2->addChild(new Translation(glm::vec3(1.f, -0.5f, 0.f)));
    sc1Transform2->addChild(sc1Transform);

    auto centerTransform = new Composite();
    centerTransform->addChild(new Translation(glm::vec3(0.f, 0.f, 0.f)));

    // Scene 1
    app.getSceneById(1)->addModel(RenderableModelBuilder(ModelKind::PLAIN)
        .setShader(ShaderBuilder()
            .setCamera(app.getSceneById(1)->getCamera())
            ->setColor(NORMALS)
            ->build())
        ->setTransformation(floorTransform)
        ->build());

    app.getSceneById(1)->addModel(ModelLoader::loadModel("suzi_hq.obj")
        .setShader(ShaderBuilder()
            .setCamera(app.getSceneById(1)->getCamera())
            ->setColor(NORMALS)
            ->build())
        ->setTransformation(sc1Transform)
        ->build());

    app.getSceneById(1)->addModel(ModelLoader::loadModel("rat.obj")
        .setShader(ShaderBuilder()
            .setCamera(app.getSceneById(1)->getCamera())
            ->setColor(NORMALS)
            ->build())
        ->setTransformation(sc1Transform2)
        ->build());

    // Scene 3

    // Lights
    auto backLight = std::vector<Light*>();
    backLight.push_back(new Light(glm::vec3(0.f, 0.f, -3.f), 1, glm::vec3(0.4f)));
    app.getSceneById(3)->setLights(backLight);

    // Objects
    app.getSceneById(3)->addModel(RenderableModelBuilder(ModelKind::SPHERE)
        .setShader(ShaderBuilder()
            .setCamera(app.getSceneById(3)->getCamera())
            ->setVertexShader("vertexShader_light.vert")
            ->setFragmentShader("phong_fs.frag")
            ->build())
        ->setTransformation(new Translation(glm::vec3(0.f, 0.f, 0.f)))
        ->build());

    // Scene 4

    // Lights
    auto centerLight = std::vector<Light*>();
    centerLight.push_back(new Light(glm::vec3(0.f, 0.f, 0.f), 1, glm::vec3(0.4f)));
    app.getSceneById(4)->setLights(centerLight);

    // Objects
    app.getSceneById(4)->addModel(RenderableModelBuilder(ModelKind::SUZI)
        .setShader(ShaderBuilder()
            .setCamera(app.getSceneById(4)->getCamera())
            ->setVertexShader("vertexShader_light.vert")
            ->setFragmentShader("constant_fs.frag")
            ->build())
        ->setTransformation(new Translation(glm::vec3(-3.f, 0.f, 0.f)))
        ->build());

    app.getSceneById(4)->addModel(RenderableModelBuilder(ModelKind::SUZI_SMOOTH)
        .setShader(ShaderBuilder()
            .setCamera(app.getSceneById(4)->getCamera())
            ->setVertexShader("vertexShader_light.vert")
            ->setFragmentShader("lambert_fs.frag")
            ->build())
        ->setTransformation(new Translation(glm::vec3(3.f, 0.f, 0.f)))
        ->build());

    app.getSceneById(4)->addModel(RenderableModelBuilder(ModelKind::SPHERE)
        .setShader(ShaderBuilder()
            .setCamera(app.getSceneById(4)->getCamera())
            ->setVertexShader("vertexShader_light.vert")
            ->setFragmentShader("phong_fs.frag")
            ->build())
        ->setTransformation(new Translation(glm::vec3(0.f, 3.f, 0.f)))
        ->build());

    app.getSceneById(4)->addModel(RenderableModelBuilder(ModelKind::SPHERE)
        .setShader(ShaderBuilder()
            .setCamera(app.getSceneById(4)->getCamera())
            ->setVertexShader("vertexShader_light.vert")
            ->setFragmentShader("blinn_fs.frag")
            ->build())
        ->setTransformation(new Translation(glm::vec3(0.f, -3.f, 0.f)))
        ->build());


    app.run();

    // get end time
	auto finish = std::chrono::high_resolution_clock::now();

	fprintf(stdout, "[DEBUG] Application stats\n");
	fprintf(stdout, "   Time elapsed: %f seconds\n", std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() / 1000000000.0);

	return 0;
}