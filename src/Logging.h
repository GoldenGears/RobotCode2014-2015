//*********************
// Golden Gears Robotics
// 12/2/14
// Logging
// Defines a bunch of logging macros which send log statements to stdout (and subsequently gets broadcast over UDP port 6668)
//   If enabled, the macros print the current file, line, and a supplied message.
//
// UDP - Internet protocol that broadcasts data and doesn't wait for a response.
//*********************

// 12-2-14 - Tyler Robbins - Created a file to define logging macros to send messages back to the driver station.

#ifndef _LOGGING_H_
#define _LOGGING_H_

#include <stdio.h>

// Comment and uncomment these to enable/disable debugging on a specific level
#define LEVEL_ERROR
#define LEVEL_DEBUG
#define LEVEL_WARN
#define LEVEL_INFO

// Each of these will be defined depending on whether debugging has been enabled at their level.

// If they are enabled, then the function will print out the error level, the file and line number, and the supplied message
//	"[LEVEL] (file:line) message"

// If they are disabled, then the functions will be defined as empty, and will do nothing.

#ifdef LEVEL_ERROR
#define log_error(message,...) printf("[ERROR] (%s:%d) " message "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_error(message,...)
#endif

#ifdef LEVEL_DEBUG
#define log_debug(message,...) printf("[DEBUG] (%s:%d) " message "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_debug(message,...)
#endif

#ifdef LEVEL_ERROR
#define log_warn(message,...) printf("[WARN] (%s:%d) " message "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_warn(message,...)
#endif

#ifdef LEVEL_ERROR
#define log_info(message,...) printf("[INFO] (%s:%d) " message "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_info(message,...)
#endif

#endif