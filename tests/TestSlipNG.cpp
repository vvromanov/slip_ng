#include <gtest/gtest.h>
#include "slip_ng.h"

typedef struct {
    sng_packet_header_t hdr;
    uint8_t data[100];
} sng_test_packet_t;

#define PKT_CRC ((uint32_t)0x9AE0DAAFUL) /* CRC32 of 12345678 */

TEST(SlipNG, valid_packet) {
    sng_test_packet_t pkt = {{0}};
    for (int i = 0; i < 8; i++) {
        pkt.data[i] = '1' + i;
    }
    pkt.hdr.data_size = 8;
    EXPECT_EQ(sng_invalid_size, sng_valid_packet ((const uint8_t *) &pkt, sizeof(sng_packet_header_t)-1));
    EXPECT_EQ(sng_invalid_size, sng_valid_packet ((const uint8_t *) &pkt, sizeof(sng_packet_header_t)+1));
    EXPECT_EQ(sng_invalid_signature, sng_valid_packet ((const uint8_t *) &pkt, sizeof(sng_packet_header_t)+pkt.hdr.data_size));
    pkt.hdr.signature = SNG_SIGNATURE;
    EXPECT_EQ(sng_invalid_crc, sng_valid_packet ((const uint8_t *) &pkt, sizeof(sng_packet_header_t)+pkt.hdr.data_size));
    pkt.hdr.crc32 = PKT_CRC;
    EXPECT_EQ(sng_ok, sng_valid_packet ((const uint8_t *) &pkt, sizeof(sng_packet_header_t)+pkt.hdr.data_size));
}
