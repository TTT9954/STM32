#include <stdio.h>
#include <stdint.h>

typedef struct Packet
{
	uint32_t crc:2;
	uint32_t status:1;
	uint32_t payload:12;
	uint32_t bat:3;
	uint32_t sensor:3;
	uint32_t longAddr:8;
	uint32_t shortAddr:2;
	uint32_t addrMode:1;
}Packets;

int main()
{
	uint32_t packetValue;
	printf("Enter the 32 bit packet value: ");
	scanf("%x", &packetValue);

	Packets packet1;
	uint32_t *ptr = (uint32_t *)&packet1;
	packet1.crc = (uint8_t) (packetValue & 0x03);
	packet1.status = (uint8_t) ((packetValue >> 2) & 0x01);
	packet1.payload = (uint16_t) ((packetValue >> 3) & 0xFFF);
	packet1.bat = (uint8_t) ((packetValue >> 15) & 0x07);
	packet1.sensor = (uint8_t) ((packetValue >> 18) & 0x07);
	packet1.longAddr = (uint8_t) ((packetValue >> 21) & 0xFF);
	packet1.shortAddr = (uint8_t) ((packetValue >> 29) & 0x03);
	packet1.addrMode = (uint8_t) ((packetValue >> 31) & 0x01);

	printf("CRC: %#x\n", packet1.crc);
	printf("Status: %#x\n", packet1.status);
	printf("Payload: %#x\n", packet1.payload);
	printf("BAT: %#x\n", packet1.bat);
	printf("Sensor: %#x\n", packet1.sensor);
	printf("Long Address: %#x\n", packet1.longAddr);
	printf("Short Address: %#x\n", packet1.shortAddr);
	printf("Address Mode: %#x\n", packet1.addrMode);

	printf("%#x\n", *ptr);
	printf("Total size of Packets struct: %llu\n", sizeof(packet1));

	return 0;
}


