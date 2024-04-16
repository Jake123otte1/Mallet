#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "io.h"

// Splash
void splashScreen(IN int argc,  IN char* argv[], OUT int* mode)
{
	printf("\n*********************************************************\n");
	printf("  ___  ___        _  _        _           __      _____ \n");
	printf("  |  \\/  |       | || |      | |         /  |    |  _  |\n");
	printf("  | .  . |  __ _ | || |  ___ | |_        `| |    | |/' |\n");
	printf("  | |\\/| | / _` || || | / _ \\| __|        | |    |  /| |\n");
	printf("  | |  | || (_| || || ||  __/| |_        _| |_ _ \\ |_/ /\n");
	printf("  \\_|  |_/ \\__,_||_||_| \\___| \\__|       \\___/(_) \\___/ \n\n");
	printf("**********************************************************\n");

	if (argc < 2) {
		*mode = 0;
		printf("No shellcode input detected. Select a template: \n");
		printf("1. Msfvenom\n");
		printf("2. Havoc C2\n");
		printf("3. Exit\n");
	}
	else if (argc == 2) {
		*mode = 1;
		printf("Shellcode input file: %s", argv[1]);
		printf("\nSelect a generation mode:\n");
		printf("1. Quick mode\n");
		printf("2. Custom mode\n");
		printf("3. Exit\n");
	}
}

int main(int argc, char* argv[])
{

	// Splash screen and user menu
	int c = 0;
	int* mode = 2;
	splashScreen(argc, argv, &mode);
	do {
		printf("Selection: ");
		scanf_s("%d", &c);

	} while (c < 1 || c > 4);
	if (c == 3) {
		return EXIT_SUCCESS;
	}


	// Template (WIP)
	if (mode == 0)
	{
		switch (c) {

		}
	}

	// Shellcode file input
	if (mode == 1)
	{
		// Read in shellcode from file
		struct PayloadInfo pInfo;
		pInfo.pPayload = NULL;
		pInfo.sPayloadSize = NULL;
		BOOL bRead = ReadShellcode(argv[1],&pInfo.pPayload,&pInfo.sPayloadSize);

		switch (c) {
		case 1: // QUICK MODE
			printf("\n**********************************************************\n");
			printf("Generating payload with quick mode: AES encryption and .text payload...\n");
			QuickMode(pInfo.pPayload,pInfo.sPayloadSize);
			printf("Runner written. Compile MalletRun.sln and execute!");

			break;
		case 2: // CUSTOM MODE
			printf("\n**********************************************************\n");
			char line[1024];
			printf("Specify custom encryption chain: \n");
			printf("1. AES-256\n");
			printf("2. RC4\n");
			printf("3. XOR\n");
			scanf_s("%10s", line);
			printf("%s", line);

			break;
		}

		return EXIT_SUCCESS;
	}
}