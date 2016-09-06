// MESSAGE TEENSY_TEMPERATURE PACKING

#define MAVLINK_MSG_ID_TEENSY_TEMPERATURE 243

typedef struct __mavlink_teensy_temperature_t
{
 uint64_t time_usec; ///< Image timestamp (microseconds since UNIX epoch, according to camera clock)
 uint32_t time_device; ///< Sample Number
 uint16_t temp_1; ///< temperature from sensor 1
 uint16_t temp_2; ///< temperature from sensor 2
 uint16_t temp_3; ///< temperature from sensor 3
 uint16_t temp_4; ///< temperature from sensor 4
 uint16_t temp_5; ///< temperature from sensor 5
 uint16_t temp_6; ///< temperature from sensor 6
 uint16_t temp_7; ///< temperature from sensor 7
 uint16_t temp_8; ///< temperature from sensor 8
 uint16_t temp_9; ///< temperature from sensor 9
 uint16_t temp_10; ///< temperature from sensor 10
 uint16_t temp_11; ///< temperature from sensor 11
 uint16_t temp_12; ///< temperature from sensor 12
 uint16_t temp_13; ///< temperature from sensor 13
 uint16_t temp_14; ///< temperature from sensor 14
 uint16_t temp_15; ///< temperature from sensor 15
 uint16_t temp_16; ///< temperature from sensor 16
} mavlink_teensy_temperature_t;

#define MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN 44
#define MAVLINK_MSG_ID_243_LEN 44

#define MAVLINK_MSG_ID_TEENSY_TEMPERATURE_CRC 225
#define MAVLINK_MSG_ID_243_CRC 225



#define MAVLINK_MESSAGE_INFO_TEENSY_TEMPERATURE { \
	"TEENSY_TEMPERATURE", \
	18, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_teensy_temperature_t, time_usec) }, \
         { "time_device", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_teensy_temperature_t, time_device) }, \
         { "temp_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_teensy_temperature_t, temp_1) }, \
         { "temp_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_teensy_temperature_t, temp_2) }, \
         { "temp_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_teensy_temperature_t, temp_3) }, \
         { "temp_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_teensy_temperature_t, temp_4) }, \
         { "temp_5", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_teensy_temperature_t, temp_5) }, \
         { "temp_6", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_teensy_temperature_t, temp_6) }, \
         { "temp_7", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_teensy_temperature_t, temp_7) }, \
         { "temp_8", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_teensy_temperature_t, temp_8) }, \
         { "temp_9", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_teensy_temperature_t, temp_9) }, \
         { "temp_10", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_teensy_temperature_t, temp_10) }, \
         { "temp_11", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_teensy_temperature_t, temp_11) }, \
         { "temp_12", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_teensy_temperature_t, temp_12) }, \
         { "temp_13", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_teensy_temperature_t, temp_13) }, \
         { "temp_14", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_teensy_temperature_t, temp_14) }, \
         { "temp_15", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_teensy_temperature_t, temp_15) }, \
         { "temp_16", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_teensy_temperature_t, temp_16) }, \
         } \
}


/**
 * @brief Pack a teensy_temperature message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param temp_1 temperature from sensor 1
 * @param temp_2 temperature from sensor 2
 * @param temp_3 temperature from sensor 3
 * @param temp_4 temperature from sensor 4
 * @param temp_5 temperature from sensor 5
 * @param temp_6 temperature from sensor 6
 * @param temp_7 temperature from sensor 7
 * @param temp_8 temperature from sensor 8
 * @param temp_9 temperature from sensor 9
 * @param temp_10 temperature from sensor 10
 * @param temp_11 temperature from sensor 11
 * @param temp_12 temperature from sensor 12
 * @param temp_13 temperature from sensor 13
 * @param temp_14 temperature from sensor 14
 * @param temp_15 temperature from sensor 15
 * @param temp_16 temperature from sensor 16
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_teensy_temperature_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint32_t time_device, uint16_t temp_1, uint16_t temp_2, uint16_t temp_3, uint16_t temp_4, uint16_t temp_5, uint16_t temp_6, uint16_t temp_7, uint16_t temp_8, uint16_t temp_9, uint16_t temp_10, uint16_t temp_11, uint16_t temp_12, uint16_t temp_13, uint16_t temp_14, uint16_t temp_15, uint16_t temp_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, temp_1);
	_mav_put_uint16_t(buf, 14, temp_2);
	_mav_put_uint16_t(buf, 16, temp_3);
	_mav_put_uint16_t(buf, 18, temp_4);
	_mav_put_uint16_t(buf, 20, temp_5);
	_mav_put_uint16_t(buf, 22, temp_6);
	_mav_put_uint16_t(buf, 24, temp_7);
	_mav_put_uint16_t(buf, 26, temp_8);
	_mav_put_uint16_t(buf, 28, temp_9);
	_mav_put_uint16_t(buf, 30, temp_10);
	_mav_put_uint16_t(buf, 32, temp_11);
	_mav_put_uint16_t(buf, 34, temp_12);
	_mav_put_uint16_t(buf, 36, temp_13);
	_mav_put_uint16_t(buf, 38, temp_14);
	_mav_put_uint16_t(buf, 40, temp_15);
	_mav_put_uint16_t(buf, 42, temp_16);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#else
	mavlink_teensy_temperature_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.temp_1 = temp_1;
	packet.temp_2 = temp_2;
	packet.temp_3 = temp_3;
	packet.temp_4 = temp_4;
	packet.temp_5 = temp_5;
	packet.temp_6 = temp_6;
	packet.temp_7 = temp_7;
	packet.temp_8 = temp_8;
	packet.temp_9 = temp_9;
	packet.temp_10 = temp_10;
	packet.temp_11 = temp_11;
	packet.temp_12 = temp_12;
	packet.temp_13 = temp_13;
	packet.temp_14 = temp_14;
	packet.temp_15 = temp_15;
	packet.temp_16 = temp_16;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEENSY_TEMPERATURE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif
}

/**
 * @brief Pack a teensy_temperature message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param temp_1 temperature from sensor 1
 * @param temp_2 temperature from sensor 2
 * @param temp_3 temperature from sensor 3
 * @param temp_4 temperature from sensor 4
 * @param temp_5 temperature from sensor 5
 * @param temp_6 temperature from sensor 6
 * @param temp_7 temperature from sensor 7
 * @param temp_8 temperature from sensor 8
 * @param temp_9 temperature from sensor 9
 * @param temp_10 temperature from sensor 10
 * @param temp_11 temperature from sensor 11
 * @param temp_12 temperature from sensor 12
 * @param temp_13 temperature from sensor 13
 * @param temp_14 temperature from sensor 14
 * @param temp_15 temperature from sensor 15
 * @param temp_16 temperature from sensor 16
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_teensy_temperature_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint32_t time_device,uint16_t temp_1,uint16_t temp_2,uint16_t temp_3,uint16_t temp_4,uint16_t temp_5,uint16_t temp_6,uint16_t temp_7,uint16_t temp_8,uint16_t temp_9,uint16_t temp_10,uint16_t temp_11,uint16_t temp_12,uint16_t temp_13,uint16_t temp_14,uint16_t temp_15,uint16_t temp_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, temp_1);
	_mav_put_uint16_t(buf, 14, temp_2);
	_mav_put_uint16_t(buf, 16, temp_3);
	_mav_put_uint16_t(buf, 18, temp_4);
	_mav_put_uint16_t(buf, 20, temp_5);
	_mav_put_uint16_t(buf, 22, temp_6);
	_mav_put_uint16_t(buf, 24, temp_7);
	_mav_put_uint16_t(buf, 26, temp_8);
	_mav_put_uint16_t(buf, 28, temp_9);
	_mav_put_uint16_t(buf, 30, temp_10);
	_mav_put_uint16_t(buf, 32, temp_11);
	_mav_put_uint16_t(buf, 34, temp_12);
	_mav_put_uint16_t(buf, 36, temp_13);
	_mav_put_uint16_t(buf, 38, temp_14);
	_mav_put_uint16_t(buf, 40, temp_15);
	_mav_put_uint16_t(buf, 42, temp_16);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#else
	mavlink_teensy_temperature_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.temp_1 = temp_1;
	packet.temp_2 = temp_2;
	packet.temp_3 = temp_3;
	packet.temp_4 = temp_4;
	packet.temp_5 = temp_5;
	packet.temp_6 = temp_6;
	packet.temp_7 = temp_7;
	packet.temp_8 = temp_8;
	packet.temp_9 = temp_9;
	packet.temp_10 = temp_10;
	packet.temp_11 = temp_11;
	packet.temp_12 = temp_12;
	packet.temp_13 = temp_13;
	packet.temp_14 = temp_14;
	packet.temp_15 = temp_15;
	packet.temp_16 = temp_16;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEENSY_TEMPERATURE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif
}

/**
 * @brief Encode a teensy_temperature struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param teensy_temperature C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_teensy_temperature_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_teensy_temperature_t* teensy_temperature)
{
	return mavlink_msg_teensy_temperature_pack(system_id, component_id, msg, teensy_temperature->time_usec, teensy_temperature->time_device, teensy_temperature->temp_1, teensy_temperature->temp_2, teensy_temperature->temp_3, teensy_temperature->temp_4, teensy_temperature->temp_5, teensy_temperature->temp_6, teensy_temperature->temp_7, teensy_temperature->temp_8, teensy_temperature->temp_9, teensy_temperature->temp_10, teensy_temperature->temp_11, teensy_temperature->temp_12, teensy_temperature->temp_13, teensy_temperature->temp_14, teensy_temperature->temp_15, teensy_temperature->temp_16);
}

/**
 * @brief Encode a teensy_temperature struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param teensy_temperature C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_teensy_temperature_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_teensy_temperature_t* teensy_temperature)
{
	return mavlink_msg_teensy_temperature_pack_chan(system_id, component_id, chan, msg, teensy_temperature->time_usec, teensy_temperature->time_device, teensy_temperature->temp_1, teensy_temperature->temp_2, teensy_temperature->temp_3, teensy_temperature->temp_4, teensy_temperature->temp_5, teensy_temperature->temp_6, teensy_temperature->temp_7, teensy_temperature->temp_8, teensy_temperature->temp_9, teensy_temperature->temp_10, teensy_temperature->temp_11, teensy_temperature->temp_12, teensy_temperature->temp_13, teensy_temperature->temp_14, teensy_temperature->temp_15, teensy_temperature->temp_16);
}

/**
 * @brief Send a teensy_temperature message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param temp_1 temperature from sensor 1
 * @param temp_2 temperature from sensor 2
 * @param temp_3 temperature from sensor 3
 * @param temp_4 temperature from sensor 4
 * @param temp_5 temperature from sensor 5
 * @param temp_6 temperature from sensor 6
 * @param temp_7 temperature from sensor 7
 * @param temp_8 temperature from sensor 8
 * @param temp_9 temperature from sensor 9
 * @param temp_10 temperature from sensor 10
 * @param temp_11 temperature from sensor 11
 * @param temp_12 temperature from sensor 12
 * @param temp_13 temperature from sensor 13
 * @param temp_14 temperature from sensor 14
 * @param temp_15 temperature from sensor 15
 * @param temp_16 temperature from sensor 16
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_teensy_temperature_send(mavlink_channel_t chan, uint64_t time_usec, uint32_t time_device, uint16_t temp_1, uint16_t temp_2, uint16_t temp_3, uint16_t temp_4, uint16_t temp_5, uint16_t temp_6, uint16_t temp_7, uint16_t temp_8, uint16_t temp_9, uint16_t temp_10, uint16_t temp_11, uint16_t temp_12, uint16_t temp_13, uint16_t temp_14, uint16_t temp_15, uint16_t temp_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, temp_1);
	_mav_put_uint16_t(buf, 14, temp_2);
	_mav_put_uint16_t(buf, 16, temp_3);
	_mav_put_uint16_t(buf, 18, temp_4);
	_mav_put_uint16_t(buf, 20, temp_5);
	_mav_put_uint16_t(buf, 22, temp_6);
	_mav_put_uint16_t(buf, 24, temp_7);
	_mav_put_uint16_t(buf, 26, temp_8);
	_mav_put_uint16_t(buf, 28, temp_9);
	_mav_put_uint16_t(buf, 30, temp_10);
	_mav_put_uint16_t(buf, 32, temp_11);
	_mav_put_uint16_t(buf, 34, temp_12);
	_mav_put_uint16_t(buf, 36, temp_13);
	_mav_put_uint16_t(buf, 38, temp_14);
	_mav_put_uint16_t(buf, 40, temp_15);
	_mav_put_uint16_t(buf, 42, temp_16);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE, buf, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE, buf, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif
#else
	mavlink_teensy_temperature_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.temp_1 = temp_1;
	packet.temp_2 = temp_2;
	packet.temp_3 = temp_3;
	packet.temp_4 = temp_4;
	packet.temp_5 = temp_5;
	packet.temp_6 = temp_6;
	packet.temp_7 = temp_7;
	packet.temp_8 = temp_8;
	packet.temp_9 = temp_9;
	packet.temp_10 = temp_10;
	packet.temp_11 = temp_11;
	packet.temp_12 = temp_12;
	packet.temp_13 = temp_13;
	packet.temp_14 = temp_14;
	packet.temp_15 = temp_15;
	packet.temp_16 = temp_16;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE, (const char *)&packet, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE, (const char *)&packet, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_teensy_temperature_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint32_t time_device, uint16_t temp_1, uint16_t temp_2, uint16_t temp_3, uint16_t temp_4, uint16_t temp_5, uint16_t temp_6, uint16_t temp_7, uint16_t temp_8, uint16_t temp_9, uint16_t temp_10, uint16_t temp_11, uint16_t temp_12, uint16_t temp_13, uint16_t temp_14, uint16_t temp_15, uint16_t temp_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, temp_1);
	_mav_put_uint16_t(buf, 14, temp_2);
	_mav_put_uint16_t(buf, 16, temp_3);
	_mav_put_uint16_t(buf, 18, temp_4);
	_mav_put_uint16_t(buf, 20, temp_5);
	_mav_put_uint16_t(buf, 22, temp_6);
	_mav_put_uint16_t(buf, 24, temp_7);
	_mav_put_uint16_t(buf, 26, temp_8);
	_mav_put_uint16_t(buf, 28, temp_9);
	_mav_put_uint16_t(buf, 30, temp_10);
	_mav_put_uint16_t(buf, 32, temp_11);
	_mav_put_uint16_t(buf, 34, temp_12);
	_mav_put_uint16_t(buf, 36, temp_13);
	_mav_put_uint16_t(buf, 38, temp_14);
	_mav_put_uint16_t(buf, 40, temp_15);
	_mav_put_uint16_t(buf, 42, temp_16);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE, buf, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE, buf, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif
#else
	mavlink_teensy_temperature_t *packet = (mavlink_teensy_temperature_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->time_device = time_device;
	packet->temp_1 = temp_1;
	packet->temp_2 = temp_2;
	packet->temp_3 = temp_3;
	packet->temp_4 = temp_4;
	packet->temp_5 = temp_5;
	packet->temp_6 = temp_6;
	packet->temp_7 = temp_7;
	packet->temp_8 = temp_8;
	packet->temp_9 = temp_9;
	packet->temp_10 = temp_10;
	packet->temp_11 = temp_11;
	packet->temp_12 = temp_12;
	packet->temp_13 = temp_13;
	packet->temp_14 = temp_14;
	packet->temp_15 = temp_15;
	packet->temp_16 = temp_16;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE, (const char *)packet, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_TEMPERATURE, (const char *)packet, MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE TEENSY_TEMPERATURE UNPACKING


/**
 * @brief Get field time_usec from teensy_temperature message
 *
 * @return Image timestamp (microseconds since UNIX epoch, according to camera clock)
 */
static inline uint64_t mavlink_msg_teensy_temperature_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_device from teensy_temperature message
 *
 * @return Sample Number
 */
static inline uint32_t mavlink_msg_teensy_temperature_get_time_device(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field temp_1 from teensy_temperature message
 *
 * @return temperature from sensor 1
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field temp_2 from teensy_temperature message
 *
 * @return temperature from sensor 2
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field temp_3 from teensy_temperature message
 *
 * @return temperature from sensor 3
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field temp_4 from teensy_temperature message
 *
 * @return temperature from sensor 4
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field temp_5 from teensy_temperature message
 *
 * @return temperature from sensor 5
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field temp_6 from teensy_temperature message
 *
 * @return temperature from sensor 6
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field temp_7 from teensy_temperature message
 *
 * @return temperature from sensor 7
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_7(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field temp_8 from teensy_temperature message
 *
 * @return temperature from sensor 8
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_8(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field temp_9 from teensy_temperature message
 *
 * @return temperature from sensor 9
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_9(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field temp_10 from teensy_temperature message
 *
 * @return temperature from sensor 10
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_10(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field temp_11 from teensy_temperature message
 *
 * @return temperature from sensor 11
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_11(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field temp_12 from teensy_temperature message
 *
 * @return temperature from sensor 12
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_12(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field temp_13 from teensy_temperature message
 *
 * @return temperature from sensor 13
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_13(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field temp_14 from teensy_temperature message
 *
 * @return temperature from sensor 14
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_14(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field temp_15 from teensy_temperature message
 *
 * @return temperature from sensor 15
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_15(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field temp_16 from teensy_temperature message
 *
 * @return temperature from sensor 16
 */
static inline uint16_t mavlink_msg_teensy_temperature_get_temp_16(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Decode a teensy_temperature message into a struct
 *
 * @param msg The message to decode
 * @param teensy_temperature C-struct to decode the message contents into
 */
static inline void mavlink_msg_teensy_temperature_decode(const mavlink_message_t* msg, mavlink_teensy_temperature_t* teensy_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP
	teensy_temperature->time_usec = mavlink_msg_teensy_temperature_get_time_usec(msg);
	teensy_temperature->time_device = mavlink_msg_teensy_temperature_get_time_device(msg);
	teensy_temperature->temp_1 = mavlink_msg_teensy_temperature_get_temp_1(msg);
	teensy_temperature->temp_2 = mavlink_msg_teensy_temperature_get_temp_2(msg);
	teensy_temperature->temp_3 = mavlink_msg_teensy_temperature_get_temp_3(msg);
	teensy_temperature->temp_4 = mavlink_msg_teensy_temperature_get_temp_4(msg);
	teensy_temperature->temp_5 = mavlink_msg_teensy_temperature_get_temp_5(msg);
	teensy_temperature->temp_6 = mavlink_msg_teensy_temperature_get_temp_6(msg);
	teensy_temperature->temp_7 = mavlink_msg_teensy_temperature_get_temp_7(msg);
	teensy_temperature->temp_8 = mavlink_msg_teensy_temperature_get_temp_8(msg);
	teensy_temperature->temp_9 = mavlink_msg_teensy_temperature_get_temp_9(msg);
	teensy_temperature->temp_10 = mavlink_msg_teensy_temperature_get_temp_10(msg);
	teensy_temperature->temp_11 = mavlink_msg_teensy_temperature_get_temp_11(msg);
	teensy_temperature->temp_12 = mavlink_msg_teensy_temperature_get_temp_12(msg);
	teensy_temperature->temp_13 = mavlink_msg_teensy_temperature_get_temp_13(msg);
	teensy_temperature->temp_14 = mavlink_msg_teensy_temperature_get_temp_14(msg);
	teensy_temperature->temp_15 = mavlink_msg_teensy_temperature_get_temp_15(msg);
	teensy_temperature->temp_16 = mavlink_msg_teensy_temperature_get_temp_16(msg);
#else
	memcpy(teensy_temperature, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TEENSY_TEMPERATURE_LEN);
#endif
}
