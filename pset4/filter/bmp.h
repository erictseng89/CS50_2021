// BMP-related data types based on Microsoft's own

#include <stdint.h>

/**
 * Common Data Types
 *
 * The data types in this section are essentially aliases for C/C++
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE; // 1B
typedef uint32_t DWORD; // 4B
typedef int32_t  LONG; // 4B
typedef uint16_t WORD; // 2B

/**
 * BITMAPFILEHEADER
 *
 * The BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
 */
typedef struct
{
    WORD   bfType; // 2B
    DWORD  bfSize; // 4B
    WORD   bfReserved1; // 2B
    WORD   bfReserved2; // 2B
    DWORD  bfOffBits; // 4B
} __attribute__((__packed__))
BITMAPFILEHEADER; // Total 14B

/**
 * BITMAPINFOHEADER
 *
 * The BITMAPINFOHEADER structure contains information about the
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
 */
typedef struct
{
    DWORD  biSize; // 4B
    LONG   biWidth; // 4B
    LONG   biHeight; // 4B
    WORD   biPlanes; // 2B
    WORD   biBitCount; // 2B
    DWORD  biCompression; // 4B
    DWORD  biSizeImage; // 4B
    LONG   biXPelsPerMeter; // 4B
    LONG   biYPelsPerMeter; // 4B
    DWORD  biClrUsed; // 4B
    DWORD  biClrImportant; // 4B
} __attribute__((__packed__))
BITMAPINFOHEADER; // Total 40B

/**
 * RGBTRIPLE
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.
 */
typedef struct
{
    BYTE  rgbtBlue; // 1B
    BYTE  rgbtGreen; // 1B
    BYTE  rgbtRed; // 1B
} __attribute__((__packed__))
RGBTRIPLE; // Total 3B
