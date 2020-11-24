#version 450 core

uniform vec3 color;

float cross2d(vec2 a, vec2 b)
{
    return a.x * b.y - a.y * b.x;
}

in vec2 P;
in vec2 A;
in vec2 B;
in vec2 C;

out vec4 fragColor;

void main()
{
    const float a = abs(cross2d(B - A, C - A));
    const float u = abs(cross2d(A - P, C - P)) / a;
    const float v = abs(cross2d(B - P, C - P)) / a;

    const float h = u * 0.5f; // just half of 'u' value

    if ((h + v) * (h + v) < v)
    {
        fragColor = vec4(color, 1.0f);
    }
    else
    {
        discard;
    }
}
