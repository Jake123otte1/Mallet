#include <stdio.h>
#include <Windows.h>
#include "aes.h"
#include "util.h"

// Takes in a buffer for AES-256 and pads with null bytes if needed (taken from MA)
BOOL AESPadding(IN PBYTE pPayload, IN SIZE_T sPayloadSize, OUT PBYTE* pPaddedRet, OUT SIZE_T* sPaddedSizeRet) {

	// Init buffers
	PBYTE	pPadded = NULL;
	SIZE_T	sPaddedSize = NULL;

	// Find closest 16th multiple and allocate mem
	sPaddedSize = sPayloadSize + 16 - (sPayloadSize % 16);
	pPadded = malloc(sPaddedSize);

	// Zero memory as we just want to add some null bytes
	ZeroMemory(pPadded, sPaddedSize);

	// Copy payload to expanded buffer and return expanded buffer
	memcpy(pPadded, pPayload, sPayloadSize);
	*pPaddedRet = pPadded;
	*sPaddedSizeRet = sPaddedSize;

	return TRUE;
}

// Will encrypt a payload with a random key. Returns payload and the keys used
BOOL AESEncrypt(OUT PBYTE pPayload, OUT SIZE_T sPayloadSize, OUT BYTE* pKey, OUT BYTE* pIV)
{
	// Init Tiny-AES struct
	struct AES_ctx tiny;

	// Update key buffers
	RandomBytes(pKey, 32);
	RandomBytes(pIV, 16);

	AES_init_ctx_iv(&tiny, pKey, pIV);
	AES_CBC_encrypt_buffer(&tiny, pPayload, sPayloadSize);

}