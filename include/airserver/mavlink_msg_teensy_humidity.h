// MESSAGE TEENSY_HUMIDITY PACKING

#define MAVLINK_MSG_ID_TEENSY_HUMIDITY 245

typedef struct __mavlink_teensy_humidity_t
{
 uint64_t time_usec; ///< Image timestamp (microseconds since UNIX epoch, according to camera clock)
 uint32_t time_device; ///< Sample Number
 uint16_t humid_1; ///< humidity from sensor 1
 uint16_t humid_2; ///< humidity from sensor 2
 uint16_t humid_3; ///< humidity from sensor 3
 uint16_t humid_4; ///< humidity from sensor 4
 uint16_t humid_5; ///< humidity from sensor 5
 uint16_t humid_6; ///< humidity from sensor 6
 uint16_t humid_7; ///< humidity from sensor 7
 uint16_t humid_8; ///< humidity from sensor 8
 uint16_t humid_9; ///< humidity from sensor 9
 uint16_t humid_10; ///< humidity from sensor 10
 uint16_t humid_11; ///< humidity from sensor 11
 uint16_t humid_12; ///< humidity from sensor 12
 uint16_t humid_13; ///< humidity from sensor 13
 uint16_t humid_14; ///< humidity from sensor 14
 uint16_t humid_15; ///< humidity from sensor 15
 uint16_t humid_16; ///< humidity from sensor 16
} mavlink_teensy_humidity_t;

#define MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN 44
#define MAVLINK_MSG_ID_245_LEN 44

#define MAVLINK_MSG_ID_TEENSY_HUMIDITY_CRC 60
#define MAVLINK_MSG_ID_245_CRC 60



#define MAVLINK_MESSAGE_INFO_TEENSY_HUMIDITY { \
	"TEENSY_HUMIDITY", \
	18, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_teensy_humidity_t, time_usec) }, \
         { "time_device", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_teensy_humidity_t, time_device) }, \
         { "humid_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_teensy_humidity_t, humid_1) }, \
         { "humid_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_teensy_humidity_t, humid_2) }, \
         { "humid_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_teensy_humidity_t, humid_3) }, \
         { "humid_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_teensy_humidity_t, humid_4) }, \
         { "humid_5", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_teensy_humidity_t, humid_5) }, \
         { "humid_6", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_teensy_humidity_t, humid_6) }, \
         { "humid_7", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_teensy_humidity_t, humid_7) }, \
         { "humid_8", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_teensy_humidity_t, humid_8) }, \
         { "humid_9", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_teensy_humidity_t, humid_9) }, \
         { "humid_10", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_teensy_humidity_t, humid_10) }, \
         { "humid_11", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_teensy_humidity_t, humid_11) }, \
         { "humid_12", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_teensy_humidity_t, humid_12) }, \
         { "humid_13", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_teensy_humidity_t, humid_13) }, \
         { "humid_14", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_teensy_humidity_t, humid_14) }, \
         { "humid_15", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_teensy_humidity_t, humid_15) }, \
         { "humid_16", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_teensy_humidity_t, humid_16) }, \
         } \
}


/**
 * @brief Pack a teensy_humidity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param humid_1 humidity from sensor 1
 * @param humid_2 humidity from sensor 2
 * @param humid_3 humidity from sensor 3
 * @param humid_4 humidity from sensor 4
 * @param humid_5 humidity from sensor 5
 * @param humid_6 humidity from sensor 6
 * @param humid_7 humidity from sensor 7
 * @param humid_8 humidity from sensor 8
 * @param humid_9 humidity from sensor 9
 * @param humid_10 humidity from sensor 10
 * @param humid_11 humidity from sensor 11
 * @param humid_12 humidity from sensor 12
 * @param humid_13 humidity from sensor 13
 * @param humid_14 humidity from sensor 14
 * @param humid_15 humidity from sensor 15
 * @param humid_16 humidity from sensor 16
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_teensy_humidity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint32_t time_device, uint16_t humid_1, uint16_t humid_2, uint16_t humid_3, uint16_t humid_4, uint16_t humid_5, uint16_t humid_6, uint16_t humid_7, uint16_t humid_8, uint16_t humid_9, uint16_t humid_10, uint16_t humid_11, uint16_t humid_12, uint16_t humid_13, uint16_t humid_14, uint16_t humid_15, uint16_t humid_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, humid_1);
	_mav_put_uint16_t(buf, 14, humid_2);
	_mav_put_uint16_t(buf, 16, humid_3);
	_mav_put_uint16_t(buf, 18, humid_4);
	_mav_put_uint16_t(buf, 20, humid_5);
	_mav_put_uint16_t(buf, 22, humid_6);
	_mav_put_uint16_t(buf, 24, humid_7);
	_mav_put_uint16_t(buf, 26, humid_8);
	_mav_put_uint16_t(buf, 28, humid_9);
	_mav_put_uint16_t(buf, 30, humid_10);
	_mav_put_uint16_t(buf, 32, humid_11);
	_mav_put_uint16_t(buf, 34, humid_12);
	_mav_put_uint16_t(buf, 36, humid_13);
	_mav_put_uint16_t(buf, 38, humid_14);
	_mav_put_uint16_t(buf, 40, humid_15);
	_mav_put_uint16_t(buf, 42, humid_16);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#else
	mavlink_teensy_humidity_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.humid_1 = humid_1;
	packet.humid_2 = humid_2;
	packet.humid_3 = humid_3;
	packet.humid_4 = humid_4;
	packet.humid_5 = humid_5;
	packet.humid_6 = humid_6;
	packet.humid_7 = humid_7;
	packet.humid_8 = humid_8;
	packet.humid_9 = humid_9;
	packet.humid_10 = humid_10;
	packet.humid_11 = humid_11;
	packet.humid_12 = humid_12;
	packet.humid_13 = humid_13;
	packet.humid_14 = humid_14;
	packet.humid_15 = humid_15;
	packet.humid_16 = humid_16;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEENSY_HUMIDITY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN, MAVLINK_MSG_ID_TEENSY_HUMIDITY_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif
}

/**
 * @brief Pack a teensy_humidity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param humid_1 humidity from sensor 1
 * @param humid_2 humidity from sensor 2
 * @param humid_3 humidity from sensor 3
 * @param humid_4 humidity from sensor 4
 * @param humid_5 humidity from sensor 5
 * @param humid_6 humidity from sensor 6
 * @param humid_7 humidity from sensor 7
 * @param humid_8 humidity from sensor 8
 * @param humid_9 humidity from sensor 9
 * @param humid_10 humidity from sensor 10
 * @param humid_11 humidity from sensor 11
 * @param humid_12 humidity from sensor 12
 * @param humid_13 humidity from sensor 13
 * @param humid_14 humidity from sensor 14
 * @param humid_15 humidity from sensor 15
 * @param humid_16 humidity from sensor 16
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_teensy_humidity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint32_t time_device,uint16_t humid_1,uint16_t humid_2,uint16_t humid_3,uint16_t humid_4,uint16_t humid_5,uint16_t humid_6,uint16_t humid_7,uint16_t humid_8,uint16_t humid_9,uint16_t humid_10,uint16_t humid_11,uint16_t humid_12,uint16_t humid_13,uint16_t humid_14,uint16_t humid_15,uint16_t humid_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, humid_1);
	_mav_put_uint16_t(buf, 14, humid_2);
	_mav_put_uint16_t(buf, 16, humid_3);
	_mav_put_uint16_t(buf, 18, humid_4);
	_mav_put_uint16_t(buf, 20, humid_5);
	_mav_put_uint16_t(buf, 22, humid_6);
	_mav_put_uint16_t(buf, 24, humid_7);
	_mav_put_uint16_t(buf, 26, humid_8);
	_mav_put_uint16_t(buf, 28, humid_9);
	_mav_put_uint16_t(buf, 30, humid_10);
	_mav_put_uint16_t(buf, 32, humid_11);
	_mav_put_uint16_t(buf, 34, humid_12);
	_mav_put_uint16_t(buf, 36, humid_13);
	_mav_put_uint16_t(buf, 38, humid_14);
	_mav_put_uint16_t(buf, 40, humid_15);
	_mav_put_uint16_t(buf, 42, humid_16);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#else
	mavlink_teensy_humidity_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.humid_1 = humid_1;
	packet.humid_2 = humid_2;
	packet.humid_3 = humid_3;
	packet.humid_4 = humid_4;
	packet.humid_5 = humid_5;
	packet.humid_6 = humid_6;
	packet.humid_7 = humid_7;
	packet.humid_8 = humid_8;
	packet.humid_9 = humid_9;
	packet.humid_10 = humid_10;
	packet.humid_11 = humid_11;
	packet.humid_12 = humid_12;
	packet.humid_13 = humid_13;
	packet.humid_14 = humid_14;
	packet.humid_15 = humid_15;
	packet.humid_16 = humid_16;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEENSY_HUMIDITY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN, MAVLINK_MSG_ID_TEENSY_HUMIDITY_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif
}

/**
 * @brief Encode a teensy_humidity struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param teensy_humidity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_teensy_humidity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_teensy_humidity_t* teensy_humidity)
{
	return mavlink_msg_teensy_humidity_pack(system_id, component_id, msg, teensy_humidity->time_usec, teensy_humidity->time_device, teensy_humidity->humid_1, teensy_humidity->humid_2, teensy_humidity->humid_3, teensy_humidity->humid_4, teensy_humidity->humid_5, teensy_humidity->humid_6, teensy_humidity->humid_7, teensy_humidity->humid_8, teensy_humidity->humid_9, teensy_humidity->humid_10, teensy_humidity->humid_11, teensy_humidity->humid_12, teensy_humidity->humid_13, teensy_humidity->humid_14, teensy_humidity->humid_15, teensy_humidity->humid_16);
}

/**
 * @brief Encode a teensy_humidity struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param teensy_humidity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_teensy_humidity_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_teensy_humidity_t* teensy_humidity)
{
	return mavlink_msg_teensy_humidity_pack_chan(system_id, component_id, chan, msg, teensy_humidity->time_usec, teensy_humidity->time_device, teensy_humidity->humid_1, teensy_humidity->humid_2, teensy_humidity->humid_3, teensy_humidity->humid_4, teensy_humidity->humid_5, teensy_humidity->humid_6, teensy_humidity->humid_7, teensy_humidity->humid_8, teensy_humidity->humid_9, teensy_humidity->humid_10, teensy_humidity->humid_11, teensy_humidity->humid_12, teensy_humidity->humid_13, teensy_humidity->humid_14, teensy_humidity->humid_15, teensy_humidity->humid_16);
}

/**
 * @brief Send a teensy_humidity message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param humid_1 humidity from sensor 1
 * @param humid_2 humidity from sensor 2
 * @param humid_3 humidity from sensor 3
 * @param humid_4 humidity from sensor 4
 * @param humid_5 humidity from sensor 5
 * @param humid_6 humidity from sensor 6
 * @param humid_7 humidity from sensor 7
 * @param humid_8 humidity from sensor 8
 * @param humid_9 humidity from sensor 9
 * @param humid_10 humidity from sensor 10
 * @param humid_11 humidity from sensor 11
 * @param humid_12 humidity from sensor 12
 * @param humid_13 humidity from sensor 13
 * @param humid_14 humidity from sensor 14
 * @param humid_15 humidity from sensor 15
 * @param humid_16 humidity from sensor 16
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_teensy_humidity_send(mavlink_channel_t chan, uint64_t time_usec, uint32_t time_device, uint16_t humid_1, uint16_t humid_2, uint16_t humid_3, uint16_t humid_4, uint16_t humid_5, uint16_t humid_6, uint16_t humid_7, uint16_t humid_8, uint16_t humid_9, uint16_t humid_10, uint16_t humid_11, uint16_t humid_12, uint16_t humid_13, uint16_t humid_14, uint16_t humid_15, uint16_t humid_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, humid_1);
	_mav_put_uint16_t(buf, 14, humid_2);
	_mav_put_uint16_t(buf, 16, humid_3);
	_mav_put_uint16_t(buf, 18, humid_4);
	_mav_put_uint16_t(buf, 20, humid_5);
	_mav_put_uint16_t(buf, 22, humid_6);
	_mav_put_uint16_t(buf, 24, humid_7);
	_mav_put_uint16_t(buf, 26, humid_8);
	_mav_put_uint16_t(buf, 28, humid_9);
	_mav_put_uint16_t(buf, 30, humid_10);
	_mav_put_uint16_t(buf, 32, humid_11);
	_mav_put_uint16_t(buf, 34, humid_12);
	_mav_put_uint16_t(buf, 36, humid_13);
	_mav_put_uint16_t(buf, 38, humid_14);
	_mav_put_uint16_t(buf, 40, humid_15);
	_mav_put_uint16_t(buf, 42, humid_16);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY, buf, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN, MAVLINK_MSG_ID_TEENSY_HUMIDITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY, buf, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif
#else
	mavlink_teensy_humidity_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.humid_1 = humid_1;
	packet.humid_2 = humid_2;
	packet.humid_3 = humid_3;
	packet.humid_4 = humid_4;
	packet.humid_5 = humid_5;
	packet.humid_6 = humid_6;
	packet.humid_7 = humid_7;
	packet.humid_8 = humid_8;
	packet.humid_9 = humid_9;
	packet.humid_10 = humid_10;
	packet.humid_11 = humid_11;
	packet.humid_12 = humid_12;
	packet.humid_13 = humid_13;
	packet.humid_14 = humid_14;
	packet.humid_15 = humid_15;
	packet.humid_16 = humid_16;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY, (const char *)&packet, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN, MAVLINK_MSG_ID_TEENSY_HUMIDITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY, (const char *)&packet, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_teensy_humidity_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint32_t time_device, uint16_t humid_1, uint16_t humid_2, uint16_t humid_3, uint16_t humid_4, uint16_t humid_5, uint16_t humid_6, uint16_t humid_7, uint16_t humid_8, uint16_t humid_9, uint16_t humid_10, uint16_t humid_11, uint16_t humid_12, uint16_t humid_13, uint16_t humid_14, uint16_t humid_15, uint16_t humid_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, humid_1);
	_mav_put_uint16_t(buf, 14, humid_2);
	_mav_put_uint16_t(buf, 16, humid_3);
	_mav_put_uint16_t(buf, 18, humid_4);
	_mav_put_uint16_t(buf, 20, humid_5);
	_mav_put_uint16_t(buf, 22, humid_6);
	_mav_put_uint16_t(buf, 24, humid_7);
	_mav_put_uint16_t(buf, 26, humid_8);
	_mav_put_uint16_t(buf, 28, humid_9);
	_mav_put_uint16_t(buf, 30, humid_10);
	_mav_put_uint16_t(buf, 32, humid_11);
	_mav_put_uint16_t(buf, 34, humid_12);
	_mav_put_uint16_t(buf, 36, humid_13);
	_mav_put_uint16_t(buf, 38, humid_14);
	_mav_put_uint16_t(buf, 40, humid_15);
	_mav_put_uint16_t(buf, 42, humid_16);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY, buf, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN, MAVLINK_MSG_ID_TEENSY_HUMIDITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY, buf, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif
#else
	mavlink_teensy_humidity_t *packet = (mavlink_teensy_humidity_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->time_device = time_device;
	packet->humid_1 = humid_1;
	packet->humid_2 = humid_2;
	packet->humid_3 = humid_3;
	packet->humid_4 = humid_4;
	packet->humid_5 = humid_5;
	packet->humid_6 = humid_6;
	packet->humid_7 = humid_7;
	packet->humid_8 = humid_8;
	packet->humid_9 = humid_9;
	packet->humid_10 = humid_10;
	packet->humid_11 = humid_11;
	packet->humid_12 = humid_12;
	packet->humid_13 = humid_13;
	packet->humid_14 = humid_14;
	packet->humid_15 = humid_15;
	packet->humid_16 = humid_16;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY, (const char *)packet, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN, MAVLINK_MSG_ID_TEENSY_HUMIDITY_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_HUMIDITY, (const char *)packet, MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE TEENSY_HUMIDITY UNPACKING


/**
 * @brief Get field time_usec from teensy_humidity message
 *
 * @return Image timestamp (microseconds since UNIX epoch, according to camera clock)
 */
static inline uint64_t mavlink_msg_teensy_humidity_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_device from teensy_humidity message
 *
 * @return Sample Number
 */
static inline uint32_t mavlink_msg_teensy_humidity_get_time_device(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field humid_1 from teensy_humidity message
 *
 * @return humidity from sensor 1
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field humid_2 from teensy_humidity message
 *
 * @return humidity from sensor 2
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field humid_3 from teensy_humidity message
 *
 * @return humidity from sensor 3
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field humid_4 from teensy_humidity message
 *
 * @return humidity from sensor 4
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field humid_5 from teensy_humidity message
 *
 * @return humidity from sensor 5
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field humid_6 from teensy_humidity message
 *
 * @return humidity from sensor 6
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field humid_7 from teensy_humidity message
 *
 * @return humidity from sensor 7
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_7(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field humid_8 from teensy_humidity message
 *
 * @return humidity from sensor 8
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_8(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field humid_9 from teensy_humidity message
 *
 * @return humidity from sensor 9
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_9(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field humid_10 from teensy_humidity message
 *
 * @return humidity from sensor 10
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_10(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field humid_11 from teensy_humidity message
 *
 * @return humidity from sensor 11
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_11(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field humid_12 from teensy_humidity message
 *
 * @return humidity from sensor 12
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_12(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field humid_13 from teensy_humidity message
 *
 * @return humidity from sensor 13
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_13(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field humid_14 from teensy_humidity message
 *
 * @return humidity from sensor 14
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_14(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field humid_15 from teensy_humidity message
 *
 * @return humidity from sensor 15
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_15(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field humid_16 from teensy_humidity message
 *
 * @return humidity from sensor 16
 */
static inline uint16_t mavlink_msg_teensy_humidity_get_humid_16(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Decode a teensy_humidity message into a struct
 *
 * @param msg The message to decode
 * @param teensy_humidity C-struct to decode the message contents into
 */
static inline void mavlink_msg_teensy_humidity_decode(const mavlink_message_t* msg, mavlink_teensy_humidity_t* teensy_humidity)
{
#if MAVLINK_NEED_BYTE_SWAP
	teensy_humidity->time_usec = mavlink_msg_teensy_humidity_get_time_usec(msg);
	teensy_humidity->time_device = mavlink_msg_teensy_humidity_get_time_device(msg);
	teensy_humidity->humid_1 = mavlink_msg_teensy_humidity_get_humid_1(msg);
	teensy_humidity->humid_2 = mavlink_msg_teensy_humidity_get_humid_2(msg);
	teensy_humidity->humid_3 = mavlink_msg_teensy_humidity_get_humid_3(msg);
	teensy_humidity->humid_4 = mavlink_msg_teensy_humidity_get_humid_4(msg);
	teensy_humidity->humid_5 = mavlink_msg_teensy_humidity_get_humid_5(msg);
	teensy_humidity->humid_6 = mavlink_msg_teensy_humidity_get_humid_6(msg);
	teensy_humidity->humid_7 = mavlink_msg_teensy_humidity_get_humid_7(msg);
	teensy_humidity->humid_8 = mavlink_msg_teensy_humidity_get_humid_8(msg);
	teensy_humidity->humid_9 = mavlink_msg_teensy_humidity_get_humid_9(msg);
	teensy_humidity->humid_10 = mavlink_msg_teensy_humidity_get_humid_10(msg);
	teensy_humidity->humid_11 = mavlink_msg_teensy_humidity_get_humid_11(msg);
	teensy_humidity->humid_12 = mavlink_msg_teensy_humidity_get_humid_12(msg);
	teensy_humidity->humid_13 = mavlink_msg_teensy_humidity_get_humid_13(msg);
	teensy_humidity->humid_14 = mavlink_msg_teensy_humidity_get_humid_14(msg);
	teensy_humidity->humid_15 = mavlink_msg_teensy_humidity_get_humid_15(msg);
	teensy_humidity->humid_16 = mavlink_msg_teensy_humidity_get_humid_16(msg);
#else
	memcpy(teensy_humidity, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TEENSY_HUMIDITY_LEN);
#endif
}
