typedef unsigned char uint8_t;
 inline float Read (uint8_t* data)
{
    float* valuePtr = (float*) (data);
    float value = *valuePtr;
    return value;
}
static float test = 180.0f;
int main (void)
{
    uint8_t* data = (uint8_t*)malloc(8 * sizeof(char));
    memcpy (data, &test, sizeof (float));
    float value = Read (data);

    memcpy (data + 1, &test, sizeof (float));
    value = Read (data + 1); // hard fault here!
    return value;
}