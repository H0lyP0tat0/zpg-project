/**
 * @file plain.h
 *
 * @brief Plain model 
 *
 * @details  Command for rendering
 *           glDrawArrays(GL_TRIANGLES, 0, 6);
 *
 * @author Martin Nemec
 *
 * @year 2023
 **/
#pragma once

const float plain[36] = {
    100.0f, 0.0f,  100.0f, 0.0f, 1.0f, 0.0f,
    100.0f, 0.0f, -100.0f, 0.0f, 1.0f, 0.0f,
    -100.0f, 0.0f, -100.0f, 0.0f, 1.0f, 0.0f,

    -100.0f, 0.0f,  100.0f, 0.0f, 1.0f, 0.0f,
    100.0f, 0.0f,  100.0f, 0.0f, 1.0f, 0.0f,
    -100.0f, 0.0f, -100.0f, 0.0f, 1.0f, 0.0f
};

const float plain_textured[] = {
    //vrchol, normála, uv souřadnice
    1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
    1.0f, 0.0f,-1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    -1.0f, 0.0f,-1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,

    -1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
//    1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
//    -1.0f, 0.0f,-1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f
};

const int plain_textured_indices[] = {
    0, 1, 2,
    0, 2, 3
};