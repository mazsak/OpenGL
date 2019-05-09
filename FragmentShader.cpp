#version 330 core

in vec2 UV;
in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 LightDirection_cameraspace;

out vec3 color;

uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 LightPosition_worldspace;
uniform vec3
LightColor;
uniform vec3
AmbientColor;
uniform vec3
MaterialSpecularColor;
uniform int choose;

void main(){

	float LightPower = 50.0f;


	vec3 MaterialDiffuseColor = texture( myTextureSampler, UV ).rgb;
    vec3 MaterialAmbientColor = AmbientColor * MaterialDiffuseColor;

	float distance = length( LightPosition_worldspace - Position_worldspace );

	vec3 n = normalize( Normal_cameraspace );

	vec3 l = normalize( LightDirection_cameraspace );

	float cosTheta = clamp( dot( n,l ), 0,1 );

	vec3 E = normalize(EyeDirection_cameraspace);

	vec3 R = reflect(-l,n);

	float cosAlpha = clamp( dot( E,R ), 0,1 );

    switch(choose){
        case 1:
            //Ambient
            color =
                    MaterialAmbientColor;
            break;
        case 2:
            //Lamberta - diffuse
            color = MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance*distance);
            break;
        case 3:
            //spectacular
            color = MaterialSpecularColor * LightColor * LightPower * pow(cosAlpha,5) / (distance*distance);
            break;
        default:
            //Fong
            color = MaterialAmbientColor +
                    MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance*distance) +
                    MaterialSpecularColor * LightColor * LightPower * pow(cosAlpha,5) / (distance*distance);

            break;
    }
}