#version 450 core

in vec2 uv;
out vec4 fragColor;

uniform sampler2D screenTexture;
uniform int screenWidth;
//uniform int screenHeight;
uniform float gammaCorrection;
uniform bool enableSPAA;

const vec3 one = vec3(1.0f, 1.0f, 1.0f);

vec2 extractSamples(float value)
{
    float scaled = 255.0f * value;

    vec2 result;
    result.x = mod(scaled, 16.0f);
    result.y = scaled - result.x * 16.0f;

    return result;
}

vec3 getTexel(sampler2D image, vec2 coord)
{
    vec4 color = texture(image, coord);

    vec2 sample01 = extractSamples(color.r);
    vec2 sample23 = extractSamples(color.g);
    vec2 sample45 = extractSamples(color.b);

    sample01.x = mod(sample01.x, 2.0f);
    sample01.y = mod(sample01.y, 2.0f);
    sample23.x = mod(sample23.x, 2.0f);
    sample23.y = mod(sample23.y, 2.0f);
    sample45.x = mod(sample45.x, 2.0f);
    sample45.y = mod(sample45.y, 2.0f);
    float value = 1.0f - (sample01.x + sample01.y + sample23.x + sample23.y + sample45.x + sample45.y) / 6.0f;

    return vec3(value, value, value);
}

void main()
{
    if (enableSPAA)
    {
        const vec2 step = vec2(1.0f / float(screenWidth), 0.0f);

        vec3 c = one - getTexel(screenTexture, uv);           // current pixel
        vec3 l = one - getTexel(screenTexture, uv - step);    // left pixel
        vec3 r = one - getTexel(screenTexture, uv + step);    // right pixel

        const float k1 = 1.0f / 9.0f;
        const float k2 = 2.0f / 9.0f;
        const float k3 = 3.0f / 9.0f;

        fragColor.r = 1.0f - (k1*l.g + k2*l.b + k3*c.r + k2*c.g + k1*c.b);
        fragColor.g = 1.0f - (k1*l.b + k2*c.r + k3*c.g + k2*c.b + k1*r.r);
        fragColor.b = 1.0f - (k1*c.r + k2*c.g + k3*c.b + k2*r.r + k1*r.g);
        fragColor.a = 1.0f;
    }
    else
    {
        fragColor = vec4(getTexel(screenTexture, uv), 1.0f);
    }

    fragColor.rgb = pow(fragColor.rgb, vec3(1.0f/gammaCorrection));
}
