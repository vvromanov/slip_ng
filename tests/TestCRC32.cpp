#include <gtest/gtest.h>
#include "crc32.h"

#define CRC0 ((uint32_t)0x00000000UL)
#define CRC4 ((uint32_t)0x9BE3E0A3UL)
#define CRC5 ((uint32_t)0xCBF53A1CUL)
#define CRC6 ((uint32_t)0x0972D361UL)
#define CRC7 ((uint32_t)0x5003699FUL)
#define CRC8 ((uint32_t)0x9AE0DAAFUL)

#define CRC4_CONT ((uint32_t)0x4741b284UL)
#define CRC5_CONT ((uint32_t)0x6e232d25UL)
#define CRC6_CONT ((uint32_t)0x56d28d7eUL)
#define CRC7_CONT ((uint32_t)0xdd54c434UL)
#define CRC8_CONT ((uint32_t)0xdb69f762UL)

#define CRC_DATA_PREF (const uint8_t*) "ABCDEF"
#define CRC_DATA (const uint8_t*) "12345678"

//Test values checked using zip.exe utility

TEST(CRC32, calc) {
    EXPECT_EQ(CRC0, crc32(0, CRC_DATA, 0));
    EXPECT_EQ(CRC4, crc32(0, CRC_DATA, 4));
    EXPECT_EQ(CRC5, crc32(0, CRC_DATA, 5));
    EXPECT_EQ(CRC6, crc32(0, CRC_DATA, 6));
    EXPECT_EQ(CRC7, crc32(0, CRC_DATA, 7));
    EXPECT_EQ(CRC8, crc32(0, CRC_DATA, 8));
}

TEST(CRC32, calc_continue) {
    uint32_t crc_pref = crc32(0, CRC_DATA_PREF, 6);

    EXPECT_EQ(crc_pref, crc32(crc_pref, CRC_DATA, 0));
    EXPECT_EQ(CRC4_CONT, crc32(crc_pref, CRC_DATA, 4));
    EXPECT_EQ(CRC5_CONT, crc32(crc_pref, CRC_DATA, 5));
    EXPECT_EQ(CRC6_CONT, crc32(crc_pref, CRC_DATA, 6));
    EXPECT_EQ(CRC7_CONT, crc32(crc_pref, CRC_DATA, 7));
    EXPECT_EQ(CRC8_CONT, crc32(crc_pref, CRC_DATA, 8));
}

