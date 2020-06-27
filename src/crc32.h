#ifndef SRC_CRC32_H_
#define SRC_CRC32_H_
#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

uint32_t crc32(uint32_t crc_in, const uint8_t* data, uint32_t len);

#ifdef  __cplusplus
}
#endif

#endif /* SRC_CRC32_H_ */
