#version 450 core

in vec2 attrP;
in vec2 attrA;
in vec2 attrB;
in vec2 attrC;

uniform vec2 offset;
uniform vec2 scale;
uniform float parmAspect;
uniform float em;
uniform vec2 internalOffset;

out vec2 P;
out vec2 A;
out vec2 B;
out vec2 C;

void main()
{
    P = attrP * scale.x / em;
    A = attrA * scale.x / em;
    B = attrB * scale.x / em;
    C = attrC * scale.x / em;

    P.x /= parmAspect;
    A.x /= parmAspect;
    B.x /= parmAspect;
    C.x /= parmAspect;

    P += internalOffset + offset;
    A += internalOffset + offset;
    B += internalOffset + offset;
    C += internalOffset + offset;

    gl_Position = vec4(P, 0.0f, 1.0f);
}