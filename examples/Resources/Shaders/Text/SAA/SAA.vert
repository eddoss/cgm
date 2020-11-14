#version 450 core

in vec2 attrPosition;
out vec2 uv;

void main()
{
    // remap from [-1,1] to [0,1]
    uv.x = 0.5f * (attrPosition.x + 1.0f);
    uv.y = 0.5f * (attrPosition.y + 1.0f);

    gl_Position = vec4(attrPosition, 0.0f, 1.0f);
}