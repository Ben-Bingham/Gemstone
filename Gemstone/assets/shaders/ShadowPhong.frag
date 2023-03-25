#version 330 core

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

#define MAX_POINT_LIGHTS 16
#define MAX_DIRECTIONAL_LIGHTS 16

struct PointLight {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
    float linear;
    float quadratic;
};

struct DirectionalLight {
    vec3 direction;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

	mat4 lightSpaceMatrix;
	sampler2D shadowMap;
};

uniform Material material;

uniform PointLight[MAX_POINT_LIGHTS] pointLights;
uniform int numberOfPointLights;

uniform DirectionalLight[MAX_DIRECTIONAL_LIGHTS] directionalLights;
uniform int numberOfdirectionalLights;

out vec4 FragColor;

in vec3 normal;
in vec3 fragmentPosition;
in vec2 textureCordinates;

//in vec4 fragmentPositionInLightSpace;

//uniform sampler2D shadowMap;
//uniform sampler2D shadowMap; //TODO make an array
//uniform samplerCube pointShadowMap; //TODO make an array

//uniform float farPlane;

uniform vec3 cameraPosition;
//uniform Material material;

//uniform int numberOfPointLights;
//uniform PointLight pointLights[MAX_POINT_LIGHTS];

//uniform int numberOfDirectionalLights;
//uniform DirectionalLight directionalLights[MAX_DIRECTIONAL_LIGHTS];
/*
float directionalShadowCalculation(vec4 fragPosInLight, vec3 lightDir) {
	vec3 projCords = fragPosInLight.xyz / fragPosInLight.w;

	projCords = projCords * 0.5 + 0.5;
	float currentDepth = projCords.z;
	float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);

	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
	for (int x = -1; x <= 1; ++x) {
		for (int y = -1; y <=1; ++y) {
			float pcfDepth = texture(shadowMap, projCords.xy + vec2(x, y) * texelSize).r;
			shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
		}
	}

	shadow /= 9.0;

	if (projCords.z > 1.0) {
		shadow = 0.0;
	}

	return shadow;
}
*/
/*
vec3 sampleOffsetDirections[20] = vec3[]
(
   vec3( 1,  1,  1), vec3( 1, -1,  1), vec3(-1, -1,  1), vec3(-1,  1,  1), 
   vec3( 1,  1, -1), vec3( 1, -1, -1), vec3(-1, -1, -1), vec3(-1,  1, -1),
   vec3( 1,  1,  0), vec3( 1, -1,  0), vec3(-1, -1,  0), vec3(-1,  1,  0),
   vec3( 1,  0,  1), vec3(-1,  0,  1), vec3( 1,  0, -1), vec3(-1,  0, -1),
   vec3( 0,  1,  1), vec3( 0, -1,  1), vec3( 0, -1, -1), vec3( 0,  1, -1)
);  
*/
/*
float pointShadowCalculation(vec3 fragPos, PointLight light) {
	vec3 fragToLight = fragPos - light.position;
	float currentDepth = length(fragToLight);

	float shadow = 0.0;
	float bias = 0.05;
	float samples = 20.0;
	float viewDistance = length(cameraPosition - fragPos);
	float diskRadius = (1.0 + (viewDistance / farPlane)) / 25.0;
	float offset = 0.1;

	for (int i = 0; i < samples; ++i) {
		float closestDepth = texture(pointShadowMap, fragToLight + sampleOffsetDirections[i] * diskRadius).r;
		closestDepth *= farPlane;
		if (currentDepth - bias > closestDepth) {
			shadow += 1.0;
		}
	}
	shadow /= float(samples);

	return shadow;
}
*/
vec3 calcPointLight(PointLight, vec3);
vec3 calcDirectionalLight(DirectionalLight, vec3, float);
float directionalShadowCalculation(DirectionalLight, vec3);

void main() {
	vec3 viewDirection = normalize(cameraPosition - fragmentPosition);

	vec3 result = vec3(0.0, 0.0, 0.0);

	for (int i = 0; i < numberOfPointLights; i++) {
		result += calcPointLight(pointLights[i], viewDirection);
	}

	float shadow;
	for (int i = 0; i < numberOfdirectionalLights; i++) {
		vec3 lightDirection = normalize(-directionalLights[i].direction);
		float tempShadow = directionalShadowCalculation(directionalLights[i], lightDirection);
		if (tempShadow == 0.0) {
			break;
		}
		else {
			shadow += tempShadow;
		}
	}

	for (int i = 0; i < numberOfdirectionalLights; i++) {
		result += calcDirectionalLight(directionalLights[i], viewDirection, shadow);
	}

	//FragColor = vec4(result, 1.0);
	FragColor = vec4(0.0, 1.0, 0.0, 1.0);

}

vec3 calcPointLight(PointLight pointLight, vec3 viewDirection) {
	// Ambient
	vec3 ambient = pointLight.ambient * texture(material.diffuse, textureCordinates).rgb;
	
	// Diffuse
	vec3 lightDirection = normalize(pointLight.position - fragmentPosition);
	float angleOfNormAndLightDir = max(dot(normal, lightDirection), 0.0);
	vec3 diffuse = pointLight.diffuse * angleOfNormAndLightDir * texture(material.diffuse, textureCordinates).rgb;

	// Specular
	vec3 halfwayDirection = normalize(lightDirection + viewDirection);
	float specularAmount = pow(max(dot(normal, halfwayDirection), 0.0), material.shininess);
	vec3 specular = pointLight.specular * (specularAmount * texture(material.specular, textureCordinates).rgb);

	// Attenuation
	float distanceBetweenLightAndFrag = length(pointLight.position - fragmentPosition);
    float attenuation = 1.0 / (pointLight.constant + pointLight.linear * distanceBetweenLightAndFrag + pointLight.quadratic * (distanceBetweenLightAndFrag * distanceBetweenLightAndFrag));    

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	// Total
	return ambient + diffuse + specular;
}

/*
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 cameraPosition) {
	vec3 ambient = light.ambient * texture(material.diffuse, textureCordinates).rgb;

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(light.position - fragmentPosition);
	float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, textureCordinates).rgb;  

	vec3 viewDir = normalize(cameraPosition - fragmentPosition);
	vec3 halfwayDir = normalize(lightDir + viewDir);
	float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
	vec3 specular = light.specular * (spec * texture(material.specular, textureCordinates).rgb);

	float Distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * Distance + light.quadratic * (Distance * Distance));    

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	//float shadow = pointShadowCalculation(fragmentPosition, light);

	//vec3 lighting = (light.ambient + (1.0 - shadow) * ((diff * light.diffuse) + (spec * light.specular)))* diffuse;
	vec3 lighting = ambient * diffuse * specular;
	return lighting;
}
*/
vec3 calcDirectionalLight(DirectionalLight directionalLight, vec3 viewDirection, float shadow) {
	// Ambient
	vec3 ambient = directionalLight.ambient * texture(material.diffuse, textureCordinates).rgb;

	// Diffuse
	vec3 lightDirection = normalize(-directionalLight.direction);
	float angleOfNormAndLightDir = max(dot(normal, lightDirection), 0.0);
	vec3 diffuse = directionalLight.diffuse * angleOfNormAndLightDir * texture(material.diffuse, textureCordinates).rgb;

	// Specular
	vec3 halfwayDirection = normalize(lightDirection + viewDirection);
	float specularAmount = pow(max(dot(normal, halfwayDirection), 0.0), material.shininess);
	vec3 specular = directionalLight.specular * (specularAmount * texture(material.specular, textureCordinates).rgb);

	//float shadow = directionalShadowCalculation(directionalLight, lightDirection);

	// Total
	return ((1.0 - shadow) * (diffuse + specular)) + ambient;
}


float directionalShadowCalculation(DirectionalLight dirLight, vec3 lightDirection) {
	vec4 fragmentPositionInLightSpace = dirLight.lightSpaceMatrix * vec4(fragmentPosition, 1.0);

    vec3 projCoords = fragmentPositionInLightSpace.xyz / fragmentPositionInLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;

    float closestDepth = texture(dirLight.shadowMap, projCoords.xy).r; 
    float currentDepth = projCoords.z;

	float bias = max(0.05 * (1.0 - dot(normal, lightDirection)), 0.005);

	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(dirLight.shadowMap, 0);
	for(int x = -1; x <= 1; ++x)
	{
		for(int y = -1; y <= 1; ++y)
		{
			float pcfDepth = texture(dirLight.shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
			shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;        
		}    
	}

	shadow /= 9.0;

	if(projCoords.z > 1.0)
        shadow = 0.0;

    return shadow;
}  
