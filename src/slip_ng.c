#include <stddef.h>
#include "slip_ng.h"
#include <crc32.h>

bool test_function () {
    return true;
}

void slip_ng_process_data (const uint8_t *data, uint16_t data_size) {

}

bool sng_valid_packet (const uint8_t *data, uint16_t data_size) {
    const packet_header_t *hdr = (const packet_header_t *) data;
    if (data == NULL) {
        return false;
    }
    if (data_size < sizeof (packet_header_t)) {
        return false;
    }
}
