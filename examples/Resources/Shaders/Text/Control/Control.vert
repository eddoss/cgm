#version 450 core

in vec2 attrP;
in vec2 attrA;
in vec2 attrB;
in vec2 attrC;

uniform float parmAspect;
uniform vec2 offset;
uniform vec2 scale;

out vec2 P;
out vec2 A;
out vec2 B;
out vec2 C;

void main()
{
    P = attrP * scale.x * scale.y + offset;
    A = attrA * scale.x * scale.y + offset;
    B = attrB * scale.x * scale.y + offset;
    C = attrC * scale.x * scale.y + offset;

    P.x /= parmAspect;
    A.x /= parmAspect;
    B.x /= parmAspect;
    C.x /= parmAspect;

    gl_Position = vec4(P, 0.0f, 1.0f);
}