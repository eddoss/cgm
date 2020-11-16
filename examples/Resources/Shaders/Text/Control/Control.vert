#version 450 core

in vec2 attrP;
in vec2 attrA;
in vec2 attrB;
in vec2 attrC;

uniform vec2 offset;
uniform vec2 scale;
uniform float parmAspect;
uniform float em;

out vec2 P;
out vec2 A;
out vec2 B;
out vec2 C;

void main()
{
    P = attrP * scale.x / em + offset;
    A = attrA * scale.x / em + offset;
    B = attrB * scale.x / em + offset;
    C = attrC * scale.x / em + offset;

    P.x /= parmAspect;
    A.x /= parmAspect;
    B.x /= parmAspect;
    C.x /= parmAspect;

    gl_Position = vec4(P, 0.0f, 1.0f);
}