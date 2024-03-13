#include <stdio.h>
#include <stdint.h>

typedef union Packet
{
	uint32_t packetValue;
	struct
	{
		uint32_t crc:2;
		uint32_t status:1;
		uint32_t payload:12;
		uint32_t bat:3;
		uint32_t sensor:3;
		uint32_t longAddr:8;
		uint32_t shortAddr:2;
		uint32_t addrMode:1;
	}packetfields;

}Packets;

int main()
{
	Packets packet1;
	printf("Enter the 32 bit packet value: ");
	scanf("%x", &packet1.packetValue);

	uint32_t *ptr = (uint32_t *)&packet1;
	packet1.packetfields.crc = (uint8_t) (packet1.packetValue & 0x03);
	packet1.packetfields.status = (uint8_t) ((packet1.packetValue >> 2) & 0x01);
	packet1.packetfields.payload = (uint16_t) ((packet1.packetValue >> 3) & 0xFFF);
	packet1.packetfields.bat = (uint8_t) ((packet1.packetValue >> 15) & 0x07);
	packet1.packetfields.sensor = (uint8_t) ((packet1.packetValue >> 18) & 0x07);
	packet1.packetfields.longAddr = (uint8_t) ((packet1.packetValue >> 21) & 0xFF);
	packet1.packetfields.shortAddr = (uint8_t) ((packet1.packetValue >> 29) & 0x03);
	packet1.packetfields.addrMode = (uint8_t) ((packet1.packetValue >> 31) & 0x01);

	printf("CRC: %#x\n", packet1.packetfields.crc);
	printf("Status: %#x\n", packet1.packetfields.status);
	printf("Payload: %#x\n", packet1.packetfields.payload);
	printf("BAT: %#x\n", packet1.packetfields.bat);
	printf("Sensor: %#x\n", packet1.packetfields.sensor);
	printf("Long Address: %#x\n", packet1.packetfields.longAddr);
	printf("Short Address: %#x\n", packet1.packetfields.shortAddr);
	printf("Address Mode: %#x\n", packet1.packetfields.addrMode);

	printf("%#x\n", *ptr);
	printf("Total size of Packets struct: %llu\n", sizeof(packet1));

	return 0;
}


