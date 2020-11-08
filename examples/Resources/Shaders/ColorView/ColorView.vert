#version 450 core

/* ####################################################################################### */
/* Inputs */
/* ####################################################################################### */

in vec3 attrPosition;
in vec4 attrColor;

/* ####################################################################################### */
/* Uniforms */
/* ####################################################################################### */

uniform mat4 matXform;
uniform mat4 matWorldToCamera;
uniform mat4 matCameraToProject;

/* ####################################################################################### */
/* Outputs */
/* ####################################################################################### */

out Position
{
    vec4 base;
    vec4 xformed;
    vec4 camera;
    vec4 project;
} pos;

out vec4 color;

/* ####################################################################################### */
/* Main */
/* ####################################################################################### */

void main()
{
    color = attrColor;

    pos.base = vec4(attrPosition, 1.0);
    pos.xformed = matXform * pos.base;
    pos.camera = matWorldToCamera * pos.xformed;
    pos.project = matCameraToProject * pos.camera;

    gl_Position = pos.project;
}