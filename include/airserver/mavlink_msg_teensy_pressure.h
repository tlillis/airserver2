// MESSAGE TEENSY_PRESSURE PACKING

#define MAVLINK_MSG_ID_TEENSY_PRESSURE 244

typedef struct __mavlink_teensy_pressure_t
{
 uint64_t time_usec; ///< Image timestamp (microseconds since UNIX epoch, according to camera clock)
 uint32_t time_device; ///< Sample Number
 uint16_t press_1; ///< pressure from sensor 1
 uint16_t press_2; ///< pressure from sensor 2
 uint16_t press_3; ///< pressure from sensor 3
 uint16_t press_4; ///< pressure from sensor 4
 uint16_t press_5; ///< pressure from sensor 5
 uint16_t press_6; ///< pressure from sensor 6
 uint16_t press_7; ///< pressure from sensor 7
 uint16_t press_8; ///< pressure from sensor 8
 uint16_t press_9; ///< pressure from sensor 9
 uint16_t press_10; ///< pressure from sensor 10
 uint16_t press_11; ///< pressure from sensor 11
 uint16_t press_12; ///< pressure from sensor 12
 uint16_t press_13; ///< pressure from sensor 13
 uint16_t press_14; ///< pressure from sensor 14
 uint16_t press_15; ///< pressure from sensor 15
 uint16_t press_16; ///< pressure from sensor 16
} mavlink_teensy_pressure_t;

#define MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN 44
#define MAVLINK_MSG_ID_244_LEN 44

#define MAVLINK_MSG_ID_TEENSY_PRESSURE_CRC 1
#define MAVLINK_MSG_ID_244_CRC 1



#define MAVLINK_MESSAGE_INFO_TEENSY_PRESSURE { \
	"TEENSY_PRESSURE", \
	18, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_teensy_pressure_t, time_usec) }, \
         { "time_device", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_teensy_pressure_t, time_device) }, \
         { "press_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_teensy_pressure_t, press_1) }, \
         { "press_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_teensy_pressure_t, press_2) }, \
         { "press_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_teensy_pressure_t, press_3) }, \
         { "press_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_teensy_pressure_t, press_4) }, \
         { "press_5", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_teensy_pressure_t, press_5) }, \
         { "press_6", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_teensy_pressure_t, press_6) }, \
         { "press_7", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_teensy_pressure_t, press_7) }, \
         { "press_8", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_teensy_pressure_t, press_8) }, \
         { "press_9", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_teensy_pressure_t, press_9) }, \
         { "press_10", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_teensy_pressure_t, press_10) }, \
         { "press_11", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_teensy_pressure_t, press_11) }, \
         { "press_12", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_teensy_pressure_t, press_12) }, \
         { "press_13", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_teensy_pressure_t, press_13) }, \
         { "press_14", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_teensy_pressure_t, press_14) }, \
         { "press_15", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_teensy_pressure_t, press_15) }, \
         { "press_16", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_teensy_pressure_t, press_16) }, \
         } \
}


/**
 * @brief Pack a teensy_pressure message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param press_1 pressure from sensor 1
 * @param press_2 pressure from sensor 2
 * @param press_3 pressure from sensor 3
 * @param press_4 pressure from sensor 4
 * @param press_5 pressure from sensor 5
 * @param press_6 pressure from sensor 6
 * @param press_7 pressure from sensor 7
 * @param press_8 pressure from sensor 8
 * @param press_9 pressure from sensor 9
 * @param press_10 pressure from sensor 10
 * @param press_11 pressure from sensor 11
 * @param press_12 pressure from sensor 12
 * @param press_13 pressure from sensor 13
 * @param press_14 pressure from sensor 14
 * @param press_15 pressure from sensor 15
 * @param press_16 pressure from sensor 16
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_teensy_pressure_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint32_t time_device, uint16_t press_1, uint16_t press_2, uint16_t press_3, uint16_t press_4, uint16_t press_5, uint16_t press_6, uint16_t press_7, uint16_t press_8, uint16_t press_9, uint16_t press_10, uint16_t press_11, uint16_t press_12, uint16_t press_13, uint16_t press_14, uint16_t press_15, uint16_t press_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, press_1);
	_mav_put_uint16_t(buf, 14, press_2);
	_mav_put_uint16_t(buf, 16, press_3);
	_mav_put_uint16_t(buf, 18, press_4);
	_mav_put_uint16_t(buf, 20, press_5);
	_mav_put_uint16_t(buf, 22, press_6);
	_mav_put_uint16_t(buf, 24, press_7);
	_mav_put_uint16_t(buf, 26, press_8);
	_mav_put_uint16_t(buf, 28, press_9);
	_mav_put_uint16_t(buf, 30, press_10);
	_mav_put_uint16_t(buf, 32, press_11);
	_mav_put_uint16_t(buf, 34, press_12);
	_mav_put_uint16_t(buf, 36, press_13);
	_mav_put_uint16_t(buf, 38, press_14);
	_mav_put_uint16_t(buf, 40, press_15);
	_mav_put_uint16_t(buf, 42, press_16);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#else
	mavlink_teensy_pressure_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.press_1 = press_1;
	packet.press_2 = press_2;
	packet.press_3 = press_3;
	packet.press_4 = press_4;
	packet.press_5 = press_5;
	packet.press_6 = press_6;
	packet.press_7 = press_7;
	packet.press_8 = press_8;
	packet.press_9 = press_9;
	packet.press_10 = press_10;
	packet.press_11 = press_11;
	packet.press_12 = press_12;
	packet.press_13 = press_13;
	packet.press_14 = press_14;
	packet.press_15 = press_15;
	packet.press_16 = press_16;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEENSY_PRESSURE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN, MAVLINK_MSG_ID_TEENSY_PRESSURE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif
}

/**
 * @brief Pack a teensy_pressure message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param press_1 pressure from sensor 1
 * @param press_2 pressure from sensor 2
 * @param press_3 pressure from sensor 3
 * @param press_4 pressure from sensor 4
 * @param press_5 pressure from sensor 5
 * @param press_6 pressure from sensor 6
 * @param press_7 pressure from sensor 7
 * @param press_8 pressure from sensor 8
 * @param press_9 pressure from sensor 9
 * @param press_10 pressure from sensor 10
 * @param press_11 pressure from sensor 11
 * @param press_12 pressure from sensor 12
 * @param press_13 pressure from sensor 13
 * @param press_14 pressure from sensor 14
 * @param press_15 pressure from sensor 15
 * @param press_16 pressure from sensor 16
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_teensy_pressure_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint32_t time_device,uint16_t press_1,uint16_t press_2,uint16_t press_3,uint16_t press_4,uint16_t press_5,uint16_t press_6,uint16_t press_7,uint16_t press_8,uint16_t press_9,uint16_t press_10,uint16_t press_11,uint16_t press_12,uint16_t press_13,uint16_t press_14,uint16_t press_15,uint16_t press_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, press_1);
	_mav_put_uint16_t(buf, 14, press_2);
	_mav_put_uint16_t(buf, 16, press_3);
	_mav_put_uint16_t(buf, 18, press_4);
	_mav_put_uint16_t(buf, 20, press_5);
	_mav_put_uint16_t(buf, 22, press_6);
	_mav_put_uint16_t(buf, 24, press_7);
	_mav_put_uint16_t(buf, 26, press_8);
	_mav_put_uint16_t(buf, 28, press_9);
	_mav_put_uint16_t(buf, 30, press_10);
	_mav_put_uint16_t(buf, 32, press_11);
	_mav_put_uint16_t(buf, 34, press_12);
	_mav_put_uint16_t(buf, 36, press_13);
	_mav_put_uint16_t(buf, 38, press_14);
	_mav_put_uint16_t(buf, 40, press_15);
	_mav_put_uint16_t(buf, 42, press_16);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#else
	mavlink_teensy_pressure_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.press_1 = press_1;
	packet.press_2 = press_2;
	packet.press_3 = press_3;
	packet.press_4 = press_4;
	packet.press_5 = press_5;
	packet.press_6 = press_6;
	packet.press_7 = press_7;
	packet.press_8 = press_8;
	packet.press_9 = press_9;
	packet.press_10 = press_10;
	packet.press_11 = press_11;
	packet.press_12 = press_12;
	packet.press_13 = press_13;
	packet.press_14 = press_14;
	packet.press_15 = press_15;
	packet.press_16 = press_16;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEENSY_PRESSURE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN, MAVLINK_MSG_ID_TEENSY_PRESSURE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif
}

/**
 * @brief Encode a teensy_pressure struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param teensy_pressure C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_teensy_pressure_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_teensy_pressure_t* teensy_pressure)
{
	return mavlink_msg_teensy_pressure_pack(system_id, component_id, msg, teensy_pressure->time_usec, teensy_pressure->time_device, teensy_pressure->press_1, teensy_pressure->press_2, teensy_pressure->press_3, teensy_pressure->press_4, teensy_pressure->press_5, teensy_pressure->press_6, teensy_pressure->press_7, teensy_pressure->press_8, teensy_pressure->press_9, teensy_pressure->press_10, teensy_pressure->press_11, teensy_pressure->press_12, teensy_pressure->press_13, teensy_pressure->press_14, teensy_pressure->press_15, teensy_pressure->press_16);
}

/**
 * @brief Encode a teensy_pressure struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param teensy_pressure C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_teensy_pressure_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_teensy_pressure_t* teensy_pressure)
{
	return mavlink_msg_teensy_pressure_pack_chan(system_id, component_id, chan, msg, teensy_pressure->time_usec, teensy_pressure->time_device, teensy_pressure->press_1, teensy_pressure->press_2, teensy_pressure->press_3, teensy_pressure->press_4, teensy_pressure->press_5, teensy_pressure->press_6, teensy_pressure->press_7, teensy_pressure->press_8, teensy_pressure->press_9, teensy_pressure->press_10, teensy_pressure->press_11, teensy_pressure->press_12, teensy_pressure->press_13, teensy_pressure->press_14, teensy_pressure->press_15, teensy_pressure->press_16);
}

/**
 * @brief Send a teensy_pressure message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param press_1 pressure from sensor 1
 * @param press_2 pressure from sensor 2
 * @param press_3 pressure from sensor 3
 * @param press_4 pressure from sensor 4
 * @param press_5 pressure from sensor 5
 * @param press_6 pressure from sensor 6
 * @param press_7 pressure from sensor 7
 * @param press_8 pressure from sensor 8
 * @param press_9 pressure from sensor 9
 * @param press_10 pressure from sensor 10
 * @param press_11 pressure from sensor 11
 * @param press_12 pressure from sensor 12
 * @param press_13 pressure from sensor 13
 * @param press_14 pressure from sensor 14
 * @param press_15 pressure from sensor 15
 * @param press_16 pressure from sensor 16
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_teensy_pressure_send(mavlink_channel_t chan, uint64_t time_usec, uint32_t time_device, uint16_t press_1, uint16_t press_2, uint16_t press_3, uint16_t press_4, uint16_t press_5, uint16_t press_6, uint16_t press_7, uint16_t press_8, uint16_t press_9, uint16_t press_10, uint16_t press_11, uint16_t press_12, uint16_t press_13, uint16_t press_14, uint16_t press_15, uint16_t press_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, press_1);
	_mav_put_uint16_t(buf, 14, press_2);
	_mav_put_uint16_t(buf, 16, press_3);
	_mav_put_uint16_t(buf, 18, press_4);
	_mav_put_uint16_t(buf, 20, press_5);
	_mav_put_uint16_t(buf, 22, press_6);
	_mav_put_uint16_t(buf, 24, press_7);
	_mav_put_uint16_t(buf, 26, press_8);
	_mav_put_uint16_t(buf, 28, press_9);
	_mav_put_uint16_t(buf, 30, press_10);
	_mav_put_uint16_t(buf, 32, press_11);
	_mav_put_uint16_t(buf, 34, press_12);
	_mav_put_uint16_t(buf, 36, press_13);
	_mav_put_uint16_t(buf, 38, press_14);
	_mav_put_uint16_t(buf, 40, press_15);
	_mav_put_uint16_t(buf, 42, press_16);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_PRESSURE, buf, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN, MAVLINK_MSG_ID_TEENSY_PRESSURE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_PRESSURE, buf, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif
#else
	mavlink_teensy_pressure_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.press_1 = press_1;
	packet.press_2 = press_2;
	packet.press_3 = press_3;
	packet.press_4 = press_4;
	packet.press_5 = press_5;
	packet.press_6 = press_6;
	packet.press_7 = press_7;
	packet.press_8 = press_8;
	packet.press_9 = press_9;
	packet.press_10 = press_10;
	packet.press_11 = press_11;
	packet.press_12 = press_12;
	packet.press_13 = press_13;
	packet.press_14 = press_14;
	packet.press_15 = press_15;
	packet.press_16 = press_16;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_PRESSURE, (const char *)&packet, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN, MAVLINK_MSG_ID_TEENSY_PRESSURE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_PRESSURE, (const char *)&packet, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_teensy_pressure_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint32_t time_device, uint16_t press_1, uint16_t press_2, uint16_t press_3, uint16_t press_4, uint16_t press_5, uint16_t press_6, uint16_t press_7, uint16_t press_8, uint16_t press_9, uint16_t press_10, uint16_t press_11, uint16_t press_12, uint16_t press_13, uint16_t press_14, uint16_t press_15, uint16_t press_16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint16_t(buf, 12, press_1);
	_mav_put_uint16_t(buf, 14, press_2);
	_mav_put_uint16_t(buf, 16, press_3);
	_mav_put_uint16_t(buf, 18, press_4);
	_mav_put_uint16_t(buf, 20, press_5);
	_mav_put_uint16_t(buf, 22, press_6);
	_mav_put_uint16_t(buf, 24, press_7);
	_mav_put_uint16_t(buf, 26, press_8);
	_mav_put_uint16_t(buf, 28, press_9);
	_mav_put_uint16_t(buf, 30, press_10);
	_mav_put_uint16_t(buf, 32, press_11);
	_mav_put_uint16_t(buf, 34, press_12);
	_mav_put_uint16_t(buf, 36, press_13);
	_mav_put_uint16_t(buf, 38, press_14);
	_mav_put_uint16_t(buf, 40, press_15);
	_mav_put_uint16_t(buf, 42, press_16);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_PRESSURE, buf, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN, MAVLINK_MSG_ID_TEENSY_PRESSURE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_PRESSURE, buf, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif
#else
	mavlink_teensy_pressure_t *packet = (mavlink_teensy_pressure_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->time_device = time_device;
	packet->press_1 = press_1;
	packet->press_2 = press_2;
	packet->press_3 = press_3;
	packet->press_4 = press_4;
	packet->press_5 = press_5;
	packet->press_6 = press_6;
	packet->press_7 = press_7;
	packet->press_8 = press_8;
	packet->press_9 = press_9;
	packet->press_10 = press_10;
	packet->press_11 = press_11;
	packet->press_12 = press_12;
	packet->press_13 = press_13;
	packet->press_14 = press_14;
	packet->press_15 = press_15;
	packet->press_16 = press_16;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_PRESSURE, (const char *)packet, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN, MAVLINK_MSG_ID_TEENSY_PRESSURE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEENSY_PRESSURE, (const char *)packet, MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE TEENSY_PRESSURE UNPACKING


/**
 * @brief Get field time_usec from teensy_pressure message
 *
 * @return Image timestamp (microseconds since UNIX epoch, according to camera clock)
 */
static inline uint64_t mavlink_msg_teensy_pressure_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_device from teensy_pressure message
 *
 * @return Sample Number
 */
static inline uint32_t mavlink_msg_teensy_pressure_get_time_device(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field press_1 from teensy_pressure message
 *
 * @return pressure from sensor 1
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field press_2 from teensy_pressure message
 *
 * @return pressure from sensor 2
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field press_3 from teensy_pressure message
 *
 * @return pressure from sensor 3
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field press_4 from teensy_pressure message
 *
 * @return pressure from sensor 4
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field press_5 from teensy_pressure message
 *
 * @return pressure from sensor 5
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field press_6 from teensy_pressure message
 *
 * @return pressure from sensor 6
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field press_7 from teensy_pressure message
 *
 * @return pressure from sensor 7
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_7(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field press_8 from teensy_pressure message
 *
 * @return pressure from sensor 8
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_8(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field press_9 from teensy_pressure message
 *
 * @return pressure from sensor 9
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_9(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field press_10 from teensy_pressure message
 *
 * @return pressure from sensor 10
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_10(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field press_11 from teensy_pressure message
 *
 * @return pressure from sensor 11
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_11(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field press_12 from teensy_pressure message
 *
 * @return pressure from sensor 12
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_12(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field press_13 from teensy_pressure message
 *
 * @return pressure from sensor 13
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_13(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field press_14 from teensy_pressure message
 *
 * @return pressure from sensor 14
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_14(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field press_15 from teensy_pressure message
 *
 * @return pressure from sensor 15
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_15(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field press_16 from teensy_pressure message
 *
 * @return pressure from sensor 16
 */
static inline uint16_t mavlink_msg_teensy_pressure_get_press_16(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Decode a teensy_pressure message into a struct
 *
 * @param msg The message to decode
 * @param teensy_pressure C-struct to decode the message contents into
 */
static inline void mavlink_msg_teensy_pressure_decode(const mavlink_message_t* msg, mavlink_teensy_pressure_t* teensy_pressure)
{
#if MAVLINK_NEED_BYTE_SWAP
	teensy_pressure->time_usec = mavlink_msg_teensy_pressure_get_time_usec(msg);
	teensy_pressure->time_device = mavlink_msg_teensy_pressure_get_time_device(msg);
	teensy_pressure->press_1 = mavlink_msg_teensy_pressure_get_press_1(msg);
	teensy_pressure->press_2 = mavlink_msg_teensy_pressure_get_press_2(msg);
	teensy_pressure->press_3 = mavlink_msg_teensy_pressure_get_press_3(msg);
	teensy_pressure->press_4 = mavlink_msg_teensy_pressure_get_press_4(msg);
	teensy_pressure->press_5 = mavlink_msg_teensy_pressure_get_press_5(msg);
	teensy_pressure->press_6 = mavlink_msg_teensy_pressure_get_press_6(msg);
	teensy_pressure->press_7 = mavlink_msg_teensy_pressure_get_press_7(msg);
	teensy_pressure->press_8 = mavlink_msg_teensy_pressure_get_press_8(msg);
	teensy_pressure->press_9 = mavlink_msg_teensy_pressure_get_press_9(msg);
	teensy_pressure->press_10 = mavlink_msg_teensy_pressure_get_press_10(msg);
	teensy_pressure->press_11 = mavlink_msg_teensy_pressure_get_press_11(msg);
	teensy_pressure->press_12 = mavlink_msg_teensy_pressure_get_press_12(msg);
	teensy_pressure->press_13 = mavlink_msg_teensy_pressure_get_press_13(msg);
	teensy_pressure->press_14 = mavlink_msg_teensy_pressure_get_press_14(msg);
	teensy_pressure->press_15 = mavlink_msg_teensy_pressure_get_press_15(msg);
	teensy_pressure->press_16 = mavlink_msg_teensy_pressure_get_press_16(msg);
#else
	memcpy(teensy_pressure, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TEENSY_PRESSURE_LEN);
#endif
}
