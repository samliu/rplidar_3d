// Dynamixel AX-12 control table values.
//
// The values are as listed on this site:
// http://support.robotis.com/en/product/actuator/dynamixel/ax_series/dxl_ax_actuator.htm

// Lowest byte of the model number. Read only.
#define DXL_CTRL_TBL_MODEL_L 0

// Highest byte of the model number. Read only.
#define DXL_CTRL_TBL_MODEL_H 1

// Information on the firmware version.
#define DXL_CTRL_TBL_FIRMWARE_VERSION 2

// Dynamixel ID.
#define DXL_CTRL_TBL_DEVICE_ID 3

// Baud rate of the Dynamixel.
#define DXL_CTRL_TBL_DEVICE_BAUD_RATE 4

// Return delay time.
#define DXL_CTRL_TBL_RETURN_DELAY_TIME 5

// Lowest byte of the clockwise angle limit.
#define DXL_CTRL_TBL_CW_ANGLE_LIMIT_L 6

// Highest byte of the clockwise angle limit.
#define DXL_CTRL_TBL_CW_ANGLE_LIMIT_H 7

// TODO(samcliu): Finish adding comments...
#define DXL_CTRL_TBL_CCW_ANGLE_LIMIT_L 8
#define DXL_CTRL_TBL_CCW_ANGLE_LIMIT_H 9
#define DXL_CTRL_TBL_INTERNAL_TEMP_LIMIT 11
#define DXL_CTRL_TBL_VOLTAGE_LIMIT_MIN 12
#define DXL_CTRL_TBL_VOLTAGE_LIMIT_MAX 13
#define DXL_CTRL_TBL_MAX_TORQUE_L 14
#define DXL_CTRL_TBL_MAX_TORQUE_H 15
#define DXL_CTRL_TBL_STATUS_RETURN_LEVEL 16
#define DXL_CTRL_TBL_ALARM_LED 17
#define DXL_CTRL_TBL_ALARM_SHUTDOWN 18
#define DXL_CTRL_TBL_TOGGLE_TORQUE 24
#define DXL_CTRL_TBL_TOGGLE_LED 25
#define DXL_CTRL_TBL_CW_COMPLIANCE_MARGIN 26
#define DXL_CTRL_TBL_CCW_COMPLIANCE_MARGIN 27
#define DXL_CTRL_TBL_CW_COMPLIANCE_SLOPE 28
#define DXL_CTRL_TBL_CCW_COMPLIANCE_SLOPE 29
#define DXL_CTRL_TBL_GOAL_POSITION_L 30
#define DXL_CTRL_TBL_GOAL_POSITION_H 31
#define DXL_CTRL_TBL_MOVING_SPEED_L 32
#define DXL_CTRL_TBL_MOVING_SPEED_H 33
#define DXL_CTRL_TBL_TORQUE_LIMIT_L 34
#define DXL_CTRL_TBL_TORQUE_LIMIT_H 35
#define DXL_CTRL_TBL_PRESENT_POSITION_L 36
#define DXL_CTRL_TBL_PRESENT_POSITION_H 37
#define DXL_CTRL_TBL_PRESENT_SPEED_L 38
#define DXL_CTRL_TBL_PRESENT_SPEED_H 39
#define DXL_CTRL_TBL_PRESENT_LOAD_L 40
#define DXL_CTRL_TBL_PRESENT_LOAD_H 41
#define DXL_CTRL_TBL_PRESENT_VOLTAGE 42
#define DXL_CTRL_TBL_PRESENT_TEMPERATURE 43
#define DXL_CTRL_TBL_INSTRUCTION_REGISTERED 44
#define DXL_CTRL_TBL_IS_MOVING 46
#define DXL_CTRL_TBL_LOCK 47
#define DXL_CTRL_TBL_PUNCH_L 48
#define DXL_CTRL_TBL_PUNCH_H 49
