cbuffer TransformationMatrix : register(b0)
{
    float4x4 worldViewProjectionMatrix; // Matrix to transform the vertices
};

struct VertexIn
{
    float3 position : POSITION;
    float4 color : COLOR;
};

struct VertexOut
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

VertexOut main(VertexIn input)
{
    VertexOut output;
    
    output.position = mul(float4(input.position, 1.0f), worldViewProjectionMatrix);
    
    output.color = input.color;

    return output;
}


struct PixelIn
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

float4 main(PixelIn input) : SV_TARGET
{
    return input.color;
}

cbuffer TransformationMatrix : register(b0)
{
    float4x4 worldViewProjectionMatrix;
    float4x4 worldMatrix;
};

struct VertexIn
{
    float3 position : POSITION;
    float3 normal : NORMAL;
};

struct VertexOut
{
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
    float3 fragPos : TEXCOORD0;
};

VertexOut main(VertexIn input)
{
    VertexOut output;

    output.position = mul(float4(input.position, 1.0f), worldViewProjectionMatrix);

    output.normal = normalize(mul(input.normal, (float3x3)worldMatrix));

    output.fragPos = mul(float4(input.position, 1.0f), worldMatrix).xyz;

    return output;
}

cbuffer LightProperties : register(b1)
{
    float3 lightPosition;
    float3 viewPosition;
    float3 lightColor;
    float3 ambientColor;
    float shininess;
};

struct PixelIn
{
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
    float3 fragPos : TEXCOORD0;
};

float4 main(PixelIn input) : SV_TARGET
{
    float3 norm = normalize(input.normal);
    
    float3 lightDir = normalize(lightPosition - input.fragPos);
    
    float3 viewDir = normalize(viewPosition - input.fragPos);
    
    float3 ambient = ambientColor;

    float diff = max(dot(norm, lightDir), 0.0);
    float3 diffuse = diff * lightColor;
    
    float3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    float3 specular = spec * lightColor;
    
    float3 color = ambient + diffuse + specular;
    
    return float4(color, 1.0f);
}
