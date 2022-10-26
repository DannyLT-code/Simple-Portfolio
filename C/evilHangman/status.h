#ifndef STATUS_H
#define STATUS_H

enum status {FAILURE, SUCCESS, FAILURE_NOT_EOF};
enum boolean {FALSE, TRUE};

typedef enum status Status;
typedef enum boolean Boolean;

#endif
