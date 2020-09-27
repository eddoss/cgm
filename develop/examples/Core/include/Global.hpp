#pragma once


#define CGM_EXAMPLES_PRINT(message)   std::cout << message << std::endl;

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_FUNC_INFO(message) std::cout << std::endl; std::cout << __FUNCTION__ << "()" << std::endl; std::cout << message << std::endl;

/* --------------------------------------------------------------------------------------- */

#define CGM_EXAMPLES_DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;