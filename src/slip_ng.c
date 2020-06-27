#include <stddef.h>
#include "slip_ng.h"
#include <crc32.h>
#include <assert.h>

bool test_function () {
    return true;
}

void slip_ng_process_data (const uint8_t *data, uint16_t data_size) {

}

sng_result_t sng_valid_packet (const uint8_t *data, uint16_t data_size) {
    const sng_packet_header_t *hdr = (const sng_packet_header_t *) data;
    assert(data != NULL);

    if (data_size < sizeof (sng_packet_header_t)) {
        return sng_invalid_size;
    }

    if (data_size < (hdr->data_size+sizeof(sng_packet_header_t))) {
        return sng_invalid_size;
    }

    if (hdr->signature != SNG_SIGNATURE) {
        return sng_invalid_signature;
    }

    if (crc32 (0, data + sizeof (sng_packet_header_t), hdr->data_size) != hdr->crc32) {
        return sng_invalid_crc;
    }
    return sng_ok;
}
