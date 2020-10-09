#pragma once


#define CGM_EXAMPLES_PRINT(message)   std::cout << message << std::endl;

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_FUNC_INFO(message) std::cout << "[INFO | " << __FUNCTION__ << "()]: " << message << std::endl;

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_FUNC_WARNING(message) std::cout << "[WARNING | " << __FUNCTION__ << "()]: " << message << std::endl;

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_FUNC_ERROR(message) std::cout << "[ERROR | " << __FUNCTION__ << "()]: " << message << std::endl; exit(-1);

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;