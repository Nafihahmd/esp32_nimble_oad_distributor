#pragma once

#include <stdint.h>
#include <stddef.h>

/* TI OAD Service */
#define OAD_SERVICE_UUID           0xFFC0

/* Characteristics */
#define OAD_IMAGE_IDENTIFY_UUID    0xFFC1
#define OAD_IMAGE_BLOCK_UUID       0xFFC2
#define OAD_CONTROL_UUID           0xFFC5

// OAD Test
#define TEST_SVC_UUID    BLE_UUID16_DECLARE(0x180D)   // Heart rate
#define TEST_CHR_UUID    BLE_UUID16_DECLARE(0x2A37)   // Heart Rate Measurement Characteristic UUID

static const ble_uuid128_t oad_service_uuid =
    BLE_UUID128_INIT(
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,
        0x00,0x40,0x51,0x04,0xC0,0xFF,0x00,0xF0);

static const ble_uuid128_t oad_img_uuid =
    BLE_UUID128_INIT(
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,
        0x00,0x40,0x51,0x04,0xC1,0xFF,0x00,0xF0);

static const ble_uuid128_t oad_block_uuid =
    BLE_UUID128_INIT(
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,
        0x00,0x40,0x51,0x04,0xC2,0xFF,0x00,0xF0);

static const ble_uuid128_t oad_ctrl_uuid =
    BLE_UUID128_INIT(
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,
        0x00,0x40,0x51,0x04,0xC5,0xFF,0x00,0xF0);

/* OAD states */
typedef enum {
    OAD_STATE_IDLE,
    OAD_STATE_WAIT_BLOCK_SIZE,
    OAD_STATE_WAIT_IMAGE_ACCEPT,
    OAD_STATE_WAIT_BLOCK_REQ,
    OAD_STATE_TRANSFER
} oad_state_t;

static oad_state_t g_oad_state = OAD_STATE_IDLE;

/* OAD COMMANDS */
#define CMD_START_OAD    0x03
#define CMD_FINISH_OAD   0x04

/**************************************************
 * Helper Functions
 **************************************************/
// static void send_image_identify(void);
// static void send_start_oad(void);
// static void send_oad_block(uint32_t block_num);
// static void handle_block_request(uint8_t *data, uint16_t len);

/**************************************************
 * OAD Image
 **************************************************/
extern const uint8_t firmware_bin_start[] asm("_binary_basic_ble_oad_dual_image_v2_bin_start");
extern const uint8_t firmware_bin_end[]   asm("_binary_basic_ble_oad_dual_image_v2_bin_end");

static const uint8_t *g_image_data;
static uint32_t g_image_size;

static uint16_t g_block_size = 0;
static uint32_t g_total_blocks;