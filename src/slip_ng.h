#ifndef SLIP_NG_H
#define SLIP_NG_H

#include <stdbool.h>
#include <stdint.h>

#define PD_SIGNATURE 0x50443031U
#define PD_SIGNATURE_STR "PD01"

typedef struct {
    uint32_t crc32;
    uint16_t size;
    uint8_t signature[4U];
} __attribute__((__packed__)) packet_header_t;

#ifdef  __cplusplus
extern "C" {
#endif

bool test_function ();
void sng_process_data(const uint8_t* data, uint16_t data_size);
bool sng_valid_packet(const uint8_t* data, uint16_t data_size);
#ifdef  __cplusplus
}
#endif
#endif //SLIP_NG_H
