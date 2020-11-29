#version 450 core

in vec2 attrPosition;
out vec2 uv;

void main()
{
//    const float offset_x = 2.0f / 1920.0f;
//    const float offset_y = 2.0f / 1080.0f;

    // remap from [-1,1] to [0,1]
    uv.x = 0.5f * (attrPosition.x + 1.0f);
    uv.y = 0.5f * (attrPosition.y + 1.0f);

    gl_Position = vec4(attrPosition, 0.0f, 1.0f);
}