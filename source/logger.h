/***************************************************************************
 * Description:
 * version: 0.1.0
 * Author: Panda-Young
 * Date: 2024-09-26 10:35:40
 * Copyright (c) 2024 by Panda-Young, All Rights Reserved.
 **************************************************************************/

#ifndef _LOGGER_H
#define _LOGGER_H

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <unistd.h>
#endif

typedef enum {
    LOG_OFF = 0,
    LOG_ERROR,
    LOG_WARNING,
    LOG_INFO,
    LOG_DEBUG,
} LOG_TYPE;

#ifndef log_level
#define log_level LOG_DEBUG
#endif

#ifndef __FILENAME__
#define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1) : (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__))
#endif

#define LOG_FILE_NAME "C:\\Users\\60061804\\AppData\\Local\\Temp\\myNew_AWE_MODULE.log"

#ifdef _WIN32
#define LOG(level, level_str, fmt, ...)                                                                        \
    do {                                                                                                       \
        if (log_level >= level) {                                                                              \
            FILE *log_file = fopen(LOG_FILE_NAME, "a+");                                                       \
            if (log_file) {                                                                                    \
                SYSTEMTIME st;                                                                                 \
                GetLocalTime(&st);                                                                             \
                int pid = (int)GetCurrentProcessId();                                                          \
                int tid = (int)GetCurrentThreadId();                                                           \
                char _log_buf[1024] = {0};                                                                     \
                snprintf(_log_buf, sizeof(_log_buf), "%04d-%02d-%02d %02d:%02d:%02d.%03d [%d.%d] %s %s@%s:%d", \
                         st.wYear, st.wMonth, st.wDay,                                                         \
                         st.wHour, st.wMinute, st.wSecond, st.wMilliseconds,                                   \
                         pid, tid, level_str, __FILENAME__, __FUNCTION__, __LINE__);                           \
                fprintf(log_file, "%-96s" fmt "\n", _log_buf, ##__VA_ARGS__);                                  \
                fflush(log_file);                                                                              \
                fclose(log_file);                                                                              \
            }                                                                                                  \
        }                                                                                                      \
    } while (0)
#else
#define LOG(level, level_str, fmt, ...)                                                                         \
    do {                                                                                                        \
        if (log_level >= level) {                                                                               \
            FILE *log_file = fopen(LOG_FILE_NAME, "a+");                                                        \
            if (log_file) {                                                                                     \
                char _log_buf[1024] = {0};                                                                      \
                struct tm tm_info;                                                                              \
                struct timeval tv;                                                                              \
                gettimeofday(&tv, NULL);                                                                        \
                localtime_r(&tv.tv_sec, &tm_info);                                                              \
                int pid = (int)getpid();                                                                        \
                int tid = (int)syscall(SYS_gettid);                                                             \
                snprintf(_log_buf, sizeof(_log_buf), "%04d-%02d-%02d %02d:%02d:%02d.%03ld [%d.%d] %s %s@%s:%d", \
                         tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday,                           \
                         tm_info.tm_hour, tm_info.tm_min, tm_info.tm_sec, tv.tv_usec / 1000,                    \
                         pid, tid, level_str, __FILENAME__, __FUNCTION__, __LINE__);                            \
                fprintf(log_file, "%-96s" fmt "\n", _log_buf, ##__VA_ARGS__);                                   \
                fflush(log_file);                                                                               \
                fclose(log_file);                                                                               \
            }                                                                                                   \
        }                                                                                                       \
    } while (0)
#endif

#define LOGD(fmt, ...) LOG(LOG_DEBUG, "DEBUG", fmt, ##__VA_ARGS__)
#define LOGI(fmt, ...) LOG(LOG_INFO, "INFO ", fmt, ##__VA_ARGS__)
#define LOGW(fmt, ...) LOG(LOG_WARNING, "WARN ", fmt, ##__VA_ARGS__)
#define LOGE(fmt, ...) LOG(LOG_ERROR, "ERROR", fmt, ##__VA_ARGS__)

#endif // _LOGGER_H
