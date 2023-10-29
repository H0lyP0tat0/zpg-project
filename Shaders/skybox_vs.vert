#version 330
layout(location=0) in vec3 vp;

out vec3 texCoord;

uniform mat4 view;
uniform mat4 projection;

void main () {
    texCoord = vp;
    vec4 pos = projection * view * vec4(vp, 1.0);
    gl_Position = pos.xyww;
}