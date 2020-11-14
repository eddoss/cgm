#version 450 core

in vec2 attrP;
in vec2 attrA;
in vec2 attrB;
in vec2 attrC;

uniform float parmAspect;
uniform float em;
//uniform float screenWidth;
//uniform float screenHeight;
uniform vec2 offset;
uniform vec2 scale;

out vec2 P;
out vec2 A;
out vec2 B;
out vec2 C;

//float fit(float value, float omin, float omax, float nmin, float nmax)
//{
//    return (value - omin) / (omax - omin) * (nmax - nmin) + nmin;
//}
//
//vec2 get_pos(vec2 coord)
//{
//    vec2 p = coord;
//    p.x = fit(p.x, 0.0f, screenWidth, -1.0f, 1.0f);
//    p.y = fit(p.y, 0.0f, screenHeight, -1.0f, 1.0f);
//    p = p * scale.x * scale.y + offset;
//
//    return p;
//}

void main()
{
//    P = get_pos(attrP);
//    A = get_pos(attrA);
//    B = get_pos(attrB);
//    C = get_pos(attrC);

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