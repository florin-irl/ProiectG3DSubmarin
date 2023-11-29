#version 330 core
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform float Ka;
uniform float Kd;
uniform float Ks;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(vec3(1.0f, 1.0f, 1.0f));
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = Kd * diff * lightColor;
    vec3 ambient = Ka * lightColor;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);
    vec3 specular = Ks * spec * lightColor;
    FragColor = vec4(objectColor * (ambient + diffuse + specular), 1.0);
} 