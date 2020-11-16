#version 450 core

in vec2 uv;
out vec4 fragColor;

uniform sampler2DMS screenTexture;
uniform int screenWidth;
uniform int screenHeight;
uniform float gammaCorrection;
uniform bool enableSPAA;

const vec4 one = vec4(1.0f, 1.0f, 1.0f, 1.0f);

vec4 texture_ms(sampler2DMS sampler, vec2 texCoord)
{
    ivec2 coord = ivec2(texCoord * ivec2(screenWidth, screenHeight));

    vec4 color = vec4(0.0);
    for (int i = 0; i < 16; i++)
    {
        color += texelFetch(screenTexture, coord, i);
    }
    color /= 16.0f;

    return color;
}

void main()
{
    if (enableSPAA)
    {
        const vec2 step = vec2(1.0f / float(screenWidth), 0.0f);

        vec4 c = one - texture_ms(screenTexture, uv);           // current pixel
        vec4 l = one - texture_ms(screenTexture, uv - step);    // left pixel
        vec4 r = one - texture_ms(screenTexture, uv + step);    // right pixel

        const float k1 = (1.1f * 1.0f) / 9.0f;
        const float k2 = (1.1f * 2.0f) / 9.0f;
        const float k3 = (1.1f * 3.0f) / 9.0f;

        fragColor.r = 1.0f - (k1*l.g + k2*l.b + k3*c.r + k2*c.g + k1*c.b);
        fragColor.g = 1.0f - (k1*l.b + k2*c.r + k3*c.g + k2*c.b + k1*r.r);
        fragColor.b = 1.0f - (k1*c.r + k2*c.g + k3*c.b + k2*r.r + k1*r.g);
        fragColor.a = 1.0f;
    }
    else
    {
        fragColor = texture_ms(screenTexture, uv);
    }

    fragColor.rgb = pow(fragColor.rgb, vec3(1.0f/gammaCorrection));
}
