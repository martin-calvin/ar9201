#include <stdio.h>
#include <string.h>
#include "artosyn-crypto-api.h"

/*
 * cipher online calculation:
 * http://tool.chacuo.net/cryptaes
 *
 * hash/mac online calculation:
 * https://1024tools.com/hash
 */

#if 0
string "   ABCDEFGHIJKLMNOP12345678+-*/()<>HGFEDCBAPONMLKJI87654321><)(/*-+     "
#endif

unsigned char src1[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'1', '2', '3', '4', '5', '6', '7', '8',
	'+', '-', '*', '/', '(', ')', '<', '>',
};

unsigned char src2[] = {
	'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A',
	'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I',
	'8', '7', '6', '5', '4', '3', '2', '1',
	'>', '<', ')', '(', '/', '*', '-', '+'
};

unsigned char key1[] = {
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
	'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
	'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
	'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D',
};

unsigned char key2[] = {
	'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E',
	'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F',
	'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G',
	'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H',
};

unsigned char key3[] = {
	0x63, 0xa4, 0x9c, 0xc0, 0x27, 0x96, 0xfc, 0x85,
	0xad, 0x2e, 0xc1, 0x20, 0x3e, 0x77, 0xd5, 0x3d,
	0x5c, 0x19, 0x70, 0x23, 0x2f, 0xad, 0x80, 0xef,
	0x98, 0x14, 0x57, 0x52, 0x26, 0x45, 0x6c, 0x08,
};

unsigned char seckey[256] = {
	0x69, 0xb7, 0x09, 0x8f, 0xc1, 0x64, 0xef, 0xe6,
	0x5c, 0xc4, 0x92, 0x52, 0x0c, 0x6f, 0x3b, 0xba,
	0xf9, 0xf0, 0xf5, 0xd1, 0x31, 0x36, 0xb1, 0xc1,
	0x57, 0xfb, 0x08, 0xe1, 0x39, 0x29, 0xf3, 0x07,
	0x75, 0x1a, 0x10, 0x09, 0x80, 0x8c, 0xc6, 0x93,
	0x50, 0x04, 0xb0, 0xb4, 0x43, 0xd1, 0x4c, 0x8f,
	0x1e, 0x45, 0x48, 0x66, 0xdd, 0xd8, 0xda, 0x02,
	0x5b, 0xdf, 0x09, 0xe0, 0x0d, 0xcb, 0x10, 0x52,
	0xc9, 0xcf, 0xa7, 0xfb, 0x1e, 0x5a, 0x72, 0x93,
	0x58, 0xd9, 0xf4, 0xae, 0x72, 0x12, 0xeb, 0xb7,
	0x62, 0x02, 0x09, 0x7c, 0x8e, 0x82, 0x67, 0x5f,
	0x59, 0xe8, 0x3f, 0xbb, 0x6d, 0x46, 0x04, 0xa6,
	0x13, 0xeb, 0xf3, 0xb3, 0x80, 0xd8, 0xfa, 0xba,
	0x85, 0x3d, 0xae, 0x7a, 0xac, 0xa4, 0x08, 0x61,
	0xeb, 0x02, 0x73, 0xbe, 0xc0, 0xbd, 0x93, 0x57,
	0xd3, 0x03, 0xe1, 0x38, 0x68, 0x67, 0x2f, 0xd4,
	0x2d, 0xcb, 0x67, 0x78, 0x06, 0x6c, 0x2b, 0x9c,
	0x96, 0xf4, 0xb0, 0xdb, 0x46, 0xe3, 0x1b, 0x55,
	0x1c, 0x2c, 0x49, 0x56, 0xed, 0x43, 0x5b, 0xa8,
	0xf2, 0xbc, 0x2c, 0x2e, 0xb8, 0xff, 0x18, 0x4f,
	0xbb, 0xab, 0x56, 0x5b, 0x53, 0xbf, 0x7d, 0x71,
	0x85, 0x26, 0x25, 0xc4, 0x70, 0x0a, 0x30, 0x58,
	0xa4, 0xab, 0x27, 0x09, 0x13, 0x32, 0x18, 0x83,
	0x10, 0xdd, 0x71, 0x17, 0x27, 0xb2, 0x8d, 0x8f,
	0x9a, 0xe9, 0x42, 0xd9, 0xca, 0x8d, 0xf1, 0xe0,
	0xbe, 0x67, 0x2b, 0x38, 0xe2, 0xa0, 0xd5, 0xfb,
	0xa8, 0xd6, 0x83, 0xbc, 0x42, 0xaf, 0xf8, 0x69,
	0x5b, 0xa4, 0xf4, 0x90, 0x22, 0x48, 0x60, 0x50,
	0xf6, 0x51, 0xfc, 0x6e, 0x4a, 0x17, 0x9d, 0x21,
	0xce, 0x76, 0x09, 0x72, 0xe6, 0x5f, 0xd9, 0x98,
	0x55, 0x97, 0x8b, 0x73, 0xb5, 0x1f, 0xce, 0xe0,
	0x4b, 0x82, 0xa3, 0x0b, 0xe4, 0x46, 0xf5, 0xe7
};

unsigned char iv[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'
};

unsigned char obj_id[] = {01, 02};

struct cipher_result {
	unsigned char *name;
	unsigned int algo;
	unsigned int ca;
	unsigned char *src1, *src2;
	unsigned char *iv;
	unsigned int iv_len;

	unsigned char *key1, *key2;
	unsigned int key_len;

	unsigned char *derive_str1, *derive_str2, *derive_iv;

	unsigned char *seckey;
	unsigned char *seckey_len;
	unsigned int rsa_idx;

	unsigned char *obj_id;
	unsigned int obj_id_len;
	unsigned int flags;
	unsigned int attrs;
	unsigned int storage_id;

	unsigned char *res;
};

unsigned char cipher_res_aes_ecb128[] = {
	0x0c, 0xe9, 0x73, 0x7d, 0x2c, 0x0c, 0x70, 0x52,
	0xf3, 0x7a, 0xf7, 0x49, 0x02, 0xa6, 0x96, 0x7c,
	0x99, 0xf7, 0x6a, 0x48, 0xf2, 0xaa, 0x71, 0x07,
	0x4c, 0x9e, 0xc6, 0x4f, 0x8d, 0x42, 0xc5, 0x88,
	0x28, 0xb3, 0x9b, 0x56, 0x90, 0x79, 0x80, 0xc5,
	0x58, 0x0f, 0xc9, 0x79, 0xca, 0x20, 0xd6, 0x15,
	0xdb, 0x1d, 0xb2, 0x79, 0xeb, 0xe5, 0x05, 0x4a,
	0x68, 0x18, 0x8f, 0x23, 0xb0, 0xd2, 0xf5, 0xe8
};

unsigned char cipher_res_aes_cbc128[] = {
	0xb9, 0x7d, 0xf5, 0x33, 0xc3, 0xc4, 0xbf, 0xef,
	0x50, 0xa5, 0xa3, 0xb4, 0xbd, 0xb0, 0x7e, 0x2d,
	0xa6, 0x98, 0x2a, 0x73, 0x50, 0x1b, 0x8d, 0xea,
	0x41, 0xd4, 0x6c, 0x3a, 0x27, 0xb8, 0x37, 0x87,
	0x60, 0x04, 0xe0, 0x00, 0x40, 0x22, 0xaf, 0xf4,
	0x62, 0xd2, 0xbf, 0x2e, 0x7b, 0x1a, 0x4a, 0xe5,
	0xac, 0x0c, 0xdb, 0x91, 0x9e, 0xd4, 0x4e, 0x45,
	0x54, 0xb3, 0x0d, 0xd2, 0x92, 0xa2, 0x67, 0x3f
};

unsigned char cipher_res_aes_ctr128[] = {
	0x4d, 0xab, 0x30, 0x39, 0x69, 0x4a, 0x37, 0x1a,
	0xba, 0x30, 0xbc, 0x05, 0x4f, 0xe8, 0xd9, 0x2c,
	0x88, 0x74, 0xd1, 0x0b, 0x3f, 0x6a, 0x16, 0xd1,
	0x42, 0x01, 0x63, 0x2b, 0xa3, 0x69, 0x42, 0xc6,
	0x74, 0x57, 0x19, 0x13, 0xa3, 0x3b, 0x8f, 0x54,
	0x0c, 0x3f, 0x14, 0x4e, 0x66, 0x7a, 0x2d, 0x54,
	0xdd, 0x09, 0xe1, 0xaa, 0x45, 0x32, 0x8c, 0xa3,
	0xb0, 0x9a, 0x75, 0x21, 0x86, 0xd6, 0xc2, 0x4c
};

unsigned char cipher_res_aes_ecb256[] = {
	0x55, 0x95, 0xc6, 0xb0, 0x2a, 0x47, 0xf3, 0xdb,
	0x63, 0xc3, 0xd8, 0xac, 0xc0, 0x35, 0x0d, 0xd3,
	0x04, 0x6c, 0xac, 0x16, 0x4f, 0xf5, 0x23, 0x55,
	0xe3, 0x22, 0x17, 0xa7, 0x9d, 0xda, 0xaa, 0x08,
	0xdb, 0x03, 0x26, 0xe4, 0x7f, 0x58, 0x84, 0x9d,
	0x90, 0x95, 0x1c, 0x85, 0xb8, 0x1b, 0xae, 0xb2,
	0x9f, 0x42, 0x3e, 0xfa, 0xdf, 0xb1, 0x9d, 0x90,
	0xd6, 0x5b, 0x2e, 0xfc, 0xf8, 0x11, 0x4d, 0xe6
};

unsigned char cipher_res_aes_cts256[] = {
	0xe7, 0x26, 0xb5, 0xf3, 0x0a, 0xbd, 0xd7, 0x9c,
	0x86, 0xac, 0xe5, 0xe9, 0xda, 0xe1, 0xfa, 0xea,
	0xf9, 0x22, 0xbf, 0xad, 0xc9, 0xa2, 0xee, 0x62,
	0xc6, 0x33, 0xd4, 0x42, 0x3f, 0xc9, 0x17, 0xf7,
	0x85, 0x9a, 0xa9, 0x21, 0xb3, 0x75, 0xa6, 0x71,
	0x38, 0x59, 0xd1, 0x55, 0x8b, 0xbb, 0xdc, 0x29,
	0x33, 0x1a, 0x27, 0x59, 0x20, 0x29, 0xa1, 0xc2,
	0x95, 0x20, 0x9f, 0xb5, 0xb3, 0xba, 0xbd, 0x8d
};

unsigned char cipher_res_des_ecb256[] = {
	0xf8, 0xb5, 0x4a, 0x73, 0xce, 0xa2, 0x2c, 0xd5,
	0xec, 0xe0, 0x91, 0x80, 0x4d, 0x52, 0x93, 0x6e,
	0xc4, 0x2c, 0x86, 0x9f, 0x1d, 0x99, 0xcd, 0xca,
	0x5a, 0x82, 0x17, 0x6c, 0x0f, 0x3b, 0x9d, 0x0d,
	0x55, 0x68, 0x8e, 0xc0, 0xfc, 0x2b, 0xde, 0x61,
	0xc4, 0xe7, 0x31, 0x0e, 0x22, 0xbd, 0xbe, 0x45,
	0xe4, 0xa4, 0xae, 0x0f, 0xd9, 0x56, 0x52, 0x02,
	0xdb, 0xa4, 0x1c, 0x44, 0x10, 0x0b, 0xac, 0x1e
};

unsigned char cipher_res_aes_cbc256_rootkey_all_0[] = {
	0x2e, 0x1a, 0x9f, 0x67, 0x9a, 0x7f, 0x31, 0xc6,
	0xc2, 0xee, 0x61, 0x41, 0xbc, 0xe0, 0x7d, 0xed,
	0x14, 0xd7, 0x41, 0xbe, 0x21, 0x46, 0x83, 0x34,
	0x80, 0xa9, 0xb9, 0x11, 0xfe, 0x1b, 0x4b, 0x61,
	0x4f, 0x32, 0xca, 0x77, 0xfa, 0x26, 0x9e, 0xe3,
	0x87, 0xa9, 0xab, 0xc4, 0x1c, 0xff, 0xd3, 0xb1,
	0xad, 0xf1, 0x3f, 0x74, 0x13, 0x44, 0xad, 0x86,
	0xa2, 0x3c, 0x0c, 0xf6, 0x46, 0x03, 0x89, 0x73
};

unsigned char cipher_res_aes_cbc256_seckey[] = {
	0xe7, 0x26, 0xb5, 0xf3, 0x0a, 0xbd, 0xd7, 0x9c,
	0x86, 0xac, 0xe5, 0xe9, 0xda, 0xe1, 0xfa, 0xea,
	0xf9, 0x22, 0xbf, 0xad, 0xc9, 0xa2, 0xee, 0x62,
	0xc6, 0x33, 0xd4, 0x42, 0x3f, 0xc9, 0x17, 0xf7,
	0x33, 0x1a, 0x27, 0x59, 0x20, 0x29, 0xa1, 0xc2,
	0x95, 0x20, 0x9f, 0xb5, 0xb3, 0xba, 0xbd, 0x8d,
	0x85, 0x9a, 0xa9, 0x21, 0xb3, 0x75, 0xa6, 0x71,
	0x38, 0x59, 0xd1, 0x55, 0x8b, 0xbb, 0xdc, 0x29
};

struct cipher_result cipher_result[] = {
	{
		.name = "aes ecb128",
		.algo = AR_CRYPTO_ALG_AES_ECB_NOPAD,
		.ca = AR_CIPHER_CA_USER,
		.src1 = src1,
		.src2 = src2,
		.key1 = key1,
		.iv   = iv,
		.key_len = 128,
		.iv_len  = 128,
		.res = cipher_res_aes_ecb128,
	},

	{
		.name = "aes cbc128",
		.algo = AR_CRYPTO_ALG_AES_CBC_NOPAD,
		.ca = AR_CIPHER_CA_USER,
		.src1 = src1,
		.src2 = src2,
		.key1 = key1,
		.iv   = iv,
		.key_len = 128,
		.iv_len  = 128,
		.res = cipher_res_aes_cbc128,
	},

	{
		.name = "aes ctr128",
		.algo = AR_CRYPTO_ALG_AES_CTR,
		.ca = AR_CIPHER_CA_USER,
		.src1 = src1,
		.src2 = src2,
		.key1 = key1,
		.iv   = iv,
		.key_len = 128,
		.iv_len  = 128,
		.res = cipher_res_aes_ctr128,
	},

	{
		.name = "aes ecb256",
		.algo = AR_CRYPTO_ALG_AES_ECB_NOPAD,
		.ca = AR_CIPHER_CA_USER,
		.src1 = src1,
		.src2 = src2,
		.key1 = key1,
		.iv   = iv,
		.key_len = 256,
		.iv_len  = 128,
		.res = cipher_res_aes_ecb256,
	},

	{
		.name = "aes cts256",
		.algo = AR_CRYPTO_ALG_AES_CTS,
		.ca = AR_CIPHER_CA_USER,
		.src1 = src1,
		.src2 = src2,
		.key1 = key1,
		.iv   = iv,
		.key_len = 256,
		.iv_len  = 128,
		.res = cipher_res_aes_cts256,
	},

	{
		.name = "des ecb256",
		.algo = AR_CRYPTO_ALG_DES_ECB_NOPAD,
		.ca = AR_CIPHER_CA_USER,
		.src1 = src1,
		.src2 = src2,
		.key1 = key1,
		.iv   = iv,
		.key_len = 64,/* des key is 8 byte */
		.iv_len  = 128,
		.res = cipher_res_des_ecb256,
	},

	/* test root key */
	{
		.name = "aes cbc256 compare root key",
		.algo = AR_CRYPTO_ALG_AES_CBC_NOPAD,
		.ca = AR_CIPHER_CA_USER,
		.src1 = src1,
		.src2 = src2,
		.key1 = key3,
		.iv   = iv,
		.key_len = 256,
		.iv_len  = 128,
		.res = cipher_res_aes_cbc256_rootkey_all_0,
	},


	/* test root key */
	/* root key is 32byte 0, derive key is key3*/
	{
		.name = "aes cbc256 root key",
		.algo = AR_CRYPTO_ALG_AES_CBC_NOPAD,
		.ca = AR_CIPHER_CA_ROOT,
		.src1 = src1,
		.src2 = src2,
		.key1 = key1,
		.iv   = iv,
		.key_len = 256,
		.iv_len  = 128,
		.derive_str1 = "arosyn_str1",
		.derive_str2 = "arosyn_str2",
		.derive_iv = "arosyn_iv",
		.res = cipher_res_aes_cbc256_rootkey_all_0,
	},

#if 0
	/* test sec key */
	{
			.name = "aes cbc256 sec key",
			.algo = AR_CRYPTO_ALG_AES_CBC_NOPAD,
			.ca = AR_CIPHER_CA_SECU,
			.src1 = src1,
			.src2 = src2,
			.iv   = iv,
			.iv_len  = 128,
			.seckey = seckey,
			.seckey_len = 256,
			.rsa_idx = 0,
			.res = cipher_res_aes_cbc256_seckey,
	},
#endif

#if 0
	/* test file key */
	{
		.name = "aes cbc256 file key",
		.algo = AR_CRYPTO_ALG_AES_CBC_NOPAD,
		.ca = AR_CIPHER_CA_FILE,
		.src1 = src1,
		.src2 = src2,
		.iv   = iv,
		.iv_len  = 128,
		.obj_id = &obj_id,
		.obj_id_len = sizeof(obj_id),
		.flags = AR_DATA_FLAG_ACCESS_READ,
		.attrs = 0,
		.storage_id = AR_STORAGE_ID_PRIVATE_REE,
		.res = cipher_res_aes_cbc256_seckey,
	},

#endif

	{
	},
};

unsigned char hash_src[] = {
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A',
	'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
	'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
	'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
	'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
};

unsigned char hash_dst_md5[] = {
	0x58, 0x66, 0x88, 0xef, 0xf8, 0x88, 0x92, 0xb7,
	0xb3, 0x8a, 0x47, 0xc7, 0x18, 0x3c, 0xb4, 0xd5
};
unsigned char hash_dst_sha1[] = {
	0x9b, 0x91, 0x37, 0x8f, 0x6f, 0xbf, 0xa3, 0x31,
	0xcb, 0xf7, 0x37, 0xbb, 0xeb, 0xd9, 0xbb, 0xb6,
	0x58, 0x1e, 0x42, 0xa9
};

unsigned char hash_dst_sha224[] = {
	0xe5, 0x9d, 0x86, 0x3d, 0xb3, 0x1e, 0xa6, 0x32,
	0xc3, 0xfb, 0xcb, 0xc7, 0x89, 0xbd, 0x56, 0x69,
	0x1b, 0x54, 0xf7, 0x50, 0x42, 0xc5, 0x70, 0x86,
	0x3b, 0x0d, 0x77, 0xc2
};

unsigned char hash_dst_sha256[] = {
	0x9e, 0x2d, 0x1f, 0x68, 0xa3, 0xf9, 0x80, 0x59,
	0xc3, 0xc8, 0xe6, 0xf7, 0x7d, 0xe8, 0x63, 0xbe,
	0x7f, 0x58, 0x65, 0xc0, 0xf5, 0xf3, 0x04, 0xd7,
	0x85, 0xc3, 0x45, 0x83, 0x3b, 0x47, 0xf2, 0x49
};

unsigned char hash_dst_sha384[] = {
	0x59, 0x36, 0xdf, 0x6d, 0x2b, 0xd8, 0x1d, 0x69,
	0x8a, 0xed, 0x0f, 0x25, 0x97, 0xce, 0xa3, 0xc7,
	0x77, 0xad, 0x31, 0x22, 0x20, 0x06, 0x03, 0xa6,
	0x89, 0xce, 0x06, 0x1a, 0x7f, 0x27, 0xcd, 0x35,
	0x8b, 0xc0, 0x68, 0xf5, 0xe4, 0x9f, 0xbb, 0x68,
	0x6b, 0xf7, 0x04, 0xe7, 0x84, 0x06, 0xa7, 0x54,
};

unsigned char hash_dst_sha512[] = {
	0x0a, 0x89, 0x8f, 0xec, 0xf9, 0x53, 0xe1, 0x70,
	0x53, 0x9c, 0x7f, 0x53, 0x49, 0xa5, 0x00, 0x18,
	0x50, 0x26, 0x21, 0xac, 0xb9, 0xa9, 0xd5, 0x32,
	0xd5, 0x6e, 0xf0, 0x7f, 0x90, 0xa1, 0x0e, 0xc1,
	0x35, 0xce, 0xf0, 0xc8, 0x37, 0x27, 0x8c, 0xdf,
	0x6d, 0x80, 0xce, 0x07, 0xc5, 0x98, 0x54, 0x35,
	0xea, 0x9e, 0xf4, 0xc6, 0x03, 0xb0, 0x1d, 0x9a,
	0xf2, 0xff, 0xfc, 0x2e, 0x4c, 0xa1, 0x9c, 0xf3
};

struct hash_result {
	unsigned char *name;
	unsigned int algo;
	unsigned int digest_len;
	unsigned int key_len;
	unsigned char *res;
};

struct hash_result hash_result[] = {
	{
		.name = "MD5",
		.algo = AR_CRYPTO_ALG_MD5,
		.digest_len = 128,
		.res = hash_dst_md5,
	},

	{
		.name = "SHA1",
		.algo = AR_CRYPTO_ALG_SHA1,
		.digest_len = 160,
		.res = hash_dst_sha1,
	},

	{
		.name = "SHA224",
		.algo = AR_CRYPTO_ALG_SHA224,
		.digest_len = 224,
		.res = hash_dst_sha224,
	},

	{
		.name = "SHA256",
		.algo = AR_CRYPTO_ALG_SHA256,
		.digest_len = 256,
		.res = hash_dst_sha256,
	},

	{
		.name = "SHA384",
		.algo = AR_CRYPTO_ALG_SHA384,
		.digest_len = 384,
		.res = hash_dst_sha384,
	},

	{
		.name = "SHA512",
		.algo = AR_CRYPTO_ALG_SHA512,
		.digest_len = 512,
		.res = hash_dst_sha512,
	},

	{
	},
};

unsigned char mac_dst_md5_128[] = {
	0x40, 0x84, 0xa8, 0x13, 0x81, 0x2e, 0x66, 0xbf,
	0x9e, 0x73, 0x4f, 0xf8, 0x08, 0x2c, 0x08, 0x6a
};

unsigned char mac_dst_sha1_128[] = {
	0x30, 0x0b, 0x52, 0x93, 0x15, 0xdf, 0x3a, 0xe0,
	0x87, 0x77, 0xa7, 0x09, 0x15, 0x33, 0x38, 0x60,
	0x80, 0x3f, 0x71, 0x82
};

unsigned char mac_dst_sha224_128[] = {
	0xe3, 0x52, 0x36, 0x59, 0x7d, 0xa2, 0x9b, 0x9a,
	0xfd, 0xe7, 0xe1, 0x81, 0xb2, 0x4d, 0x2c, 0x55,
	0xaa, 0x72, 0xa7, 0xe4, 0x09, 0x37, 0x21, 0x9f,
	0xd5, 0x89, 0x6a, 0xb2
};

unsigned char mac_dst_sha256_128[] = {
	0x68, 0xb6, 0xbd, 0x93, 0x2f, 0xac, 0x08, 0xf6,
	0xee, 0xee, 0x87, 0x17, 0x32, 0xb8, 0x23, 0xdf,
	0xcd, 0x6d, 0xfc, 0x64, 0x6d, 0x96, 0x9b, 0xfa,
	0xed, 0x8b, 0xee, 0x37, 0x29, 0x65, 0x98, 0xdf
};

unsigned char mac_dst_sha384_128[] = {
	0xc1, 0xc0, 0x17, 0x28, 0xd0, 0xc0, 0xf6, 0xe4,
	0x78, 0x83, 0xc9, 0xa4, 0xc7, 0xd9, 0x87, 0xfb,
	0x6f, 0x76, 0xf0, 0xd7, 0xf8, 0x1f, 0xe5, 0xe9,
	0x49, 0xce, 0x25, 0xc8, 0x66, 0x00, 0x19, 0x5f,
	0x82, 0x65, 0x73, 0x4d, 0xae, 0x76, 0x29, 0x9d,
	0x41, 0x58, 0x7c, 0xc0, 0x77, 0xeb, 0xfa, 0xfc
};

unsigned char mac_dst_sha512_128[] = {
	0x1d, 0x5b, 0x32, 0x33, 0x52, 0x39, 0x2b, 0x59,
	0xa6, 0xb8, 0x43, 0xc6, 0xc6, 0x17, 0x7f, 0x54,
	0x2b, 0xb2, 0x11, 0x04, 0x67, 0x98, 0x62, 0xbf,
	0xba, 0x83, 0x5e, 0x79, 0x6d, 0xc8, 0x0f, 0x3e,
	0x2e, 0xd8, 0xab, 0xca, 0x9c, 0x40, 0xd9, 0x41,
	0xcf, 0x12, 0x1a, 0x74, 0x42, 0x99, 0xa4, 0x49,
	0x7e, 0xc5, 0x42, 0x52, 0xc1, 0x8d, 0xaa, 0x09,
	0x7d, 0x09, 0x33, 0x3b, 0xe4, 0x7b, 0xcd, 0x7c
};

unsigned char mac_dst_md5_256[] = {
	0xc9, 0x71, 0x54, 0x48, 0xae, 0x22, 0xfa, 0xb4,
	0x59, 0x70, 0x21, 0xd1, 0x21, 0xbe, 0x3c, 0x9c
};

unsigned char mac_dst_sha1_256[] = {
	0x79, 0x47, 0x30, 0x91, 0x9d, 0xd2, 0x1e, 0xf8,
	0x28, 0x39, 0x26, 0x48, 0xfe, 0xf6, 0xc0, 0xba,
	0xe6, 0xc7, 0x7c, 0x99
};

unsigned char mac_dst_sha224_256[] = {
	0xf1, 0xea, 0xac, 0x00, 0xd6, 0x78, 0x16, 0xd4,
	0xe1, 0x07, 0xfd, 0xa4, 0xcb, 0xd6, 0x90, 0x4e,
	0x18, 0xb2, 0xef, 0x23, 0xbc, 0x57, 0xef, 0xe3,
	0x3e, 0x97, 0x90, 0xc9
};

unsigned char mac_dst_sha256_256[] = {
	0x1d, 0xda, 0x0e, 0x05, 0x11, 0xcb, 0xfd, 0xca,
	0xda, 0x53, 0x38, 0x63, 0x8c, 0x6f, 0xd2, 0xe2,
	0x1a, 0xdb, 0x54, 0xec, 0x4c, 0x04, 0xc0, 0x74,
	0x6d, 0x96, 0xb7, 0x62, 0x56, 0x12, 0x75, 0x94
};

unsigned char mac_dst_sha384_256[] = {
	0x1f, 0x11, 0x53, 0x51, 0xc0, 0xfc, 0x8c, 0x20,
	0xc0, 0xbc, 0x78, 0x19, 0x69, 0xeb, 0x22, 0x83,
	0xc1, 0xd4, 0xb5, 0x4f, 0x36, 0x6d, 0x13, 0x60,
	0x44, 0x45, 0xc5, 0x04, 0xdd, 0x3d, 0x1c, 0xe5,
	0xc9, 0x08, 0x62, 0xda, 0x7f, 0xa4, 0x46, 0x88,
	0x67, 0x8d, 0x0d, 0x1a, 0x6a, 0xa9, 0xcc, 0xd5
};

unsigned char mac_dst_sha512_256[] = {
	0xf6, 0xc7, 0xf6, 0x85, 0x6e, 0xcb, 0x11, 0xb9,
	0x38, 0x55, 0x9d, 0x94, 0x60, 0xce, 0x31, 0x6f,
	0x08, 0x54, 0xec, 0xa0, 0x47, 0x1d, 0x2a, 0x46,
	0xd9, 0x42, 0xa8, 0x09, 0xb2, 0x37, 0x8a, 0x53,
	0x87, 0xcc, 0x7a, 0x1c, 0x95, 0xba, 0x5c, 0xb8,
	0xb0, 0x34, 0x73, 0xad, 0xe3, 0x65, 0x13, 0x31,
	0xaf, 0x21, 0x59, 0xde, 0xaa, 0x07, 0xab, 0x4b,
	0xdf, 0x2c, 0x38, 0xca, 0xfd, 0x82, 0xa7, 0x47
};

/*
 * (Hmac algo, min key size, max key size)
 *
 * TEE_TYPE_HMAC_MD5, 64, 512
 * TEE_TYPE_HMAC_SHA1, 80, 512
 * TEE_TYPE_HMAC_SHA224, 112, 512
 * TEE_TYPE_HMAC_SHA256, 192, 1024
 * TEE_TYPE_HMAC_SHA384, 256, 1024
 * TEE_TYPE_HMAC_SHA512, 256, 1024
 */
struct hash_result mac_result[] = {
	{
		.name = "MD5",
		.algo = AR_CRYPTO_ALG_HMAC_MD5,
		.digest_len = 128,
		.key_len = 128,
		.res = mac_dst_md5_128,
	},

	{
		.name = "SHA1",
		.algo = AR_CRYPTO_ALG_HMAC_SHA1,
		.digest_len = 160,
		.key_len = 128,
		.res = mac_dst_sha1_128,
	},

	{
		.name = "SHA224",
		.algo = AR_CRYPTO_ALG_HMAC_SHA224,
		.digest_len = 224,
		.key_len = 128,
		.res = mac_dst_sha224_128,
	},
#if 0
	/* Fail in optee*/
	{
		.name = "SHA256",
		.algo = AR_CRYPTO_ALG_HMAC_SHA256,
		.digest_len = 256,
		.key_len = 128,
		.res = mac_dst_sha256_128,
	},

	/* Fail in optee*/
	{
		.name = "SHA384",
		.algo = AR_CRYPTO_ALG_HMAC_SHA384,
		.digest_len = 384,
		.key_len = 128,
		.res = mac_dst_sha384_128,
	},

	/* Fail in optee*/
	{
		.name = "SHA512",
		.algo = AR_CRYPTO_ALG_HMAC_SHA512,
		.digest_len = 512,
		.key_len = 128,
		.res = mac_dst_sha512_128,
	},
#endif
	{
		.name = "MD5",
		.algo = AR_CRYPTO_ALG_HMAC_MD5,
		.digest_len = 128,
		.key_len = 256,
		.res = mac_dst_md5_256,
	},

	{
		.name = "SHA1",
		.algo = AR_CRYPTO_ALG_HMAC_SHA1,
		.digest_len = 160,
		.key_len = 256,
		.res = mac_dst_sha1_256,
	},

	{
		.name = "SHA224",
		.algo = AR_CRYPTO_ALG_HMAC_SHA224,
		.digest_len = 224,
		.key_len = 256,
		.res = mac_dst_sha224_256,
	},

	{
		.name = "SHA256",
		.algo = AR_CRYPTO_ALG_HMAC_SHA256,
		.digest_len = 256,
		.key_len = 256,
		.res = mac_dst_sha256_256,
	},

	{
		.name = "SHA384",
		.algo = AR_CRYPTO_ALG_HMAC_SHA384,
		.digest_len = 384,
		.key_len = 256,
		.res = mac_dst_sha384_256,
	},

	{
		.name = "SHA512",
		.algo = AR_CRYPTO_ALG_HMAC_SHA512,
		.digest_len = 512,
		.key_len = 256,
		.res = mac_dst_sha512_256,
	},


	{
	},
};

unsigned char encbuf[512] = {0};
unsigned char decbuf[512] = {0};
unsigned char hashdst[512] = {0};
unsigned char mac_dst[512] = {0};
unsigned char rsaencbuf[512] = {0};
unsigned char rsadecbuf[512] = {0};
unsigned char eccencbuf[512] = {0};
unsigned char eccdecbuf[512] = {0};

void cipher_test(void)
{
	ar_crypto_handle_t handle;
	ar_cipher_ctrl_t ctl = {0};
	int i, ret;
	int out_offs = 0, out_size = sizeof(encbuf);
	struct cipher_result *result = cipher_result;

	while(result->name) {
		printf("cipher test %s\n", result->name);

		out_offs = 0;
		out_size = sizeof(encbuf);

		memset(encbuf, 0, 512);
		memset(decbuf, 0, 512);

		/* encrypt */
		handle = ar_cipher_create();
		if(!handle) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			return;
		}

		ctl.algo = result->algo;
		ctl.mode = AR_MODE_ENCRYPT;
		ctl.ca = result->ca;
		ctl.iv_len = result->iv_len / 8;
		memcpy(ctl.iv, result->iv, result->iv_len / 8);

		if(ctl.ca == AR_CIPHER_CA_USER) {
			ctl.key.user.len1 = result->key_len / 8;
			memcpy(ctl.key.user.key1, result->key1, result->key_len / 8);
			if(result->key2) {
				memcpy(ctl.key.user.key2, result->key2, result->key_len / 8);
				ctl.key.user.len2 = result->key_len / 8;
			}
		}
		else if(ctl.ca == AR_CIPHER_CA_ROOT) {
			memset(ctl.key.root.str1, 0, 32);
			memset(ctl.key.root.str2, 0, 32);
			memset(ctl.key.root.iv, 0, 16);

			sprintf(ctl.key.root.str1, "%s", result->derive_str1);
			sprintf(ctl.key.root.str2, "%s", result->derive_str2);
			sprintf(ctl.key.root.iv, "%s", result->derive_iv);

			ctl.key.root.index = 0;
		}
		else if(ctl.ca == AR_CIPHER_CA_SECU) {
			memcpy(ctl.key.secure.seckey, result->seckey, 256);
			ctl.key.secure.len = result->seckey_len;
			ctl.key.secure.index = result->rsa_idx;
		}
		else if(ctl.ca == AR_CIPHER_CA_FILE) {
			memset(ctl.key.file.obj_id, 0, sizeof(ctl.key.file.obj_id));
			memcpy(ctl.key.file.obj_id, result->obj_id, result->obj_id_len);
			ctl.key.file.obj_len = result->obj_id_len;
			ctl.key.file.flag = result->flags;
			ctl.key.file.attr = result->attrs;
			ctl.key.file.storage_id = result->storage_id;
		}

		ret = ar_cipher_config(handle, &ctl);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_cipher_destroy(handle);
			return;
		}

		if(ctl.ca == AR_CIPHER_CA_SECU) {
			uint8_t id[2] = {01, 02};
			ret = ar_store_op_key(handle, id, 2,
					AR_DATA_FLAG_ACCESS_WRITE, 0, AR_STORAGE_ID_PRIVATE_REE);
			if(ret < 0) {
				printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			}
		}

		ret = ar_cipher_update(handle, AR_MODE_ENCRYPT, result->src1, 32, encbuf + 00, &out_size, 0);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_cipher_destroy(handle);
			return;
		}

		out_offs += out_size;
		out_size = sizeof(encbuf) - out_offs;

		ret = ar_cipher_update(handle, AR_MODE_ENCRYPT, result->src2, 32, encbuf + out_offs, &out_size, 1);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_cipher_destroy(handle);
			return;
		}

		out_offs += out_size;
		out_size = sizeof(encbuf) - out_offs;

		ar_cipher_final(handle);

		ar_cipher_destroy(handle);

		for(i = 0; i < 64; i++) {
			printf("%02x ", encbuf[i]);
			if((i + 1) % 16 == 0)
				printf("\n");
		}
		printf("\n");

		for(i = 0; i < 64; i++) {
			if(encbuf[i] != result->res[i]) {
				printf("<<-----------------enc fail----------------->> %s %d\n", __func__, __LINE__);
				break;
			}
		}
		if(i == 64)
			printf("encrypt success\n");


		/* decrypt */
		handle = ar_cipher_create();
		if(!handle) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			return;
		}

		memset(&ctl, 0 , sizeof(ctl));
		ctl.algo = result->algo;
		ctl.mode = AR_MODE_DECRYPT;
		ctl.ca = result->ca;
		ctl.iv_len = result->iv_len / 8;
		memcpy(ctl.iv, result->iv, result->iv_len / 8);

		if(ctl.ca == AR_CIPHER_CA_USER) {
			memcpy(ctl.key.user.key1, result->key1, result->key_len / 8);
			ctl.key.user.len1 = result->key_len / 8;
			if(result->key2) {
				memcpy(ctl.key.user.key2, result->key2, result->key_len / 8);
				ctl.key.user.len2 = result->key_len / 8;
			}
		}
		else if(ctl.ca == AR_CIPHER_CA_ROOT) {
			memset(ctl.key.root.str1, 0, 32);
			memset(ctl.key.root.str2, 0, 32);
			memset(ctl.key.root.iv, 0, 16);

			sprintf(ctl.key.root.str1, "%s", result->derive_str1);
			sprintf(ctl.key.root.str2, "%s", result->derive_str2);
			sprintf(ctl.key.root.iv, "%s", result->derive_iv);

			ctl.key.root.index = 0;
		}
		else if(ctl.ca == AR_CIPHER_CA_SECU) {
			memcpy(ctl.key.secure.seckey, result->seckey, 256);
			ctl.key.secure.len = result->seckey_len;
			ctl.key.secure.index = result->rsa_idx;
		}
		else if(ctl.ca == AR_CIPHER_CA_FILE) {
			memset(ctl.key.file.obj_id, 0, sizeof(ctl.key.file.obj_id));
			memcpy(ctl.key.file.obj_id, result->obj_id, result->obj_id_len);
			ctl.key.file.obj_len = result->obj_id_len;
			ctl.key.file.flag = result->flags;
			ctl.key.file.attr = result->attrs;
			ctl.key.file.storage_id = result->storage_id;
		}

		ret = ar_cipher_config(handle, &ctl);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_cipher_destroy(handle);
			return;
		}

		out_offs = 0;
		out_size = sizeof(decbuf);

		ret = ar_cipher_update(handle, AR_MODE_DECRYPT, encbuf + 00, 32, decbuf + out_offs, &out_size, 0);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_cipher_destroy(handle);
			return;
		}

		out_offs += out_size;
		out_size = sizeof(decbuf) - out_offs;

		ret = ar_cipher_update(handle, AR_MODE_DECRYPT, encbuf + 32, 32, decbuf + out_offs, &out_size, 1);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_cipher_destroy(handle);
			return;
		}

		out_offs += out_size;
		out_size = sizeof(decbuf) - out_offs;

		ar_cipher_final(handle);

		ar_cipher_destroy(handle);

		for(i = 0; i < 64; i++) {
			if(i < 32) {
				if(decbuf[i] != src1[i]) {
					printf("<<-----------------dec fail----------------->> %s %d\n", __func__, __LINE__);
					break;
				}
			}
			else {
				if(decbuf[i] != src2[i - 32]) {
					printf("<<-----------------dec fail----------------->> %s %d\n", __func__, __LINE__);
					break;
				}
			}

		}
		if(i == 64)
			printf("decrypt success\n\n");

		result++;
	}
}

void hash_test(void)
{
	ar_crypto_handle_t handle;
	ar_hash_ctrl_t ctl;
	int i, ret;
	struct hash_result *result = hash_result;

	while(result->name) {
		printf("Hash %s test\n", result->name);

		/* encrypt */
		handle = ar_hash_create();
		if(!handle) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			return;
		}

		ctl.algo = result->algo;

		ret = ar_hash_config(handle, &ctl);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_hash_destroy(handle);
			return;
		}

		ret = ar_hash_update(handle, hash_src, 32);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_hash_destroy(handle);
			return;
		}

		ret = ar_hash_update(handle, hash_src + 32, 32);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_hash_destroy(handle);
			return;
		}

		ret = ar_hash_final(handle, hashdst, 128);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			ar_hash_destroy(handle);
			return;
		}

		ret = ar_hash_destroy(handle);
		if(ret < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			return;
		}

		for(i = 0; i < result->digest_len / 8; i++) {
			if(hashdst[i] != result->res[i]) {
				printf("<<-----------------Hash %s fail----------------->>\n", result->name);
				break;
			}
		}
		if(i == result->digest_len / 8)
			printf("Hash %s success\n", result->name);

		result++;
	}
}

void rsa_test_genkey_export_import(int keysize)
{
	ar_rsa_keypair_t *key;
	ar_rsa_keypair_t *privkey, *pubkey;
	int ret, i;
	unsigned char out[4096];
	unsigned long size = sizeof(out);

	printf("test generate rsa key, size %d\n", keysize);

	key = ar_rsa_gen_key(keysize);
	if(!key) {
		printf("Generate rsa key fail\n");
		return;
	}

	printf("length of key: n=%d, e=%d, d=%d\n",
		key->n_len, key->e_len, key->d_len);

	printf("n:\n");
	for(i = 0; i < key->n_len; i++) {
		printf("%02x ", key->n[i]);
		if((i + 1) % 16 == 0 || (i + 1) == key->n_len)
			printf("\n");
	}
	printf("e:\n");
	for(i = 0; i < key->e_len; i++) {
		printf("%02x ", key->e[i]);
		if((i + 1) % 16 == 0 || (i + 1) == key->e_len)
			printf("\n");
	}
	printf("d:\n");
	for(i = 0; i < key->d_len; i++) {
		printf("%02x ", key->d[i]);
		if((i + 1) % 16 == 0 || (i + 1) == key->d_len)
			printf("\n");
	}

	printf("test rsa export priv\n");

	ret = ar_rsa_export(key, AR_ASYM_PRIVATE, out, &size);
	if(ret < 0) {
		printf("export rsa key fail\n");
		return;
	}
	printf("success\n");

	printf("test rsa import priv\n");

	privkey = ar_rsa_import(out, size);
	if(!privkey) {
		printf("import rsa key fail\n");
		return;
	}
	printf("success\n");

	printf("length of key: n=%d, e=%d, d=%d\n",
		privkey->n_len, privkey->e_len, privkey->d_len);

	printf("n:\n");
	for(i = 0; i < privkey->n_len; i++) {
		printf("%02x ", privkey->n[i]);
		if((i + 1) % 16 == 0 || (i + 1) == privkey->n_len)
			printf("\n");
	}
	printf("e:\n");
	for(i = 0; i < privkey->e_len; i++) {
		printf("%02x ", privkey->e[i]);
		if((i + 1) % 16 == 0 || (i + 1) == privkey->e_len)
			printf("\n");
	}
	printf("d:\n");
	for(i = 0; i < privkey->d_len; i++) {
		printf("%02x ", privkey->d[i]);
		if((i + 1) % 16 == 0 || (i + 1) == privkey->d_len)
			printf("\n");
	}
	ar_rsa_free_key(privkey);

	/////////////////////////////////////////////////////////////////////////////
	printf("test rsa export pub\n");

	size = sizeof(out);

	ret = ar_rsa_export(key, AR_ASYM_PUBLIC, out, &size);
	if(ret < 0) {
		printf("export rsa key fail\n");
		return;
	}

	printf("test rsa import pub\n");

	pubkey = ar_rsa_import(out, size);
	if(!pubkey) {
		printf("import pub rsa key fail\n");
		return;
	}

	printf("length of key: n=%d, e=%d, d=%d\n",
		pubkey->n_len, pubkey->e_len, pubkey->d_len);

	printf("n:\n");
	for(i = 0; i < pubkey->n_len; i++) {
		printf("%02x ", pubkey->n[i]);
		if((i + 1) % 16 == 0 || (i + 1) == pubkey->n_len)
			printf("\n");
	}
	printf("e:\n");
	for(i = 0; i < pubkey->e_len; i++) {
		printf("%02x ", pubkey->e[i]);
		if((i + 1) % 16 == 0 || (i + 1) == pubkey->e_len)
			printf("\n");
	}
	printf("d:\n");
	for(i = 0; i < pubkey->d_len; i++) {
		printf("%02x ", pubkey->d[i]);
		if((i + 1) % 16 == 0 || (i + 1) == pubkey->d_len)
			printf("\n");
	}
	ar_rsa_free_key(pubkey);
}

void rsa_test_acipher(int keysize, int algo)
{
	ar_rsa_keypair_t *key;
	ar_rsa_keypair_t pubkey;
	int i, res;
	unsigned long out_len = 512;

	printf("Test rsa encrypt and decrypt %d %x\n", keysize, algo);

	key = ar_rsa_gen_key(keysize);
	if(!key) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
		return;
	}
	pubkey.type = AR_ASYM_PUBLIC;
	pubkey.e = key->e;
	pubkey.n = key->n;
	pubkey.e_len = key->e_len;
	pubkey.n_len = key->n_len;

	res = ar_rsa_encrypt(algo,
		&pubkey,
		src1, rsaencbuf,
		32, &out_len);
	if(res < 0) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
		return;
	}

	res = ar_rsa_decrypt(algo,
		key,
		rsaencbuf, rsadecbuf,
		out_len, &out_len);
	if(res < 0) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
		return;
	}

	if(out_len != 32) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
		return;
	}
	for(i = 0; i < out_len; i++) {
		if(rsadecbuf[i] != src1[i]) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			return;
		}
	}
	printf("success\n", keysize);
out:
	ar_rsa_free_key(key);
}

void rsa_test_sign_verify(int keysize, int algo)
{
	ar_rsa_keypair_t *key;
	ar_rsa_keypair_t pubkey;
	int i, res;
	unsigned long out_len = 512;
	ar_crypto_handle_t handle;
	int hash_size = sizeof(hash_src);

	printf("Test rsa sign and verify %d, algo %x\n", keysize, algo);

	key = ar_rsa_gen_key(keysize);
	if(!key) {
		printf("Generate rsa key fail\n");
		return;
	}

	pubkey.type = AR_ASYM_PUBLIC;
	pubkey.e = key->e;
	pubkey.n = key->n;
	pubkey.e_len = key->e_len;
	pubkey.n_len = key->n_len;

	res = ar_rsa_sign(algo,
		key,
		0x10,
		hash_src,
		hash_size,
		rsaencbuf,
		&out_len);
	if(res < 0) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
		return;
	}

	printf("sign success\n");

	res = ar_rsa_verify(algo,
		&pubkey,
		0x10,
		hash_src,
		hash_size,
		rsaencbuf,
		out_len);
	if(res != 0) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
		return;
	}

	printf("verify success\n");
out:
	ar_rsa_free_key(key);
}

void ecc_test_genkey_export_import(int curve)
{
	ar_ecc_keypair_t *key;
	ar_ecc_keypair_t *privkey, *pubkey;
	int ret, i;
	unsigned char out[1024];
	unsigned long size = sizeof(out);

	printf("test ecc gen key %d\n", curve);

	key = ar_ecc_gen_key(curve);
	if(!key) {
		printf("<<-----------------fail----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("success, xlen=%d ylen=%d dlen=%d\n", key->x_len, key->y_len, key->d_len);

	printf("d\n");
	for(i = 0; i < key->d_len; i++) {
		printf("%02x ", key->d[i]);
		if((i + 1) % 16 == 0 || (i + 1) == key->d_len)
			printf("\n");
	}
	printf("\nx\n");
	for(i = 0; i < key->x_len; i++) {
		printf("%02x ", key->x[i]);
		if((i + 1) % 16 == 0 || (i + 1) == key->x_len)
			printf("\n");
	}
	printf("\ny\n");
	for(i = 0; i < key->y_len; i++) {
		printf("%02x ", key->y[i]);
		if((i + 1) % 16 == 0 || (i + 1) == key->y_len)
			printf("\n");
	}
	printf("\n");

	printf("test ecc export private\n");
	ret = ar_ecc_export(key, AR_ASYM_PRIVATE, out, &size);
	if(ret < 0) {
		printf("<<-----------------fail----------------->> %s %d\n", __func__, __LINE__);
	}
	printf("test ecc import private\n");

	privkey = ar_ecc_import(out, size);
	if(!privkey) {
		printf("<<-----------------fail----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("d\n");
	for(i = 0; i < privkey->d_len; i++) {
		printf("%02x ", privkey->d[i]);
		if((i + 1) % 16 == 0 || (i + 1) == privkey->d_len)
			printf("\n");
	}
	printf("\nx\n");
	for(i = 0; i < privkey->x_len; i++) {
		printf("%02x ", privkey->x[i]);
		if((i + 1) % 16 == 0 || (i + 1) == privkey->x_len)
			printf("\n");
	}
	printf("\ny\n");
	for(i = 0; i < privkey->y_len; i++) {
		printf("%02x ", privkey->y[i]);
		if((i + 1) % 16 == 0 || (i + 1) == privkey->y_len)
			printf("\n");
	}
	printf("\n");

	//////////////////////////////////////////////////////////////////
	printf("test ecc export public\n");

	size = sizeof(out);

	ret = ar_ecc_export(key, AR_ASYM_PUBLIC, out, &size);
	if(ret < 0) {
		printf("<<-----------------fail----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("test ecc import public\n");

	pubkey = ar_ecc_import(out, size);
	if(!pubkey) {
		printf("<<-----------------fail----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("d\n");
	for(i = 0; i < pubkey->d_len; i++) {
		printf("%02x ", pubkey->d[i]);
		if((i + 1) % 16 == 0 || (i + 1) == pubkey->d_len)
			printf("\n");
	}
	printf("\nx\n");
	for(i = 0; i < pubkey->x_len; i++) {
		printf("%02x ", pubkey->x[i]);
		if((i + 1) % 16 == 0 || (i + 1) == pubkey->x_len)
			printf("\n");
	}
	printf("\ny\n");
	for(i = 0; i < pubkey->y_len; i++) {
		printf("%02x ", pubkey->y[i]);
		if((i + 1) % 16 == 0 || (i + 1) == pubkey->y_len)
			printf("\n");
	}
	printf("\n");
}

void ecc_test_sign(int ecc_algo, int curve)
{
	ar_ecc_keypair_t *key;
	ar_ecc_keypair_t pubkey;
	int i, res;
	unsigned long out_len = 512;
	int hash_size = sizeof(hash_src);

	printf("Test ecc sign and verify curve %x\n", curve);

	key = ar_ecc_gen_key(curve);
	if(!key) {
		printf("Generate rsa key fail\n");
		return;
	}

	pubkey.type = AR_ASYM_PUBLIC;
	pubkey.x = key->x;
	pubkey.y = key->y;
	pubkey.x_len = key->x_len;
	pubkey.y_len = key->y_len;
	pubkey.curve = key->curve;

	/* get algo from curve in key */
	res = ar_ecc_sign(ecc_algo,
		key,
		hash_src,
		hash_size,
		eccencbuf,
		&out_len);
	if(res < 0) {
		printf("<<-----------------sign fail----------------->> %s %d\n", __func__, __LINE__);
		return;
	}
	printf("sign success\n");

	/* get algo from curve in key */
	res = ar_ecc_verify(ecc_algo,
		&pubkey,
		hash_src,
		hash_size,
		eccencbuf,
		out_len);
	if(res) {
		printf("<<-----------------verify fail----------------->> %s %d\n", __func__, __LINE__);
		return;
	}
	printf("verify success\n");
}

void mac_test(void)
{
	ar_crypto_handle_t handle;
	ar_mac_ctrl_t ctl;
	int i, res;
	struct hash_result *result = mac_result;

	while(result->name) {
		printf("Mac %s test\n", result->name);

		/* encrypt */
		handle = ar_mac_create();
		if(!handle) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			return;
		}

		ctl.algo = result->algo;
		ctl.mode = AR_MODE_DIGEST;
		ctl.ca = AR_CIPHER_CA_USER;
		ctl.key.user.len1 = result->key_len / 8;
		memcpy(ctl.key.user.key1, key1, result->key_len / 8);

		res = ar_mac_config(handle, &ctl);
		if(res < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			goto out;
		}

		res = ar_mac_update(handle, hash_src + 0, 16);
		if(res < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			goto out;
		}

		res = ar_mac_update(handle, hash_src + 16, 16);
		if(res < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			goto out;
		}

		res = ar_mac_update(handle, hash_src + 32, 16);
		if(res < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			goto out;
		}

		res = ar_mac_update(handle, hash_src + 48, 16);
		if(res < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
			goto out;
		}

out:
		res = ar_mac_final(handle, mac_dst, 512);
		if(res < 0) {
			printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
		}

		for(i = 0; i < result->digest_len / 8; i++) {
			if(mac_dst[i] != result->res[i]) {
				printf("<<-----------------fail----------------->> %s %d\n", __func__, __LINE__);
				break;
			}
		}
		if(i == result->digest_len / 8)
			printf("success\n");

		ar_mac_destroy(handle);
		result++;
	}
}

static void prng_test(void)
{
	int i, j, ret;
	unsigned char buf[128];

	for(i = 0; i < 16; i++) {
		printf("prng test %d times\n", i);

		ret = ar_prng_read(buf, 128);
		if(ret < 0)
			break;
		for(j = 0; j < 128; j++) {
			printf("%02x ", buf[j]);
			if((j + 1) % 16 == 0 || (j + 1) == 128)
				printf("\n");
		}
		printf("\n");
	}
}

void test_crypto()
{
	int ret;

	cipher_test();
	hash_test();
	rsa_test_genkey_export_import(1024);
	rsa_test_genkey_export_import(2048);
#if 0
	rsa_test_genkey_export_import(3072);
	rsa_test_genkey_export_import(4096);
#endif
	rsa_test_acipher(512, AR_CRYPTO_ALG_RSA_NOPAD);
	rsa_test_acipher(512, AR_CRYPTO_ALG_RSAES_PKCS1_V1_5);
#if 0
	rsa_test_acipher(512, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA1);/*should fail*/
	rsa_test_acipher(512, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA224);/*should fail*/
	rsa_test_acipher(512, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA256);/*should fail*/
	rsa_test_acipher(512, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA384);/*should fail*/
	rsa_test_acipher(512, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA512);/*should fail*/
#endif
	rsa_test_acipher(1024, AR_CRYPTO_ALG_RSA_NOPAD);
	rsa_test_acipher(1024, AR_CRYPTO_ALG_RSAES_PKCS1_V1_5);
	rsa_test_acipher(1024, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA1);
	rsa_test_acipher(1024, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA224);
	rsa_test_acipher(1024, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA256);
#if 0
	rsa_test_acipher(1024, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA384);/*should fail*/
	rsa_test_acipher(1024, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA512);/*should fail*/
#endif
	rsa_test_acipher(2048, AR_CRYPTO_ALG_RSA_NOPAD);
	rsa_test_acipher(2048, AR_CRYPTO_ALG_RSAES_PKCS1_V1_5);
	rsa_test_acipher(2048, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA1);
	rsa_test_acipher(2048, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA224);
	rsa_test_acipher(2048, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA256);
	rsa_test_acipher(2048, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA384);
	rsa_test_acipher(2048, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA512);

#if 0
	/* Optee max rsa key is 208*/
	rsa_test_acipher(3072, AR_CRYPTO_ALG_RSA_NOPAD);                     /*should fail in optee*/
	rsa_test_acipher(3072, AR_CRYPTO_ALG_RSAES_PKCS1_V1_5);              /*should fail in optee*/
	rsa_test_acipher(3072, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA1);    /*should fail in optee*/
	rsa_test_acipher(3072, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA224);  /*should fail in optee*/
	rsa_test_acipher(3072, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA256);  /*should fail in optee*/
	rsa_test_acipher(3072, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA384);  /*should fail in optee*/
	rsa_test_acipher(3072, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA512);  /*should fail in optee*/
	rsa_test_acipher(4096, AR_CRYPTO_ALG_RSA_NOPAD);                     /*should fail in optee*/
	rsa_test_acipher(4096, AR_CRYPTO_ALG_RSAES_PKCS1_V1_5);              /*should fail in optee*/
	rsa_test_acipher(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5SHA1);     /*should both fail*/
	rsa_test_acipher(4096, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA1);    /*should fail in optee*/
	rsa_test_acipher(4096, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA224);  /*should fail in optee*/
	rsa_test_acipher(4096, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA256);  /*should fail in optee*/
	rsa_test_acipher(4096, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA384);  /*should fail in optee*/
	rsa_test_acipher(4096, AR_CRYPTO_ALG_RSAES_PKCS1_OAEP_MGF1_SHA512);  /*should fail in optee*/
#endif
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5);
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA1);
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA224);
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA256);
#if 0
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA384);/*should fail*/
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA512);/*should fail*/
#endif
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA1);
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA224);
#if 0
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA256);/*should fail*/
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA384);/*should fail*/
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA512);/*should fail*/
	rsa_test_sign_verify(512, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5SHA1);/*should fail*/
#endif
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA1);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA224);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA256);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA384);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA512);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA1);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA224);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA256);
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA384);
#if 0
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA512);/*should fail*/
	rsa_test_sign_verify(1024, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5SHA1);/*should fail*/
#endif
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA1);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA224);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA256);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA384);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA512);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA1);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA224);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA256);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA384);
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA512);
#if 0
	rsa_test_sign_verify(2048, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5SHA1);/*should fail*/
#endif

#if 0
	/* Optee max rsa key is 2048*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5);       /*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA1);      /*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA224);    /*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA256);    /*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA384);    /*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA512);    /*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA1);  /*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA224);/*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA256);/*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA384);/*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA512);/*should fail in optee*/
	rsa_test_sign_verify(3072, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5SHA1);   /*should both fail */
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5);       /*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA1);      /*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA224);    /*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA256);    /*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA384);    /*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_SHA512);    /*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA1);  /*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA224);/*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA256);/*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA384);/*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_PSS_MGF1_SHA512);/*should fail in optee*/
	rsa_test_sign_verify(4096, AR_CRYPTO_ALG_RSASSA_PKCS1_V1_5_MD5SHA1);   /*should fail in optee*/
#endif
	ecc_test_genkey_export_import(AR_CRYPTO_ECC_CURVE_NIST_P192);
	ecc_test_genkey_export_import(AR_CRYPTO_ECC_CURVE_NIST_P224);
	ecc_test_genkey_export_import(AR_CRYPTO_ECC_CURVE_NIST_P256);
	ecc_test_genkey_export_import(AR_CRYPTO_ECC_CURVE_NIST_P384);
	ecc_test_genkey_export_import(AR_CRYPTO_ECC_CURVE_NIST_P521);
	ecc_test_sign(AR_CRYPTO_ALG_ECDSA_P192, AR_CRYPTO_ECC_CURVE_NIST_P192);
	ecc_test_sign(AR_CRYPTO_ALG_ECDSA_P224, AR_CRYPTO_ECC_CURVE_NIST_P224);
	ecc_test_sign(AR_CRYPTO_ALG_ECDSA_P256, AR_CRYPTO_ECC_CURVE_NIST_P256);
	ecc_test_sign(AR_CRYPTO_ALG_ECDSA_P384, AR_CRYPTO_ECC_CURVE_NIST_P384);
	ecc_test_sign(AR_CRYPTO_ALG_ECDSA_P521, AR_CRYPTO_ECC_CURVE_NIST_P521);

	mac_test();

	prng_test();
}

void test_storage1(void)
{
	int ret, handle_1 = 0, handle_2 = 0, outsize = 0;
	int i;
	unsigned char file_id[2] = {01, 02};
	unsigned char data[16];
	unsigned char out[16] = {0};

	printf("test storage 1\n");

	for(i = 0; i < sizeof(data); i++)
		data[i] = i;

	ret = ar_secure_fs_create(file_id, 2,
			AR_DATA_FLAG_ACCESS_WRITE,
			0, data, sizeof(data),
			&handle_1,
			AR_STORAGE_ID_PRIVATE_REE);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("handle1 = %d\n", handle_1);

	ret = ar_secure_fs_close(handle_1);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	ret = ar_secure_fs_open(file_id, 2,
			AR_DATA_FLAG_ACCESS_READ,
			&handle_2,
			AR_STORAGE_ID_PRIVATE_REE);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("handle2 = %d\n", handle_2);

	ret = ar_secure_fs_read(handle_2, out, sizeof(data), &outsize);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}
	printf("out size %d\n", outsize);
	for(i = 0; i < outsize; i++) {
		printf("%02x ", out[i]);
		if((i + 1) % 16 == 0 || (i + 1) == outsize)
			printf("\n");
	}

	ret = ar_secure_fs_seek(handle_2, sizeof(data) / 2,
		AR_DATA_SEEK_SET);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	ret = ar_secure_fs_read(handle_2, out, sizeof(data), &outsize);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("out size %d\n", outsize);
	for(i = 0; i < outsize; i++) {
		printf("%02x ", out[i]);
		if((i + 1) % 16 == 0 || (i + 1) == outsize)
			printf("\n");
	}

	ret = ar_secure_fs_close(handle_2);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	ret = ar_secure_fs_open(file_id, 2,
			AR_DATA_FLAG_ACCESS_READ |
			AR_DATA_FLAG_ACCESS_WRITE,
			&handle_2,
			AR_STORAGE_ID_PRIVATE_REE);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	for(i = 0; i < sizeof(data); i++)
		data[i] = 0xa0 + i;

	ret = ar_secure_fs_write(handle_2, data,
		sizeof(data));
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	ret = ar_secure_fs_seek(handle_2, 0,
		AR_DATA_SEEK_SET);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	ret = ar_secure_fs_read(handle_2, out, sizeof(data), &outsize);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("out size %d\n", outsize);
	for(i = 0; i < outsize; i++) {
		printf("%02x ", out[i]);
		if((i + 1) % 16 == 0 || (i + 1) == outsize)
			printf("\n");
	}

	ret = ar_secure_fs_close(handle_2);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}
}

void test_storage2(void)
{
	int ret;
	int handle;
	unsigned char file_id[2] = {03, 04};
	unsigned char data[16]={0};

	printf("test storage 2\n");

	ret = ar_secure_fs_create(file_id, sizeof(file_id),
			AR_DATA_FLAG_ACCESS_WRITE |
			AR_DATA_FLAG_ACCESS_WRITE_META,
			0, data, sizeof(data),
			&handle,
			AR_STORAGE_ID_PRIVATE_REE);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("handle1 = %d\n", handle);

	ret = ar_secure_fs_unlink(handle);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}
}

void test_storage3(void)
{
	int ret, i;
	int handle;
	unsigned char file_id[2] = {05, 06};
	unsigned char info[256] = {0};
	unsigned char id[256] = {0};

	printf("test storage 3\n");

	ret = ar_secure_fs_alloc_enum(&handle);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	printf("handle = %d\n", handle);

	ret = ar_secure_fs_start_enum(handle, AR_STORAGE_ID_PRIVATE_REE);
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}

	ret = ar_secure_fs_next_enum(handle, info, sizeof(info), id, sizeof(id));
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}
	else {
		printf("info\n");
		for(i = 0; i < sizeof(info); i++) {
			printf("%02x ", info[i]);
			if((i + 1) % 16 == 0 || (i + 1) == sizeof(info))
				printf("\n");
		}
		printf("id\n");
		for(i = 0; i < sizeof(id); i++) {
			printf("%02x ", id[i]);
			if((i + 1) % 16 == 0 || (i + 1) == sizeof(id))
				printf("\n");
		}
	}

	ret = ar_secure_fs_next_enum(handle, info, sizeof(info), id, sizeof(id));
	if(ret) {
		printf("<<-----------------error----------------->> %s %d\n", __func__, __LINE__);
	}
	else {
		printf("info\n");
		for(i = 0; i < sizeof(info); i++) {
			printf("%02x ", info[i]);
			if((i + 1) % 16 == 0 || (i + 1) == sizeof(info))
				printf("\n");
		}
		printf("id\n");
		for(i = 0; i < sizeof(id); i++) {
			printf("%02x ", id[i]);
			if((i + 1) % 16 == 0 || (i + 1) == sizeof(id))
				printf("\n");
		}
	}
}
int main()
{
	ar_crypto_init();
	test_crypto();
	test_storage1();
	test_storage2();
	test_storage3();
	ar_crypto_destroy();
}
