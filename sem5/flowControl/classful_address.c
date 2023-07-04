#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int first_octet;
    int second_octet;
    int third_octet;
    int fourth_octet;
} IPAddress;
void getClassfulAddressInfo(IPAddress address)
{
    if (address.first_octet >= 1 && address.first_octet <= 126)
    {
        printf("Class A Address: %d.%d.%d.%d\n", address.first_octet, address.second_octet, address.third_octet, address.fourth_octet);
    }
    else if (address.first_octet >= 128 && address.first_octet <= 191)
    {
        printf("Class B Address: %d.%d.%d.%d\n", address.first_octet, address.second_octet, address.third_octet, address.fourth_octet);
    }
    else if (address.first_octet >= 192 && address.first_octet <= 223)
    {
        printf("Class C Address: %d.%d.%d.%d\n", address.first_octet, address.second_octet, address.third_octet, address.fourth_octet);
    }
    else if (address.first_octet >= 224 && address.first_octet <= 239)
    {
        printf("Class D Address: %d.%d.%d.%d\n", address.first_octet, address.second_octet, address.third_octet, address.fourth_octet);
    }
    else if (address.first_octet >= 240 && address.first_octet <= 255)
    {
        printf("Class E Address: %d.%d.%d.%d\n", address.first_octet, address.second_octet, address.third_octet, address.fourth_octet);
    }
    else
    {
        printf("Invalid Address\n");
    }
}
int main()
{
    IPAddress address;
    printf("Enter IP Address (format: xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &address.first_octet, &address.second_octet, &address.third_octet, &address.fourth_octet);
    getClassfulAddressInfo(address);
    return 0;
}

