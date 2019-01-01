struct pixel
{
    float4 Position: SV_Position;
    float2 PixelP: PIXEL_p;
};

float4 main(pixel Pixel): SV_TARGET
{
    return float4(1.0f, 0.0f, 0.0f, 1.0f);
}