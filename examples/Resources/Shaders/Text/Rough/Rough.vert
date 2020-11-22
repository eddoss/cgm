#version 450 core

in vec2 attrPosition;

uniform float parmAspect;
uniform float em;
uniform vec2 offset;
uniform vec2 scale;
uniform vec2 internalOffset;


void main()
{
    gl_Position = vec4(attrPosition * scale.x / em, 0.0f, 1.0f);
    gl_Position.x /= parmAspect;
    gl_Position.x += internalOffset.x + offset.x;
    gl_Position.y += internalOffset.y + offset.y;
}