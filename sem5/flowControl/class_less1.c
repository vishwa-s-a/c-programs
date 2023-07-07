#include <stdio.h>
#include <string.h>
void splitIPAddress(char ip[])
{
    char ipAddress[20];
    strcpy(ipAddress, ip);
    // Separate IP address and network bits
    char ipAddressPart[16];
    int networkBits = 0;
    int i = 0;
    int j = 0;
    while (ipAddress[i] != '/')
    {
        ipAddressPart[j] = ipAddress[i];
        i++;
        j++;
    }
    ipAddressPart[j] = '\0';
    i++;
    while (ipAddress[i] != '\0')
    {
        networkBits = networkBits * 10 + (ipAddress[i] - '0');
        i++;
    }
    // Separate IP address into octets
    int octet1, octet2, octet3, octet4;
    sscanf(ipAddressPart, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
    // Calculate network ID and host ID
    unsigned int networkID = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;
    unsigned int hostID = networkID & ((1 << (32 - networkBits)) - 1);
    networkID = networkID & (~((1 << (32 - networkBits)) - 1));
    // Determine IP address class
    char ipClass;
    printf("Network ID: %d.%d.%d.%d\n", (networkID >> 24) & 255, (networkID >> 16) & 255, (networkID >> 8) & 255, networkID & 255);
    printf("Host ID: %d.%d.%d.%d\n", (hostID >> 24) & 255, (hostID >> 16) & 255, (hostID >> 8) & 255, hostID & 255);
}
int main()
{
    printf("Name: Vishwa Shivanand Appaji\nReg No:21BCI0026\n");
    char ipAddress[20];
    printf("Enter IP address in x.y.z.t/n format: ");
    scanf("%s", ipAddress);
    splitIPAddress(ipAddress);
    return 0;
}
