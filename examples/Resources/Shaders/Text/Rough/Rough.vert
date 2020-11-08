#version 450 core

in vec2 attrPosition;

uniform float parmAspect;

void main()
{
    gl_Position = vec4(attrPosition, 0.0f, 1.0f);
    gl_Position.x /= parmAspect;
}