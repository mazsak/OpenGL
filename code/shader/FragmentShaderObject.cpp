#version 330 core

in vec2 UV;
in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 LightDirection_cameraspace;

out vec3 color;

uniform sampler2D myTextureSampler;
uniform vec3 LightPosition_worldspace;
uniform vec3 Diffuse;

void main() {

    vec3 LightColor = vec3(1, 1, 1);
    float LightPower = 50.0f;

    vec3 MaterialDiffuseColor = Diffuse * texture(myTextureSampler, UV).rgb;

    float distance = length(LightPosition_worldspace - Position_worldspace);

    vec3 n = normalize( Normal_cameraspace );

    vec3 l = normalize( LightDirection_cameraspace );

    float cosTheta = clamp( dot( n,l ), 0,1 );

    color = MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance * distance);
}