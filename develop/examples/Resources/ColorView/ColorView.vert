#version 330 core

/* ####################################################################################### */
/* Inputs */
/* ####################################################################################### */

in vec3 vertexPosition;
in vec4 vertexColor;

/* ####################################################################################### */
/* Uniforms */
/* ####################################################################################### */

uniform mat4 xform;
uniform mat4 cameraSpace;
uniform mat4 cameraProjection;

/* ####################################################################################### */
/* Outputs */
/* ####################################################################################### */

out vec4 color;
out vec4 posLocal;
out vec4 posWorld;
out vec4 posCamera;
out vec4 posProject;

/* ####################################################################################### */
/* Main */
/* ####################################################################################### */

void main()
{
    color = vertexColor;

    posLocal = vec4(vertexPosition, 1.0);
    posWorld = xform * posLocal;
    posCamera = cameraSpace * posWorld;
    posProject = cameraProjection * posCamera;
    
    gl_Position = posProject;
}