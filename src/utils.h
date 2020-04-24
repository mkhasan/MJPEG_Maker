/*
 * utils.h
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <string>
#include <exception>


#define THROW(exceptionClass, message) throw exceptionClass(__FILE__, \
__LINE__, (message) )

namespace mjpeg_maker {

	class RobotException : public std::exception
	{
		// Disable copy constructors
		RobotException& operator=(const RobotException&);
		std::string file_;
		int line_;
		std::string e_what_;
		int errno_;
	public:
		explicit RobotException(std::string file, int line, int errnum)
			: file_(file), line_(line), errno_(errnum) {
			std::stringstream ss;
#if defined(_WIN32) && !defined(__MINGW32__)
			char error_str[1024];
			strerror_s(error_str, 1024, errnum);
#else
			char * error_str = strerror(errnum);
#endif
			ss << "Robot Exception (" << errno_ << "): " << error_str;
			ss << ", file " << file_ << ", line " << line_ << ".";
			e_what_ = ss.str();
		}
		explicit RobotException(std::string file, int line, const char * description)
			: file_(file), line_(line), errno_(0) {
			std::stringstream ss;
			ss << "Robot Exception: " << description;
			ss << ", file " << file_ << ", line " << line_ << ".";
			e_what_ = ss.str();
		}
		virtual ~RobotException() throw() {}
		RobotException(const RobotException& other) : line_(other.line_), e_what_(other.e_what_), errno_(other.errno_) {}

		int getErrorNumber() const { return errno_; }

		virtual const char* what() const throw () {
			return e_what_.c_str();
		}

	};

}

#endif /* SRC_UTILS_H_ */
