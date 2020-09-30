#version 330 core

/* ####################################################################################### */
/* Support functions */
/* ####################################################################################### */

float map(float value, float min1, float max1, float min2, float max2)
{
   return (value - min1) / (max1 - min1) * (max2 - min2) + min2;
}

/* --------------------------------------------------------------------------------------- */

float mapTo01(float value, float min1, float max1)
{
    return (value - min1) / (max1 - min1);
}

/* ####################################################################################### */
/* [ INPUTS ] */
/* ####################################################################################### */

in vec3 vertexPosition;
in vec4 vertexColor;

/* ####################################################################################### */
/* [ UNIFORMS ] */
/* ####################################################################################### */

uniform mat4 xform;
uniform mat4 cameraSpace;
uniform mat4 cameraProjection;

/* ####################################################################################### */
/* [ OUTPUTS ] */
/* ####################################################################################### */

out vec4 color;
out vec4 posLocal;
out vec4 posWorld;
out vec4 posCamera;
out vec4 posProject;

void main()
{
    color = vertexColor;

    posLocal = vec4(vertexPosition, 1.0);
    posWorld = xform * posLocal;
    posCamera = cameraSpace * posWorld;
    posProject = cameraProjection * posCamera;
    
    gl_Position = posProject;
}