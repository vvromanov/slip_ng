#ifndef SLIP_NG_H
#define SLIP_NG_H

#include <stdbool.h>
#include <stdint.h>

#define SNG_SIGNATURE 0x50443031U
#define SNG_SIGNATURE_STR "PD01"

typedef struct {
    uint32_t crc32;
    uint16_t data_size;
    uint32_t signature;
} __attribute__((__packed__)) sng_packet_header_t;

typedef enum {
    sng_ok,
    sng_invalid_signature,
    sng_invalid_size,
    sng_invalid_crc,
} sng_result_t;

#ifdef  __cplusplus
extern "C" {
#endif

bool test_function ();
void sng_process_data(const uint8_t* data, uint16_t data_size);
sng_result_t sng_valid_packet(const uint8_t* data, uint16_t data_size);
#ifdef  __cplusplus
}
#endif
#endif //SLIP_NG_H
