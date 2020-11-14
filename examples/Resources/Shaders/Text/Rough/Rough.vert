#version 450 core

in vec2 attrPosition;

uniform float parmAspect;
uniform float em;
//uniform int screenWidth;
//uniform int screenHeight;
uniform vec2 offset;
uniform vec2 scale;

//float fit(float value, float omin, float omax, float nmin, float nmax)
//{
//    return (value - omin) / (omax - omin) * (nmax - nmin) + nmin;
//}
//
//vec2 position(vec2 coord)
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
//    vec2 pos = position(attrPosition);
//    gl_Position = vec4(pos, 0.0f, 1.0f);

    vec2 pos = attrPosition * scale.x / em + offset;

    gl_Position = vec4(pos, 0.0f, 1.0f);
    gl_Position.x /= parmAspect;
}