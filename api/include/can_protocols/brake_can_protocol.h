/**
 * @file brake_can_protocol.h
 * @brief Brake CAN Protocol.
 *
 */


#ifndef _OSCC_BRAKE_CAN_PROTOCOL_H_
#define _OSCC_BRAKE_CAN_PROTOCOL_H_


#include <stdint.h>


/*
 * @brief Brake command message (CAN frame) ID.
 *
 */
#define OSCC_BRAKE_COMMAND_CAN_ID (0x60)

/*
 * @brief Brake report message (CAN frame) ID.
 *
 */
#define OSCC_BRAKE_REPORT_CAN_ID (0x61)

/*
 * @brief Brake report message (CAN frame) length.
 *
 */
#define OSCC_BRAKE_REPORT_CAN_DLC (8)

/*
 * @brief Brake report message publishing frequency. [Hz]
 *
 */
#define OSCC_BRAKE_REPORT_PUBLISH_FREQ_IN_HZ (50)

/*
 * @brief Brake DTC bitfield position indicating an invalid sensor value.
 *
 */
#define OSCC_BRAKE_DTC_INVALID_SENSOR_VAL (0x0)


/**
 * @brief Brake command message data.
 *
 * CAN frame ID: \ref OSCC_BRAKE_COMMAND_CAN_ID
 *
 */
typedef struct
{
    uint16_t pedal_command; /*!< Pedal command. [65535 == 100%] */

    uint8_t enable; /*!< Command to enable or disable steering control.
                     * Zero value means disable.
                     * Non-zero value means enable. */

    uint8_t reserved[5]; /*!< Reserved. */
} oscc_brake_command_s;


/**
 * @brief Brake report message data.
 *
 * CAN frame ID: \ref OSCC_BRAKE_REPORT_CAN_ID
 *
 */
typedef struct
{
    uint8_t enabled; /*!< Braking controls enabled state.
                      * Zero value means disabled (commands are ignored).
                      * Non-zero value means enabled (no timeouts or overrides have occured). */

    uint8_t operator_override; /*!< Driver override state.
                                * Zero value means there has been no operator override.
                                * Non-zero value means an operator has physically overridden
                                * the system. */

    uint8_t dtcs; /* Bitfield of DTCs present in the module. */

    int16_t brake_pressure_front_left; /* Brake pressure at front left wheel. */

    int16_t brake_pressure_front_right; /* Brake pressure at front right wheel. */

    uint8_t reserved; /*!< Reserved. */
} oscc_brake_report_s;


#endif /* _OSCC_BRAKE_CAN_PROTOCOL_H_ */
