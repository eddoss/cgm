#version 450 core

in vec2 attrPosition;

uniform float parmAspect;
uniform vec2 offset;
uniform vec2 scale;

void main()
{
    vec2 pos = attrPosition * scale.x * scale.y + offset;
    gl_Position = vec4(pos, 0.0f, 1.0f);
    gl_Position.x /= parmAspect;
}