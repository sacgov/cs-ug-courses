/*
 * Advanced Encryption Standard (AES 128)
*/ 
#include <iostream>
#include <stdint.h>
#include <string>
#include <stdio.h>

using namespace std;

#define ARR_SIZE 16
#define Nk 4
#define Nr 10
#define KEYLEN 128 // bits
#define Nb 4

/*
 * S-box transformation table
 */
uint8_t s_box[256] = {
	// 0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, // 0
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, // 1
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, // 2
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, // 3
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, // 4
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, // 5
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, // 6
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, // 7
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, // 8
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, // 9
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, // a
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, // b
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, // c
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, // d
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, // e
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16  // f
};

/*
 * Inverse S-box transformation table
 */
uint8_t inv_s_box[256] = {
	// 0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb, // 0
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb, // 1
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e, // 2
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25, // 3
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92, // 4
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84, // 5
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06, // 6
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b, // 7
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73, // 8
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e, // 9
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b, // a
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4, // b
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f, // c
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef, // d
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61, // e
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d  // f
};

uint8_t R[] = {0x02, 0x00, 0x00, 0x00};

uint8_t gmult(uint8_t a, uint8_t b) {
	uint8_t p = 0, i = 0, hbs = 0;
	for (i = 0; i < 8; i++) {
		if (b & 1) {
			p ^= a;
		}
		hbs = a & 0x80;
		a <<= 1;
		if (hbs) a ^= 0x1b; // irreducibe polynomial
		b >>= 1;
	}
	return p;
}

void Rcon(uint8_t i) {
	
	if (i == 1) {
		R[0] = 0x01;
	} else if (i > 1) {
		R[0] = 0x02;
		i--;
		while (i-1 > 0) {
			R[0] = gmult(R[0], 0x02);
			i--;
		}
	}
}

void KeyExpansion(uint8_t key[], uint8_t word[]) {
	uint8_t tmp[4], i, j, len = (Nr+1)*Nb, t;
	for (i=0; i<Nk; i++) {
		word[4*i] = key[4*i];
		word[4*i+1] = key[4*i+1];
		word[4*i+2] = key[4*i+2];
		word[4*i+3] = key[4*i+3];
	}
	for (i=Nk; i < len; i++) {
		tmp[0] = word[4*(i-1)];
		tmp[1] = word[4*(i-1)+1];
		tmp[2] = word[4*(i-1)+2];
		tmp[3] = word[4*(i-1)+3];
		if (i%Nk == 0) {
			
			/* rotate word */
			t = tmp[0];
			
			for (j=0; j < Nb-1; j++) {
				tmp[j] = tmp[j+1];
			}
			tmp[Nb-1] = t;
			/* Substitute Word */
			for (j=0; j<4; j++) {
				tmp[j] = s_box[16*((tmp[j] & 0xf0) >> 4) + (tmp[j] & 0x0f)];
			}
			Rcon(i/Nk);
			for (j=0; j<4; j++) {
				tmp[j] ^= R[j];
			}
		} 
		word[4*i]   = word[4*(i-Nk)] ^ tmp[0];
		word[4*i+1] = word[4*(i-Nk)+1] ^ tmp[1];
		word[4*i+2] = word[4*(i-Nk)+2] ^ tmp[2];
		word[4*i+3] = word[4*(i-Nk)+3] ^ tmp[3];
	}
}

void SubBytes(uint8_t arr[]) {
	uint8_t x,y;
	for (uint8_t i=0; i < ARR_SIZE; i++) {
		x = arr[i] >> 4;
		y = arr[i] << 4;
		y = y >> 4;
		arr[i] = s_box[x*ARR_SIZE + y];
	}
}

void ShiftRows(uint8_t arr[]) {
	uint8_t shifts, r, l, tmp;
	for (uint8_t i=0; i < ARR_SIZE; i+=4) {
		shifts = i/4;
		l = i; r = i+4;
		for (uint8_t s = 0; s < shifts; s++) {
			tmp = arr[l];
			for (uint8_t k=l; k < r-1; k++) {
				arr[k] = arr[k+1];
			}
			arr[r-1] = tmp;
		}
	}
}

void MixColumns(uint8_t arr[]) {
	uint8_t r, tmp[4];
	for (uint8_t c=0; c < 4; c++) {
		tmp[0] = gmult(0x02, arr[c]) ^ gmult(0x03, arr[c+4]) ^ arr[c+8] ^ arr[c+12];
		tmp[1] = arr[c] ^ gmult(0x02, arr[c+4]) ^ gmult(0x03, arr[c+8]) ^ arr[c+12];
		tmp[2] = arr[c] ^ arr[c+4] ^ gmult(0x02, arr[c+8]) ^ gmult(0x03, arr[c+12]); 
		tmp[3] = gmult(0x03, arr[c]) ^ arr[c+4] ^ arr[c+8] ^ gmult(0x02, arr[c+12]);
		for (int j=0; j<4; j++) {
			arr[c+4*j] = tmp[j]; 
		}
	}
}

void AddRoundKey(uint8_t arr[], uint8_t word[], uint8_t r) {
	uint8_t c;
	for (c = 0; c < Nb; c++) {
		arr[Nb*0+c] = arr[Nb*0+c] ^ word[4*Nb*r+4*c]; 
		arr[Nb*1+c] = arr[Nb*1+c] ^ word[4*Nb*r+4*c+1];
		arr[Nb*2+c] = arr[Nb*2+c] ^ word[4*Nb*r+4*c+2];
		arr[Nb*3+c] = arr[Nb*3+c] ^ word[4*Nb*r+4*c+3];	
	}
}

void InvShiftRows(uint8_t arr[]) {
	uint8_t shifts, r, l, tmp;
	for (uint8_t i=0; i < ARR_SIZE; i+=4) {
		shifts = i/4;
		l = i; r = i+4;
		for (uint8_t s = 0; s < shifts; s++) {
			tmp = arr[r-1];
			for (uint8_t k=r-1; k > l; k--) {
				arr[k] = arr[k-1];
			}
			arr[l] = tmp;
		}
	}
}

void InvMixColumns(uint8_t arr[]) {
	uint8_t r, tmp[4];
	for (uint8_t c=0; c < 4; c++) {
		tmp[0] = gmult(0x0E, arr[c]) ^ gmult(0x0B, arr[c+4]) ^ gmult(0x0D, arr[c+8]) ^ (0x09, arr[c+12]);
		tmp[1] = gmult(0x09, arr[c]) ^ gmult(0x0E, arr[c+4]) ^ gmult(0x0B, arr[c+8]) ^ (0x0D, arr[c+12]);
		tmp[2] = gmult(0x0D, arr[c]) ^ gmult(0x09, arr[c+4]) ^ gmult(0x0E, arr[c+8]) ^ (0x0B, arr[c+12]);
		tmp[3] = gmult(0x0B, arr[c]) ^ gmult(0x0D, arr[c+4]) ^ gmult(0x09, arr[c+8]) ^ (0x0E, arr[c+12]);
		for (int j=0; j<4; j++) {
			arr[c+4*j] = tmp[j]; 
		}
	}
}

void InvSubBytes(uint8_t arr[]) {
	uint8_t x,y;
	for (uint8_t i=0; i < ARR_SIZE; i++) {
		x = arr[i] >> 4;
		y = arr[i] << 4;
		y = y >> 4;
		arr[i] = inv_s_box[x*ARR_SIZE + y];
	}
}

void Cipher (uint8_t text[], uint8_t enc[],  uint8_t word[]) {
	uint8_t r, state [16];
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			state[i*4+j] = text[j*4+i];
		}
	}
	AddRoundKey(state, word, 0);

	for (r=1; r < Nr; r++) {
		SubBytes(state);
		ShiftRows(state);
		MixColumns(state);
		AddRoundKey(state, word, r);
	}
	SubBytes(state);
	ShiftRows(state);
	AddRoundKey(state, word, r);

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			enc[i+j*4] = state[i*4+j];
		}
	}
}

void Decipher (uint8_t text[], uint8_t dec[],  uint8_t word[]) {
	uint8_t r, state [16];
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			state[i*4+j] = text[j*4+i];
		}
	}
	AddRoundKey(state, word, Nr);

	for (r=Nr-1; r > 0; r--) {
		InvShiftRows(state);
		InvSubBytes(state);
		AddRoundKey(state, word, r);
		InvMixColumns(state);
	}
	
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state, word, 0);

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			dec[i+j*4] = state[i*4+j];
		}
	}
}

int main() {
	uint8_t text[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
	uint8_t key [] = {0x0f, 0x15, 0x71, 0xc9, 0x47, 0xd9, 0xe8, 0x59, 0x0c, 0xb7, 0xad, 0xd6, 0xaf, 0x7f, 0x67, 0x98};
	
	uint8_t word[Nb*(Nr+1)*4];
	uint8_t enc[16], dec[16];
	KeyExpansion(key, word);

	Cipher(text, enc, word);
	printf("\nCiphertext: ");
	for (int i=0; i < 16; i++) {
		printf("%2x ", enc[i]);
	}

	Decipher(enc, dec, word);
	printf("\nplainetext: ");
	for (int i=0; i < 16; i++) {
		printf("%2x ", dec[i]);
	}
	printf("\n");

    return 0;
}
